#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

double findTheta(double x, double y);
double findRad(double x, double y);

int main() {
    //Step one. Basic Instructions
    cout << "ECE 0301 - Vectors in R2 and Complex Numbers\nPlease enter two numbers, seperated by a space,\nthat will represent a vector or a complex number.\n " << endl;

    double a, b; //x, y. 
   
    //user input.
    cin >> a >> b;
    
    //Editing Cout Output methods. 
    cout.precision(3);
    cout << fixed;

    //dislpaying the user inputs
    cout << "You entered " << a << " and " << b << ".\n" << endl;

    string input;
    cout << "Are these numbers in Cartesian (C) or polar (p) coordinates?\n";
    cout << "Please enter a single character as your choice." << endl;
    cin >> input;
    bool notChosen; //True -> Cartesian
                    //False -> Polar



    //This is a long story I'm sorry in advance.
    if(input == "P" || input == "p") {
        notChosen = true;
    } else if(input == "C" || input == "c") {
        notChosen = false;
    } else {
        cout << "\nERROR! Invalid selection, exiting.";
        return -1;
    }

    double c, d;
    //anyway here's my checking the bounds on my polar coords
    if (notChosen) {
        if (a < 0 || b < -M_PI || b > M_PI){
            cout << "You entered polar coordinates.\n";

            cout << "\nERROR! Invalid polar coordinates, exiting";
            return -1;
        }

        //and me calculating my signs
        c = a * cos(b);
        d = a * sin(b);
        cout << "You entered polar coordinates.\nThe equivalent Cartesian coordinates are:\n";
        cout << "X = " << c << ", Y = " << d;
    } else {
        //gotta calculate the polar coords
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


    cout << "\nPlease enter another pair of numbers, separated by a\nspace, to represent a second vector or complex number.\n" << endl;

    double e,f; //x, y. 
   
    //user input.
    cin >> e >> f;
    
    //Editing Cout Output methods. 
    cout.precision(3);
    cout << fixed;

    //dislpaying the user inputs
    cout << "You entered " << e << " and " << f << ".\n" << endl;

    cout << "Are these numbers in Cartesian (C) or polar (p) coordinates?\n";
    cout << "Please enter a single character as your choice." << endl;
    cin >> input;
     //True -> Cartesian
                    //False -> Polar

    //when I copy and pasted the code, I just remoced the ot. I was able to keep track but like yeah I'm sorry
    bool nChosen;
    if(input == "P" || input == "p") {
        nChosen = true;
    } else if(input == "C" || input == "c") {
        nChosen = false;
    } else {
        cout << "\nERROR! Invalid selection, exiting.";
        return -1;
    }

    // same stuff from before
    double g, h;
    if (nChosen) {
        if (e < 0 || f < -M_PI || f > M_PI){
            cout << "You entered polar coordinates.\n";
            cout << "\nERROR! Invalid polar coordinates, exiting";
            return -1;
        }


        g = e * cos(f);
        h = e * sin(f);
        cout << "You entered polar coordinates.\nThe equivalent Cartesian coordinates are:\n";
        cout << "X = " << g << ", Y = " << h;
    } else {
        g = sqrt(pow(e, 2) + pow(f, 2));
        if(e >= 0){
            h = atan(f/e);
        } else if (f >= 0) {
            h = atan(f/e) + M_PI;
        } else {
            h = atan(f/e) - M_PI;
        }
        cout << "You entered Cartesian coordinates.\nThe equivalent Polar coordinates are:\n";
        cout << "R = " << g << ", Theta = " << h;
    }


    //Step 8
    //new Stuff!

    cout << "\nDo the values you entered represent vectors (v) or complex numbers (c)?\nPlease enter a single character as your choice.\n";
    cin >> input;


    //anotha one. This is where we really messed up. It works fine and keeping track was a breeze, (i needed to just change assignment with more descript variable names)
    bool noChosen;
    if(input == "V" || input == "v") {
        noChosen = true;
    } else if(input == "C" || input == "c") {
        noChosen = false;
    } else {
        cout << "\nERROR! Invalid selection, exiting.";
        return -1;
    }


    //Displaying the Cartesian and Polar Coords. 
    if(noChosen){
        //vector Space
        if (notChosen){
            //A&B = polar
            cout << "Cartesian:\tv1 = (" << c << ", " << d << ")\n";
            cout << "Polar:\tv1 = (" << a << ", " << b << ")\n";
        } else {
            cout << "Cartesian:\tv1 = (" << a << ", " << b << ")\n";
            cout << "Polar:\tv1 = (" << d << ", " << c << ")\n";
        }

        if (nChosen){
            cout << "Cartesian:\tv2 = (" << g << ", " << h << ")\n";
            cout << "Polar:\tv2 = (" << e << ", " << f << ")\n";
        } else {
            cout << "Cartesian:\tv2 = (" << e << ", " << f << ")\n";
            cout << "Polar:\tv2 = (" << g << ", " << h << ")\n";
        }
    } else {
        //Complex Space
        if(notChosen){
            string sign = (d>0)? "+":"-";
            cout << "Cartesian:\tz1 = " << c << " " << sign << " j " << abs(d) << endl;
            cout << "Polar:\tz1 = " << a << " exp(j " << b << ")\n";
        } else {
            string sign = (b>0)? "+":"-";

            cout << "Cartesian:\tz1 = " << a << " " << sign << " j " << abs(b) << endl;
            cout << "Polar:\tz1 = " << c << " exp(j " << d << ")\n";
        }

        if(nChosen){
            string sign = (d>0)? "+":"-";
            cout << "Cartesian:\tz2 = " << g << " " << sign << " j " << abs(h) << endl;

            cout << "Polar:\tz2 = " << e << " exp(j " << f << ")\n";
        } else {
            string sign = (b>0)? "+":"-";

            cout << "Cartesian:\tz2 = " << e << " " << sign << " j " << abs(f) << endl;
            cout << "Polar:\tz2 = " << g << " exp(j " << h << ")\n";
        }


    }


    int num;
    if(noChosen){
        cout << "Which of the following vector sums or differences\nwould you like to compute?" << endl;
        cout << "(1) v1 + v2\n(2) v1 - v2\n(3) v2 - v1\n(4) -v1 - v2\n" << endl;
        cin >> num;
        switch(num){
            case 1:
                if (notChosen){
                    if(nChosen){
                        cout << "Sum, Cartesian:\tv_sum = (" << c + g << ", " << d + h << ")\n";
                        cout << "Sum, Polar:\tv_sum = (" << a + e << ", " << b + f << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tv_sum = (" << c + e << ", " << d + f << ")\n";
                        cout << "Sum, Polar:\tv_sum = (" << a + g << ", " << b + h << ")\n";
                    }
                } else {
                    if(nChosen){
                        cout << "Sum, Cartesian:\tv_sum = (" << a + g << ", " << b + h << ")\n";
                        cout << "Sum, Polar:\tv_sum = (" << c + e << ", " << d + f << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tv_sum = (" << a + e << ", " << b + f << ")\n";
                        cout << "Sum, Polar:\tv_sum = (" << c + g << ", " << d + h << ")\n";
                    }
                }
                break;
            case 2:
                if (notChosen){
                    if(nChosen){
                        cout << "Difference, Cartesian:\tv_difference = (" << c - g << ", " << d - h << ")\n";
                        cout << "Difference, Polar\tv_difference = (" << a - e << ", " << b - f << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tv_sum = (" << c - e << ", " << d - f << ")\n";
                        cout << "Sum, Polar:\tv_sum = (" << a - g << ", " << b - h << ")\n";
                    }
                } else {
                    if(nChosen){
                        cout << "Difference, Cartesian:\tv_diff = (" << a - g << ", " << b - h << ")\n";
                        cout << "Difference, Polar:\tv_diff = (" << c - e << ", " << d - f << ")\n";
                    } else {
                        cout << "Difference, Cartesian:\tv_diff = (" << a - e << ", " << b - f << ")\n";
                        cout << "Difference, Polar:\tv_diff = (" << c - g << ", " << d - h << ")\n";
                    }
                }

                break;
            case 3:
                if (notChosen){
                    if(nChosen){
                        cout << "Difference, Cartesian:\tv_difference = (" << g - c << ", " << h - d << ")\n";
                        cout << "Difference, Polar:\tv_difference = (" << e - a << ", " << f - b << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tv_sum = (" << e - c << ", " << f - d << ")\n";
                        cout << "Sum, Polar:\tv_sum = (" << g - a << ", " << h - b << ")\n";
                    }
                } else {
                    if(nChosen){
                        cout << "Difference, Cartesian:\tv_diff = (" << g - a << ", " << h - b << ")\n";
                        cout << "Difference, Polar\tv_diff = (" << e - c << ", " << f - d << ")\n";
                    } else {
                        cout << "Difference, Cartesian:\tv_diff = (" << e - a << ", " <<f - b << ")\n";
                        cout << "Difference, Polar:\tv_diff = (" << g - c << ", " << h - d << ")\n";
                    }
                }
                break; 
            case 4:
                if (notChosen){
                    if(nChosen){
                        cout << "Sum, Cartesian:\tv_sum = (" << -1*(c + g) << ", " << -1*(d + h) << ")\n";
                        cout << "Sum, Polar\tv_sum = (" << -1*(a + e)<< ", " << -1*(b + f) << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tv_sum = (" << -1* (c + e) << ", " << -1*(d + f) << ")\n";
                        cout << "Sum, Polar:\tv_sum = (" << -1*(a + g) << ", " << -1*(b + h) << ")\n";
                    }
                } else {
                    if(nChosen){
                        cout << "Sum, Cartesian:\tv_sum = (" << -1*(a + g) << ", " << -1*(b + h) << ")\n";
                        cout << "Sum, Polar:\tv_sum = (" << -1*(c + e) << ", " << -1*(d + f) << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tv_sum = (" << -1 * (a + e )<< ", " <<  -1 * (b + f )<< ")\n";
                        cout << "Sum, Polar:\tv_sum = (" << -1 * (c + g) << ", " << -1 * (d + h) << ")\n";
                    }
                }
                break;
            default:
                cout << "\nERROR! Invalid selection, exiting.";
                return -1;

        }
    } else {
        cout << "Which of the following sums or differences\nwould you like to complete?" << endl;
        cout << "(1) z1 + z2\n(2) z1 - z2\n(3) z2 - z1\n(4) -z1 - z2\n" << endl;
        cin >> num;
        switch(num){
            case 1:
                if (notChosen){
                    if(nChosen){
                        cout << "Sum, Cartesian:\tz_sum = " << c + g << " + j " << d + h << "\n";
                        cout << "Difference, Polar:\tz_difference = " << findRad(g+c, h+d) << " exp(j  " << findTheta(g+c, h+d) << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tz_sum = " << c + e << " + j " << d + f << "\n";
                        cout << "Difference, Polar:\tz_difference = " << findRad(e+c, f+d) << " exp(j  " << findTheta(e+c, f+d) << ")\n";
                    }
                } else {
                    if(nChosen){
                        cout << "Sum, Cartesian:\tz_sum = " << a + g << " + j " << b + h << "\n";
                        cout << "Difference, Polar:\tz_difference = " << findRad(g+a, h+b) << " exp(j  " << findTheta(g+a, h+b) << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tz_sum = " << a + e << " + j " << b + f << "\n";
                        cout << "Difference, Polar:\tz_difference = " << findRad(a+e, b+f) << " exp(j  " << findTheta(a+e, b+f) << ")\n";
                    }
                }
                break;
            case 2:
                if (notChosen){
                    if(nChosen){
                        cout << "Sum, Cartesian:\tz_sum = " << c - g << " + j " << d - h << "\n";
                        cout << "Difference, Polar:\tz_difference = " << findRad(c-g, d-h) << " exp(j  " << findTheta(c-g, d-h) << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tz_sum = (" << c - e << " + j " << d - f << "\n";
                        cout << "Difference, Polar:\tz_difference = " << findRad(c-e, d-f) << " exp(j  " << findTheta(c-e, d-f) << ")\n";
                    }
                } else {
                    if(nChosen){
                        cout << "Sum, Cartesian:\tz_sum = " << a - g << " + j " << b - h << "\n";
                        cout << "Difference, Polar:\tz_difference = " << findRad(a-g, b-h) << " exp(j  " << findTheta(a-g, b-h) << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tz_sum = " << a - e << " + j " << b - f << "\n";
                        cout << "Difference, Polar:\tz_difference = " << findRad(a-e, b-f) << " exp(j  " << findTheta(a-e, b-f) << ")\n";
                    }
                }

                break;
            case 3:
                if (notChosen){
                    if(nChosen){
                        cout << "Difference, Cartesian:\tz_difference = " << g - c << " + j " << h - d << "\n";
                        cout << "Difference, Polar:\tz_difference = " << findRad(g-c, h-d) << " exp(j  " << findTheta(g-c, h-d) << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tz_sum = " << e - c << " + j " << f - d << "\n";
                        cout << "Difference, Polar:\tz_difference = " << findRad(e-c, f-d) << " exp(j  " << findTheta(e-c, f-d) << ")\n";
                    }
                } else {
                    if(nChosen){
                        cout << "Difference, Cartesian:\tz_diff = " << g - a << " + j " << h - b << "\n";
                        cout << "Difference, Polar:\tz_difference = " << findRad(g-a, h-b) << " exp(j  " << findTheta(g-a, h-b) << ")\n";
                    } else {
                        cout << "Difference, Cartesian:\tz_diff = " << e - a << " + j " <<f - b << "\n";
                        cout << "Difference, Polar:\tz_difference = " << findRad(e-a, f-b) << " exp(j  " << findTheta(e-a, f-b) << ")\n";
                    }
                }
                break; 
            case 4:
                if (notChosen){
                    if(nChosen){
                        cout << "Sum, Cartesian:\tz_sum = " << -1*(c + g) << " + j " << -1*(d + h) << "\n";
                        cout << "Difference, Polar:\tz_difference = " << findRad(-g-c, -h-d) << " exp(j  " << findTheta(-g-c, -h-d) << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tz_sum = " << -1* (c + e) << " + j " << -1*(d + f) << "\n";
                        cout << "Difference, Polar:\tz_difference = " << findRad(-e-c, -f-d) << " exp(j  " << findTheta(-e-c, -f-d) << ")\n";
                    }
                } else {
                    if(nChosen){
                        cout << "Sum, Cartesian:\tz_sum = " << -1*(a + g) << " + j " << -1*(b + h) << "\n";
                        cout << "Difference, Polar:\tz_difference = " << findRad(-g-a, -h-b) << " exp(j  " << findTheta(-g-a, -h-b) << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tz_sum = " << -1 * (a + e )<< " + j " <<  -1 * (b + f )<< "\n";
                        cout << "Difference, Polar:\tz_difference = " << findRad(-a-e, -b-f) << " exp(j  " << findTheta(-a-e, -b-f) << ")\n";
                    }
                }
                break;
            default:
                cout << "\nERROR! Invalid selection, exiting.";
                return -1;
        }
    }
}


double findTheta(double x, double y){
    if(x >= 0){
        return atan(y/x);
    } else if (y >= 0) {
        return atan(y/x) + M_PI;
    } else {
        return atan(y/x) - M_PI;
    }
}

double findRad(double x, double y){
    return sqrt(pow(x, 2) + pow(y, 2));

}

