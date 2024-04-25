#include<iostream>
using namespace std;

// function to find the maximum sum subarray of size k having sum at most maxSum
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


// Function to find maximum_sumh subarray of size k.
vector <int> max_of_subarrays(int *arr, int n, int k)
{
    int sum=0, ans=0;
    for (int i = 0; i < k; i++){
        sum += arr[i];
    }
    int end = k;
    ans = sum;
    
    for (int i = k; i < n; i++){
        sum -= arr[i-k]; // removing left number
        sum += arr[i];   // adding right number

        if(ans < sum){
            end = i;
            ans = max(ans, sum);
        }
    }
    
    vector<int> res;
    for(int i=end-k+1; i<=end; i++)
        res.push_back(arr[i]);
    
    return res;
}

int main(){
    int arr[] = {2,4,1,3,6,5,9,8};
    int n = 8, windowSize = 3, maxSum = 15;

    cout<<maxSum_Subsequence(arr,n,windowSize,maxSum);
}
