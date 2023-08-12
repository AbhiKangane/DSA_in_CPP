// given D dice of F faces throws & 
// we have to find the no. of ways of getting sum of numbers obtained of upper face of dice equals to target(T)


#include<bits/stdc++.h>
using namespace std;

// recursive sol
long long solveRec(int dice, int faces, int target){
    // base cases
    if(target < 0)
        return 0;
    
    if(dice == 0 && target != 0)
        return 0;
   
    if(dice != 0 && target == 0)
        return 0;
    
    if(dice == 0 && target == 0)
        return 1;
    
    long long ans = 0;
    for (int i = 1; i <= faces; i++){
        ans = ans + solveRec(dice-1, faces, target-i);
    }
    
    return ans;
}

// recursive memoization sol
long long solveMem(int dice, int faces, int target, vector<vector<long long>> &dp){
    // base cases
    if(target < 0)
        return 0;
    
    if(dice == 0 && target != 0)
        return 0;
   
    if(dice != 0 && target == 0)
        return 0;
    
    if(dice == 0 && target == 0)
        return 1;
    
    if(dp[dice][target] != -1)
        return dp[dice][target];

    long long ans = 0;
    for (int i = 1; i <= faces; i++){
        ans = ans + solveMem(dice-1, faces, target-i, dp);
    }
    
    return dp[dice][target] = ans;
}

// iterative tabulation sol
long long solveTab(int dice, int faces, int target){
    vector<vector<long long>> dp(dice+1, vector<long long>(target+1, 0));
    // analysing base cases    
   dp[0][0] = 1;
    
    for (int i = 1; i <= dice; i++){
        for(int j=1; j <= target; j++){
            long long ans = 0;
            for (int k = 1; k <= faces; k++){
                if(j-k >= 0)
                    ans = ans + dp[i-1][j-k];
            }
            dp[i][j] = ans;
        }
    }
    
    return dp[dice][target];
}

// space optimization sol
long long solve_SO(int dice, int faces, int target){
    vector<long long> curr(target+1, 0);
    vector<long long> prev(target+1, 0);
    // analysing base cases    
    prev[0] = 1;
    
    for (int i = 1; i <= dice; i++){
        for(int j=1; j <= target; j++){
            long long ans = 0;
            for (int k = 1; k <= faces; k++){
                if(j-k >= 0)
                    ans = ans + prev[j-k];
            }
            curr[j] = ans;
        }
        prev = curr;
    }
    
    return prev[target];
}


// driver function
long long noOfWays(int D, int F, int T){
// sol 1
    // return solveRec(D,F,T);
// sol 2
    // vector<vector<long long>> dp(D+1, vector<long long>(T+1, -1));
    // return solveMem(D,F,T, dp);
// sol 2
    // return solveTab(D,F,T);
// sol 2
    return solve_SO(D,F,T);
}

int main(){
    int no_of_Dices = 2,
        no_of_Faces = 6,
        target = 11;

    cout<<"Total no. of ways of making target : "<<noOfWays(no_of_Dices, no_of_Faces, target);
    return 0;
}