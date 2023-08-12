// leetcode question
// There is a pizza with 3n slices with varying size, you & your friends will take slices as follows:
// 1) you can pick any pizza slce
// 2) 1st friend pick next slice in anti-clockwise direction of your pick
// 3) 12nd friend pick next slice in clockwise direction of your pick
// Repeat untill no more slices
// vector slices[] represent size of pizza slices in clockwise direction
// find maximum possible sum of slice size that you can pick

#include<bits/stdc++.h>
using namespace std;

// recursive sol
int solveRec(int index, int endIndex, vector<int> &slices, int n){
    // base case
    if(n == 0 || index > endIndex)
        return 0;
    
    int take  = slices[index] + solveRec(index+2, endIndex, slices, n-1);
    int notTake = 0 + solveRec(index+1, endIndex, slices, n);

    return max(take, notTake);
}

// recursion + memoization
int solveMem(int index, int endIndex, vector<int> &slices, int n, vector<vector<int>> &dp){
    // base case
    if(n == 0 || index > endIndex)
        return 0;
    
    if(dp[index][n] != -1)
        return dp[index][n];

    int take  = slices[index] + solveMem(index+2, endIndex, slices, n-1, dp);
    int notTake = 0 + solveMem(index+1, endIndex, slices, n, dp);

    return dp[index][n] = max(take, notTake);
}

// Tabulation
int solveTab(vector<int> &slices){
    int k = slices.size();
    vector<vector<int>> dp1(k+2, vector<int>(k+2, 0));
    vector<vector<int>> dp2(k+2, vector<int>(k+2, 0));

    for(int index=k-2; index>=0; index--){
        for(int n=1; n<=k/3; n++){

            int take  = slices[index] + dp1[index+2][n-1];
            int notTake = 0 + dp1[index+1][n];

            dp1[index][n] = max(take, notTake);
        }
    }
    int case1 = dp1[1][k/3];

    
    for(int index=k-1; index>=1; index--){
        for(int n=1; n<=k/3; n++){

            int take  = slices[index] + dp2[index+2][n-1];
            int notTake = 0 + dp2[index+1][n];

            dp2[index][n] = max(take, notTake);
        }
    }
    int case2 = dp2[1][k/3];

    return max(case1, case2);
}

// space optimization
int solve_SO(vector<int> &slices){
    int k = slices.size();
    // for case 1
    vector<int> prev2(k+2, 0);
    vector<int> curr2(k+2, 0);
    vector<int> next2(k+2, 0);
    
    // for case 2
    vector<int> prev1(k+2, 0);
    vector<int> curr1(k+2, 0);
    vector<int> next1(k+2, 0);

    for(int index=k-2; index>=0; index--){
        for(int n=1; n<=k/3; n++){

            int take  = slices[index] + next1[n-1];
            int notTake = 0 + curr1[n];

            prev1[n] = max(take, notTake);
        }
        next1 = curr1;
        curr1 = prev1;
    }
    int case1 = curr1[k/3];

    
    for(int index=k-1; index>=1; index--){
        for(int n=1; n<=k/3; n++){

            int take  = slices[index] + next2[n-1];
            int notTake = 0 + curr2[n];

            prev2[n] = max(take, notTake);
        }
        next2 = curr2;
        curr2 = prev2;
    }
    int case2 = curr2[k/3];

    return max(case1, case2);
}


// driver function
int maxSizeSlices(vector<int> &slices){
    int k = slices.size();

// sol 1
    // int case1 = solveRec(0, k-2, slices, k/3);
    // int case2 = solveRec(1, k-1, slices, k/3);
    // return  max(case1, case2);

// sol 2
    // vector<vector<int>> dp1(k, vector<int> (k, -1));
    // int case1 = solveMem(0, k-2, slices, k/3, dp1);

    // vector<vector<int>> dp2(k, vector<int> (k, -1));
    // int case2 = solveMem(1, k-1, slices, k/3, dp2);

    // return  max(case1, case2);

// sol 3
    return solveTab(slices);

// sol 4
    // return solve_SO(slices);
}

int main(){
    vector<int> slices = {1,2,3,4,5,6};
    cout<<maxSizeSlices(slices); // 10
    return 0;
}