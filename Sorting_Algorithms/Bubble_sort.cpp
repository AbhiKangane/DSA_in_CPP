#include<iostream>
using namespace std;

void BubbleSort(int *arr, int size){
    if(size == 0 || size == 1) 
        return ;

    for(int i=0; i<size; i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    BubbleSort(arr+1, size-1);   
}

int main(){
    int arr[5] = {10, 2, 33, 4, 5};

    cout<<"Sorted array: ";
    BubbleSort(arr, 5);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}