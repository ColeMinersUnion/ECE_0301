#include <string>
#include <iostream>

class Not{

    private:
        std::string lbl;
        bool input;

    public:
        Not(){
            lbl = "";
            input = false;
        }

        void setlbl(std::string Lbl){
            lbl = Lbl;
        }

        std::string getLbl(){
            return lbl;
        }

        void setInput(bool in){
            input = in;
        }

        bool getInput(){
            return input;
        }

        bool getOutput(){
            return !input;
        }

        std::string getOutputLbl(){
            return lbl + "_not";
        }
};


int main(){
    using namespace std;
    Not gate;
    //setting the label
    cout << "This program will simulate a not gate.\nWhat is the label for the gate input? ";
    string lbl;
    cin >> lbl;
    gate.setlbl(lbl);
    //setting input value
    cout << "What is the logic value at the input (0/1)? ";
    bool in;
    cin >> in;
    gate.setInput(in);
    //output statements
    cout << "Here are the data on the not gate:" << endl;
    cout << "Input label: " << gate.getLbl() << endl;
    cout << "Output label: " << gate.getOutputLbl() << endl;
    cout << "Logic value at input: " << gate.getInput() << endl;
    cout << "Logic value at output: " << gate.getOutput() << endl;

    return 0;
}