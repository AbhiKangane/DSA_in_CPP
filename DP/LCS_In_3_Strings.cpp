// Given 3 strings A, B and C, the task is to find the length of the longest sub-sequence that is common in all the three given strings.

#include<bits/stdc++.h>
using namespace std;

// recursive sol
int solveRec(string &a, string &b, string &c, int i, int j, int k){
    // base case
    if(i == a.size())
        return 0;
    if(j == b.size())
        return 0;
    if(k == c.size())
        return 0;
    
    int ans = 0;
    if(a[i] == b[j] && a[i]==c[k])
        ans = 1 + solveRec(a,b,c,i+1,j+1,k+1);
    
    else if(a[i]==b[j])
        ans = max(solveRec(a,b,c,i+1,j+1,k), solveRec(a,b,c,i,j,k+1));
    
    else if (a[i]==c[k])
        ans = max(solveRec(a,b,c,i+1,j,k+1), solveRec(a,b,c,i,j+1,k));
    
    else 
        ans = max(solveRec(a,b,c,i,j+1,k+1), solveRec(a,b,c,i+1,j,k));
    
    return ans;
}


// Memoization sol
int solveMem(string &a, string &b, string &c, int i, int j, int k, 
            vector<vector<vector<int>>> &dp){
    // base case
    if(i == a.size())
        return 0;
    if(j == b.size())
        return 0;
    if(k == c.size())
        return 0;
        
    if(dp[i][j][k] != -1)
        return dp[i][j][k];
    
    int ans = 0;
    if(a[i] == b[j] && a[i]==c[k])
        ans = 1 + solveMem(a,b,c,i+1,j+1,k+1,dp);
    
    else if(a[i]==b[j])
        ans = max(solveMem(a,b,c,i+1,j+1,k,dp), solveMem(a,b,c,i,j,k+1,dp));
    
    else if (a[i]==c[k])
        ans = max(solveMem(a,b,c,i+1,j,k+1,dp), solveMem(a,b,c,i,j+1,k,dp));
    
    else 
        ans = max(solveMem(a,b,c,i,j+1,k+1,dp), solveMem(a,b,c,i+1,j,k,dp));
    
    return dp[i][j][k] = ans;
}


// Tabulation
int solveTab (string a, string b, string c, int n1, int n2, int n3){
    vector<vector<vector<int>>> dp(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1,0)));
    
    for(int i=n1-1; i>=0; i--){
        for(int j=n2-1; j>=0; j--){
            for(int k=n3-1; k>=0; k--){
                int ans = 0;
                if(a[i] == b[j] && a[i]==c[k])
                    ans = 1 + solveMem(a,b,c,i+1,j+1,k+1,dp);
                
                else if(a[i]==b[j])
                    ans = max(solveMem(a,b,c,i+1,j+1,k,dp), solveMem(a,b,c,i,j,k+1,dp));
                
                else if (a[i]==c[k])
                    ans = max(solveMem(a,b,c,i+1,j,k+1,dp), solveMem(a,b,c,i,j+1,k,dp));
                
                else 
                    ans = max(solveMem(a,b,c,i,j+1,k+1,dp), solveMem(a,b,c,i+1,j,k,dp));
                
                dp[i][j][k] = ans;
            }
        }
    }
    return dp[0][0][0];
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // return solveRec(A,B,C,0,0,0);
    
    // vector<vector<vector<int>>> dp(n1, vector<vector<int>>(n2, vector<int>(n3,-1)));
    // return solveMem(A,B,C,0,0,0,dp);
    
    return solveTab(A,B,C,n1,n2,n3);
}


int main(){
    string  A = "geeks",
            B = "abcgeeksfor", 
            C = "efgthggeeksforgeeks";
    
    cout<<LCSof3(A,B,C, A.size(), B.size(), C.size()); // 5 => "geeks"
    
    return 0;
}