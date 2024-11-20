// Find the maximum sum of continuous subarray

#include<bits/stdc++.h>
using namespace std;

int main(){
    int size;
    cout<<"Enter the size of array: ";
    cin>>size;

    vector<int> arr(size);
    cout<<"Enter the numbers in array: ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

//  1st method : brute force
    // int maxSum = INT_MIN;
    // for(int i=0; i<size; i++)
    //     for(int j=i; j<size; j++){
    //         int sum = 0;
    //         for(int k=i; k<=j; k++){
    //             sum += arr[k];
    //         }
    //         maxSum= max(maxSum, sum);
    //     }
    // cout<<maxSum;

// 2nd method: Cumulative Sum or Prefix Sum approach
    // int currsum[size+1];
    // currsum[0]= 0;

    // for(i=1; i<=size; i++){
    //     currsum[i] = currsum[i-1] + arr[i-1];
    // }

    // int maxSum = INT_MIN;
    // for(int i=1; i<=size; i++){
    //     int sum = 0;
    //     for(int j=0; j<i; j++){
    //         sum = currsum[i] - currsum[j];
    //         maxSum = max(sum, maxSum);
    //     }
    // }
    // cout<<maxSum;

// 3rd Method: Kadane algorithm
    int currentSum  = 0;
    int maxSum = arr[0];

    for(int i=0; i<size; i++){
        // sol 1
        currentSum += arr[i];
        maxSum = max(maxSum, currentSum);
        if(currentSum < 0)
            currentSum = 0;

         // sol 2
        // currentSum=max(arr[i],currentSum+arr[i]);
        // maxSum = max(maxSum, currentSum);
    }
    
    std::cout<<maxSum<<endl;
    
    return 0;
}
