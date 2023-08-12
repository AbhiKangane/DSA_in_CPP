// rod of length n & segments of length{x,y,z} & we have to find maximum segments
#include<bits/stdc++.h>
using namespace std;

// recursion
int solve1(int n, int x, int y, int z){
    // base case
    if(n==0)        return 0;
    if(n<0)         return INT_MIN;

    int a = solve1(n-x, x,y,z) + 1;
    int b = solve1(n-y, x,y,z) + 1;
    int c = solve1(n-z, x,y,z) + 1;

    int ans = max(a, max(b,c));
    return ans;
}

// dp(recursion + memoization)
int solve2(int n, int x, int y, int z, vector<int> &dp){
    // base case
    if(n==0)        return 0;
    if(n<0)         return INT_MIN;

    if(dp[n] != -1)     return dp[n];

    int a = solve2(n-x, x,y,z, dp) + 1;
    int b = solve2(n-y, x,y,z, dp) + 1;
    int c = solve2(n-z, x,y,z, dp) + 1;

    dp[n] = max(a, max(b,c));
    
    return dp[n];
}

// dp(iterative + tabulation)
int solve3(int n, int x, int y, int z){
    // creating vector dp
    vector<int> dp(n+1, INT_MIN);
    // anylysing base cases
    dp[0] = 0;
    
    for (int i = 1; i <= n; i++){
        if(i-x >=0)         dp[i] = max(dp[i], dp[i-x] + 1);
        if(i-y >=0)         dp[i] = max(dp[i], dp[i-y] + 1);
        if(i-z >=0)         dp[i] = max(dp[i], dp[i-z] + 1);
    }
    
    if(dp[n] < 0)
        dp[n] = 0;

    return dp[n];
}

// driver function
int max_Segments(int n, int x, int y, int z){
// sol 1
    // int ans = solve1(n,x,y,z);
    // if(ans < 0)         ans = 0;
    // return ans;

// sol 2
    // vector<int> dp(n+1, -1);
    // int ans = solve2(n,x,y,z, dp);
    // if(ans < 0)         ans = 0;
    // return ans;

// sol3
    return solve3(n,x,y,z);
}

int main(){
    int n=7, x=5, y=2, z=2;
    cout<<max_Segments(8,3,3,3)<<endl;  // 0
    cout<<max_Segments(n,x,y,z)<<endl;  // 2
}