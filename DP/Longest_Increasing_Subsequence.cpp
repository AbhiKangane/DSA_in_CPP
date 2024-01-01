// gfg & leetcode que: finding length of longest increasing subsequence from given array
// this problem used in russian dolls question
#include<bits/stdc++.h>
using namespace std;

// recursive sol
int solveRec(int n, vector<int> &a, int curr, int prev){
    // base case
    if(curr == n)
        return 0;

    // include
    int take = 0;
    if(prev == -1 || a[curr] > a[prev])
        take = 1 + solveRec(n,a,curr+1,curr);
    
    // exclude
    int notTake = solveRec(n, a, curr+1, prev);

    return max(take, notTake);
}


// dp (recursive + memoization)
int solveMem(int n, vector<int> &a, int curr, int prev, vector<vector<int>> &dp){
    // base case
    if(curr == n)       
        return 0;

    if(dp[curr][prev+1] != -1)
        return dp[curr][prev+1];

    // include
    int take = 0;
    if(prev == -1 || a[prev] < a[curr])
        take = 1 + solveMem(n,a,curr+1,curr,dp);
    
    // exclude
    int notTake = solveMem(n, a, curr+1, prev,dp);

    return dp[curr][prev+1] = max(take, notTake);
}

// dp (tabulation)
int solveTab(int n, vector<int> &a){
    vector<vector<int>> dp(n+1, vector<int> (n+1,0));    

    for (int curr = n-1; curr >= 0; curr--){
        for (int prev = curr-1; prev >= -1; prev--){
            // include
            int take = 0;
            if(prev == -1 || a[prev] < a[curr])
                take = 1 + dp[curr+1][curr+1];
    
            // exclude
            int notTake = dp[curr+1][prev+1];
            
            dp[curr][prev+1] = max(take, notTake);
        }
    }
    return dp[0][0];
}

// dp (space optimization)
int solve_SO(int n, vector<int> &a){
    vector<int> currRow(n+1,0);    
    vector<int> nextRow(n+1,0);    

    for (int curr = n-1; curr >= 0; curr--){
        for (int prev = curr-1; prev >= -1; prev--){
            // include
            int take = 0;
            if(prev == -1 || a[prev] < a[curr])
                take = 1 + nextRow[curr+1];
    
            // exclude
            int notTake = nextRow[prev+1];
            
            currRow[prev+1] = max(take, notTake);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}

// optimal sol : 
int solve_Optimal(int n , vector<int> &a){
    if(n==0)
        return 0;
    
    vector<int> ans;
    ans.push_back(a[0]);

    for(int i=1; i<n; i++){
        if(a[i] > ans.back())
            ans.push_back(a[i]);
        
        else{
            // finding index of just greater number
            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i];
        }
    }

    return ans.size();
}


// driver function
int max_increasing_SubSequence(int n, vector<int> &a){
// sol1
    // return solveRec(n,a,0,-1);

// sol 2
    // vector<vector<int>> dp(n, vector<int>(n+1, -1));
    // return solveMem(n,a,0,-1,dp);

// sol 3
    // return solveTab(n, a);

// sol 4
    // return solve_SO(n, a);
// sol 5
    return solve_Optimal(n,a);
}

int main(){
    vector<int> a = {1,5,7,2,4,9,10};
    int n = a.size();
    // cout<<n<<endl;
    cout<<Longest_increasing_SubSequence(7,a);
}
