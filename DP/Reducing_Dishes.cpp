// Given each dish requires 1 unit time.
// satisfaction[] gives satisfaction associated with each dish
// total satisfaction = sum of all products of satisfaction[index] * time required

//  This problem is a variation of knapSack problem
#include<bits/stdc++.h>
using namespace std;

// recursive sol
int solveRec(vector<int> &satisfaction, int index, int time){
    // base case
    if(index == satisfaction.size())
        return 0;
    
    int include = satisfaction[index] * (time+1) + solveRec(satisfaction, index+1, time+1);
    int exclude = solveRec(satisfaction, index+1, time);

    return max(include, exclude);
}

// recursion + memoization
int solveMem(vector<int> &satisfaction, int index, int time, vector<vector<int>> &dp){
    // base case
    if(index == satisfaction.size())
        return 0;
    
    if(dp[index][time] != -1)
        return dp[index][time];

    int include = satisfaction[index] * (time+1) + solveMem(satisfaction,index+1,time+1,dp);
    int exclude = solveMem(satisfaction, index+1, time, dp);

    return dp[index][time] = max(include, exclude);
}

// tabulation
int solveTab(vector<int> &satisfaction){
    int n = satisfaction.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    for (int index = n-1; index >=0; index--){
        for(int time=index; time>=0; time--){
            int include = satisfaction[index] * (time+1) + dp[index+1][time+1];
            int exclude = dp[index+1][time];

            dp[index][time] = max(include, exclude);
        }
    }
    return dp[0][0];
}

// space optimization
int solve_SO(vector<int> &satisfaction){
    int n = satisfaction.size();
    vector<int> curr(n+1, 0);
    vector<int> next(n+1, 0);
    
    for (int index = n-1; index >=0; index--){
        for(int time=index; time>=0; time--){
            int include = satisfaction[index] * (time+1) + next[time+1];
            int exclude = next[time];

            curr[time] = max(include, exclude);
        }
        next = curr;
    }
    return next[0];
}

// driver function
int maxSatisfaction(vector<int> &satisfaction){
    int n = satisfaction.size();
// sort the satisfaction vector
    sort(satisfaction.begin(), satisfaction.end());

// sol 1
    // return solveRec(satisfaction, 0, 0);

// sol 2
    // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    // return solveMem(satisfaction, 0, 0, dp);

// sol 3
    // return solveTab(satisfaction);

// sol 4
    return solve_SO(satisfaction);
}


int main(){
    vector<int> satisfaction = {1,-12, -2, 7, 2};  
    // after sorting = {-12, -2, 1, 2, 7} 
    // => (-12*0) + (-2*1) + (1*2) + (2*3) + (4*7)   // here -12 is reduced
    // => -2 + 2 + 6 + 28 = 34
    cout<<maxSatisfaction(satisfaction);
    return 0;
}