// Rahul & Neha are playing a game. Given even no. of coins, they take alternate turns & in each turn a player pick either 1st or 
// last coin from row & remove it from the row. The value of coin  is received by the that player, Determine maximum value that
// Rahul can win if he moves 1st. Both player plays optimally.
#include<iostream>
#include<vector>
using namespace std;

// recursive sol
int solveRec(vector<int> a, int i, int j){
    if(i==j)
        return a[i];

    if(i>j)
        return 0;

    int l = a[i] + min(solveRec(a,i+2, j), solveRec(a,i+1,j-1));
    // remaining coins => a[i+1,j]
    int r = a[j] + min(solveRec(a,i,j-2), solveRec(a,i+1, j-1));
    // remaining coins => a[i,j-1]

    return max(l,r);
}

// memoization
int solveMem(vector<int> a, int i, int j, vector<vector<int>> dp){
    if(i==j)
        return a[i];

    if(i>j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int l = a[i] + min(solveRec(a,i+2, j), solveRec(a,i+1,j-1));
    // remaining coins => a[i+1,j]
    int r = a[j] + min(solveRec(a,i,j-2), solveRec(a,i+1, j-1));
    // remaining coins => a[i,j-1]

    return dp[i][j] = max(l,r);
}



int main(){
    vector<int> a = {2,3,4,1,2,5,6,4};  // optimum selection: Rahul => 4,5,2,4  & Neha => 6,2,3,1
    int n = a.size();
    // sol 1
    // cout<<solveRec(a,0,n-1);

    // sol 2
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    cout<<solveMem(a,0,n-1,dp);
}