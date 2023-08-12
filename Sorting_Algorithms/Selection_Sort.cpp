#include<iostream>
using namespace std;

int main(){
    int i, j, n, arr[10];
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the elements in array: ";
    for(i=0; i<n; i++)
        cin>>arr[i];
    
    // Selection sort
    for(i=0; i<n; i++)
        for(j=i+1; j<n; j++){
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    
    cout<<"After sorting array elements: ";
    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;
}