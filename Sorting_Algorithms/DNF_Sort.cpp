// DNF : Dutch National Flag
// in dnf_sort the given array contains only (0,1,2) elements

#include<iostream>
using namespace std;

void swap(int a[], int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void dnfSort(int arr[], int size){

    int low=0, mid=0, high=size-1;

    while (mid<=high)
    {
        if(arr[mid]==0){
            swap(arr, low, mid);
            low++; mid++;
        }

        else if(arr[mid]==1){
            mid++;
        }
        
        else if(arr[mid]==2){
            swap(arr, mid, high);
            high--;
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

    dnfSort(arr, n);
    // printing after dnf sort
    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";
}