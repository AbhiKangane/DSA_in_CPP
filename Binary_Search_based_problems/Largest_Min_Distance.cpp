// in given array elements act as numbers on straight line
// consider subset of k elements 
// return min distance between any 2 elements is maximum
#include<bits/stdc++.h>
using namespace std;

bool isFeasible(int arr[], int n, int k, int mid){
    int pos = arr[0], elements = 1;

    for(int i=1; i<n; i++){
        if(arr[i] - pos >= mid){
            pos = arr[i];
            elements++;
            if(elements == k)
                return true;
        }
    }
    return false;
}

int largestMinDistance(int arr[], int n, int k){ // here k is size of subset
    sort(arr, arr+n);
    
    int result = -1;
    if(n<k)
        return result;
        
    int left = 1, right = arr[n-1];

    while (left<right){
        int mid = left + (right-left)/2;  // mid acts as minimum difference between any 2 elements
        if(isFeasible(arr,n,k,mid)){
            result = max(result, mid);
            left = mid+1; // for right part
        }
        else{  // if not feasible 
            right = mid; // for left part
        }
    }
    return result;
}

int main(){
    int arr[] = {1,2,3,8,9}, 
        n = 5, k = 3;

    cout<<"Largest min distance is : "<<largestMinDistance(arr,n,k);
    // ans : 3
    // subset (1,4,8)

    return 0;
}