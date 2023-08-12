// Part IV : here you may complete at most 'k' transactions ie. 1 Transaction => buy + sell
// condition : You can only hold at most one share of stock at any time

#include<bits/stdc++.h>
using namespace std;

// space optimizationc: O(1) space complexity
int solve_SO_IV(vector<int> &prices, int k){
    int n = prices.size();
    vector<vector<int>> curr(2,vector<int>(k+1,0));
    vector<vector<int>> next(2,vector<int>(k+1,0));

    for (int index = n-1; index>=0; index--){
        for (int buy = 0; buy < 2; buy++){
            for(int limit=1; limit<=k; limit++){
                int profit = 0;
                
                if(buy){  // if we can able to buy stock i.e. stock already sell
                    int buyKaro = -prices[index] + next[0][limit];
                    int skipKaro = 0 + next[1][limit];
                    profit = max(buyKaro, skipKaro);
                }
                
                else{  // if we can't able to buy stock i.e. stock already buy
                    int sellKaro = prices[index] + next[1][limit-1];
                    int skipKaro = 0 + next[0][limit];
                    profit = max(sellKaro, skipKaro);
                }

                curr[buy][limit] = profit;
            }
        }
        next = curr;
    }
    return next[1][k];
}

// recursive sol: using transaction number
int solveRec(int index, int operationNo, int k, vector<int> &prices){
    if(index == prices.size())
        return 0;
    
    if(operationNo == 2*k)  // because 1 transaction or k = 2 operations
        return 0;

    int profit = 0;
    if(operationNo % 2 == 0){ // allowed to buy
        int buyKaro = -prices[index] + solveRec(index+1,operationNo+1,k,prices);
        int skipKaro = 0 + solveRec(index+1,operationNo,k,prices);
        profit = max(buyKaro, skipKaro);
    }
    
    else{ // allowed to sell
        int sellKaro = prices[index] + solveRec(index+1,operationNo+1,k,prices);
        int skipKaro = 0 + solveRec(index+1,operationNo,k,prices);
        profit = max(sellKaro, skipKaro);
    }

    return profit;
}

// memoization
int solveMem(int index, int operationNo, int k, vector<int> &prices, vector<vector<int>> &dp){
    if(index == prices.size())
        return 0;
    
    if(operationNo == 2*k)  // because 1 transaction or k = 2 operations
        return 0;

    if(dp[index][operationNo] != -1)
        return dp[index][operationNo];

    int profit = 0;
    if(operationNo % 2 == 0){ // allowed to buy
        int buyKaro = -prices[index] + solveMem(index+1,operationNo+1,k,prices, dp);
        int skipKaro = 0 + solveMem(index+1,operationNo,k,prices, dp);
        profit = max(buyKaro, skipKaro);
    }
    
    else{ // allowed to sell
        int sellKaro = prices[index] + solveMem(index+1,operationNo+1,k,prices, dp);
        int skipKaro = 0 + solveMem(index+1,operationNo,k,prices, dp);
        profit = max(sellKaro, skipKaro);
    }

    return dp[index][operationNo] = profit;
}

// tabulation
int solve_Tab(vector<int> &prices, int k){
    int n = prices.size();
    vector<vector<int>> dp (n+1, vector<int>(2*k+1, 0));

    for (int index = n-1; index >= 0; index--){
        for(int operationNo = 0; operationNo<2*k; operationNo++){
            int profit = 0;
            if(operationNo % 2 == 0){ // allowed to buy
                int buyKaro = -prices[index] + dp[index+1][operationNo+1];
                int skipKaro = 0 + dp[index+1][operationNo];
                profit = max(buyKaro, skipKaro);
            }
            
            else{ // allowed to sell
                int sellKaro = prices[index] + dp[index+1][operationNo+1];
                int skipKaro = 0 + dp[index+1][operationNo];
                profit = max(sellKaro, skipKaro);
            }

            dp[index][operationNo] = profit;
        }
    }
    return dp[0][0];
}

// space optimization
int solve_SO(vector<int> &prices, int k){
    int n = prices.size();
    vector<int> curr(2*k+1, 0);
    vector<int> next(2*k+1, 0);

    for (int index = n-1; index >= 0; index--){
        for(int operationNo = 0; operationNo<2*k; operationNo++){
            int profit = 0;
            if(operationNo % 2 == 0){ // allowed to buy
                int buyKaro = -prices[index] + next[operationNo+1];
                int skipKaro = 0 + next[operationNo];
                profit = max(buyKaro, skipKaro);
            }
            
            else{ // allowed to sell
                int sellKaro = prices[index] + next[operationNo+1];
                int skipKaro = 0 + next[operationNo];
                profit = max(sellKaro, skipKaro);
            }

            curr[operationNo] = profit;
        }
        next = curr;
    }
    return next[0];
}


// Part IV
int maxProfit_Part_IV(vector<int> &prices, int k){
// space optimized code made from part III sol 4
    // return solve_SO_IV(prices, k);

// recursive sol
    // return solveRec(0,0,k,prices);

// memoization
    // int n = prices.size(); 
    // vector<vector<int>>dp(n,vector<int>(2*k, -1));
    // return solveMem(0,0,k,prices,dp);

// tabulation
    // return solve_Tab(prices, k);

// space optimization
    return solve_SO(prices, k);
}


int main(){
    vector<int> prices = {7,1,5,3,6,4,5,7,2,10}; 
// Part IV
    cout<<maxProfit_Part_IV(prices, 3)<<endl; // (1,6) + (4,7) + (2,10) = 16
}