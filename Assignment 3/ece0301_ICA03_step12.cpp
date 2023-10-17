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



    if(input == "P" || input == "p") {
        notChosen = true;
    } else if(input == "C" || input == "c") {
        notChosen = false;
    } else {
        cout << "\nERROR! Invalid selection, exiting.";
        return -1;
    }

    double c, d;
    if (notChosen) {
        if (a < 0 || b < -M_PI || b > M_PI){
            cout << "You entered polar coordinates.\n";

            cout << "\nERROR! Invalid polar coordinates, exiting";
            return -1;
        }


        c = a * cos(b);
        d = a * sin(b);
        cout << "You entered polar coordinates.\nThe equivalent Cartesian coordinates are:\n";
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


    bool nChosen;
    if(input == "P" || input == "p") {
        nChosen = true;
    } else if(input == "C" || input == "c") {
        nChosen = false;
    } else {
        cout << "\nERROR! Invalid selection, exiting.";
        return -1;
    }

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

    cout << "\nDo the values you entered represent vectors (v) or complex numbers (c)?\nPlease enter a single character as your choice.\n";
    cin >> input;

    bool noChosen;
    if(input == "V" || input == "v") {
        noChosen = true;
    } else if(input == "C" || input == "c") {
        noChosen = false;
    } else {
        cout << "\nERROR! Invalid selection, exiting.";
        return -1;
    }

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
                        cout << "Sum, Cartesian:\tv_sum = (" << c - g << ", " << d - h << ")\n";
                        cout << "Sum, Polar\tv_sum = (" << a - e << ", " << b - f << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tv_sum = (" << c - e << ", " << d - f << ")\n";
                        cout << "Sum, Polar:\tv_sum = (" << a - g << ", " << b - h << ")\n";
                    }
                } else {
                    if(nChosen){
                        cout << "Sum, Cartesian:\tv_sum = (" << a - g << ", " << b - h << ")\n";
                        cout << "Sum, Polar:\tv_sum = (" << c - e << ", " << d - f << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tv_sum = (" << a - e << ", " << b - f << ")\n";
                        cout << "Sum, Polar:\tv_sum = (" << c - g << ", " << d - h << ")\n";
                    }
                }

                break;
            case 3:
                if (notChosen){
                    if(nChosen){
                        cout << "Sum, Cartesian:\tv_sum = (" << g - c << ", " << h - d << ")\n";
                        cout << "Sum, Polar:\tv_sum = (" << e - a << ", " << f - b << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tv_sum = (" << e - c << ", " << f - d << ")\n";
                        cout << "Sum, Polar:\tv_sum = (" << g - a << ", " << h - b << ")\n";
                    }
                } else {
                    if(nChosen){
                        cout << "Sum, Cartesian:\tv_sum = (" << g - a << ", " << h - b << ")\n";
                        cout << "Sum, Polar\tv_sum = (" << e - c << ", " << f - d << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tv_sum = (" << e - a << ", " <<f - b << ")\n";
                        cout << "Sum, Polar:\tv_sum = (" << g - c << ", " << h - d << ")\n";
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
        cout << endl << endl;;
        if(notChosen){
            if(nChosen){
                cout << "The inner product of v1 and v2 using polar coordinates is " << a*e*cos(b-f) << endl;
                cout << "The inner product of v1 and v2 using Cartesian coordinates is " << (c*g) + (d*h) << ".\n";
            } else {
                cout << "The inner product of v1 and v2 using polar coordinates is " << a*g*cos(b-h) << endl;
                cout << "The inner product of v1 and v2 using Cartesian coordinates is " << (c*e) + (d*f) << ".\n";
            }
        } else {
            if(nChosen){
                cout << "The inner product of v1 and v2 using polar coordinates is " << c*e*cos(d-f) << endl;
                cout << "The inner product of v1 and v2 using Cartesian coordinates is " << (a*g) + (b*h) << ".\n";
            } else {
                cout << "The inner product of v1 and v2 using polar coordinates is " << c*g*cos(d-h) << endl;
                cout << "The inner product of v1 and v2 using Cartesian coordinates is " << (a*e) + (b*f) << ".\n";
            }
        }
    } else {
        cout << "Which of the following sums or differences\nwould you like to complete?" << endl;
        cout << "\n(1) z1 + z2\n(2) z1 - z2\n(3) z2 - z1\n(4) -z1 - z2\n" << endl;
        cin >> num;
        cout << endl;
        switch(num){
            case 1:
                if (notChosen){
                    if(nChosen){
                        cout << "Sum, Cartesian:\tz_sum = " << c + g << " + j " << d + h << "\n";
                        cout << "Sum, Polar:\tz_sum = " << findRad(g+c, h+d) << " exp(j  " << findTheta(g+c, h+d) << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tz_sum = " << c + e << " + j " << d + f << "\n";
                        cout << "Sum, Polar:\tz_sum = " << findRad(e+c, f+d) << " exp(j  " << findTheta(e+c, f+d) << ")\n";
                    }
                } else {
                    if(nChosen){
                        cout << "Sum, Cartesian:\tz_sum = " << a + g << " + j " << b + h << "\n";
                        cout << "Sum, Polar:\tz_sum = " << findRad(g+a, h+b) << " exp(j  " << findTheta(g+a, h+b) << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tz_sum = " << a + e << " + j " << b + f << "\n";
                        cout << "Sum, Polar:\tz_difference = " << findRad(a+e, b+f) << " exp(j  " << findTheta(a+e, b+f) << ")\n";
                    }
                }
                break;
            case 2:
                if (notChosen){
                    if(nChosen){
                        cout << "Sum, Cartesian:\tz_sum = " << c - g << " + j " << d - h << "\n";
                        cout << "Sum, Polar:\tz_sum = " << findRad(c-g, d-h) << " exp(j  " << findTheta(c-g, d-h) << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tz_sum = (" << c - e << " + j " << d - f << "\n";
                        cout << "Sum, Polar:\tz_sum = " << findRad(c-e, d-f) << " exp(j  " << findTheta(c-e, d-f) << ")\n";
                    }
                } else {
                    if(nChosen){
                        cout << "Sum, Cartesian:\tz_sum = " << a - g << " + j " << b - h << "\n";
                        cout << "Sum, Polar:\tz_sum = " << findRad(a-g, b-h) << " exp(j  " << findTheta(a-g, b-h) << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tz_sum = " << a - e << " + j " << b - f << "\n";
                        cout << "Sum, Polar:\tz_sum = " << findRad(a-e, b-f) << " exp(j  " << findTheta(a-e, b-f) << ")\n";
                    }
                }

                break;
            case 3:
                if (notChosen){
                    if(nChosen){
                        cout << "Sum, Cartesian:\tz_sum = " << g - c << " + j " << h - d << "\n";
                        cout << "Sum, Polar:\tz_sum = " << findRad(g-c, h-d) << " exp(j  " << findTheta(g-c, h-d) << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tz_sum = " << e - c << " + j " << f - d << "\n";
                        cout << "Sum, Polar:\tz_sum = " << findRad(e-c, f-d) << " exp(j  " << findTheta(e-c, f-d) << ")\n";
                    }
                } else {
                    if(nChosen){
                        cout << "Sum, Cartesian:\tz_sum = " << g - a << " + j " << h - b << "\n";
                        cout << "Sum, Polar:\tz_sum = " << findRad(g-a, h-b) << " exp(j  " << findTheta(g-a, h-b) << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tz_sum = " << e - a << " + j " <<f - b << "\n";
                        cout << "Sum, Polar:\tz_sum = " << findRad(e-a, f-b) << " exp(j  " << findTheta(e-a, f-b) << ")\n";
                    }
                }
                break; 
            case 4:
                if (notChosen){
                    if(nChosen){
                        cout << "Sum, Cartesian:\tz_sum = " << -1*(c + g) << " + j " << -1*(d + h) << "\n";
                        cout << "Sum, Polar:\tz_sum = " << findRad(-g-c, -h-d) << " exp(j  " << findTheta(-g-c, -h-d) << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tz_sum = " << -1* (c + e) << " + j " << -1*(d + f) << "\n";
                        cout << "Sum, Polar:\tz_sum = " << findRad(-e-c, -f-d) << " exp(j  " << findTheta(-e-c, -f-d) << ")\n";
                    }
                } else {
                    if(nChosen){
                        cout << "Sum, Cartesian:\tz_sum = " << -1*(a + g) << " + j " << -1*(b + h) << "\n";
                        cout << "Sum, Polar:\tz_sum = " << findRad(-g-a, -h-b) << " exp(j  " << findTheta(-g-a, -h-b) << ")\n";
                    } else {
                        cout << "Sum, Cartesian:\tz_sum = " << -1 * (a + e )<< " + j " <<  -1 * (b + f )<< "\n";
                        cout << "Sum, Polar:\tz_sum = " << findRad(-a-e, -b-f) << " exp(j  " << findTheta(-a-e, -b-f) << ")\n";
                    }
                }
                break;
            default:
                cout << "\nERROR! Invalid selection, exiting.";
                return -1;
        }
        cout << "\n" << endl;
        if(notChosen){
            if(nChosen){
                string sign = ((c*h + d*g)>0)? "+":"-";

                cout << "Product, Polar:\t\t z1 * z2 = " << a * e << " exp(j " << (b + f) << ".\n";
                cout << "Product, Cartesian:\t z1 * z2 = " << (g*c - h*d) << " " << sign << " j " << (c*h + d*g) << ".\n";
                
                string sign2 = ((a*e) * sin(b + f) >= 0) ? "+":"-";
                cout << "Polar, converted to Cartesian: z1 * z2 = " << (a*e)* cos(b+f) << " " << sign2 << " j " << abs((a*e)* sin(b + f)) << endl;
            } else {
                string sign = ((c*f + d*e)>0)? "+":"-";
                cout << "Product, Polar:\t\t z1 * z2 = " << a * g << " exp(j " << b + h << ".\n";
                cout << "Product, Cartesian:\t z1 * z2 = " << (c*e - f*d) << " " << sign << " j " << (c*f + d*e) << ".\n";
                        
                string sign2 = ((a*g) * sin(b + h) >= 0) ? "+":"-";
                cout << "Polar, converted to Cartesian: z1 * z2 = " << (a * g) * cos(b + h) << " " << sign2 << " j " << abs((a * g) * sin(b + h)) << endl;

            }
        } else {
            if(nChosen){
                string sign = ((a*h + b*g)>0)? "+":"-";

                cout << "Product, Polar:\t\t z1 * z2 = " << c*e << " exp(j " << f + d<< ".\n";
                cout << "Product, Cartesian:\t z1 * z2 = " << (g*a - h*b) << " " << sign << " j " << (a*h + b*g) << ".\n";
                
                string sign2 = ((c*e) * sin(d + f) >= 0) ? "+":"-";              
                cout << "Polar, converted to Cartesian: z1 * z2 = " << (c * e) * cos(f + d) << " " << sign2 << " j " << abs((c * e) * sin(f + d)) << endl;

            } else {
                string sign = ((a*f + b*e)>0)? "+":"-";
                cout << "Product, Polar:\t\t z1 * z2 = " << c*g << " exp(j " << h + d << ".\n";
                cout << "Product, Cartesian:\t z1 * z2 = " << (e*a - f*b) << " " << sign << " j " << (a*f + b*e)<< ".\n";

                string sign2 = ((c*g) * sin(h + d) >= 0) ? "+":"-";
                cout << "Polar, converted to Cartesian: z1 * z2 = (" << (c * g) * cos(h + d) << " " << sign2 << " j " << abs((c * g) * sin(h + d)) << endl;

            }
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

/*
        if(notChosen){
            if(nChosen){
                cout << "Dot Product, Cartesian:\tv_prod = " << (c*g) + (d*h) << ".\n";
                cout << "Dot Product, Polar:\tv_prod = " << a*e*cos(b-f) << ".\n";
            } else {
                cout << "Dot Product, Cartesian:\tv_prod = " << (c*e) + (d*f) << ".\n";
                cout << "Dot Product, Polar:\tv_prod = " << a*g*cos(b-h) << ".\n";
            }
        } else {
            if(nChosen){
                cout << "Dot Product, Cartesian:\tv_prod = " << (a*g) + (b*h) << ".\n";
                cout << "Dot Product, Polar:\tv_prod = " << c*e*cos(d-f) << ".\n";
            } else {
                cout << "Dot Product, Cartesian:\tv_prod = " << (a*e) + (b*f) << ".\n";
                cout << "Dot Product, Polar:\tv_prod = " << c*g*cos(d-h) << ".\n";
            }
        }
                
*/

/*
        if(notChosen){
            if(nChosen){
                cout << "Dot Product, Cartesian:\tz_prod = " << (c + d) * (g + h) << ".\n";
                cout << "Dot Product, Polar:\tz_prod = " << (a*e - b*f) << " + j " << (a*f + e*b) << ".\n";
            } else {
                cout << "Dot Product, Cartesian:\tz_prod = " << (c + d) * (e + f) << ".\n";
                cout << "Dot Product, Polar:\tz_prod = " << (a*g - b*h) << " + j " << (a*h + g*b) << ".\n";
            }
        } else {
            if(nChosen){
                cout << "Dot Product, Cartesian:\tz_prod = " << (a + b) * (g + h) << ".\n";
                cout << "Dot Product, Polar:\tz_prod = " << (c*e - d*f) << " + j " << (c*f + d*b) << ".\n";
            } else {
                cout << "Dot Product, Cartesian:\tz_prod = " << (a + b) * (e + f) << ".\n";
                cout << "Dot Product, Polar:\tz_prod = " << (c*g - d*h) << " + j " << (c*h + g*d) << ".\n";
            }
        }

*/