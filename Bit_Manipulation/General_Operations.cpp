#include<iostream>
using namespace std;

int getBit(int n, int pos){
    return ((n & (1<<pos)) != 0);
}

int setBit(int n, int pos){
    return (n | (1<<pos));
}

int clearBit(int n, int pos){
    int mask = ~(1<<pos);
    return (n & mask);
}

int updateBit(int n, int pos, int value){
    int mask = ~(1<<pos);
    n = n & mask;
    return (n | (value<<pos));
}

int main(){
    cout<<getBit(5,2)<<endl; // indexing in bit starts from right->left & from 0   -> 5 = 0101
    cout<<setBit(5,1)<<endl; // sets bit value at index 1 - '1' : ans = 7  = 0111
    cout<<clearBit(5,0)<<endl; //sets bit value at 0th index - '0' : ans = 4 = 0100
    cout<<updateBit(5,1,1)<<endl; // updates bit value at given index 
    return 0;
}