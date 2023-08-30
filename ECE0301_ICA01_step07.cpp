#include <iostream>
#include <string>

using namespace std;

int main() {
    //Step One
    //Declared a string and sent it to ouput.
    string myOutput = "ECE 0301 DC Resistice Circuit Simulation\nModeled after www.falstad.com/circuit/\nCircuits -> Basics -> Ohm's Law\n";
    cout << myOutput <<endl;

    //--------------------------------------------------

    //step Two
    //Declared doubles and prints them out
    double Voltage = 7200.00, Resistance1 = 8.00, Resistance2 = 10.00;

    //cout.precision(3);  //It gave me Voltake 2 in kV
    cout << "Vs = " << Voltage << " Volts" << endl;
    cout << "R1 = " << Resistance1 << " Ohms" << endl;
    cout << "R2 = " << Resistance2 <<  " Ohms" << endl;

    //---------------------------------------------------

    //Step 3
    //Calculating the Current
    double Current1, Current2;
    double Power1, Power2;

    //V = IR, ergo I = V/R
    Current1 = Voltage/Resistance1;
    Current2 = Voltage/Resistance2;

    //P = IV, ergo P = V^2/R
    Power1 = Voltage * Voltage / Resistance1;
    Power2 = Voltage * Voltage / Resistance2;

    //Printing the Values for resistor 1
    cout << "I1 = " << Current1 << " Amperes" << endl;
    cout << "P1 = " << Power1 << " Watts" << endl;

    //printing the values for resistor 2
    cout << "I2 = " << Current2 << " Amperes" << endl;
    cout << "P2 = " << Power2 << " Watts" << endl;

    //-------------------------------------------------
    //Step 4
    int time = 1;
    double Energy;
    //1 Watt = 1 Joule / Second
    Energy = Power1 + Power2; //-> The total energy driven by the voltage source
    Energy *= time;
    double cost1 = Energy/1000/60/60; //Energy is watts/second. Divide Watts into kilowats, divide time from seconds to minutes then hours
    cost1 *= 0.1;
    cout << "Energy supplied in one second = " << Energy << " Joules" << endl;

    time = 60 * 60; //Hour
    Energy = Power1 + Power2; 
    Energy *= time;
    double cost2 = Energy/1000/60/60;
    cost2 *= 0.1 ;
    cout << "Energy supplied in one hour = " << Energy << " Joules" << endl;

    time = 60 * 60 * 24; //day
    Energy = Power1 + Power2; 
    Energy *= time;
    double cost3 = Energy/1000/60/60;
    cost3 *= 0.1 ;
    cout << "Energy supplied in one day = " << Energy << " Joules" << endl;

    time = 60 * 60 * 24 * 365; //Hour
    Energy = Power1 + Power2; 
    Energy *= time;
    double cost4 = Energy/1000/60/60;
    cost4 *= 0.1 ;
    cout << "Energy supplied in one year = " << Energy << " Joules" << endl;


    //I mushed parts 4 and 5 together but below will be the output for question 5
    cout << "Cost of supplying energy for one second at $0.10/kWh =$" << cost1 << endl;
    cout << "Cost of supplying energy for one hour at $0.10/kWh =$" << cost2 << endl;
    cout << "Cost of supplying energy for one day at $0.10/kWh =$" << cost3 << endl;
    cout << "Cost of supplying energy for one year at $0.10/kWh =$" << cost4 << endl;


    return 0;
}