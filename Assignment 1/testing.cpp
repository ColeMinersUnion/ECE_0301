#include <iostream>
using namespace std;

int main(){
    unsigned char data = 5;
    bool bits[8];

    for(int i = 0; i < 8; i++) {
        bits[i] = ((data >> i) & 0x01);
    }

    for(int i = 0; i < 8; i++){
        cout << bits[i] << endl;
    }
    return 0;
}