// here n walls, k colors & we have to find number of ways to color the walls such that not more than two walls adjacent walls have same colors
#include<bits/stdc++.h>
using namespace std;


int add(int a, int b){
    return a+b;
}

int mul(int a, int b){
    return a*b;
}

// sol recursion
int solveRec(int n, int k){
    // base case
    if(n == 1)      return k;
    if(n == 2)      return add(k, mul(k, k-1));

    int ans = add(mul(solveRec(n-2, k), k-1), mul(solveRec(n-1,k), k-1));
    return ans;
}

// dp(recursion + memoization)
int solveMem(int n, int k, vector<int> &dp){
    // base case
    if(n == 1)      return k;
    if(n == 2)      return add(k, mul(k, k-1));

    if(dp[n] != -1)     return dp[n];
    
    dp[n] = add(mul(solveRec(n-2, k), k-1), mul(solveRec(n-1,k), k-1));
    return dp[n];
}

// dp(tabulation)
int solveTab(int n, int k){
    vector<int> dp(n+1, 0);

    dp[1] = k;
    dp[2] = add(k, mul(k, k-1));

    for (int i = 3; i <= n; i++){
        dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1));
    }

    return dp[n];
}

// space optimization
int solve_SO(int n, int k){
    int prev2 = k;
    int prev1 = add(k, mul(k, k-1));

    for (int i = 3; i <= n; i++){
        int curr = add(mul(prev2, k-1), mul(prev1, k-1));
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

// driver function
int no_of_Ways(int n, int k){
// sol 1
    // return solveRec(n,k);
// sol 2
    // vector<int> dp(n+1, -1);
    // return solveMem(n,k,dp);
// sol 3
    // return solveTab(n,k);
// sol 4
    return solve_SO(n, k);
}


int main(){
    cout<<no_of_Ways(3,2)<<endl;//6
}