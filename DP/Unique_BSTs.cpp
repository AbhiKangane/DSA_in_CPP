// given integer n, return structurely unique BSTs having exactly n nodes of unique values from 1 to n
// it will be equals to catalan number of of n
// => (2n !) / [(n+1 !)* (n !)]  => (n+2)*(n+3)*...(2n) / n!  => product of((n+k)/k) terms where 2 <= k <= n
// => 1, 1, 2, 5, 14, ....           for n = 0 to ...       =>  CATALAN SERIES
#include<bits/stdc++.h>
using namespace std;

//it gives incorrect output for values >= 19
int solve_SO(int n) {
    long double ans = 1;
    for (int k = 2; k <= n; k++){
        ans *= (n + k);
        ans /= k;
    }
    return ans;
}

// optimal : iterative sol 1 : it gives incorrect output for values >= 19
int solve_Iterative(int n){
    long double Numerator = 1;  // int type work till n=9, long long int work till 14, long double work correctly till 18
    for (int i = n+2; i <= 2*n; i++){  
        Numerator *= i;
    }
    
    // cout<<Numerator<<endl;
    
    long double Denominator = 1;
    for (int i = 1; i <= n; i++){  
        Denominator *= i;
    }
    
    // cout<<Denominator<<endl;

    int ans = Numerator/Denominator;

    return ans;
}

// recursive sol
int solveRec(int n){
    if(n <= 1)
        return 1;

    int ans = 0;
    for (int i = 1; i <= n; i++){  // here i is denoted root of BST
        ans += solveRec(i-1)/*left subtree*/ * solveRec(n-i)/*right subtree*/;
    }
    return ans;
}

// recursive memoization sol
int solveMem(int n, vector<int> &dp){
    if(n <= 1)
        return 1;

    if(dp[n] != -1)
        return dp[n];

    int ans = 0;
    for (int i = 1; i <= n; i++){  // here i is denoted root of BST
        ans = (ans + (1LL*solveMem(i-1, dp)/*left subtree*/ * solveMem(n-i, dp))%mod)%mod/*right subtree*/;
    }
    return dp[n] = ans;
}

// Tabulation sol
int solveTab(int n){
    vector<int> dp(n+1, 0);

    dp[0] = dp[1] = 1;

    // i -> number of nodes
    for (int i = 2; i<=n; i++){
        // j -> root node
        for(int j=1; j<=i; j++){
            dp[i] = (dp[i] + (1LL* dp[j-1] * dp[i-j])%mod)%mod;
        }
    }
    
    return dp[n];
}


// driver function
int uniqueBSTs(int n){
// optimal sol
    return solve_SO(n);

    // return solve_Iterative(n);

// sol 1
    // return solveRec(n);
// sol 1
    // vector<int> dp(n+1, -1);
    // return solveMem(n, dp);
// sol 3
    // return solveTab(n);

}


int main(){
    int n = 14;
    cout<<uniqueBSTs(n)<<endl; // 1767263190
    cout<<solve_Iterative(n);
}
