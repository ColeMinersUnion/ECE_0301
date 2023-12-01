#include "Resistor.h"
#include <fstream>
Resistor::Resistor() : Component(){
    resistance = 1000;
}

Resistor::Resistor(double r) : Component(){
    resistance = r;
}

void Resistor::setResistance(double r){resistance = r;}
double Resistor::getResistance() const {return resistance;}
void Resistor::output(std::ofstream* file) const {
    *file << "\nComponent # " << Component::getIndex() << " is a Resistor, R = " << resistance << " Ohms.\n"; 
    Component::output(file);
    *file << "The current in this Resistor = " << abs(findCurrent()) << " Amps,\n";
    if(findCurrent() > 0){
        *file << "flowing from Node " << getA() << " to Node " << getB() <<".\n";
    } else {
        *file << "flowing from Node " << getB() << " to Node " << getA() <<".\n";
    }
    *file << "The power dissapated in this Resistor = " << findPower() << " Watts.\n";
}

double Resistor::findCurrent() const {return voltage()/resistance;}
double Resistor::findPower() const {return voltage() * voltage() / resistance;}