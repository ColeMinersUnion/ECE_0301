#include "Sortable.h"
#include <fstream>
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>

Sortable::Sortable(){ //constructor function
    size = 10;
    arr = new double[size];
    fill();
}

Sortable::Sortable(unsigned int Size){
    size = Size;
    arr = new double[size];
    fill();
}

Sortable::~Sortable(){ //deconstructor function
    delete arr;
}

void Sortable::fill(){
    for(int i = 0; i < size; i++){
        arr[i] = 0;
    }
}

double* Sortable::ptr(){
    return arr;
}

int Sortable::getSize(){
    return size;
}

void Sortable::header(std::ofstream &output, bool sorted){
    if(!sorted){
        output << "ECE 0301 - Sorting Arrays" << std::endl;
        output << "Unsorted Array: " << std::endl;
    } else{
        output << "Sorted Array: " << std::endl;
    }
    

    for(int i = 0; i < size; i++){
        output << arr[i] << std::endl;
    }
}

void Sortable::merge(double* preArray, double* postArray, unsigned int start2){
    //insert the values from the second array into the first.
    //given the both are already sorted, we can start from the last insertion point to find the next insertion
    unsigned int pre = 0, post = start2;
    for(int i = 0; i < size; i++){
        if(preArray[pre] < preArray[post] && pre < start2){
            postArray[i] = preArray[pre];
            pre++;
        } else {
            postArray[i] = preArray[post];
            post++;
        }
    }

}

void Sortable::merge(double* preArray, double* postArray, unsigned int start1, unsigned int start2, unsigned int end2){
    static int i;
    unsigned int pre = start1, post = start2;
    for(i = start1; i < end2; i++){
        if(post == end2 || preArray[pre] < preArray[post] && pre < start2){
            postArray[i] = preArray[pre];
            pre++;
        } else {
            postArray[i] = preArray[post];
            post++;
        }
    }
}

void Sortable::splitter(double* preArray, double* postArray, int start, int end){
    if(end-start == 1){
        return;
    }

    int middle =  start + (end-start) / 2;
    splitter(postArray, preArray, start, middle);
    splitter(postArray, preArray, middle, end);

    merge(preArray, postArray, start, middle, end);
}

void Sortable::mergeSort(){
    double* orig = ptr();

    Sortable vect(getSize());
    double* working = vect.ptr();

    for(int i = 0; i < size; i++){
        working[i] = orig[i];
    }

    splitter(orig, working, 0, size);

    
    int middle =  size / 2;
    merge(working, orig, middle);
}   

void Sortable::debug(){
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << "\t";
    }
}


void Sortable::fillRandom(){
    unsigned seed = time(0);
    srand(seed); //this should set my seed while i instantiate the random device
    
    double randNum, rand_pm;
    for(int i = 0; i < size; i++){
        randNum = static_cast<double>(rand()) / RAND_MAX;
        rand_pm = 2 * randNum - 1;
        arr[i] = rand_pm;
    }


}
