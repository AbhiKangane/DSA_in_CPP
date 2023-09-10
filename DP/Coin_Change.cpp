// Leetcode 322
// given an integer array coins representing coins of different denominations and 
// an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. 
// If that amount of money cannot be made up by any combination of the coins, return -1.
// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

#include<bits/stdc++.h>
using namespace std;

// sol 1: Recursive
int solveRec(vector<int>& coins, int amount, int n){
    // base cases
    if(n==0 && amount==0)
        return 0;
    if(n==0 && amount!=0)
        return INT_MAX - 1;

    if(coins[n-1] <= amount){
        int take = solveRec(coins, amount-coins[n-1], n);
        int notTake = solveRec(coins, amount, n-1);
        return min(1 + take, notTake);
    }

    return solveRec(coins, amount, n-1);
}

// sol 2 : Memoization
int solveMem(vector<int>& coins, int amount, int n, vector<vector<int>> &dp){
    // base cases
    if(n==0 && amount==0)
        return 0;
    if(n==0 && amount!=0)
        return INT_MAX - 1;

    if(dp[n][amount] != -1)
        return dp[n][amount];

    if(coins[n-1] <= amount){
        int take = solveMem(coins, amount-coins[n-1], n, dp);
        int notTake = solveMem(coins, amount, n-1, dp);
        return dp[n][amount] = min(1 + take, notTake);      //storing & return 
    }

    return dp[n][amount] = solveMem(coins, amount, n-1, dp);    // storing & return
}

// sol 3 : Tabulation
int solveTab(vector<int>& coins, int amount){
    int n = coins.size();
    vector<vector<int>> dp(13, vector<int>(10001, -1));
    
    for(int j=1; j<=amount; j++)
        dp[0][j] =  INT_MAX - 1;     // for 1st row or if size of coins array is 0
    
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;                // for 1st col or when amount is 0

    for(int i=1; i<=n; i++){
        for(int j=1; j<= amount; j++){
            if(coins[i-1] <= j){
                int take = dp[i][j-coins[i-1]];
                int notTake = dp[i-1][j];
                dp[i][j] = min(1 + take, notTake);      //storing & not need to return 
            }
            else
                dp[i][j] = dp[i-1][j];    // storing & not need to return
        }
    }
    return dp[n][amount];
}


int coinChange(vector<int>& coins, int amount) {
    int n = coins.size(), ans;
    // sol 1
    // ans = solveRec(coins, amount, n);

    // sol 2
    // Constraints:
    // 1 <= coins.length <= 12
    // 1 <= coins[i] <= 2^31 - 1
    // 0 <= amount <= 10^4
    // vector<vector<int>> dp(13,vector<int>(10001,-1));
    // ans = solveMem(coins, amount, n, dp);
    
    
    // sol 3
    ans = solveTab(coins,amount); 
    if(ans == INT_MAX - 1)
        return -1;
    return ans;
}


int main(){
    vector<int> coins = {1,2,5};
    int amount = 11;

    cout<<"Minimum no. of coins required : "<<coinChange(coins, amount);
}