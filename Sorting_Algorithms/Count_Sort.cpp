#include<iostream>
using namespace std;

// count sort time complexity : O(n)

void CountSort(int arr[], int size){
    int large=arr[0];
    for(int i=0; i<size; i++)
        large = max(large, arr[i]); //for finding maximum number from array
    
    int count[large+1] = {0}; //creating count array of size max number 
    for(int i=0; i<size; i++) 
        count[arr[i]] += 1;    // increasing count of number arr[i] in count array at count[arr[i]]
    
    for(int i=1; i<=large; i++)
        count[i] += count[i-1];   
    
    int output[size];
    for(int i=size-1; i>=0; i--)
        output[--count[arr[i]]] = arr[i];

    for(int i=0; i<size; i++)
        arr[i] = output[i];  //copying numbers from output array into original array: arr

}

int main(){
    int i, j, n, arr[10];
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the elements in array: ";
    for(i=0; i<n; i++)
        cin>>arr[i];

    CountSort(arr, n);
    // printing after dnf sort
    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";
}