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

int changeBits(int n){   // it changes bits value 1 -> 0 && 0 -> 1
    int k = (1 << (int)floor(log2(n))+1) - 1;  // setting all bits to 1
    return k^n; // as we know 1^1 = 0 && 0^1 = 1
    // return k-n;  // ex. 15-10 = 15^10 , 31^24 = 31-24
}

int main(){
    cout<<getBit(5,2)<<endl; // indexing in bit starts from right->left & from 0   -> 5 = 0101
    cout<<setBit(5,1)<<endl; // sets bit value at index 1 - '1' : ans = 7  = 0111
    cout<<clearBit(5,0)<<endl; //sets bit value at 0th index - '0' : ans = 4 = 0100
    cout<<updateBit(5,1,1)<<endl; // updates bit value at given index 
    cout<<changeBits(24)<<endl; // updates bit value at given index 
    return 0;
}
