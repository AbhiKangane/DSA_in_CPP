// leetcode 279 : Perfect Squares
// for given integer n return minimum squares of any number required that sums n
#include<bits/stdc++.h>
using namespace std;

// recursive sol
int solveRec(int n){
    if(n==0)
        return 0;
    
    int ans = n;
    for(int i=1; i*i<=n; i++){
        ans = min(ans, 1+solveRec(n-i*i));
    }

    return ans;
}

// recursion + Memoization
int solveMem(int n, vector<int> &dp){
    if(n==0)
        return 0;
    
    if(dp[n] != -1)
        return dp[n];

    int ans = n;
    for(int i=1; i*i<=n; i++){
        ans = min(ans, 1+solveMem(n-i*i, dp))
    }

    dp[n] = ans;
    return dp[n];
}

// tabulation
int solveTab(int n){
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    int ans = n;
    for(int i=1; i<=n; i++){
        for(int j=1; j*j<=n; j++){
            if(i-j*j >= 0)
                dp[i] = min(dp[i], 1+ dp[i-j*j]);
        }
    }  
    return dp[n];
}

// driver sol
int minimum_squares(int n){
// sol 1
    // return solveRec(n);

// sol 2
    // vector<int> dp(n+1, -1);
    // return solveMem(n, dp);

// sol 3
    return solveTab(n);
}

int main(){
    cout<<minimum_squares(4);
    return 0;
}
