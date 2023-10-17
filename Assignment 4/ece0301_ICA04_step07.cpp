#include <iostream>
#include <string>
#include <fstream> //This file contains the syntax for basic file handlling

using namespace std;

//function declarations
void Divider(string file); //I'm separating these out into functions to make my life easier
int Wheatstone(string file); //the handle the necessary functions 

int main(){
    string addr = "divider_wheatstone_circuits.txt"; //output file. Relative path with no headings
    ifstream infile;
    infile.open(addr); //creating and opening my file

    string header;
    infile >> header;

    if(header == "Divider"){ //if the heading is Divider
        infile.close(); //closing the infile so I can reopen it under a different scope
        Divider(addr); //doing all the divider stuff
    }else if (header == "Wheatstone"){
        cout << "ECE 0301: Circuit Solver for Voltage Divider\nand Wheatstone bridge example circuits."; //intro message again
        infile.close(); //gotta close this one so I can reopen it under a another scope without issues
        Wheatstone(addr); //all da wheatstone stuff
    } else {
        infile.close(); //closing the file 
        cout << "ERROR! Invalid header.";
        return -1; //
    }


    return 0;
}

void Divider(string file){
    //input file
    ifstream infile;
    infile.open(file);
    //stuff for later
    double Vs;
    int R1, R2;
    string Out = "divider_wheatstone_solutions.txt";
    //output file
    ofstream outfile;
    outfile.open(Out);

    //reading inputs
    //gotta reread the header.
    infile >> file >> Vs >> R1 >> R2; 
    infile.close();

    outfile << "ECE 0301: Circuit Solver for Voltage Divider\nand Wheatstone bridge example circuits." << endl; //intro message
    outfile << "-----" << endl;
    outfile << "Circuit #1 (Voltage Divider)" << endl; //idk it was in the thingy

    outfile << "---" << endl;
    outfile << "Source voltage: Vs = " << Vs << " Volts.\n";
    outfile << "Resistor: R1 = " << R1 << " Ohms.\n";
    outfile << "Resistor: R2 = " << R2 << " Ohms.\n";

    //step 4 solving for Current and Potential Differences across the resistors. 
    double Req = R1 + R2;
    double Current = Vs / Req;
    double Vr1 = Current * R1, Vr2 = Current * R2;

    outfile << "\nLoop current: I = " << Current << " Amperes.\n";
    outfile << "Resistor voltage: V1 = " << Vr1 << " Volts.\n";
    outfile << "Resistor voltage: V2 = " << Vr2 << " Volts.\n";

    outfile.close();
}

int Wheatstone(string file){
    //input file
    ifstream infile;
    infile.open(file);
    //stuff for later
    double Vs, Is;
    int R1, R2, R3, R4, R5;
    string Out = "divider_wheatstone_solutions.txt";
    //output file
    ofstream outfile;
    outfile.open(Out);

    //reading inputs
    //gotta reread the header.
    infile >> file >> Vs >> Is >> R1 >> R2 >> R3 >> R4 >> R5; 
    infile.close();

    outfile << "ECE 0301: Circuit Solver for Voltage Divider\nand Wheatstone bridge example circuits." << endl; //intro message
    outfile << "-----" << endl;
    outfile << "Circuit #1 (Voltage Divider)" << endl; //idk it was in the thingy

    outfile << "---" << endl;
    outfile << "Source voltage: Vs = " << Vs << " Volts.\n";
    outfile << "Source current: Is = " << Is << " Amperes.\n";
    outfile << "Resistor: R1 = " << R1 << " Ohms.\n";
    outfile << "Resistor: R2 = " << R2 << " Ohms.\n";
    outfile << "Resistor: R3 = " << R3 << " Ohms.\n";
    outfile << "Resistor: R4 = " << R4 << " Ohms.\n";
    outfile << "Resistor: R5 = " << R5 << " Ohms.\n";

    double bound = pow(10, -13);
    //checking for possible 
    if (R2 == 0 || R3 == 0 || Vs - (Is*R4) < -1 * bound || Vs - (Is*R4) > bound || Vs + (Is * R5) < -1 * bound || Vs + (Is *R5) > bound){
        outfile << "ERROR! Unstable floating-point division.\n";
        return -1;
    }

    //using the equations from the top to solve for stuff
    double a = 1 + (R4/R2);
    double b = Vs - (Is * R4);
    double c = 1 + (R5/R3);
    double d = Vs + (Is * R5);
    double e = R1 / R2;
    double f = R1 / R3;

    //solving for w, x, y, z
    double w = (a + e) / b;
    double x = f / b;
    double y = e / d;
    double z = (c + f) / d;


    //The variables I actually want. 
    double V3 = (y-w) / ((x * y) - (w * z));
    double V2 = (1 - (x * V3))/w;
    double V1 = (e * V2) - (f * V3);
    double V4 = Vs - V1 - V2;
    double V5 = Vs - V1 - V3;

    double I1 = V1 / R1;
    double I2 = V2 / R2;
    double I3 = V3 / R3;
    double I4 = V4 / R4;
    double I5 = V5 / R5;
    
    outfile << endl;
    outfile << "Resistor voltage: V1 = " << V1 << " Volts.\n";
    outfile << "Resistor current: I1 = " << I1 << " Amperes.\n";
    outfile << "Resistor voltage: V2 = " << V2 << " Volts.\n";
    outfile << "Resistor current: I2 = " << I2 << " Amperes.\n";
    outfile << "Resistor voltage: V3 = " << V3 << " Volts.\n";
    outfile << "Resistor current: I3 = " << I3 << " Amperes.\n";
    outfile << "Resistor voltage: V4 = " << V4 << " Volts.\n";
    outfile << "Resistor current: I4 = " << I4 << " Amperes.\n";
    outfile << "Resistor voltage: V5 = " << V5 << " Volts.\n";
    outfile << "Resistor current: I5 = " << I5 << " Amperes.\n";

    return 0;
}