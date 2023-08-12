#include<bits/stdc++.h>
#include<climits>

using namespace std;

int kadane(int arr[], int size){
    // Max_Sum_Subarray Method: Kadane algorithm
    int currentSum  = 0;
    int maxSum = INT_MIN;

    for(int i=0; i<size; i++){
        currentSum += arr[i];
        if(currentSum < 0)
            currentSum = 0;
        
        maxSum = max(maxSum, currentSum);
    }
    
    return maxSum;
}

int main(){
    int size, i, j, k;
    cout<<"Enter the size of array: ";
    cin>>size;

    int arr[size];
    cout<<"Enter the numbers in array: ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    int wrapsum, non_wrapsum;

    non_wrapsum = kadane(arr,size);
    int totalSum = 0;
    for(i=0; i<size; i++){
        totalSum += arr[i];
        arr[i] =-arr[i];
    }

    wrapsum = totalSum + kadane(arr, size);
    cout<<max(wrapsum, non_wrapsum);
    
    return 0;
}