// you have to guess a number
// if you guess right no. you win game, 
// else I'll tell you whether correct number is higher or lower
// every time you guess wrong number x, you will pay x dollars. 
// If you run out of money, you lose the game

#include<bits/stdc++.h>
using namespace std;

// recursive sol
int solveRec(int start, int end){
    if(start >= end)
        return 0;
    
    int maxi = INT_MAX;
    for (int i = start; i<=end; i++){
        maxi = min(maxi, i + max(solveRec(start, i-1), solveRec(i+1, end)));
    }
    
    return maxi;
}

// recursive memoization sol
int solveMem(int start, int end, vector<vector<int>> &dp){
    if(start >= end)
        return 0;
    
    if(dp[start][end] != -1)
        return dp[start][end];

    int maxi = INT_MAX;
    for (int i = start; i<=end; i++){
        maxi = min(maxi, i + max(solveMem(start, i-1, dp), solveMem(i+1, end, dp)));
    }
    
    return dp[start][end] = maxi;
}

// iterative tabulation sol
int solveTab(int n){
    vector<vector<int>> dp(n+2, vector<int> (n+2, 0));
   
    for (int start = n; start >= 1; start--){
        for(int end=start; end<=n; end++){
            if(start == end)
                continue;
            else{
                int maxi = INT_MAX;
                for (int i = start; i<=end; i++){
                    maxi = min(maxi, i + max(dp[start][i-1], dp[i+1][end]));
                }
                
                dp[start][end] = maxi;
            }
        }
    }
    
    return dp[1][n];
}

// driver function
int getMoneyAmount(int n){
// sol 1
    // return solveRec(1, n);
// sol 2
    // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    // return solveMem(1, n, dp);
// sol 3
    return solveTab(n);
}

int main(){
    int n = 10; // 16
    cout<<getMoneyAmount(n)<<endl;
}