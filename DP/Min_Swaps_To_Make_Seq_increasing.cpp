// given two vectors( say v1 & v2) of equal size & we have to find minimum swaps( bet v1[i] & v2[i]) required to make both vectors strictly increasing 

#include<bits/stdc++.h>
using namespace std;

// recursive sol
int solveRec(vector<int> &num1, vector<int> &num2, int index, int swapped){
    // base case
    if(index == num1.size())
        return 0;
    
    int ans = INT_MAX;

    int prev1 = num1[index - 1];
    int prev2 = num2[index - 1];

    // catch : we didn't make changes in actual vectors
    if(swapped)
        swap(prev1, prev2);
    
    // no swapping
    if(num1[index] > prev1 && num2[index] > prev2)
        ans = solveRec(num1, num2, index+1, 0);
    
    // swapping
    if(num1[index] > prev2 && num2[index] > prev1)  // cross checking
        ans = min(ans, 1 + solveRec(num1, num2, index+1, 1));
    
    return ans;
}

// recursion + memoization
int solveMem(vector<int> &num1, vector<int> &num2, int index, int swapped, vector<vector<int>> &dp){
    // base case
    if(index == num1.size())
        return 0;

    if(dp[index][swapped] !=  -1)
        return dp[index][swapped];
    
    int ans = INT_MAX;

    int prev1 = num1[index - 1];
    int prev2 = num2[index - 1];

    // catch : we didn't make changes in actual vectors
    if(swapped)
        swap(prev1, prev2);
    
    // no swapping
    if(num1[index] > prev1 && num2[index] > prev2)
        ans = solveMem(num1, num2, index+1, 0, dp);
    
    // swapping
    if(num1[index] > prev2 && num2[index] > prev1)  // cross checking
        ans = min(ans, 1 + solveMem(num1, num2, index+1, 1, dp));
    
    return dp[index][swapped] = ans;
}

// tabulation
int solveTab(vector<int> &num1, vector<int> &num2){
    int n = num1.size();
    vector<vector<int>> dp(n+1, vector<int> (2,0));

    for (int index = n-1; index >= 1; index--){
        for (int swapped = 1; swapped >= 0; swapped--){
            
            int ans = INT_MAX;
            int prev1 = num1[index - 1];
            int prev2 = num2[index - 1];

            // catch : we didn't make changes in actual vectors
            if(swapped)
                swap(prev1, prev2);
            
            // no swapping
            if(num1[index] > prev1 && num2[index] > prev2)
                ans = dp[index+1][0];
            
            // swapping
            if(num1[index] > prev2 && num2[index] > prev1)  // cross checking
                ans = min(ans, 1 + dp[index+1][1]);
            
            dp[index][swapped] = ans;
        }
    }
    return dp[1][0];
}

// space optimization
int solve_SO(vector<int> &num1, vector<int> &num2){
    int n = num1.size();
    int swap = 0, noswap = 0,
        currswap = 0, currnoswap = 0;

    for (int index = n-1; index >= 1; index--){
        for (int swapped = 1; swapped >= 0; swapped--){
            
            int ans = INT_MAX;
            int prev1 = num1[index - 1];
            int prev2 = num2[index - 1];

            // catch : we didn't make changes in actual vectors
            if(swapped){
                // swapping prev1 & prev2
                int temp = prev2;
                prev2 = prev1;
                prev1 = temp;
            }

            // no swapping
            if(num1[index] > prev1 && num2[index] > prev2)
                ans = noswap;
            
            // swapping
            if(num1[index] > prev2 && num2[index] > prev1)  // cross checking
                ans = min(ans, 1 + swap);
            
            if(swapped)
                currswap = ans;
            else // swapped == 0
                currnoswap = ans;
        }
        swap = currswap;
        noswap = currnoswap;
    }
    return min(swap, noswap);
}


// driver function
int min_Swaps(vector<int> &num1, vector<int> &num2){
    num1.insert(num1.begin(), -1);
    num2.insert(num2.begin(), -1);

    int index = 1, swapped = 0;
// sol 1
    // return solveRec(num1, num2, 1, 0);

// sol 2
    // vector<vector<int>> dp(num1.size(), vector<int>(2, -1));
    // return solveMem(num1, num2, index, swapped, dp);

// sol 3
    // return solveTab(num1, num2);

// sol 4
    return solve_SO(num1, num2);
}

int main(){
    vector<int> num1 = {1,8,7,10}, num2 = {5,6,9,8};  // way 1: by swapping (8,6) & (10,8) way 2: by swapping(7,9)
    
    // vector<int> num1 = {1,8,11,10}, num2 = {5,4,9,15};  // only 1 way: by swapping (8,4) & (10,15)
    cout<<"Minimum swaps required to make vectors strictly increasing : "<<min_Swaps(num1, num2);
    return 0;
}