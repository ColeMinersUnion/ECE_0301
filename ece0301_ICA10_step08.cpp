#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

unsigned int read(double* Sampfreq, double* time, double* amp, double* freq, double* phase);

class Signal{

    private:
        unsigned int samples;
        double frequency, initial_time; //in Hz and Seconds
        double* signalPtr;
        double* timePtr;
        std::string filename;


        void fill(){
            for(int i = 0; i < samples; i++){
                signalPtr[i] = 0;
            }
        }

        void fillTime(){
            for(int i = 0; i < samples; i++){
                double N = i/1.0;
                timePtr[i] = initial_time + (i/frequency);
            }
        }

        

    public:
        Signal(){
            samples = 101;
            frequency = 100;
            initial_time = 0.0;
            signalPtr = new double[samples];
            timePtr = new double[samples];
            filename = "tsdig";

            //filling arrays. 
            fill();
            fillTime();
        }

        //overloaded constructor
        Signal(int size, double freq, double time){
            samples = size;
            frequency = freq;
            initial_time = time;
            //these are the same in both constructors
            signalPtr = new double[samples];
            timePtr = new double[samples];
            filename = "tsdig";

            //filling arrays. 
            fill();
            fillTime();

        }

        void round(){
            for(int i = 0; i < samples; i++){
                signalPtr[i] = std::round(signalPtr[i]);
            }
        }

        void fillSin(double A, double f, double phi){
            for(int i = 0; i < samples; i++){
                signalPtr[i] = A * cos(2 * M_PI * f * timePtr[i] + phi);
            }
        }

        ~Signal(){
            delete signalPtr;
            delete timePtr;
        }

        //mutator functions
        void setSamples(int size){
            samples = size;
        }

        void setFreq(double freq){
            frequency = freq;
        }

        void setTime(double time){
            initial_time = time;
        }

        void setFileName(std::string address){
            filename = address;
        }

        //accessor functions
        int getSamples(){
            return samples;
        }

        double getFreq(){
            return frequency;
        }

        double getTime(){
            return initial_time;
        }

        double* getPtr(){
            return signalPtr;
        }

        double* getTptr(){
            return timePtr;
        }


        //other functions
        void txt(){
            std::ofstream output;
            output.open(filename + ".txt");

            output << "ECE 0301: Time-Domain Signal Samples\n";
            output << "The number of samples is " << samples << std::endl;
            output << "The sample rate is " << frequency << std::endl;
            output << "The inital time is " << initial_time << std::endl;

            for(int i = 0; i < samples; i++){
                output << timePtr[i] << ", " << signalPtr[i] << std::endl;
            }

            output.close();
        }
};

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
