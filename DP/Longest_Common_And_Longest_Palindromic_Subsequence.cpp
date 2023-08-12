#include<bits/stdc++.h>
using namespace std;

// recursive sol
int solveRec(string &a, string &b, int i, int j){
    // base case
    if(i == a.size())
        return 0;
    if(j == b.size())
        return 0;
    
    int ans = 0;
    if(a[i] == b[j])
        ans = 1 + solveRec(a,b,i+1,j+1);
    else
        ans = max(solveRec(a,b,i+1,j), solveRec(a,b,i,j+1));
    
    return ans;
}

// recursive memoization
int solveMem(string &a, string &b, int i, int j, vector<vector<int>> &dp){
    // base case
    if(i == a.size())
        return 0;
    if(j == b.size())
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int ans = 0;
    if(a[i] == b[j])
        ans = 1 + solveMem(a,b,i+1,j+1,dp);
    else
        ans = max(solveMem(a,b,i+1,j,dp), solveMem(a,b,i,j+1,dp));
    
    return dp[i][j] = ans;
}

// tabulation
int solveTab(string &a, string &b){
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 0));

    for(int i = a.size()-1; i>=0; i--){
        for (int j = b.size()-1; j>=0; j--){
            int ans = 0;
            if(a[i] == b[j])
                ans = 1 + dp[i+1][j+1];
            else
                ans = max(dp[i+1][j], dp[i][j+1]);
            
            dp[i][j] = ans;
        }
    }
    
    return dp[0][0];    
}

// space optimization
int solve_SO(string &a, string &b){
    vector<int> curr(b.size() + 1, 0);
    vector<int> next(b.size() + 1, 0);

    for(int i = a.size()-1; i>=0; i--){
        for (int j = b.size()-1; j>=0; j--){
            int ans = 0;
            if(a[i] == b[j])
                ans = 1 + next[j+1];
            else
                ans = max(next[j], curr[j+1]);
            
            curr[j] = ans;
        }
        next = curr;
    }
    
    return next[0];    
}


// driver function for longest common Subsequence
int longestCommonSubsequence(string & str1, string &str2){
// sol 1
    // return solveRec(str1,str2,0,0);

// sol 2
    // vector<vector<int>> dp(str1.size(), vector<int>(str2.size(), -1));
    // return solveMem(str1,str2,0,0,dp);

// sol 3
    // return solveTab(str1, str2);

// sol 4
    return solve_SO(str1, str2);
}


// driver function for longest palindromic Subsequence
int longest_Palindromic_Subsequence(string s){
    string revStr = s;
    reverse(revStr.begin(), revStr.end());
    
    return solve_SO(s, revStr);
}


int main(){
    string str1 = "Abhishek",
           str2 = "Abhinav";

    string str = "daabbbaac"; // longest_Palindromic_Subsequence = 7
    cout<<"Longest Common Subsequence : "<<longestCommonSubsequence(str1,str2)<<endl;
    cout<<"Longest palindromic Subsequence : "<<longest_Palindromic_Subsequence(str)<<endl;
}