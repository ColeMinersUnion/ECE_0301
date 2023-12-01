#include "Network.h"
#include <fstream>
int Network::num = 0;

Network::Network(){
    index = num;
    num++;
    nodes = 2;
    list = new Node[nodes];
}

Network::Network(int node){
    index = num;
    num++;
    nodes = node;
    list = new Node[nodes];
}

Network::~Network(){delete list;}
int Network::getNum() const {return num;}
int Network::getIndex() const {return index;}
int Network::getNodes() const {return nodes;}
Node* Network::getList() const {return list;}


void Network::setVoltageI(int i, double v){
    list[i].setVoltage(v);
}

void Network::output(std::ofstream* file){
    *file << "\n";
    for(int i = 0; i < 48; i++){
        *file << "-";
    }

    *file << "\n\nData for Electrical Network # " << index << ":\n";
    *file << "At present, there are " << num << " Networks in existance.\n";
    *file << "At present, there are " << list[0].getNum() << " nodes in existance.\n";
    *file << "Network # " << index << " has " << nodes << " nodes.\n";
    
    for(int i = 0; i < nodes; i++){
        *file << "Voltage at node " << list[i].getIndex() << " = " << list[i].getVoltage() << std::endl;
    }
}

void Network::addComponent(Component* C, int A, int B){
    C->setA(&list[A]);
    C->setB(&list[B]);
}

