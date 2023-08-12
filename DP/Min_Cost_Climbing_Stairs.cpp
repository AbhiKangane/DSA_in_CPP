#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// recursive sol
int solve1(vector<int> &cost, int n){
    // base case
    if(n==0)
        return cost[0];
    
    if(n==1)
        return cost[1];
    
    // top to down
    int ans = cost[n] + min(solve1(cost, n-1), solve1(cost, n-2));

    return ans; 
}

// DP( recursion + memoization => top-down approach)
int solve2(vector<int> &cost, int n, vector<int> &dp){
    // step 1: base case
    if(n==0)
        return cost[0];
    
    if(n==1)
        return cost[1];
    
    // step 3
    if(dp[n] != -1)
        return dp[n];

    // step 2
    dp[n] = cost[n] + min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));

    return dp[n]; 
}

// DP( iterative + tabulation => bottom-up approach)
int solve3(vector<int> &cost, int n){
    // step 1: creating a dp array
    vector<int> dp(n+1);

    // step 2: base case analysis
    dp[0] = cost[0];
    dp[1] = cost[1];

    // step 3: iterative updation
    for (int i = 2; i < n; i++){
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]); 
    }
    
    return min(dp[n-1], dp[n-2]); 
}


// DP( space optimization => using variables)
int solve4(vector<int> &cost, int n){
    // creating variables
    int prev2 = cost[0];
    int prev1 = cost[1];

    // step 3: iterative updation
    for (int i = 2; i < n; i++){
        int curr = cost[i] + min(prev1, prev2);
        // shifting variables
        prev1 = curr;
        prev2 = prev1;
    }
    
    return min(prev1, prev2);
}




// driver function
int minCostClimbingStairs(vector<int> &cost){
    int n = cost.size();
    if(n == 0)      return 0;
    

// sol 1:
// for last(nth) stair we not includes its weight
    // else if(n==1)   return cost[0];
    // int ans = min(solve1(cost, n-1), solve1(cost, n-2));


// sol 2:
    // vector<int> dp(n+1, -1);
    // int ans = min(solve2(cost, n-1, dp), solve2(cost, n-2, dp));
    
// sol 3:
    // int ans = solve3(cost, n);
    
// sol 4:
    int ans = solve4(cost, n);
    return ans;
}

int main(){
    vector<int> cost = {10,130, 12};

    cout<<"Minimum Cost of Climbing Stairs: "<<minCostClimbingStairs(cost);
    return 0;
}