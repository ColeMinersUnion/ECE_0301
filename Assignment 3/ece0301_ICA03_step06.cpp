#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

//it's the exact same code twice. 
int step_06();
//This is the start of me regretting not reading the whole prompt before coding. 

int main() {
    //Step one. Basic Instructions
    cout << "ECE 0301 - Vectors in R2 and Complex Numbers\nPlease enter two numbers, seperated by a space,\nthat will represent a vector or a complex number.\n " << endl;
    
    //making sure it returns -1 from main as well
    int code = step_06();
    if(code == -1){
        return -1;
    }
    
    //another time
    cout << "\nPlease enter another pair of numbers, separated by a\nspace, to represent a second vector or complex number.\n" << endl;

    //making sure it returns -1 from main
    int newCode = step_06();
    if (newCode == -1){
        return -1;
    }


    return 0;

}

int step_06(){
    double a, b; //x, y. 
    //Running theme, I made this assignment so so so much harder by trying to not rename variables and stuff. Anyway it's not readable because instead of changing assignment
    //I Just ran a bajillion conditionals
   
    //user input.
    cin >> a >> b;
    
    //Editing Cout Output methods. 
    cout.precision(3);
    cout << fixed;

    //dislpaying the user inputs
    cout << "You entered " << a << " and " << b << ".\n" << endl;


    //seeing if it's polat or cartesian
    string input;
    cout << "Are these numbers in Cartesian (C) or polar (p) coordinates?\n";
    cout << "Please enter a single character as your choice." << endl;
    cin >> input;
    bool notChosen; //True -> Cartesian
                    //False -> Polar


    //Making the first of many poor decisions
    if(input == "P" || input == "p") {
        notChosen = true;
    } else if(input == "C" || input == "c") {
        notChosen = false;
    } else {
        cout << "\nERROR! Invalid selection, exiting.";
        return -1;
    }

    double c, d; //either x y or r theta, even idk what it means. I had a table but then i lost it
    if (notChosen) {
        if (a < 0 || b < -M_PI || b > M_PI){
            //input checkins for polar bounds
            cout << "You entered polar coordinates.\n";
            cout << "\nERROR! Invalid polar coordinates, exiting";
            return -1;
        }

        //calculating my cartesian coordinators
        c = a * cos(b);
        d = a * sin(b);
        cout << "You entered polar coordinates.\nThe equivalent Cartesian coordinates are:\n";
        cout << "X = " << c << ", Y = " << d;
    } else {
        //calculating my polar coordinates
        c = sqrt(pow(a, 2) + pow(b, 2));
        if(a >= 0){
            d = atan(b/a);
        } else if (b >= 0) {
            d = atan(b/a) + M_PI;
        } else {
            d = atan(b/a) - M_PI;
        }
        cout << "You entered Cartesian coordinates.\nThe equivalent Polar coordinates are:\n";
        cout << "R = " << c << ", Theta = " << d;
    }

}