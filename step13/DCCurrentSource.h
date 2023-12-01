#include "Component.h"
#include "fstream"

#ifndef DCCurrentSource_H
#define DCCurrentSource_H

class DCCurrentSource : public Component{
    private:
        double current;
    public: 
        DCCurrentSource();
        void setCurr(double);
        double getCurr() const;
        void output(std::ofstream*) const;

        double getPower() const;

};

#endif