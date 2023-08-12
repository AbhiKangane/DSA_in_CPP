//  This program gives only 1st solution

#include<bits/stdc++.h>
using namespace std;

int main(){
    int size, reqsum;
    cout<<"Enter the size of array & require sum of subarray: ";
    cin>>size>>reqsum;

    int arr[size];
    cout<<"Enter the numbers in array: ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    int i=0, j=0, sum=0, st=-1, en=-1;
    // while(j<size && sum+arr[j] <= reqsum){
    //     sum += arr[j];
    //     j++;
    // }

    // if(sum == reqsum){
    //     cout<< i+1 <<" "<< j<<endl;
    //     return 0;
    // }

// the following code is fail when reqsum = 0
    while(j<size){
        sum += arr[j];
        while(sum > reqsum){
            sum -= arr[i];
            i++;
        }
        if(sum == reqsum){
            st = i+1;
            en = j+1;
            break;
        }
        j++;
    }

    cout<<"Start & End index of req subarray: "<<st<<" "<<en<<endl;
    return 0;
}