#include "DCVoltageSource.h"

DCVoltageSource::DCVoltageSource() : Component() {
    VDD = 0;
    current = 0;
}

void DCVoltageSource::setVDD(double V){VDD = V;}
double DCVoltageSource::getVDD() const {return VDD;}
void DCVoltageSource::output(std::ofstream* file) const {
    *file << "Component # " << Component::getIndex() << " is a DC Voltage Source, Vs = " << VDD << " Volts.\n"; 
    *file << "Component # " << getIndex() << " is connected between node " << getA() << " and node " << getB() << ".\n"; 

    *file << "The Voltage across Component # " << this->getIndex() << " = " << abs(voltage()) << " Volts,\n";
    if(voltage() < 0){
        *file << "with the negative terminal at node " << getB() << ".\n";
    } else {
        *file << "with the negative terminal at node " << getA() << ".\n";
    }

    *file << "The current in this DC Voltage Source = " << abs(current) << " Amps,\n";
    if(current > 0){
        *file << "flowing from Node " << getA() << " to Node " << getB() <<".\n";
    } else {
        *file << "flowing from Node " << getB() << " to Node " << getA() <<".\n";
    }
    *file << "The power supplied by this DC Voltage Source = " << getPower() << " Watts.\n";

}

void DCVoltageSource::setCurrent(double I){current = I;}
double DCVoltageSource::getCurrent() const { return current;}
double DCVoltageSource::getPower() const { return VDD * current;}