#include "Network.h"
#include "DCVoltageSource.h"
#include "Resistor.h"
#include <fstream>
#ifndef VoltageDivider_H
#define VoltageDivider_H

class VoltageDivider : public Network{
    private:
        DCVoltageSource src;
        Resistor R1, R2;
    public:
        VoltageDivider();
        VoltageDivider(double, double, double);

        void setVoltage(double);
        void setR1(double);
        void setR2(double);
        void output(std::ofstream*);
        void calculate();
};

#endif