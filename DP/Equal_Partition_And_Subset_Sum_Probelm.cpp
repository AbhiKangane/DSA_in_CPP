// equal sum partion problem: here we have to check that whether given array partitioned into to subarrays such that both having same sum
// target sum or subset sum problem: here we have to check that whether given array has subarrays such that having sum equals to target

#include<bits/stdc++.h>
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
    if(index >= size || target < 0)
        return 0;
    if(target == 0)
        return 1;

    if(dp[index][target] != -1)
        return dp[index][target];

    bool incl = solveMem(index+1, arr, size, target-arr[index], dp);
    bool excl = solveMem(index+1, arr, size, target, dp);

    return dp[index][target] = incl || excl;
}

// iterative tabulation sol for equal sum partition
bool solveTab(vector<int> &arr, int size, int total){
    vector<vector<int>> dp(size+1, vector<int>(total+1, 0));
    // analysing base case
    for (int i = 0; i<=size; i++){
        dp[i][0] = 1;
    }
    
    for (int index = size-1; index >= 0; index--){
        for (int target = 0; target <= total/2; target++){
            bool incl = 0;
            if(target-arr[index] >= 0)
                incl = dp[index+1][target-arr[index]];
            
            bool excl = dp[index+1][target];

            dp[index][target] = incl || excl;
        }
    }
    
    return dp[0][total/2];
}

// space optimization sol for equal sum partition
bool solve_SO(vector<int> &arr, int size, int total){
    vector<int> curr(total+1, 0);
    vector<int> next(total+1, 0);
    // analysing base case
    curr[0] = 1;
    next[0] = 1;
    
    for (int index = size-1; index >= 0; index--){
        for (int target = 0; target <= total/2; target++){
            bool incl = 0;
            if(target-arr[index] >= 0)
                incl = next[target-arr[index]];
            
            bool excl = next[target];

            curr[target] = incl || excl;
        }
        next = curr;
    }
    
    return next[total/2];
}


// driver function
int equal_Sum_Partition(vector<int> &arr, int size){
    int total = 0;
    for (int i = 0; i < size; i++){
        total += arr[i];
    }

    if(total & 1) // if total is odd
        return 0;
    
// sol 1
    // return solveRec(0, arr, size, total/2);
// sol 2
    // vector<vector<int>> dp(size+1, vector<int>(total+1, -1));
    // return solveMem(0, arr, size, total/2, dp);

// sol 3
    return solveTab(arr, size, total);
// sol 4
    // return solve_SO(arr, size, total);
}


int main(){
    vector<int> arr = {1, 2, 3 ,4, 8};  // (2,3,4) & (1,8)
    cout<<equal_Sum_Partition(arr, arr.size());
}