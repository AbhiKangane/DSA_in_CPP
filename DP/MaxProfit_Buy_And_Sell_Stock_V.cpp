// Part V : similar to part II
// In this part you may do multiple transactions but you need to pay transaction fee for each transaction
// space optimization
#include<iostream>
#include<vector>
using namespace std;


// space optimized code of part II
int solve_SO(vector<int> &prices, int Fee){
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
                int sellKaro = prices[index] + next[1] - Fee;
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
int maxProfit_Part_V(vector<int> & prices, int transaction_Fee){
// sol using space optimized code of part II
    return solve_SO(prices, transaction_Fee);
}



int main(){
    vector<int> prices = {7,1,5,3,6,4,5,7,2,10}; 
    int transaction_Fee = 2;
// Part II : here (buy,sell) prices seq => (1,5) + (3,6) + (4,5) + (5,7) + (2,10) = 18
// Part V : here (buy,sell) prices seq => (1,7) + (2,10) & TFee = 6 & maxProfit = 9
    cout<<maxProfit_Part_V(prices, transaction_Fee)<<endl; 
}