#include "Component.h"
#include <fstream>
#ifndef Resistor_H
#define Resistor_H

class Resistor : public Component{
    private:    
        double resistance;

    public:
        Resistor();
        Resistor(double);
        void setResistance(double);
        double getResistance() const;
        void output(std::ofstream*) const;

        double findCurrent() const;
        double findPower() const;


};

#endif