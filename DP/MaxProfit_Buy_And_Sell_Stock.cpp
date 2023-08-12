// given prices[i] is the price of a given stock on ith day & return maxProfit
#include<bits/stdc++.h>
using namespace std;

// Part I :  here choose a single day to buy 1 stock & choosing a differnt day in future to sell that stock
int maxProfit_Part_I(vector<int> &prices){
    int mini = prices[0];
    int profit = 0;
    for (int i = 1; i<prices.size(); i++){
        int diff = prices[i] - mini; //here considered that we sell stock at ith day
        profit = max(profit, diff);
        mini = min(mini, prices[i]);
    }
    
    return profit;
}



// Part II : here you may decide to buy or sell the stock more than 1 time
// condition : You can only hold at most one share of stock at any time
// i.e Sequence : buy-> sell-> buy-> sell-> buy-> .... -> sell
int solveRec(int index, int buy, vector<int> &prices){
    if(index == prices.size())
        return 0;
    
    int profit = 0;
    
    if(buy){  // if we can able to buy stock i.e. stock already sell
        int buyKaro = -prices[index] + solveRec(index+1, 0, prices);
        int skipKaro = 0 + solveRec(index+1, 1, prices);
        profit = max(buyKaro, skipKaro);
    }
    
    else{  // if we can't able to buy stock i.e. stock already buy
        int sellKaro = prices[index] + solveRec(index+1, 1, prices);
        int skipKaro = 0 + solveRec(index+1, 0, prices);
        profit = max(sellKaro, skipKaro);
    }

    return profit;
}  

// recursive memoization
int solveMem(int index, int buy, vector<int> &prices, vector<vector<int>> &dp){
    if(index == prices.size())
        return 0;
    
    if(dp[index][buy] != -1)
        return dp[index][buy];

    int profit = 0;
    
    if(buy){  // if we can able to buy stock i.e. stock already sell
        int buyKaro = -prices[index] + solveMem(index+1, 0, prices,dp);
        int skipKaro = 0 + solveMem(index+1, 1, prices, dp);
        profit = max(buyKaro, skipKaro);
    }
    
    else{  // if we can't able to buy stock i.e. stock already buy
        int sellKaro = prices[index] + solveMem(index+1, 1, prices, dp);
        int skipKaro = 0 + solveMem(index+1, 0, prices, dp);
        profit = max(sellKaro, skipKaro);
    }

    return dp[index][buy] = profit;
}  

// iterative tabulation
int solveTab(vector<int> &prices){
    int n = prices.size();
    vector<vector<int>> dp(n+1, vector<int>(2,0));

    for(int index = n-1; index >= 0; index--){
        for(int buy = 0; buy <= 1; buy++){
            int profit = 0;
            if(buy){  // if we can able to buy stock i.e. stock already sell
                int buyKaro = -prices[index] + dp[index+1][0];
                int skipKaro = 0 + dp[index+1][1];
                profit = max(buyKaro, skipKaro);
            }
            
            else{  // if we can't able to buy stock i.e. stock already buy
                int sellKaro = prices[index] + dp[index+1][1];
                int skipKaro = 0 + dp[index+1][0];
                profit = max(sellKaro, skipKaro);
            }

            dp[index][buy] = profit;
        }
    }
    return dp[0][1];
}  

// space optimization
int solve_SO(vector<int> &prices){
    int n = prices.size();
    vector<int> curr(2,0);
    vector<int> next(2,0);

    for(int index = n-1; index >= 0; index--){
        for(int buy = 0; buy <= 1; buy++){
            int profit = 0;
            if(buy){  // if we can able to buy stock i.e. stock already sell
                int buyKaro = -prices[index] + next[0];
                int skipKaro = 0 + next[1];
                profit = max(buyKaro, skipKaro);
            }
            
            else{  // if we can't able to buy stock i.e. stock already buy
                int sellKaro = prices[index] + next[1];
                int skipKaro = 0 + next[0];
                profit = max(sellKaro, skipKaro);
            }

            curr[buy] = profit;
        }
        next = curr;
    }
    return next[1];
}  


// driver function 
int maxProfit_Part_II(vector<int> & prices){
// sol 1
    // return solveRec(0, 1, prices);
    
// sol 2
    // vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
    // return solveMem(0, 1, prices, dp);

// sol 3
    // return solveTab(prices);
// sol 4
    return solve_SO(prices);
}



int main(){
    vector<int> prices = {7,1,5,3,6,4,5,7,2,10}; 
// part I
    cout<<maxProfit_Part_I(prices)<<endl; // here buying & selling price for maximum profit 1 & 10

// Part II
    cout<<maxProfit_Part_II(prices)<<endl; // here (buy,sell) prices seq => (1,5) + (3,6) + (4,5) + (5,7) + (2,10)
}