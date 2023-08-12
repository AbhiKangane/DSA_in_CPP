// Fibonacci series : 0,1,1,2,3,5,8,13,21,34,55,...

#include<iostream>
#include<vector>
using namespace std;

// 1) using recursion
int Recursive_fib(int n, vector<int> &dp){
    if(n<=1)
        return n;

    return Recursive_fib(n-1, dp) + Recursive_fib(n-2, dp);
}

// 2) using DP (recursion + memoization => Top Down Approach)
int memoization_fib(int n, vector<int> &dp){
    if(n<=1)
        return n;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = memoization_fib(n-1, dp) + memoization_fib(n-2, dp);
    return dp[n];
}

// 3) using DP (iterative Tabulation: bottom up Approach)
int Tabulation_Fib(int n, vector<int> &dp){
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}



int main(){
    int n = 7;
    vector<int> dp(n+1, -1);

/* 1) */    
    // cout<<Recursive_fib(n, dp)<<endl;

/* 2) */
    // cout<<memoization_fib(n, dp)<<endl;

/* 3) */
    // cout<<Tabulation_Fib(n, dp)<<endl;
 
/* 4)  using DP (space optimization) */
    int prev1 = 1;
    int prev2 = 0;
    
    if(n==0)    cout<<"0";

    else{
        cout<<"0  1  ";
        for(int i=2; i<=n; i++){
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
            cout<<prev1<<"  ";
        }
    }

    return 0;
}