#include<iostream>
#include<math.h>
using namespace std;

bool isPowerOf2(int n){
    return (n && !(n & n-1));    // let n = 8 = 1000, n-1 = 7 = 0111, !(n & n-1) = 1, ans = n 
}

bool isPow2(int n){
    for(int i=0; i<=30; i++){
        int ans = pow(2, i);
        if(n == ans) return true;
    }
    return false;
}

int numberOfOnes(int n){
    int count = 0;
    while(n){
        n= n & (n-1);
        count++;
    }
    return count;
}

int main(){
    cout<<isPowerOf2(8)<<endl;
    // cout<<7 && !(7 & 6);
    cout<<isPow2(8)<<endl;

    cout<<numberOfOnes(7);
    return 0;
}