#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool Or(bool, bool, bool, bool, bool, bool); //I used a simple name because I think I'll have to overload it later
bool And(bool, bool, bool, bool, bool, bool);
bool BoundsCheck(int, int, int);
void OrTruthTable(ofstream &, bool, bool, bool, int);
void AndTruthTable(ofstream &, bool, bool, bool, int);
string minterm(int);
string minterm(int, ofstream &, int);

string maxterm(int);
string maxterm(int, ofstream &, int);

string CSOP(int, ofstream &);
bool CSOP(int, ofstream &, bool, bool, bool);

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
    bool x = false, y = false, z = false;
    string myStr = CSOP(num, output);
    bool myBool = CSOP(num, output, x, y, z);
    if (myStr == "ERROR! Invalid minterm index.\n"){ 
        output << myStr << endl;
        return 0;
    } 

    output.close();

    return 0;
}

bool CSOP(int index, ofstream &output, bool x, bool y, bool z){

    string CanSumProd = "";

    int num = index;


    if(index > 127){
        if(And(x, y, z, false, false, false)){
            return true;
        }
        index -= 127;
    };
    if(index > 63){
        if(And(x, y, z, false, false, true)){
            return true;
        }
        index -= 63;
    }
    if(index > 31){
        if(And(x, y, z, false, true, false)){
            return true;
        }
        index -= 31;
    }
    if(index > 15){
        if(And(x, y, z, false, true, true)){
            return true;
        }
        index -= 15;
    }
    if(index > 7){
        if(And(x, y, z, true, false, false)){
            return true;
        }
        index -= 7;
    }
    if(index > 3){
        if(And(x, y, z, true, false, true)){
            return true;
        }
        index -= 3;
    }
    if(index > 1){
        if(And(x, y, z, true, true, false)){
            return true;
        }
        index -= 1;
    }
    if(index > 0){
        if(And(x, y, z, true, true, true)){
            return true;
        }
    }


    return false;    
}

string CSOP(int index, ofstream &output){
    if(!BoundsCheck(index, 255, 0)){
        return "ERROR! Invalid minterm index.\n";
    }

    string CanSumProd = "";

    int num = index;


    if(index > 127){
        CanSumProd += minterm(7, output, num);
        CanSumProd += " + ";
        index -= 127;
    };
    if(index > 63){
        CanSumProd += minterm(6, output, num);
        CanSumProd += " + ";
        index -= 63;
    }
    if(index > 31){
        CanSumProd += minterm(5, output, num);
        CanSumProd += " + ";
        index -= 31;
    }
    if(index > 15){
        CanSumProd += minterm(4, output, num);
        CanSumProd += " + ";
        index -= 15;
    }
    if(index > 7){
        CanSumProd += minterm(3, output, num);
        CanSumProd += " + ";
        index -= 7;
    }
    if(index > 3){
        CanSumProd += minterm(2, output, num);
        CanSumProd += " + ";
        index -= 3;
    }
    if(index > 1){
        CanSumProd += minterm(1, output, num);
        CanSumProd += " + ";
        index -= 1;
    }
    if(index > 0){
        CanSumProd += minterm(0, output, num);
    }

    output << "\n" << CanSumProd;
    
    return CanSumProd;

}

bool BoundsCheck(int index, int upperbound = 7, int lowerbound = 0){
    if(index <= upperbound && index >= lowerbound){
        return true;
    } else {return false;}
}

bool Or(bool x, bool y, bool z, bool x1 = false, bool y1 = false, bool z1 = false){
    if(x1){ x = !x; }
    if(y1){ y = !y; }
    if(z1){ z = !z; }
    
    if(x || y || z){ // probably could have made this a ternery statement to keep the function to one line
        return true;
    } else {
        return false;
    }
}

bool And(bool x, bool y, bool z, bool x1 = true, bool y1 = true, bool z1 = true){
    if(!x1){ x = !x; }
    if(!y1){ y = !y; }
    if(!z1){ z = !z; }


    if(x && y && z){ // probably could have made this a ternery statement to keep the function to one line
        return true;
    } else {
        return false;
    }
}




void OrTruthTable(ofstream &output, bool x1, bool y1, bool z1, int index){
    output << "\nTruth table for M" << index << ".\n\n";
    output << "X\tY\tZ\tf(z, y, z)\n";
    for(int i = 0; i < 32; i++){
        output << "-";
    }

    output << "\n";

    for (int x = 0; x <= 1; x++){
        for (int y = 0; y <= 1; y++){
            for (int z = 0; z <= 1; z++){
                output << x << "\t" << y << "\t" << z << "\t" << Or(x, y, z, x1, y1, z1) << "\n";
            }
        }
    }    

}

void AndTruthTable(ofstream &output, bool x1, bool y1, bool z1, int index){
    output << "\nTruth table for minterm " << index << ".\n\n";
    output << "X\tY\tZ\tf(z, y, z)\n";
    for(int i = 0; i < 32; i++){
        output << "-";
    }

    output << "\n";

    for (int x = 0; x <= 1; x++){
        for (int y = 0; y <= 1; y++){
            for (int z = 0; z <= 1; z++){
                output << x << "\t" << y << "\t" << z << "\t" << And(x, y, z, x1, y1, z1) << "\n";
            }
        }
    }

}

string minterm(int index, ofstream &output, int num){
    bool x = true, y = true, z = true;
    if(!BoundsCheck(index)){
        return "ERROR! Invalid minterm index.\n";
    } 
    string m = "";
    if(index <= 3){
        m += "x'";
        x = !x;
    } else { m += "x"; }

    if(index == 0 || index == 1 || index == 4 || index == 5) // couldn't think of any good way to parse thise one
    {
        m += "y'";
        y = !y;
    } else { m += "y"; }

    if (index % 2 == 0){
        m += "z'";
        z = !z;
    } else { m += "z";}
    output << "\nCSOP: f" << num << " = " << m << endl;

    AndTruthTable(output, x, y, z, index);



    return m;
}

string maxterm(int index, ofstream &output, int num){
    bool x = false, y = false, z = false;
    if(!BoundsCheck(index)){
        return "ERROR! Invalid minterm index.\n";
    } 
    string m = "";
    if(index <= 3){
        m += "x + ";
        x = !x;
    } else { m += "x' + "; }

    if(index == 0 || index == 1 || index == 4 || index == 5) // couldn't think of any good way to parse thise one
    {
        m += "y + ";
        y = !y;
    } else { m += "y' + "; }

    if (index % 2 == 0){
        m += "z";
        z = !z;
    } else { m += "z'";};
    output << "\nCSOP: f" << num << " = " << m << endl;

    OrTruthTable(output, x, y, z, index);



    return m;


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
            return "x+y+z";
        case 1:
            return "x+y+z'";
        case 2:
            return "x+y'+z";
        case 3:
            return "x+y'+z'";
        case 4:
            return "x'+y+z";
        case 5:
            return "x'+y+z'";
        case 6:
            return "x'+y'+z";
        case 7:
            return "x'+y'+z'";
        default:
            return "ERROR! Invalid minterm index.\n";
        

    }
}
