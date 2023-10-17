#include <iostream>
#include <string>
#include <fstream> //This file contains the syntax for basic file handlling

using namespace std;

//function declarations
void Divider(string file); //I'm separating these out into functions to make my life easier
//void Wheatstone(string file); //the handle the necessary functions 

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
        //Wheatstone(addr); //all da wheatstone stuff
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

    outfile << "Loop current: I = " << Current << " Amperes.\n";
    outfile << "Resistor voltage: V1 = " << Vr1 << " Volts.\n";
    outfile << "Resistor voltage: V2 = " << Vr2 << " Volts.\n";

}