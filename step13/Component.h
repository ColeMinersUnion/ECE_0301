#include "Node.h"
#include <fstream>

#ifndef Component_H
#define Component_H

class Component{
    private:
        Node* terminalA;
        Node* terminalB;
        static int num;
        unsigned int index;
    public:
        Component();
        int getNum() const;
        int getIndex() const;
        void setA(Node*);
        void setB(Node*);
        int getA() const;
        int getB() const;
        double voltage() const;
        void output(std::ofstream*) const;
};


#endif