#include <fstream>
#ifndef Sortable_H
#define Sortable_H

class Sortable{
    private:
        int size;
        double* arr;

        void merge(double*, double*, unsigned int);

        void merge(double* preArray, double* postArray, unsigned int start1, unsigned int start2, unsigned int end2);

        void splitter(double*, double*, int, int);

    public:
        Sortable();
        Sortable(unsigned int); //anotha one

        ~Sortable();

        void fill();

        double* ptr();
        
        int getSize();

        void header(std::ofstream &, bool);

        void fillRandom();

        void mergeSort();

        void debug();
};
#endif