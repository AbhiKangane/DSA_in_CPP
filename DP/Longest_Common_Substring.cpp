/*
Given two strings. The task is to find the length of the longest common substring.

Input: S1 = "ABCDGH", S2 = "ACDGHR", n = 6, m = 6
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4.
*/

#include<bits/stdc++.h>
using namespace std;

// sol 1: Recursion : Gives TLE
int SolveRec(string S1, string S2, int i, int j, int count){
    // base case
    if (i == 0 || j == 0)
        return count;

    // If characters match, increment count and recursively call function
    if (S1[i - 1] == S2[j - 1]) {
        count = SolveRec(S1,S2, i-1, j-1, count+1);
    }
    
    // Explore options by recursively calling function with different indices and reset count
    int res = max(count, max(SolveRec(S1,S2, i,j-1, 0),SolveRec(S1,S2, i-1,j, 0)));
    
    return res;
}

// sol 2: recursive memoization : It also Gives TLE?
int SolveMem(string S1, string S2, int i, int j, int count, unordered_map<string,int> &mp){

    if (i == 0 || j == 0)
        return count;
    
    string key = to_string(i)+"for"+to_string(j)+"key"+to_string(count);
    
    if(mp[key] != 0)
        return mp[key];

    if (S1[i-1] == S2[j-1]) {
        count = SolveMem(S1,S2, i-1,j-1, count+1, mp);
    }
    
    int res = max(count, max(SolveMem(S1,S2, i,j-1, 0,mp), SolveMem(S1,S2, i-1,j, 0,mp)));
    
    mp[key] = res;
    
    return res;
}


// Sol 3: Iterative Tabulation
int SolveTab (string S1, string S2, int m, int n){
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    int result = 0;
    
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){

            if (S1[i - 1] == S2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                result = max(result, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return result;
}

// Sol 4: Iterative Tabulation + Space Optimization
int Solve_SO (string &S1, string &S2, int m, int n){
    vector<int> curr(n+1,0), prev(n+1,0);
    int result = 0;
    
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){

            if (S1[i - 1] == S2[j - 1]) {
                curr[j] = prev[j - 1] + 1;
                result = max(result, curr[j]);
            }
            else
                curr[j] = 0;
        }
        prev = curr;
    }
    return result;
}


int longestCommonSubstr (string s1, string s2, int m, int n)
{
    // sol 1
    // return SolveRec(s1,s2,m,n,0);
    
    // sol 2 : for memoization we need 3D DP matrix
    // hence here use map<key, count> 
    // unordered_map<string, int> mp;
    // return SolveMem(s1,s2,m,n,0, mp);
    
    // sol 3
    // return SolveTab(s1,s2,m,n);
    
    // sol 3
    return Solve_SO(s1,s2,m,n);
}


int main(){
    string s1="ABCDEFGH", s2 = "BCDAEFGABC";
    cout<<longestCommonSubstr(s1,s2, s1.size(), s2.size());

    return 0;
}