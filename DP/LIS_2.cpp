#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


// sol 1 : recursive
int solveRec(vector<int> &arr, int n, int ans){
    ans = 1;
    for(int i=0; i<n; i++){
        if(arr[n] > arr[i]){
            ans = max(ans, 1+solveRec(arr,i,ans));
        }
    }

    return ans;
}


// sol 2 : tabulation
int solveTab(vector<int> &arr) {
    int n = arr.size(), ans=0;
    vector<int> dp(n, 1); // Initialize a DP array to store the length of LIS ending at each index

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}

// driver function
int LIS_size(vector<int> &arr){
    int n = arr.size();
    // sol 1
    // return solveRec(arr,n-1,1);

    // sol 2
    return solveTab(arr);
}


int main(){
    vector<int> a = {0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15,16,10,18};   // LIS = {0,4,6,9,13,15,16,18}
    // cout<<n<<endl;
    cout<<LIS_size(a);
}
