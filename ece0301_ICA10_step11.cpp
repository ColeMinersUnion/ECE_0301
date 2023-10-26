#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
//#include <mgl2/mgl.h>
#include "Signal.h"
#include "Signal.cpp"

unsigned int read(double* Sampfreq, double* time, double* amp, double* freq, double* phase);

int main(){
    double Sampf, time, freq, amp, phi;
    unsigned int size;

    size = read(&Sampf, &time, &amp, &freq, &phi);

    //instantiating (i can't spell)
    Signal MySignal(size, Sampf, time);
    MySignal.fillSin(amp, freq, phi);

    MySignal.round();

    //output steps
    MySignal.setFileName("time_domain_signal_samples");
    MySignal.txt();

    return 0;
}

unsigned int read( double* Sampfreq, double* time, double* amp, double* freq, double* phase){
    std::ifstream infile;
    const std::string address = "sine_wave_specification.txt";
    infile.open(address);
    
    std::string line;
    std::getline(infile, line);

    if(line.substr(0, 19) != "Number of samples: "){
        std::cout << line.substr(0, 20) << std::endl;
        std::cout << "ERROR! Invalid input file header.";
        exit(1);
    }

    int samples = std::stoi(line.substr(19));

    //line 2
    std::getline(infile, line);
    if(line.substr(0, 20) != "Sampling frequency: "){
        std::cout << line.substr(0, 21) << std::endl;
        std::cout << "ERROR! Invalid input file header.";
        exit(1);
    }

    *Sampfreq = std::stod(line.substr(20));

    //line 3
    std::getline(infile, line);
    if(line.substr(0, 14) != "Initial time: "){
        std::cout << line.substr(0, 15) << std::endl;
        std::cout << "ERROR! Invalid input file header.";
        exit(1);
    }

    *time = std::stod(line.substr(14));

    //line 4
    std::getline(infile, line);
    if(line.substr(0, 11) != "Amplitude: "){
        std::cout << line.substr(0, 12) << std::endl;
        std::cout << "ERROR! Invalid input file header.";
        exit(1);
    }

    *amp = std::stod(line.substr(11));

    //line 5
    std::getline(infile, line);
    if(line.substr(0, 11) != "Frequency: "){
        std::cout << line.substr(0, 12) << std::endl;
        std::cout << "ERROR! Invalid input file header.";
        exit(1);
    }

    *freq = std::stod(line.substr(11));

    //line 6
    std::getline(infile, line);
    if(line.substr(0, 7) != "Phase: "){
        std::cout << line.substr(0, 8) << std::endl;
        std::cout << "ERROR! Invalid input file header.";
        exit(1);
    }

    *phase = std::stod(line.substr(7));
    
    infile.close();
    return samples;
}
