#include<iostream>
using namespace std;

void sayDigit(int num, string arr[]){
    // base case
    if(num == 0)
        return;

    int digit = num % 10;
    sayDigit(num/10, arr);

    cout<<arr[digit]<<" ";
}

int main(){
    string arr[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int n; 
    cout<<"Enter a number: ";
    cin>>n;

    sayDigit(n, arr);
    return 0;
}