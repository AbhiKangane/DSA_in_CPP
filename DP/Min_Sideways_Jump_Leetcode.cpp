// Here 3 lane road with n+1 points(0 to n) & at most 1 ostacle on each lane(array of obstacles[n+1] ranging from 0 to 2 over road)
// ex obstacle[2] = 1 it means there is an obstacle on lane 1 at point 2
// Frog starts from points 0 of 2nd lane wants to jump to point n
// we have to find minimum sideway jumps perform by frog to reach at point n

#include<bits/stdc++.h>
using namespace std;

// recursive sol
int solveRec(vector<int> &obstacles, int currLane, int currPos){
    // base case
    int n = obstacles.size() - 1;
    if(currPos == n)
        return 0;
    
    if(obstacles[currPos+1] != currLane)  // no obstacle in currLane at point (currPos+1)
        return solveRec(obstacles, currLane, currPos+1);

    else{
        // sideways jumps
        int ans = INT_MAX;
        for (int i = 1; i <=3; i++){ // loop for each lane
            if(currLane != i && obstacles[currPos] != i)
                ans = min(ans, 1+solveRec(obstacles, i, currPos));
        }
        return ans;
    }

}

// recursion + memoization : top down
int solveMem(vector<int> &obstacles, int currLane, int currPos, vector<vector<int>> &dp){
    // base case
    int n = obstacles.size() - 1;
    if(currPos == n)
        return 0;

    if(dp[currLane][currPos] != -1)
        return dp[currLane][currPos];
    
    if(obstacles[currPos+1] != currLane)  // no obstacle in currLane at point (currPos+1)
        return solveMem(obstacles, currLane, currPos+1, dp);

    else{
        // sideways jumps
        int ans = INT_MAX;
        for (int i = 1; i <=3; i++){ // loop for each lane
            if(currLane != i && obstacles[currPos] != i)
                ans = min(ans, 1+solveMem(obstacles, i, currPos, dp));
        }
        return dp[currLane][currPos] = ans;
    }

}

// tabulation : bottom up
int solveTab(vector<int> &obstacles){
    int n = obstacles.size() - 1;
    vector<vector<int>> dp(4, vector<int> (obstacles.size(), 1e9));

    // analysing base case : last column
    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for (int currpos = n-1; currpos>=0 ;currpos--){
        for (int currlane = 1; currlane<=3; currlane++){
            if(obstacles[currpos+1] != currlane)  // no obstacle in currLane at point (currPos+1)
                dp[currlane][currpos] = dp[currlane][currpos+1];

            else{
                // sideways jumps
                int ans = 1e9;
                for (int i = 1; i <=3; i++){ // loop for each lane
                    if(currlane != i && obstacles[currpos] != i)
                        ans = min(ans, 1+dp[i][currpos+1]);
                }
                dp[currlane][currpos] = ans;
            }
        }
    }
    
    return min(dp[2][0],(1 + min(dp[1][0], dp[3][0])));
}

// space optimization
int solve_SO(vector<int> &obstacles){
    int n = obstacles.size() - 1;
    vector<int> curr(4, 1e9);
    vector<int> next(4, 1e9);

    // analysing base case : last column
    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for (int currpos = n-1; currpos>=0 ;currpos--){
        for (int currlane = 1; currlane<=3; currlane++){
            if(obstacles[currpos+1] != currlane)  // no obstacle in currLane at point (currPos+1)
                curr[currlane] = next[currlane];

            else{
                // sideways jumps
                int ans = 1e9;
                for (int i = 1; i <=3; i++){ // loop for each lane
                    if(currlane != i && obstacles[currpos] != i)
                        ans = min(ans, 1+next[i]);
                }
                curr[currlane] = ans;
            }
        }
        next = curr;
    }
    
    return min(next[2],(1 + min(next[1], next[3])));
}

// driver function
int min_sideway_jumps(vector<int> &obstacles){
// sol 1
    // return solveRec(obstacles, 2, 0);
// sol 2
    // vector<vector<int>> dp(4, vector<int> (obstacles.size(), -1));
    // return solveMem(obstacles, 2, 0, dp);

// sol 3
    // return solveTab(obstacles);
// sol 4
    return solve_SO(obstacles);
}

int main(){
/*
        ---@---@--->--->--->
   frog --->--->---@-------
        ------->--->---@---
        0  1   2   3   4  5

        minimum sideway jumps = 2
*/
    vector<int> obstacles = {0,1,1,2,2,0};
    cout<<"Minimum sideway jumps: "<<min_sideway_jumps(obstacles);

    return 0;
}