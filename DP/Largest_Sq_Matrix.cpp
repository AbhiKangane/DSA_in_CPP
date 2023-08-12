// given binary matrix(n*m), find maximum size of square sub-matrix with all 1s
#include<bits/stdc++.h>
using namespace std;

// recursive sol
int solveRec(vector<vector<int>> &mat, int i, int j, int &maxi){
    if(i>=mat.size() || j>=mat[0].size())
        return 0;
    
    int right = solveRec(mat,i,j+1,maxi);
    int diagonal = solveRec(mat,i+1,j+1,maxi);
    int down = solveRec(mat,i+1,j,maxi);

    if(mat[i][j] == 1){
        int ans = 1 + min(right, min(diagonal,down));
        maxi = max(maxi,ans);
        return ans;
    }
    else
        return 0;
}

// recursion + memoization
int solveMem(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp){
    if(i>=mat.size() || j>=mat[0].size())
        return 0;
    
    if( dp[i][j] != -1)
        return  dp[i][j];

    int right = solveMem(mat,i,j+1,maxi,dp);
    int diagonal = solveMem(mat,i+1,j+1,maxi,dp);
    int down = solveMem(mat,i+1,j,maxi,dp);

    if(mat[i][j] == 1){
        dp[i][j] = 1 + min(right, min(diagonal,down));
        maxi = max(maxi, dp[i][j]);
        return  dp[i][j];
    }
    else
        return  dp[i][j] = 0;
}

// tabulation
int solveTab(vector<vector<int>> &mat, int &maxi){
    int row = mat.size(), col = mat[0].size();

    vector<vector<int>> dp(row+1, vector<int>(col+1, 0));
    
    for (int i = row-1; i>=0; i--){
        for (int j = col-1; j>=0; j--){
            int right = dp[i][j+1];
            int diagonal = dp[i+1][j+1];
            int down = dp[i+1][j];

            if(mat[i][j] == 1){
                dp[i][j] = 1 + min(right, min(diagonal,down));
                maxi = max(maxi, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    
    return dp[0][0];
}

// tabulation
int solve_SO(vector<vector<int>> &mat, int &maxi){
    int row = mat.size(), col = mat[0].size();

    vector<int> currRow(col+1, 0);
    vector<int> nextRow(col+1, 0);    
    
    for (int i = row-1; i>=0; i--){
        for (int j = col-1; j>=0; j--){
            int right = currRow[j+1];
            int diagonal = nextRow[j+1];
            int down = nextRow[j];

            if(mat[i][j] == 1){
                currRow[j] = 1 + min(right, min(diagonal,down));
                maxi = max(maxi,currRow[j]);
            }
            else
                currRow[j] = 0;
        }
        nextRow = currRow;
    }
    
    return currRow[0];
}

// driver function
int largest_sq_mat(int n, int m, vector<vector<int>> &mat){
    int maxi = 0;
// sol 1
    // solveRec(mat, 0,0, maxi);

// sol 2
    // vector<vector<int>> dp(n, vector<int> (m, -1));
    // solveMem(mat, 0,0, maxi, dp);
    
// sol 3 
    // solveTab(mat,maxi);
    
// sol 4 
    solve_SO(mat,maxi);
    
    return maxi;
}


int main(){
    vector<vector<int>> matrix = {{0,0,0,0},
                                  {1,1,1,1},
                                  {1,1,1,1},
                                  {0,1,1,1}};
    int n = matrix.size();
    int m = matrix[0].size();
    cout<<"Maximum size of square sub-matrix with all 1's: "<<largest_sq_mat(n,m, matrix);  // 3

    return 0;
}