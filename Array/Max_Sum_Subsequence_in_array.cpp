#include<iostream>
using namespace std;

int maxSum_Subsequence(int arr[], int n, int k, int maxSum){
    int sum=0, ans=0;
    for (int i = 0; i < k; i++){
        sum += arr[i];
    }

    if(sum <= maxSum)
        ans = sum;
    
    for (int i = k; i < n; i++){
        sum -= arr[i-k]; // removing left number
        sum += arr[i]; // adding right number

        if(sum <= maxSum)
            ans = max(ans, sum);
    }
    return ans;
}

int main(){
    int arr[] = {2,4,1,3,6,5,9,8};
    int n = 8, k = 3, maxSum = 15;

    cout<<maxSum_Subsequence(arr,n,k,maxSum);
}