#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool Or(bool, bool, bool); //I used a simple name because I think I'll have to overload it later
bool And(bool, bool, bool);
void OrTruthTable(ofstream &);
void AndTruthTable(ofstream &);
string minterm(int);
string maxterm(int);

int main(){
    string addr = "Bool_func_3var_CSOP_CPOS.txt";
    string addr2 = "Bool_func_3var.txt";

    ifstream input;
    input.open(addr2);


    //inputing
    int num;
    input >> num;

    input.close();

    ofstream output;
    output.open(addr);

    output << "ECE 0301: Boolean Function of 3 Variables.\nRealization in Canonical Forms.\n" << endl;

    string myStr = minterm(num);
    string maxtm = maxterm(num);

    if (myStr == "ERROR! Invalid minterm index.\n"){ 
        output << myStr << endl;
        return 0;
    }
    if (maxtm == "ERROR! Invalid maxterm index.\n"){ 
        output << maxtm << endl;
        return 0;
    }
    
    output << "m" << num << " = " << myStr << endl;
    output << "M" << num << " = " << maxtm << endl;
    

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
    output << "X\tY\tZ\tf(z, y, z)\n";
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
    output << "X\tY\tZ\tf(z, y, z)\n";
    for(int i = 0; i < 32; i++){
        output << "-";
    }

    output << "\n";

    for (int x = 0; x <= 1; x++){
        for (int y = 0; y <= 1; y++){
            for (int z = 0; z <= 1; z++){
                output << x << "\t" << y << "\t" << z << "\t" << And(x, y, z) << "\n";
            }
        }
    }

}


string minterm(int index){
    //I probably could have converted the index into bits and parsed over it like a string but oh well
    switch (index){
        case 0:
            return "x'y'z'";
        case 1:
            return "x'y'z";
        case 2:
            return "x'yz'";
        case 3:
            return "x'yz";
        case 4:
            return "xy'z'";
        case 5:
            return "xy'z";
        case 6:
            return "xyz'";
        case 7:
            return "xyz";
        default:
            return "ERROR! Invalid minterm index.\n";
        

    }
}

string maxterm(int index){
    //I probably could have converted the index into bits and parsed over it like a string but oh well
    switch (index){
        case 0:
            return "x + y + z";
        case 1:
            return "x + y + z'";
        case 2:
            return "x + y' + z";
        case 3:
            return "x + y' + z'";
        case 4:
            return "x' + y + z";
        case 5:
            return "x' + y + z'";
        case 6:
            return "x' + y' + z";
        case 7:
            return "x' + y' + z'";
        default:
            return "ERROR! Invalid minterm index.\n";
        

    }
}
