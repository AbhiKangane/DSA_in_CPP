// given D dice of F faces throws & 
// we have to find the no. of ways of getting sum of numbers obtained of upper face of dice equals to target(T)


#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
    
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
        ans = (ans%mod + solveRec(dice-1, faces, target-i)%mod)%mod;
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
        ans = (ans%mod + solveMem(dice-1, faces, target-i, dp)%mod)%mod;
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
                    ans = (ans%mod + dp[i-1][j-k]%mod)%mod;
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
                    ans = (ans%mod + prev[j-k]%mod)%mod;
            }
            curr[j] = ans;
        }
        prev = curr;
    }

    return prev[target];
}


int numRollsToTarget(int dice, int faces, int target) {
    if(target < dice && target>dice*faces)
        return 0;
    
    // sol 1: recursion => Gives TLE
    // return solveRec(dice,faces,target);
    
    // sol 2: Memoization
    // vector<vector<long long>> dp(dice+1, vector<long long>(target+1, -1));
    // return solveMem(dice,faces,target,dp);
    
    // sol 3: Tabulation
    // return solveTab(dice,faces,target);
    
    // sol 4: Space Optimization
    return solve_SO(dice,faces,target);
}

int main(){
    int no_of_Dices = 2,
        no_of_Faces = 6,
        target = 11;

    cout<<"Total no. of ways of making target : "<<numRollsToTarget(no_of_Dices, no_of_Faces, target);
    return 0;
}
