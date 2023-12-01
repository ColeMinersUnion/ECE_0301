#include "Node.h"
#include <iostream>
int Node::num = 0;
Node::Node(){
    index = num;
    num++;
    voltage = 0;
}

int Node::getIndex() const {return index;}
int Node::getNum() const {return num;}
double Node::getVoltage() const {return voltage;}

void Node::setVoltage(double V){voltage = V;}

void Node::output(std::ofstream* file){
    *file << "Voltage at Node " << index << " = " << voltage << "\n";
}
