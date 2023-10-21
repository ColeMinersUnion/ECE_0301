#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Sortable{
    private:
        int size;
        double* arr;

        

    public:
        Sortable();
        Sortable(unsigned int); //anotha one

        ~Sortable();

        void fill();

        double* ptr();
        
        int getSize();

        void header(std::ofstream &, bool);

        void merge(double*, double*, unsigned int);

        void merge(double* preArray, double* postArray, unsigned int start1, unsigned int start2, unsigned int end2);
};

Sortable read(ifstream&);

int main(){
    //my addresses to my files
    string addrIN = "ece0301_unsorted_array.txt";
    string addrOUT = "ece0301_merge_sort_results.txt";

    //creating my sortable object
    ifstream infile;
    infile.open(addrIN);
    Sortable array = read(infile);
    infile.close();

    ofstream output;
    output.open(addrOUT);

    //reading out my array to double check my 
    array.header(output, false);

    double* copied = new double[array.getSize()];
    double* ptr = array.ptr();
    for(int i = 0; i < array.getSize(); i++){
        copied[i] = ptr[i];
    }

    for(int i = 0; i < array.getSize(); i++){
        cout << copied[i] << "\t";
    }

    cout << endl;

    array.merge(copied, array.ptr(), 2, 6, 11);
    array.header(output, true);

    output.close();

    return 0;
}

Sortable read(ifstream &infile){

    //variable instances
    unsigned int size;
    double element;
    string line;
    getline(infile, line);

    if(line.substr(0, 8) != "LENGTH ="){
        cout << line.substr(0, 7) << endl;
        cout << "ERROR! Invalid input file header.";
        exit(1);
    }

    size = stoi(line.substr(8));

    Sortable array(size); //instantiating my object

    for(int i = 0; i < size; i++){ //reading in the array itself
        getline(infile, line);
        element = stod(line);
        array.ptr()[i] = element;
    }

    return array;
}


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
    
    unsigned int pre = start1, post = start2;
    for(int i = start1; i < end2; i++){
        if(post == end2 || preArray[pre] < preArray[post] && pre < start2){
            postArray[i] = preArray[pre];
            pre++;
        } else {
            postArray[i] = preArray[post];
            post++;
        }
    }
}
