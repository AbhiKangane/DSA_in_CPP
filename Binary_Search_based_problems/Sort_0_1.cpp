// sort the given array contains only (0,1) elements

#include<iostream>
using namespace std;

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void Sort_0_1(int arr[], int size){

    int low=0, high=size-1;

    while (low<high)
    {
        while(arr[low]==0 && low<high){
            low++;
        }

        while(arr[high]==1 && low<high){
            high--;
        }
        
        if(arr[low]>arr[high]){  //if(low < high) also works here
            swap(arr, low, high);
            low++; high--;
        }
    }
    
}

int main(){
    int i, j, n, arr[10];
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the elements in array: ";
    for(i=0; i<n; i++)
        cin>>arr[i];

    Sort_0_1(arr, n);
    // printing after sort
    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";
}