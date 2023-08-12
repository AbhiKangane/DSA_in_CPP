// ex: arr[] = {1,2,3}, N=3, Target=7
// solutions: {1,1,1,1,1,1,1}, {1,1,1,1,1,2}, {1,1,1,2,2}, {1,2,2,2}, {1,1,2,3}, {1,1,1,1,3}, {2,2,3}, {2,1,1}, {3,3,1}
// Minimum numbers required to get target sum: 3

#include<bits/stdc++.h>
using namespace std;

// sol1: recursive sol 
int solve1(vector<int> &num, int x){
    // base case
    if(x==0)    return 0;
    if(x<0)     return INT_MAX;

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++){
        int ans = solve1(num, x-num[i]);
        if(ans != INT_MAX)
            mini = min(mini, 1+ans);
    }
    return mini;
}

// 
// DP( recursion + memoization => top-down approach)
int solve2(vector<int> &num, int x, vector<int> &dp){
    // base case
    if(x==0)    return 0;
    if(x<0)     return INT_MAX;

    if(dp[x] != -1)
        return dp[x];

    int mini = INT_MAX;
    for (int i = 0; i < num.size(); i++){
        int ans = solve2(num, x-num[i], dp);
        if(ans != INT_MAX)
            mini = min(mini, 1+ans);
    }
    dp[x] = mini;

    return mini;
}



// driver function
int minimum_Elements(vector<int> &num, int x){
// sol 1:
    // int ans = solve1(num, x);
    // if(ans == INT_MAX)      return -1;


// sol 2:
    // vector<int> dp(x+1, -1);
    // int ans = solve2(num, x, dp);
    // if(ans == INT_MAX)      return -1;

// sol 3: tabulation (bottom up approach)
    vector<int> dp(x+1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i<x+1; i++){
        for(int j=0; j<num.size(); j++){
            if(i-num[j] >= 0 && dp[i-num[j]] != INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i-num[j]]);
            }
        }
    }

    if(dp[x] == INT_MAX)    return -1;

    return dp[x];
}


int main(){
    vector<int> nums = {1};
    int target = 10;

    cout<<"Minimum numbers required to get target sum: "<<minimum_Elements(nums, target);
    return 0;
}