#include "FlashLight.h"
#include <iostream>

//constructors
FlashLight::FlashLight(double Voltage, double Resistance, bool SwitchState){
    voltage = Voltage;
    resistance = Resistance;
    switchState = SwitchState;
}

FlashLight::FlashLight(){
    voltage = 3;
    resistance = 100;
    switchState = false;
}

//accessor functions
double FlashLight::getV(){ return voltage; }
double FlashLight::getR(){ return resistance; }
double FlashLight::getI(){ 
    if(switchState){
        return  voltage / resistance; 
    } else {
        return 0;
    }
}
double FlashLight::getW(){ 
    if(switchState){
        return  voltage * voltage / resistance; 
    } else {
        return 0;
    }
}
bool FlashLight::getState(){ return switchState; }

//mutator functions
void FlashLight::setV(double V){ voltage = V; }
void FlashLight::setR(double R){ resistance = R; }
void FlashLight::swapState(){ switchState = !switchState; }

void FlashLight::stdOut(){
    //output function
    std::cout << "\nHere are the data on the FlashLight:" << std::endl;
    std::cout << "The battery voltage is " << voltage << " Volts." << std::endl;
    std::cout << "The bulb resistance is " << resistance << " Ohms." << std::endl;
    if(switchState){
        std::cout << "The switch is closed." << std::endl;
        std::cout << "The flashlight is on." << std::endl;

    } else {
        std::cout << "The switch is open." << std::endl;
        std::cout << "The flashlight is off." << std::endl;
    }
    std::cout << "The bulb current is " << getI() << " Amperes." << std::endl;
    std::cout << "The bulb current is " << getW() << " Watts." << std::endl;


}

