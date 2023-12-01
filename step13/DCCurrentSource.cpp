#include "DCCurrentSource.h"

DCCurrentSource::DCCurrentSource() : Component() {
    current = 0;
}

void DCCurrentSource::setCurr(double V){current = V;}
double DCCurrentSource::getCurr() const {return current;}
void DCCurrentSource::output(std::ofstream* file) const {
    *file << "Component # " << Component::getIndex() << " is a DC Current Source, Is = " << current << " Amps.\n"; 
    *file << "Component # " << getIndex() << " is connected between node " << getA() << " and node " << getB() << ".\n"; 

    *file << "The Voltage across Component # " << this->getIndex() << " = " << abs(voltage()) << " Volts,\n";
    if(voltage() < 0){
        *file << "with the negative terminal at node " << getB() << ".\n";
    } else {
        *file << "with the negative terminal at node " << getA() << ".\n";
    }

    *file << "The current in this DC Current Source = " << abs(current) << " Amps,\n";
    if(current > 0){
        *file << "flowing from Node " << getA() << " to Node " << getB() <<".\n";
    } else {
        *file << "flowing from Node " << getB() << " to Node " << getA() <<".\n";
    }
    *file << "The power supplied by this DC Current Source = " << getPower() << " Watts.\n";

}
double DCCurrentSource::getPower() const { return voltage() * current;}