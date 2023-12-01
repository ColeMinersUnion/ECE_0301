#include <fstream>

#ifndef Node_H
#define Node_H


class Node{
    private:
        static int num;
        unsigned int index;
        double voltage;

    public:
        Node();

        int getNum() const;
        int getIndex() const;
        double getVoltage() const;

        void setVoltage(double);

        void output(std::ofstream*);


};

#endif