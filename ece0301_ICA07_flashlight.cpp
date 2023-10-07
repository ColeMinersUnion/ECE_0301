#include <iostream>
#include "FlashLight.h"

using namespace std;

void menu();

int main(){
    FlashLight light;
    light.stdOut();
    int choice;
    while(true){
        menu();
        cin >> choice;
        switch(choice){
            case 1:
                double v;
                cout << "Enter the new battery voltage: ";
                cin >> v;
                light.setV(v);
                light.stdOut();
                break;
            case 2:
                double resistance;
                cout << "Enter the new bulb resistance: ";
                cin >> resistance;
                light.setR(resistance);
                light.stdOut();
                break;
            case 3:
                light.swapState();
                light.stdOut();
                break;
            case 4:
                exit(0);
            default:
                break;
        }
    }
    
    return 0;
}

void menu(){
    cout << "(1) Change the battery voltage" << endl;
    cout << "(2) Change the bulb resistance" << endl;
    cout << "(3) Toggle the switch state" << endl;
    cout << "(4) Exit the program" << endl;
}
