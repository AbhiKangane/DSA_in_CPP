#include<bits/stdc++.h>
using namespace std;

int main(){
    int size, i, j, k;
    // cout<<"Enter the size of array: ";
    // cin>>size;

    // int arr[size];
    // cout<<"Enter the numbers in array: ";
    // for(int i=0; i<size; i++){
    //     cin>>arr[i];
    // }

    int arr[] = {-3, -5, -4, -2};

//  1st method : brute force
    // int maxSum = INT_MIN;
    // for(i=0; i<size; i++)
    //     for(j=i; j<size; j++){
    //         int sum = 0;
    //         for(k=i; k<=j; k++){
    //             sum += arr[k];
    //         }
    //         maxSum= max(maxSum, sum);
    //     }
    // cout<<maxSum;

// 2nd method: Cumulative Sum approach
    // int currsum[size+1];
    // currsum[0]= 0;

    // for(i=1; i<=size; i++){
    //     currsum[i] = currsum[i-1] + arr[i-1];
    // }

    // int maxSum = INT_MIN;
    // for(i=1; i<=size; i++){
    //     int sum = 0;
    //     for(j=0; j<i; j++){
    //         sum = currsum[i] - currsum[j];
    //         maxSum = max(sum, maxSum);
    //     }
    // }
    // cout<<maxSum;

// 3rd Method: Kadane algorithm
    int currentSum  = arr[0];
    int maxSum = arr[0];

    for(i=0; i<4; i++){
        currentSum=max(arr[i],currentSum+arr[i]);
        maxSum = max(maxSum, currentSum);
    }
    
    std::cout<<maxSum<<endl;
    
    return 0;
}
