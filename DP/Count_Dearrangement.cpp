// Dearrangement is permutation of n elements such that no elements appears in its original position 
#include<bits/stdc++.h>
using namespace std;

#define mod 10000007
// sol 1 : recusrion
long long int solveRec(int n){
    if(n==1)        return 0;
    if(n==2)        return 1;

    int ans = ((n-1)%mod)*((solveRec(n-1)%mod /*if swapping of two numbers not takes place*/ + 
                            solveRec(n-2)%mod /*if swapping takes place*/)%mod);
    return ans;
}

// sol 2 : dp (recusrion + memoization)
long long int solveMem(int n, vector<int> &dp){
    if(n==1)        return 0;
    if(n==2)        return 1;

    if(dp[n] != -1)     return dp[n];

    dp[n] = ((n-1)%mod)*((solveMem(n-1, dp)%mod /*if swapping of two numbers not takes place*/ + 
                            solveMem(n-2, dp)%mod /*if swapping takes place*/)%mod);
    return dp[n];
}


// sol 3 : dp (iterative tabulation)
long long int solveTab(int n){
    vector<int> dp(n+1, -1);
    dp[1] = 0;
    dp[2] = 1;

   for (int i = 3; i <= n; i++){
        dp[i] = ((i-1) % mod) * (((dp[i-1] % mod) + (dp[i-2] % mod)) % mod) ;
   }
   
    return dp[n];
}

// sol 4 : dp (space optimiation)
long long int solve_SO(int n){
    long long int prev2 = 0;
    long long int prev1 = 1;

   for (int i = 3; i <= n; i++){
        long long int ans = ((i-1) % mod) * (((prev1 % mod) + (prev2 % mod)) % mod) ;
        prev2 = prev1;
        prev1 = ans;
   }
   
    return prev1;
}



// driver function
long long int Count_Dearrangements(int n){
// sol 1
    // return solveRec(n);
// sol 2
    // vector<int> dp(n+1, -1); 
    // return solveMem(n, dp);
// sol 3
    // return solveTab(n);
// sol 4
    return solve_SO(n);
}

int main(){
    int n=4;
    cout<<Count_Dearrangements(n);
}