#include "Network.h"
#include "Node.h"
#include "Component.h"
#include "DCVoltageSource.h"
#include "Resistor.h"
#include <iostream>
#include <fstream>

int main(){
    std::ofstream outfile;
    outfile.open("ECE 0301 - Electrical Network Reports.txt");
    outfile << "ECE 0301 - Electrical Network Simulation\n";

    double DC = 12;

    Network social(3);
    social.setVoltageI(0, 0);
    social.setVoltageI(1, DC);
    social.setVoltageI(2, DC/3);
    DCVoltageSource Vcc;

    Resistor R2(200), R3(100);
    Vcc.setVDD(DC);
    Vcc.setA(&social.getList()[0]);
    Vcc.setB(&social.getList()[1]);

    R2.setA(&social.getList()[1]);
    R2.setB(&social.getList()[2]);

    R3.setA(&social.getList()[2]);
    R3.setB(&social.getList()[0]);
    
    social.output(&outfile);
    Vcc.output(&outfile);
    R2.output(&outfile);
    R3.output(&outfile);

    outfile.close();

    return 0;
}
