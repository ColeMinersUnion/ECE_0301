#include "VoltageDivider.h"
#include "VoltageDivider.cpp"
#include "Network.h"
#include "Network.cpp"
#include "Node.h"
#include "Node.cpp"
#include "Component.h"
#include "Component.cpp"
#include "DCVoltageSource.h"
#include "DCVoltageSource.cpp"
#include "Resistor.h"
#include "Resistor.cpp"
#include "DCCurrentSource.h"
#include "DCCurrentSource.cpp"
#include "CurrentDivider.h"
#include "CurrentDivider.cpp"
#include <iostream>
#include <fstream>

int main(){
    std::ofstream outfile;
    std::ifstream infile;
    infile.open("ECE 0301 - Circuits to Simulate.txt");
    outfile.open("ECE 0301 - Electrical Network Reports.txt");
    outfile << "ECE 0301 - Electrical Network Simulation\n\n";

    std::string temp;
    std::getline(infile, temp);
    double src, R1, R2;
    if(temp == "Voltage Divider"){
        std::getline(infile, temp);
        src = std::stof(temp);
        std::getline(infile, temp);
        R1 = std::stod(temp);
        std::getline(infile, temp);
        R2 = std::stod(temp);
        VoltageDivider net(src, R1, R2);
        net.output(&outfile);
    } else if(temp == "Current Divider") {
        std::getline(infile, temp);
        src = std::stof(temp);
        std::getline(infile, temp);
        R1 = std::stod(temp);
        std::getline(infile, temp);
        R2 = std::stod(temp);
        CurrentDivider net(src, R1, R2);
        net.output(&outfile);
    } else { exit(1);}

    outfile.close();
    infile.close();
    return 0;
}

