#ifndef FlashLight_H
#define FlashLight_H

class FlashLight{
    private:
        double voltage;
        double resistance;
        bool switchState;
    
    public:
        FlashLight(double, double, bool);
        FlashLight();

        //mutator functions
        void setV(double);
        void setR(double);
        void swapState();

        double getV();
        double getR();
        bool getState();

        double getI();
        double getW();

        void stdOut();

};

#endif