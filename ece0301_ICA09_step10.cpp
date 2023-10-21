#include "Sortable.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

Sortable read(ifstream&);

int main(){
    //my addresses to my files
    string addrOUT = "ece0301_merge_sort_results.txt";
    const unsigned int SIZE = 256;
    //creating my sortable object
    Sortable array(SIZE);
    array.fillRandom();

    ofstream output;
    output.open(addrOUT);

    //reading out my array to double check my 
    array.header(output, false);

   
    array.mergeSort();

    //i've sorted it now
    array.header(output, true);

    output.close();

    return 0;
}
