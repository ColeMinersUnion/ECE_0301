#include "Component.h"

int Component::num = 0;

Component::Component(){
    terminalA = nullptr;
    terminalB = nullptr;
    index = num;
    num++;
}

int Component::getNum() const {return num;}
int Component::getIndex() const {return index;}
void Component::setA(Node* A){ terminalA = A;}
void Component::setB(Node* B){ terminalB = B;}
int Component::getA() const {return terminalA->getIndex();}
int Component::getB() const {return terminalB->getIndex();}

double Component::voltage() const {
    return terminalB->getVoltage() - terminalA->getVoltage();
}

void Component::output(std::ofstream* file) const{
    *file << "Component # " << index << " is connected between node " << terminalA->getIndex() << " and node " << terminalB->getIndex() << ".\n"; 
    *file << "The Voltage across Component # " << index << " = " << abs(voltage()) << " Volts,\n";
    if(voltage() < 0){
        *file << "with the negative terminal at node " << terminalB->getIndex() << ".\n";
    } else {
        *file << "with the negative terminal at node " << terminalA->getIndex() << ".\n";
    }
}
