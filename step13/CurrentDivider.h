#include "Network.h"
#include "DCCurrentSource.h"
#include "Resistor.h"
#include <fstream>
#ifndef CurrentDivider_H
#define CurrentDivider_H

class CurrentDivider : public Network{
    private:
        DCCurrentSource src;
        Resistor R1, R2;
    public:
        CurrentDivider();
        CurrentDivider(double, double, double);

        void setCurrent(double);
        void setR1(double);
        void setR2(double);
        void output(std::ofstream*);
        void calculate();
};

#endif