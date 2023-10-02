#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int DIM = 4;

int getN(ifstream &, double[DIM][DIM], double[DIM]);
int print(ifstream &, ofstream &, double[DIM][DIM], double[DIM]);

int main(){
    ofstream output;
    string addr = "ECE0301_ICA06_Axeqb_Solution.txt"; //the path to my output file. w
    output.open(addr);
    addr = "ECE0301_ICA06_Axeqb_problem.txt";

    ifstream input;
    input.open(addr);

    double matrixA[DIM][DIM];
    double matrixB[DIM];
    

    return print(input, output, matrixA, matrixB);
}

int getN(ifstream &input, double A[DIM][DIM], double B[DIM]){

    string N;
    getline(input, N);

    if(N != "ECE 0301: Ax = b Problem"){
        return -1;
    }

    getline(input, N);//What I actually want

    char dim = N.back();
    N.pop_back();
    string expected = "N = ";
    if(N != expected){
        return -1;
    }

    if(dim - '0' != DIM){
        return dim - '0'; //this is to quit early and have main do the rest of the thingymabobs
    }



    getline(input, N);

    if (N != "A = "){ return -1; } //error code. 
    for(int i = 0; i < DIM; i++){
        for(int j = 0; j < DIM; j++){
            input >> N;
            A[i][j] = stod(N);
            //matrix A is two dimensions so it gets filled in the inner for loop
        }

    }


    getline(input, N); //this one kept reading in "" so i added another and it worked. 
    getline(input, N);
    if (N != "b = "){ return -1; } //error code. 
    for (int k = 0; k < DIM; k++)
    {
        input >> N; //matrix b is one dimension os only one for loop. 
        B[k] = stod(N);
    }

    return dim - '0';
}

int print(ifstream &input, ofstream &output, double A[DIM][DIM], double B[DIM]){
    output << "ECE 0301 - Matrix-Vector Computations,\nDeterminants and Cramer's Rule\n" << endl;
    output << "Global array dimension: DIM = " << DIM << endl;

    int n = getN(input, A, B); //calling my function to fill the matrices and find n

    switch(n){
        case -1: //throw a file formatting error
            output << "ERROR! Input file format error." << endl;
            return -1;
        default:
            if(n != DIM){ //this is if the dimensions don't match
                output << "ERROR! Dimension mismatch, N != DIM." << endl;
                return -1;
            }
            output << "Input file: N = " << n << endl; //if it did
            break;
    }

    //throws an output flag and then prints out my values in matrix A. 
    output << setw(10);
    output << "\nA = " << endl;
    for(int i = 0; i < DIM; i++){
        output << "[\t";
        for(int j = 0; j < DIM; j++){
            output << A[i][j] << "\t";
        }
        output << "]\n";
    }

    //outputting the contents of matrix B
    output << "\nb = " << endl;
    output << "[\t";
    for(int i = 0; i < DIM; i++){
        output << B[i] << "\t"; 
    }
    output << "]\n";


    return 0;
}
