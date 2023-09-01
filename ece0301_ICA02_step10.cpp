#include <iostream>
#include <string>

using namespace std;

int main() {

    cout << "ECE 0301 Propositional Logic Example\n" << endl; //Step 1.

    string P1 = "Pigs can fly.";
    string P2 = "Earth is flat.";       //My Three Proposition variables
    string P3 = "The moon is cheese.";

    cout << "P1: " << P1 << endl << "P2: " << P2 << endl << "P3: " << P3 << endl; //Printing my propositions. End of step 2

    //----------------------------------------------------------------------------------------
    bool P1_Truth, P2_Truth, P3_Truth;

    cout << "\nEnter P1 Truth Value: ";
    cin >> P1_Truth;                    //1s and 0s are truthy/falsy values so when I'm assigning them to boolean values they should 
                                        //convert to their respective boolean type on assignment.
    cout << "Enter P2 Truth Value: ";
    cin >> P2_Truth;                    //One question I had was that when I was testing, aren't all non-zero integers considered a truthy value?
                                        //Why does it throw a runtime error with 
    cout << "Enter P3 Truth Value: ";
    cin >> P3_Truth;

    cout << boolalpha << "\nYou entered: P1 = " << P1_Truth << ", P2 = " << P2_Truth << ", P3 = " << P3_Truth << "." << endl;
    //Used the boolalpha flag to convert boolean values to True and False in the output terminal.

    //Creating my truth Table
    cout << "Truth Table: " << endl;
    cout << "Proposition\tTruth Value" << endl;
    cout << "-----------\t-----------" << endl;


    //determining my coumpound value (I think i'm just doing 1 & 2 & 3)
    bool P4_Truth = P1_Truth && P2_Truth && P3_Truth;
    bool P5_Truth = P1_Truth || P2_Truth || P3_Truth;
    bool P6_Truth = 1 == P1_Truth + P2_Truth + P3_Truth;
    bool P7_Truth = !P1_Truth && !P2_Truth && !P3_Truth;
    bool P8_Truth = 1 < P1_Truth + P2_Truth + P3_Truth;
    bool P9_Truth = P1_Truth == 0 && P2_Truth + P3_Truth == 1;
    

    //Why does boolaplha still work? It should be out of the scope. If i'm calling it within the previous cout object
    //why does it still affect the below object.
    cout << "P1\t\t" << P1_Truth << endl;
    cout << "P2\t\t" << P2_Truth << endl;
    cout << "P3\t\t" << P3_Truth << endl;
    cout << "P4\t\t" << P4_Truth << endl;
    cout << "P5\t\t" << P5_Truth << endl;
    cout << "P6\t\t" << P6_Truth << endl;
    cout << "P7\t\t" << P7_Truth << endl;
    cout << "P8\t\t" << P8_Truth << endl;
    cout << "P8\t\t" << P9_Truth << endl;


    return 0;
}
