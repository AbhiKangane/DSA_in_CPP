// Part III : here you may complete at most 2 transactions ie. 1 Transaction => buy + sell
// condition : You can only hold at most one share of stock at any time

#include<bits/stdc++.h>
using namespace std;

int solveRec_III(int index, int buy, vector<int> &prices, int limit){
    if(index == prices.size())
        return 0;

    if(limit == 0)
        return 0;
    
    int profit = 0;
    
    if(buy){  // if we can able to buy stock i.e. stock already sell
        int buyKaro = -prices[index] + solveRec_III(index+1, 0, prices, limit);
        int skipKaro = 0 + solveRec_III(index+1, 1, prices, limit);
        profit = max(buyKaro, skipKaro);
    }
    
    else{  // if we can't able to buy stock i.e. stock already buy
        int sellKaro = prices[index] + solveRec_III(index+1, 1, prices, limit-1);
        int skipKaro = 0 + solveRec_III(index+1, 0, prices, limit);
        profit = max(sellKaro, skipKaro);
    }

    return profit;
}  

// recursive memoization
int solveMem_III(int index, int buy, vector<int> &prices, int limit, vector<vector<vector<int>>> &dp){
    if(index == prices.size())
        return 0;

    if(limit == 0)
        return 0;
    
    if(dp[index][buy][limit] != -1)
        return dp[index][buy][limit];

    int profit = 0;
    
    if(buy){  // if we can able to buy stock i.e. stock already sell
        int buyKaro = -prices[index] + solveMem_III(index+1, 0, prices, limit, dp);
        int skipKaro = 0 + solveMem_III(index+1, 1, prices, limit, dp);
        profit = max(buyKaro, skipKaro);
    }
    
    else{  // if we can't able to buy stock i.e. stock already buy
        int sellKaro = prices[index] + solveMem_III(index+1, 1, prices, limit-1, dp);
        int skipKaro = 0 + solveMem_III(index+1, 0, prices, limit, dp);
        profit = max(sellKaro, skipKaro);
    }

    return dp[index][buy][limit] = profit;
}  

// iterative tabulation
int solveTab_III(vector<int> &prices){
    int n = prices.size();
    vector<vector<vector<int>>> dp (n+1, vector<vector<int>> (2,vector<int>(3,0)));

    for (int index = n-1; index>=0; index--){
        for (int buy = 0; buy < 2; buy++){
            for(int limit=1; limit<=2; limit++){
                int profit = 0;
                
                if(buy){  // if we can able to buy stock i.e. stock already sell
                    int buyKaro = -prices[index] + dp[index+1][0][limit];
                    int skipKaro = 0 + dp[index+1][1][limit];
                    profit = max(buyKaro, skipKaro);
                }
                
                else{  // if we can't able to buy stock i.e. stock already buy
                    int sellKaro = prices[index] + dp[index+1][1][limit-1];
                    int skipKaro = 0 + dp[index+1][0][limit];
                    profit = max(sellKaro, skipKaro);
                }

                dp[index][buy][limit] = profit;
            }
        }
    }
    return dp[0][1][2];    
}  


// space optimizationc: O(1) space complexity
int solve_SO_III(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> curr(2,vector<int>(3,0));
    vector<vector<int>> next(2,vector<int>(3,0));

    for (int index = n-1; index>=0; index--){
        for (int buy = 0; buy < 2; buy++){
            for(int limit=1; limit<=2; limit++){
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
    return next[1][2];    
}  


int maxProfit_Part_III(vector<int> &prices){
    int n = prices.size();
// sol 1
    // return solveRec_III(0, 1, prices, 2);

// sol 2
    // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,vector<int>(3,-1)));
    // return solveMem_III(0,1,prices,2,dp);

// sol 3
    // return solveTab_III(prices);

// sol 4
    return solve_SO_III(prices);
}


int main(){
    vector<int> prices = {7,1,5,3,6,4,5,7,2,10}; 
// part III
    cout<<"Maximum profit get in at most 10 transactions: "<<maxProfit_Part_III(prices)<<endl; // in at most 2 transaction : (1,7) + (2,10) == 14
}