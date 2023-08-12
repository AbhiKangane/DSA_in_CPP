#include<iostream>
using namespace std;

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void waveSort(int arr[], int size){
    for(int i=1; i<size; i+=2){
        if(arr[i]>arr[i-1])
            swap(arr, i, i-1);

        if(arr[i]>arr[i+1] && i<=(size-2))
            swap(arr, i, i+1);

    }
}

int main(){
    int i, j, n, arr[10];
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the elements in array: ";
    for(i=0; i<n; i++)
        cin>>arr[i];

    waveSort(arr, n);
    // printing after wave sort
    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";
}