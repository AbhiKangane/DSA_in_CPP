#include<iostream>
using namespace std;

bool isSorted(int *arr, int size){
    if(size == 0 || size == 1) 
        return 1;

    if(arr[0] > arr[1])
        return 0;
        
    else
        return isSorted(arr+1, size-1);   
}

int getSum(int *arr, int size){
    if(size == 0) 
        return 0;

    if(size == 1)
        return arr[0];
        
    
    int remainPart = getSum(arr+1, size-1);
    int sum = arr[0] + remainPart;
    return sum;
}

bool LinearSearch(int *arr, int size, int key){
    if(size == 0) 
        return false;

    if(size == key)
        return true;
        
    
    else
        return LinearSearch(arr+1, size-1, key);
}

bool BinarySearch(int *arr, int start, int end, int key){
    if(start > end) 
        return false;

    int mid = (start + end)/2;

    if(arr[mid] == key)
        return true;
        
    
    else if(arr[mid] > key)
        return BinarySearch(arr+1, start, mid-1, key);
    
    else 
        return BinarySearch(arr+1, mid+1, end, key);
}

int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    // int arr[] = {12, 23, 3, 33, 21};
    // cout<<"Is array sorted: "<<isSorted(arr, 5)<<endl;
    // cout<<"Sum: "<<getSum(arr, 5)<<endl;
    // cout<<"Number is present: "<<LinearSearch(arr, 5, 3)<<endl;
    cout<<"Number is present: "<<BinarySearch(arr, 0, 4, 11)<<endl;

    return 0;
}