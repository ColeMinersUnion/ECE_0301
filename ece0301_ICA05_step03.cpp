#include <iostream>
#include <fstream>
using namespace std;

bool Or(bool, bool, bool); //I used a simple name because I think I'll have to overload it later
void OrTruthTable(ofstream &);

bool And(bool, bool, bool);
void AndTruthTable(ofstream &);

int main(){
    string addr = "Bool_func_3var_CSOP_CPOS.txt";
    ofstream output;
    output.open(addr);

    output << "ECE 0301: Boolean Function of 3 Variables.\nRealization in Canonical Forms." << endl;

    OrTruthTable(output);
    AndTruthTable(output);

    output.close();

    return 0;
}


bool Or(bool x, bool y, bool z){
    if(x || y || z){ // probably could have made this a ternery statement to keep the function to one line
        return true;
    } else {
        return false;
    }
}

bool And(bool x, bool y, bool z){
    if(x && y && z){ // probably could have made this a ternery statement to keep the function to one line
        return true;
    } else {
        return false;
    }
}

void OrTruthTable(ofstream &output){
    output << "\nTruth table for OR gate.\n\n";
    output << "x\ty\tz\tf(z,y,z)\n";
    for(int i = 0; i < 32; i++){
        output << "-";
    }

    output << "\n";

    for (int x = 0; x <= 1; x++){
        for (int y = 0; y <= 1; y++){
            for (int z = 0; z <= 1; z++){
                output << x << "\t" << y << "\t" << z << "\t" << Or(x, y, z) << "\n";
            }
        }
    }    

}

void AndTruthTable(ofstream &output){
    output << "\nTruth table for AND gate.\n\n";
    output << "x\ty\tz\tf(z,y,z)\n";
    for(int i = 0; i < 32; i++){
        output << "-";
    }
    for (int x = 0; x <= 1; x++){
        for (int y = 0; y <= 1; y++){
            for (int z = 0; z <= 1; z++){
                output << x << "\t" << y << "\t" << z << "\t" << And(x, y, z) << "\n";
            }
        }
    }

}
