// given an input stream & pattern implement wildcard pattern matching with support for
// ? (matches any single character)
// * (matches sequence any single characters including empty string)
#include<iostream>
#include<vector>
using namespace std;

// recursive sol
bool solveRec(string str, string pattern, int i, int j){
    // base case
    if(i<0 && j<0)
        return true;

    if(i>=0 && j<0)
        return false;
    
    if(i<0 && j>=0){
        for (int k = 0; k <= j; k++){ // here k will traverse [pattern.size() - str.size()] times
            if(pattern[k] != '*')
                return false;
        }
        return true;
    }

    // if char matches
    if(str[i] == pattern[j] || pattern[j] == '?')
        return solveRec(str, pattern, i-1, j-1);
    
    else if(pattern[j] == '*')
        return (solveRec(str,pattern,i-1,j) || solveRec(str,pattern,i,j-1));
    
    else
        return false;
}

// recursive memoization : here dp is 0 based indexing
bool solveMem(string str, string pattern, int i, int j, vector<vector<int>> &dp){
    // base case
    if(i<0 && j<0)
        return true;

    if(i>=0 && j<0)
        return false;
    
    if(i<0 && j>=0){
        for (int k = 0; k <= j; k++){ // here k will traverse [pattern.size() - str.size()] times
            if(pattern[k] != '*')
                return false;
        }
        return true;
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    // if char matches
    if(str[i] == pattern[j] || pattern[j] == '?')
        return dp[i][j] = solveMem(str, pattern, i-1, j-1, dp);
    
    else if(pattern[j] == '*')
        return dp[i][j] = (solveMem(str,pattern,i-1,j, dp) || solveMem(str,pattern,i,j-1, dp));
    
    else
        return false;
}

// recursive memoization : here dp is 1 based indexing
bool solveMem2(string str, string pattern, int i, int j, vector<vector<int>> &dp){
    // base case
    if(i==0 && j==0)
        return true;

    if(i>0 && j==0)
        return false;
    
    if(i==0 && j>0){
        for (int k = 1; k <= j; k++){ // here k will traverse [pattern.size() - str.size()] times
            if(pattern[k-1] != '*')
                return false;
        }
        return true;
    }

    if(dp[i][j] != -1)
        return dp[i][j];

    // if char matches
    if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
        return dp[i][j] = solveMem2(str, pattern, i-1, j-1, dp);
    
    else if(pattern[j-1] == '*')
        return dp[i][j] = (solveMem2(str,pattern,i-1,j, dp) || solveMem2(str,pattern,i,j-1, dp));
    
    else
        return false;
}

// iterative tabulation : here dp is 1 based indexing
bool solveTab(string str, string pattern){
    vector<vector<int>> dp(str.size()+1, vector<int>(pattern.size()+1, 0));

    dp[0][0] = 1;

    
    for(int j=1; j<=pattern.length(); j++){
        bool flag = 1;
        for (int k = 1; k <= j; k++){ // here k will traverse [pattern.size() - str.size()] times
            if(pattern[k-1] != '*'){
                flag = 0;
                break;
            }
        }
        dp[0][j] = flag;
    }

    for (int i = 1; i <= str.size(); i++){
        for(int j=1; j<=pattern.size(); j++){
            // if char matches
            if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
                dp[i][j] = dp[i-1][j-1];
            
            else if(pattern[j-1] == '*')
                dp[i][j] = (dp[i-1][j] || dp[i][j-1]);
            
            else
                dp[i][j] = false;
        }
    }
    
    return dp[str.length()][pattern.length()];
}

// iterative space optimizaation : here dp is 1 based indexing
bool solve_SO(string str, string pattern){
    vector<int> prev(pattern.size()+1, 0);
    vector<int> curr(pattern.size()+1, 0);

    prev[0] = 1;

    
    for(int j=1; j<=pattern.length(); j++){
        bool flag = 1;
        for (int k = 1; k <= j; k++){ // here k will traverse [pattern.size() - str.size()] times
            if(pattern[k-1] != '*'){
                flag = 0;
                break;
            }
        }
        prev[j] = flag;
    }

    for (int i = 1; i <= str.size(); i++){
        for(int j=1; j<=pattern.size(); j++){
            // if char matches
            if(str[i-1] == pattern[j-1] || pattern[j-1] == '?')
                curr[j] = prev[j-1];
            
            else if(pattern[j-1] == '*')
                curr[j] = (prev[j] || curr[j-1]);
            
            else
                curr[j] = false;
        }
        prev = curr;
    }
    
    return prev[pattern.length()];
}


// driver function
bool isMatch(string s, string p){
// sol 1
    // return solveRec(s,p, s.size()-1, p.size()-1);

// sol 2.(a)
    // vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
    // return solveMem(s,p, s.size()-1, p.size()-1, dp);
// sol 2.(b)
    // vector<vector<int>> dp2(s.size()+1, vector<int>(p.size()+1, -1));
    // return solveMem2(s,p, s.size(), p.size(), dp2);

// sol 3
    // return solveTab(s,p);
// sol 4
    return solve_SO(s,p);
}


int main(){
    string s1 = "aa" , p1 = "a";
    cout<<isMatch(s1,p1)<<endl;

    string s2 = "aa" , p2 = "*";
    cout<<isMatch(s2,p2)<<endl;

    string s3 = "abc" , p3 = "**a?c";
    cout<<isMatch(s3,p3)<<endl;


}