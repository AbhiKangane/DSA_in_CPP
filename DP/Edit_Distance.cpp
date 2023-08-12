// given two strings word1 & word2 AND return minimum of operations required to convert word1 to word2
// you have 3 operations: inserting, deleting and replacing a char

#include<bits/stdc++.h>
using namespace std;

// recursive sol
int solve_Rec(string &a, string &b, int i, int j){
    // base case
    if(i == a.size())       return b.size() - j;  // if(a.size() < b.size())
    if(j == b.size())       return a.size() - i;  // if(a.size() > b.size())

    int ans = 0;
    if(a[i] == b[j])        return solve_Rec(a,b,i+1,j+1);

    else{
        int insertAns  = 1 + solve_Rec(a,b,i,j+1); // here b[j] char matched hence j+1, while i remains same
        int deleteAns  = 1 + solve_Rec(a,b,i+1,j); // here a[i] char not matched hence i+1, while j remains same
        int replaceAns = 1 + solve_Rec(a,b,i+1,j+1); // here both char will matched after replace

        ans = min(insertAns, min(deleteAns, replaceAns));
    }
    return ans;
}

// recursive memoization sol
int solveMem(string &a, string &b, int i, int j, vector<vector<int>> &dp){
    // base case
    if(i == a.size())       return b.size() - j;  // if(a.size() < b.size())
    if(j == b.size())       return a.size() - i;  // if(a.size() > b.size())

    if(dp[i][j] != -1)      return dp[i][j];

    int ans = 0;
    if(a[i] == b[j])        return solveMem(a,b,i+1,j+1,dp);

    else{
        int insertAns  = 1 + solveMem(a,b,i,j+1,dp); // here b[j] char matched hence j+1, while i remains same
        int deleteAns  = 1 + solveMem(a,b,i+1,j,dp); // here a[i] char not matched hence i+1, while j remains same
        int replaceAns = 1 + solveMem(a,b,i+1,j+1,dp); // here both char will matched after replace

        ans = min(insertAns, min(deleteAns, replaceAns));
    }
    return dp[i][j] = ans;
}

// iterative tabulation sol
int solveTab(string &a, string &b){
    vector<vector<int>> dp(a.size()+1, vector<int>(b.size()+1, 0));
    // for last row
    for (int j = 0; j < b.size(); j++){
        dp[a.size()][j] = b.size()-j;
    }
    // for last col
    for (int i = 0; i < a.size(); i++){
        dp[i][b.size()] = a.size()-i;
    }    

    for (int i = a.size()-1; i>=0; i--){
        for(int j = b.size()-1; j>=0; j--){
            int ans = 0;
            if(a[i] == b[j])
                ans = dp[i+1][j+1];

            else{
                int insertAns  = 1 + dp[i][j+1]; // here b[j] char matched hence j+1, while i remains same
                int deleteAns  = 1 + dp[i+1][j]; // here a[i] char not matched hence i+1, while j remains same
                int replaceAns = 1 + dp[i+1][j+1]; // here both char will matched after replace

                ans = min(insertAns, min(deleteAns, replaceAns));
            }
            dp[i][j] = ans;
        } 
    }
    
    return dp[0][0];    
}

// space optimization sol
int solve_SO(string &a, string &b){
    vector<int> curr(b.size()+1, 0);
    vector<int> next(b.size()+1, 0);


    // for last row
    for (int j = 0; j < b.size(); j++){
        next[j] = b.size()-j;
    }

    for (int i = a.size()-1; i>=0; i--){
        for(int j = b.size()-1; j>=0; j--){
            // base case -> for last col
            curr[b.size()] = a.size() - i;

            int ans = 0;
            if(a[i] == b[j])
                ans = next[j+1];

            else{
                int insertAns  = 1 + curr[j+1]; // here b[j] char matched hence j+1, while i remains same
                int deleteAns  = 1 + next[j]; // here a[i] char not matched hence i+1, while j remains same
                int replaceAns = 1 + next[j+1]; // here both char will matched after replace

                ans = min(insertAns, min(deleteAns, replaceAns));
            }
            curr[j] = ans;
        } 
        next = curr;
    }
    
    return next[0];    
}

// driver sol
int edit_Distance(string a, string b){
    // case 1
    if(a.size() == 0)       return b.size();
    if(b.size() == 0)       return a.size();


// sol 1
    // return solve_Rec(a,b,0,0);

// sol 2
    // vector<vector<int>> dp(a.size(), vector<int>(b.size(), -1));
    // return solveMem(a,b,0,0,dp);

// sol 3
    // return solveTab(a,b);

// sol 4
    return solve_SO(a,b);
}

int main(){
    string a = "horse";
    string b = "ros";

    cout<<edit_Distance(a, b); // 3
}