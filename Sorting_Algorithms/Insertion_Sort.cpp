#include<iostream>
using namespace std;

int main(){
    int i, j, n, arr[10];
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the elements in array: ";
    for(i=0; i<n; i++)
        cin>>arr[i];
    
    // Insertion sort
    for(i=1; i<n; i++){

        int current = arr[i];

        for(j=i-1; j>=0 && arr[j] > current; j--){
            
                arr[j+1] = arr[j];
            }

            arr[j+1] = current;
        }
    
    cout<<"After sorting array elements: ";
    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;
}