// GFG Question : Hard
// Given an array arr[] of N integers arranged in a circular fashion. 
// Your task is to find the maximum contiguous subarray sum.
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

//Function to find maximum circular subarray sum.
int circularSubarraySum(int arr[], int size){
    bool allNeg = true;
    int maxi = INT_MIN;
    for(int i=0; i<size; i++){
        if(arr[i] >= 0)
            allNeg = false;
        maxi = max(maxi, arr[i]);
    }
    if(allNeg)
        return maxi;
    
    int wrapsum, non_wrapsum;

    non_wrapsum = kadane(arr,size);
    int totalSum = 0;
    for(int i=0; i<size; i++){
        totalSum += arr[i];
        arr[i] =-arr[i];
    }

    wrapsum = totalSum + kadane(arr, size);
    // cout<<non_wrapsum<<" "<<wrapsum<<endl;
    return max(wrapsum, non_wrapsum);

}

int main(){
    int size, i;
    cout<<"Enter the size of array: ";
    cin>>size;

    int arr[size];
    cout<<"Enter the numbers in array: ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    cout<<"Maximum sum in circular subarray: "<<circularSubarraySum(arr,size);
    
    return 0;
}
