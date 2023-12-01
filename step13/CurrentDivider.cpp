#include "CurrentDivider.h"
#include <fstream>

CurrentDivider::CurrentDivider() : Network(2){
    src.setCurr(1);
    R1.setResistance(1000);
    R2.setResistance(1000);

    src.setA(&getList()[0]);
    src.setB(&getList()[1]);

    R1.setA(&getList()[0]);
    R1.setB(&getList()[1]);

    R2.setA(&getList()[0]);
    R2.setB(&getList()[1]);
    CurrentDivider::calculate();
}

CurrentDivider::CurrentDivider(double V, double R, double RR) : Network(2){
    src.setCurr(V);
    R1.setResistance(R);
    R2.setResistance(RR);

    src.setA(&getList()[0]);
    src.setB(&getList()[1]);

    R1.setA(&getList()[0]);
    R1.setB(&getList()[1]);

    R2.setA(&getList()[0]);
    R2.setB(&getList()[1]);
    CurrentDivider::calculate();

}


void CurrentDivider::setR1(double r){ R1.setResistance(r);
    CurrentDivider::calculate();}
void CurrentDivider::setR2(double r){ R2.setResistance(r);
    CurrentDivider::calculate();}
void CurrentDivider::setCurrent(double v){ src.setCurr(v);
    CurrentDivider::calculate();}

void CurrentDivider::output(std::ofstream* file){
    *file << "\n";
    for(int i = 0; i < 48; i++){
        *file << "-";
    }

    *file << "\n\nData for Electrical Network # " << getIndex() << ":\n";
    *file << "Network # " << getIndex() << " is a Current Divider.\n";
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


void CurrentDivider::calculate(){
    getList()[0].setVoltage(0);
    double eqResistance = 1 / ((1/R1.getResistance()) + (1/R2.getResistance()));
    getList()[1].setVoltage(src.getCurr() * eqResistance);
}
