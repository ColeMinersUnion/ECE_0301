//Complex Number Class
#include <cmath>
#include <iostream>

using namespace std;

class MyComplex{
    private:
        double real;
        double imaginary;

    public:
        //constructor
        MyComplex(double Real, double Imaginary){
            real = Real;
            imaginary = Imaginary;
        }

        MyComplex(){
            real = 0;
            imaginary = 0;
        }

        //another mutator func
        void setReal(double Real){
            real = Real;
        }

        //mutator functions
        void setImaginary(double Imag){
            imaginary = Imag;
        }

        //accessor functions
        double getReal(){
            return real;
        }

        //accessor functions
        double getImaginary(){
            return imaginary;
        }

        double phaseAngle(){
            return atan2(imaginary, real);
        }

        double magnitude(){
            return sqrt(pow(real, 2) + pow(imaginary, 2));
        }
};


int main(){

    MyComplex num;

    cout << "This program will calculate the magnitude and phase\nangle of a complex number.\n" << endl;
    cout << "What is the real part? ";

    double temp;
    cin >> temp;
    num.setReal(temp);

    cout << "What is the imaginary part? ";
    cin >> temp;
    num.setImaginary(temp);

    cout << "Here are the data on complex number z:" << endl;
    cout << "Real part: " << num.getReal() << endl;
    cout << "Imaginary part: " << num.getImaginary() << endl;
    cout << "Magnitude: " << num.magnitude() << endl;
    cout << "Phase angle (radians): " << num.phaseAngle() << endl;



    return 0;
}

