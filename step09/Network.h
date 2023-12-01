#include "Node.h"
#include "Component.h"

#ifndef Network_H
#define Network_H
#include <fstream>

class Network{
    private:   
        static int num;
        unsigned int index;
        unsigned int nodes;
        Node* list;
    public:
        Network();
        Network(int);
        ~Network();

        int getNum() const;
        int getIndex() const;
        int getNodes() const;
        Node* getList() const;

        void setVoltageI(int, double);
        void output(std::ofstream*);

        void addComponent(Component*, int, int);
}; 

#endif