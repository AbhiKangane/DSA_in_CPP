#include<iostream>
using namespace std;

void numberOfSubsets(int arr[], int size){
    for(int i=0; i<(1<<size); i++){
        for(int j=0; j<size; j++)
            if(i & (1<<j))
                cout<<arr[j]<<" ";
            
            cout<<endl;
    }
} 

int main(){
    int arr[] = {1,2,3,4};
    numberOfSubsets(arr, 4);
    return 0;
}