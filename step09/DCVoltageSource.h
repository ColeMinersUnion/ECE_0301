#include "Component.h"
#include "fstream"

#ifndef DCVoltageSource_H
#define DCVoltageSource_H

class DCVoltageSource : public Component{
    private:
        double VDD;
        double current;
    public: 
        DCVoltageSource();
        void setVDD(double);
        double getVDD() const;
        void output(std::ofstream*) const;

        double getCurrent() const;
        double getPower() const;
        void setCurrent(double);

};

#endif