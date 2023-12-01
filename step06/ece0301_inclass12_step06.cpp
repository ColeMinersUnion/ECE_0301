#include "Node.h"
#include "Network.h"
#include "Component.h"
#include <iostream>
#include <fstream>

int main(){

    std::ofstream outfile;
    outfile.open("ECE 0301 - Electrical Network Reports.txt");
    outfile << "ECE 0301 - Electrical Network Simulation\n";
    Network social(3);
    social.setVoltageI(0, 0);
    social.setVoltageI(1, -5);
    social.setVoltageI(2, 1.25);

    Component R1, R2, R3;
    R1.setA(&social.getList()[0]);
    R1.setB(&social.getList()[1]);

    R2.setA(&social.getList()[1]);
    R2.setB(&social.getList()[2]);

    R3.setA(&social.getList()[2]);
    R3.setB(&social.getList()[0]);
    
    social.output(&outfile);
    R1.output(&outfile);
    R2.output(&outfile);
    R3.output(&outfile);

    outfile.close();

    return 0;
}
