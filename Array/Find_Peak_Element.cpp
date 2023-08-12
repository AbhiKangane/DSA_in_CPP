#include<iostream>
using namespace std;

int find_Peak_Element(int arr[], int low, int high, int n){
    int mid= low + (high-low)/2;

    if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 ||arr[mid+1] <= arr[mid])) // for increasing or decreasing array
        return mid;
    
    else if(mid > 0 && arr[mid-1] > arr[mid])
        return find_Peak_Element(arr,low,mid-1,n); // check for left part
    
    else    // condition : arr[mid+1] > arr[mid]
        return find_Peak_Element(arr,mid+1,high,n); // check for right part
}


int main(){
    int arr[] = {0,6,8,7,9,5};
    int n = 6;

    cout<<"Peak element index : "<<find_Peak_Element(arr,0,n-1,n); // it will give index of 1st peak element
    return 0;
}