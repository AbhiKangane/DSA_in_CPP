#include<bits/stdc++.h>
using namespace std;

// recursive solution
int solveRec(vector<int> &nums, int n){
    // base case
    if(n<0)
        return 0;
    
    if(n==0)
        return nums[0];
    
    int incl = solveRec(nums, n-2) + nums[n];
    int excl = solveRec(nums, n-1) + 0;
    
    return max(incl, excl);
}

// dp(recursion + memoization)
int solveMem(vector<int> &nums, int n , vector<int> &dp){
    // base case
    if(n < 0)      return 0;
    if(n == 0)      return nums[0];

    if(dp[n] != -1)      return dp[n];

    int incl = solveMem(nums, n-2, dp) + nums[n];
    int excl = solveMem(nums, n-1, dp) + 0;
    
    dp[n] = max(incl, excl);

    return dp[n];
}

// dp(tabulation)
int solveTab(vector<int> &nums){
    int n = nums.size();
    vector<int> dp(n, 0);
    
    dp[0] = nums[0];

    for(int i=1; i<n; i++){
        int incl = nums[1];
        if(i>1)
            incl = dp[i-2] + nums[i];
        int excl = dp[i-1];
        dp[i] = max(incl, excl);
    }

    return dp[n-1];
}

// dp(space optimization)
int solve_SO(vector<int> &nums, int n){
    if(n==0)    return 0;
    int prev2 = 0;
    int prev1 = nums[0];

    for(int i=1; i<n; i++){
        int incl = prev2 + nums[i];
        int excl = prev1;
        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}


// driver function
int maximum_NonAdajacent_Sum(vector<int> &nums){
    int n = nums.size();
// sol 1
    // return solveRec(nums, n-1);

// sol 2
    // vector<int> dp(n, -1);
    // return solveMem(nums, n-1, dp);

// sol 3 
    // return solveTab(nums);

// sol 4
    return solve_SO(nums, n);
} 


int main(){
    vector<int> nums = {1,3,4,8,10,13};
    cout<<maximum_NonAdajacent_Sum(nums);
}
