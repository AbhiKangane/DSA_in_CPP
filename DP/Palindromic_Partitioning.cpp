// GFG Problem : Determine minimum cuts required for palindromic partitioning of given string.      
// Given string str, a partitioning of the string is a palindromic partitioning if every substring of partition is palindrome.

#include<iostream>
#include<vector>
using namespace std;

// checking sub-string is palindrome or not
bool isPalindrome(string &str, int i, int j){
    while(i<j){
        if(str[i] == str[j]){
            i++; j--;
        }
        else 
            return false;
    }
    return 1;    
} 

// recursive sol
int solveRec(string str, int i, int n){
    if(i==n)    return 0;

    int res = INT32_MAX;
    for(int j=i; j<n; j++){
        if(isPalindrome(str,i,j)){
            int cost = 1 + solveRec(str, j+1, n);
            res = min(res, cost);
        }
    }
    return res;
}

// memoization
int solveMem(string str, int i, int n, vector<int> &dp){
    if(i==n)    return 0;

    if(dp[i] != -1)
        return dp[i]; 

    int res = INT32_MAX;
    for(int j=i; j<n; j++){
        if(isPalindrome(str,i,j)){
            int cost = 1 + solveMem(str, j+1, n, dp);
            res = min(res, cost);
        }
    }
    return dp[i] = res;
}

// iterative tabulation
int solveTab(string str, int n){
    vector<int> dp(n+1, 0);

    for(int i=n-1; i>=0; i--){
        int res = INT32_MAX;
        for(int j=i; j<n; j++){
            if(isPalindrome(str,i,j)){
                int cost = 1 + dp[j+1];
                res = min(res, cost);
            }
        }
        dp[i] = res;
    }

    return dp[0];
}


int minCuts(string s){
    int n = s.size();
    // sol 1 : Recursive sol
    // return solveRec(s, 0, n) - 1;

    // sol 2 : Memoization sol
    // vector<int> dp(n, -1);
    // return solveMem(s,0,n, dp) - 1;

    // sol 3 : Tabulation
    return solveTab(s, n) - 1;
}

int main(){
    string str = "ababbbabbababa"; // a babbbab b ababa  && ans = 3
    string s = "abcdcba";   // ans = 0
    cout<<minCuts(str);  
}