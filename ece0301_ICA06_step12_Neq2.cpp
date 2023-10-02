#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

const int DIM = 2;

int getN(ifstream &, double[DIM][DIM], double[DIM]);
int print(ifstream &, ofstream &, double[DIM][DIM], double[DIM]);
void multiplication(ofstream &, double[DIM][DIM], double[DIM], double[DIM]);
void Mprint(ofstream &, double[DIM][DIM], int);

//why doesn't it see these??
void AlmostCopy(ofstream &, double[DIM][DIM], double[DIM][DIM], int, int, int);
double determinant(ofstream &, double[DIM][DIM], int);


int main(){
    ofstream output;
    string addr = "ECE0301_ICA06_Axeqb_Solution.txt"; //the path to my output file. w
    output.open(addr);
    addr = "ECE0301_ICA06_Axeqb_problem.txt";

    ifstream input;
    input.open(addr);

    double matrixA[DIM][DIM];
    double matrixB[DIM];
    
    Mprint(output, matrixA, DIM);

    int N = getN(input, matrixA, matrixB);


    output << "Det(A) = "<< determinant(output, matrixA, DIM) << endl;
    
    input.close();
    output.close();
    return 0;

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
            cout << "ERROR! Input file format error." << endl;
            return -1;
        default:
            if(n != DIM){ //this is if the dimensions don't match
                cout << "ERROR! Dimension mismatch, N != DIM." << endl;
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

void multiplication(ofstream &output, double A[DIM][DIM], double X[DIM], double C[DIM]){
    output << "\nA * x = b" << endl;
    for(int i = 0; i < DIM; i++){
        C[i] = 0;   //this just makes sure that all the values of the array are initialized and cleared of any input.
        for(int j = 0; j < DIM; j++){
            C[i] += A[i][j] * X[i]; //for any given C, find all the As and the matching X and add them into c
        }
        output <<"[" << "\t" << C[i] << "]\n";
    }
}

void Mprint(ofstream &output, double A[DIM][DIM], int N){
    //basic outputs with some flavor text for myself to know if I printed everything or not. 
    for(int i = 0; i < N; i++){
        output << "[\t";
        for(int j = 0; j < N; j++){
            output << A[i][j] << "\t";
        }
        if(N != DIM) {output << "...\n"; }
        else {output << "]\n";}
    }
}


void AlmostCopy(ofstream &output, double CtrlC[DIM][DIM], double CtrlV[DIM][DIM], int iSkip, int jSkip, int n){
    bool beenSkippedX = false, beenSkippedY = false;
    for(int i = 0; i < n; i++){
        if(iSkip == i){
            beenSkippedX = true;
            continue;
        }
        
        for(int j = 0; j < n; j++){
            if(jSkip == j){
                beenSkippedY = true;
                continue;
            } 
            if(beenSkippedX && beenSkippedY){
                CtrlV[i-1][j-1] = CtrlC[i][j];
            } else if (beenSkippedX){
                CtrlV[i-1][j] = CtrlC[i][j];
            } else if (beenSkippedY){
                CtrlV[i][j-1] = CtrlC[i][j];
            } else {
                CtrlV[i][j] = CtrlC[i][j];
            }
        }
        beenSkippedY = false;
    }
}



double determinant(ofstream &output, double MatrixA[DIM][DIM], int N=DIM){
    double det = 0;
    double subMatrix[DIM][DIM];

    if(N == 1){
        return MatrixA[0][0];
    }

    for(int j = 0; j < N; j++){
        AlmostCopy(output, MatrixA, subMatrix, 0, j, N);

        det += pow(-1, j) * MatrixA[0][j] * determinant(output, subMatrix, N-1); //a^-1 * Matrix[0][j] * determinant of the other rows
                                                                                //hard-coded to work on the first row
    }

    return det;
}
