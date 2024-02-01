// dynamic programming : Subset Sum Problem GFG
#include <bits/stdc++.h>
using namespace std;
 
// recursive sol for target sum
bool solveRec(int index, vector<int> &arr, int size, int target){
    // base case
    if(index >= size || target < 0)
        return 0;
    if(target == 0)
        return 1;

    bool incl = solveRec(index+1, arr, size, target-arr[index]);
    bool excl = solveRec(index+1, arr, size, target);

    return incl || excl;
}

// recursive memoization sol for target sum
bool solveMem(int index, vector<int> &arr, int size, int target, vector<vector<int>> &dp){
    // base case
    if(target == 0)
        return dp[index][target] = 1;

    if(index >= size || target < 0)
        return 0;

    
    if(dp[index][target] != -1)
        return dp[index][target];

    bool incl = solveMem(index+1, arr, size, target-arr[index], dp);
    bool excl = solveMem(index+1, arr, size, target, dp);

    return dp[index][target] = incl || excl;
}

// iterative tabulation sol for equal sum partition
bool solveTab(vector<int> &arr, int size, int target){
    vector<vector<int>> dp(size+1, vector<int>(target+1, 0));
    // analysing base case
    for (int i = 0; i<=size; i++){
        dp[i][0] = 1;
    }
    
    for (int index = size-1; index >= 0; index--){
        for (int t = 0; t <= target; t++){
            bool incl = 0;
            if(t-arr[index] >= 0)
                incl = dp[index+1][t-arr[index]];
            
            bool excl = dp[index+1][t];

            dp[index][t] = incl || excl;
        }
    }
    
    return dp[0][target];
}


// space optimization sol for equal sum partition
bool solve_SO(vector<int> &arr, int size, int target){
    vector<int> curr(target+1, 0);
    vector<int> next(target+1, 0);
    // analysing base case
    curr[0] = 1;
    next[0] = 1;
    
    for (int index = size-1; index >= 0; index--){
        for (int t = 0; t <= target; t++){
            bool incl = 0;
            if(t-arr[index] >= 0)
                incl = next[t-arr[index]];
            
            bool excl = next[t];

            curr[t] = incl || excl;
        }
        next = curr;
    }
    
    return next[target];
}
    
bool isSubsetSum(vector<int>arr, int target){
    int size = arr.size();
    // sol 1
    // return solveRec(0, arr, size, target);
    
    // sol 2
    // vector<vector<int>> dp(size+1, vector<int>(target+1, -1));
    // return solveMem(0, arr, size, target, dp);
    
    // sol 3
    // return solveTab(arr, size, target);
    
    // sol 4
    return solve_SO(arr, size, target);
}

int main()
{
    vector<int> arr = {1,1,1,1,1,4};
    int target = 9;
    
    cout<<isSubsetSum(arr, target);
    return 0;
}
