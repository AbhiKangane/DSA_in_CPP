#include<iostream>
#include<queue>
using namespace std;

int kth_Smallest(int a[], int start, int end, int k){

    // Sort the given array using bubble sort
    for (int i = 0; i < end; i++) // For number of pass
    {
        for (int j = 0; j < end-i ; j++) // For comparison in each pass
        {
            if(a[j]>a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp; 
            }
        }  
    } 
    return a[k-1];
    // return a[size-k] ; // this is for k'th largest element of an  array
}

// kth smallest using heap
int kth_small(int arr[], int st, int end, int k){
    priority_queue<int> pq;

    // step 1: push 1st k array elements in pq
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }

    // step 2:
    for(int i=k; i<=end; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}



int main(){
    int a[] = {12,22, 43, 2, 4,7,19};
    int n= sizeof(a)/sizeof(a[0]), k=5;  // here array is in 0 based indexed
    
    cout<<"k'th smallest elment of array is: "
        // <<kth_Smallest(a,0,6,k);
        <<kth_small(a,0,6,k);
    return 0;
}