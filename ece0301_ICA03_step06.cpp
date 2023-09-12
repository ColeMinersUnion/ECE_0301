#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int step_06();

int main() {
    //Step one. Basic Instructions
    
    int code = step_06();
    if (code != 0) {
        return -1;
    }
    int code = step_06();
    if (code != 0) {
        return -1;
    }


    return 0;

}

int step_06(){
    double a, b; //x, y. 
    cout << "ECE 0301 - Vectors in R2 and Complex Numbers\nPlease enter two numbers, seperated by a space,\nthat will represent a vector or complex numbers: ";
   
    //user input.
    cin >> a >> b;
    
    //Editing Cout Output methods. 
    cout.precision(3);
    cout << fixed;

    //dislpaying the user inputs
    cout << "You entered " << a << " and " << b << ".\n";

    string input;
    cout << "Have you entered Cartesian or Polar Coordinates? (C / P) ";
    cin >> input;
    cout << input;
    bool notChosen; //True -> Cartesian
                    //False -> Polar



    if(input == "P") {
        notChosen = true;
    } else if(input == "C") {
        notChosen = false;
    } else {
        cout << "ERROR! Invalid selection, exiting.";
        return -1;
    }

    double c, d;
    if (notChosen) {
        if (a < 0 || b < -M_PI || b > M_PI){
            cout << "ERROR! Invalid polar coordinates, exiting";
            return -1;
        }


        c = a * cos(b);
        d = a * sin(b);
        cout << "\nYou've entered Polar coordinates.\nThe equivalent Cartesian coordinates are:\n";
        cout << "X = " << c << ", Y = " << d;
    } else {
        c = sqrt(pow(a, 2) + pow(b, 2));
        if(a >= 0){
            d = atan(b/a);
        } else if (b >= 0) {
            d = atan(b/a) + M_PI;
        } else {
            d = atan(b/a) - M_PI;
        }
        cout << "\nYou've entered Cartesian coordinates.\nThe equivalent Polar coordinates are:\n";
        cout << "R = " << c << ", Theta = " << d;
    }

}