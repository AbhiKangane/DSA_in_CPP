// given arr[] of positive integers corresponds to value of each leaf in an inorder traversal binary tree such that:
// Each node has 0 or 2
// value of each non_leaf node is equal to product of the largest leaf value from left & right subtree

// we have to return smallest possible sum of non leaf node
#include<bits/stdc++.h>
using namespace std;

// recursive sol
int solveRec(vector<int> &arr, map<pair<int,int>, int> &maxi, int left, int right){
    // base cases
    if(left == right)
        return 0;
    
    int ans = INT_MAX;

    for (int i=left; i<right; i++){
        ans = min(ans, maxi[{left, i}] * maxi[{i+1,right}] + solveRec(arr,maxi,left,i) + solveRec(arr,maxi,i+1,right));
    }
     
    return ans;
}

// recursive memoization sol
int solveMem(vector<int> &arr, map<pair<int,int>, int> &maxi, int left, int right, vector<vector<int>> &dp){
    // base cases
    if(left == right)
        return 0;

    if(dp[left][right] != -1)
        return dp[left][right];
    
    int ans = INT_MAX;

    for (int i=left; i<right; i++){
        ans = min(ans, maxi[{left, i}] * maxi[{i+1,right}] + solveMem(arr,maxi,left,i,dp) + solveMem(arr,maxi,i+1,right,dp));
    }
     
    return dp[left][right] = ans;
}


// tabulation sol
int solveTab(vector<int> &arr, map<pair<int,int>, int> &maxi){
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for (int left = n-1; left>=0; left--){
        for(int right = 0; right<=n-1; right++){
            int ans = INT_MAX;

            for (int i=left; i<right; i++){
                ans = min(ans, maxi[{left, i}] * maxi[{i+1,right}] + dp[left][i] + dp[i+1][right]);
            }
            if(left == right)
                dp[left][right] = 0;
                
            else 
                dp[left][right] = ans;
        }
    }
    
    return dp[0][n-1];
    
}


// driver sol
int MCT_FromLeafValues(vector<int> &arr){
    map<pair<int,int>, int> maxi;

    for (int i = 0; i < arr.size(); i++){
        maxi[{i,i}] = arr[i];
        for(int j=i+1; j<arr.size(); j++)
            maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]);
    }

// sol 1
    // return solveRec(arr,maxi,0,arr.size()-1);

// sol 2
    int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    // return solveMem(arr, maxi, 0, n-1, dp);

// sol 3
    return solveTab(arr,maxi);
}

int main(){
    vector<int> arr = {6,2,4};
    cout<<"Minimum cost tree from leaf values: "<<MCT_FromLeafValues(arr);
}