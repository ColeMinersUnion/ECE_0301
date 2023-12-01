#include "VoltageDivider.h"
#include <fstream>
VoltageDivider::VoltageDivider() : Network(3){
    src.setVDD(1);
    R1.setResistance(1000);
    R2.setResistance(1000);

    src.setA(&getList()[0]);
    src.setB(&getList()[1]);

    R1.setA(&getList()[1]);
    R1.setB(&getList()[2]);

    R2.setA(&getList()[2]);
    R2.setB(&getList()[0]);
    VoltageDivider::calculate();
}

VoltageDivider::VoltageDivider(double V, double R, double RR) : Network(3){
    src.setVDD(V);
    R1.setResistance(R);
    R2.setResistance(RR);

    src.setA(&getList()[0]);
    src.setB(&getList()[1]);

    R1.setA(&getList()[1]);
    R1.setB(&getList()[2]);

    R2.setA(&getList()[2]);
    R2.setB(&getList()[0]);
    VoltageDivider::calculate();

}


void VoltageDivider::setR1(double r){ R1.setResistance(r);
    VoltageDivider::calculate();}
void VoltageDivider::setR2(double r){ R2.setResistance(r);
    VoltageDivider::calculate();}
void VoltageDivider::setVoltage(double v){ src.setVDD(v);
    VoltageDivider::calculate();}

void VoltageDivider::output(std::ofstream* file){
    *file << "\n";
    for(int i = 0; i < 48; i++){
        *file << "-";
    }

    *file << "\n\nData for Electrical Network # " << getIndex() << ":\n";
    *file << "Network # " << getIndex() << " is a Voltage Divider.\n";
    *file << "At present, there are " << getNum() << " Networks in existance.\n";
    *file << "At present, there are " << getList()[0].getNum() << " nodes in existance.\n";
    *file << "Network # " << getIndex() << " has " << getNodes() << " nodes.\n";
    
    for(int i = 0; i < getNodes(); i++){
        *file << "Voltage at node " << getList()[i].getIndex() << " = " << getList()[i].getVoltage() << std::endl;
    }
    *file << "At present, there are " << src.getNum() << " components in existance.\n\n";

    src.output(file);
    R1.output(file);
    R2.output(file);
}


void VoltageDivider::calculate(){
    getList()[0].setVoltage(0);
    getList()[1].setVoltage(src.getVDD());
    double current = src.getVDD() / (R1.getResistance() + R2.getResistance());
    src.setCurrent(current);
    getList()[2].setVoltage(current * R2.getResistance());
}
