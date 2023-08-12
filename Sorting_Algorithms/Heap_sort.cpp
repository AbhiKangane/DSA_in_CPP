#include<iostream>
using namespace std;


void heapify(int arr[], int n, int i){  // for 1 based indexing
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right <= n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest] , arr[i]);
        heapify(arr, n, largest);
    }
}

void heap_Sort(int arr[], int n){
    int size = n;
    
    while(size > 1){
        // step 1: swap 
        swap(arr[size], arr[1]);
        
        // step 2
        size--;

        // step 3
        heapify(arr, size, 1);
    }
}

void PrintHeap(int arr[], int size){
    for(int i = 1; i<=size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int a[] = {-1, 54, 53, 51, 55, 52, 01, 50};  // here consider given unsorted array from 2nd element
    int n = sizeof(a) / sizeof(a[0]) - 1;

    // heap creation
    for(int i=n/2; i>0; i--){
        heapify(a, n, i);
    }

    heap_Sort(a, n);
    PrintHeap(a, n);
    
    return 0;
}