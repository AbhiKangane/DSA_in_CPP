#include<iostream>
using namespace std;

int setBit(int n, int pos){
    return ((n & (1<<pos)) != 0);
}

void unique(int arr[], int size){
    int xorsum = 0;
    for(int i=0; i<size; i++){
        xorsum = xorsum ^ arr[i];
    }

    int tempxor = xorsum;
    int setbit=0;
    int pos=0;
    while(setbit != 1){
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum >> 1;
    }
    int newxor = 0;
    for(int i=0; i<size; i++){
        if(setBit(arr[i], pos-1))
            newxor = newxor ^ arr[i]; //in xor operation if both bits are same then it gives 0 else gives 1
    }

    cout<<newxor<<endl;
    cout<<(tempxor^newxor)<<endl;
} 

int main(){
    int arr[] = {1,2,3,4,1,2};
    unique(arr, 6);
    return 0;
}