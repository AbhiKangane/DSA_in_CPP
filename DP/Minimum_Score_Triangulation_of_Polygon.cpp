#include<bits/stdc++.h>
using namespace std;

// recursive sol
int solveRec(vector<int> &v, int first, int last){
    // it will be make a line or single edge
    if(first+1 == last)
        return 0;

    int ans = INT_MAX;
    for (int k = first+1; k<last; k++){
        ans = min(ans, v[first]*v[k]*v[last] + solveRec(v,first,k) + solveRec(v,k,last));
    }
    return ans;
}

// recursion + memoization
int solveMem(vector<int> &v, int first, int last, vector<vector<int>> &dp){
    // it will be make a line or single edge
    if(first+1 == last)
        return 0;

    if(dp[first][last] != -1)
        return dp[first][last];

    int ans = INT_MAX;
    for (int k = first+1; k<last ;k++){
        ans = min(ans, v[first]*v[k]*v[last] + solveMem(v,first,k,dp) + solveMem(v,k,last,dp));
    }

    return dp[first][last] = ans;
}


// tabulation
int solveTab(vector<int> &v){
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(n,0));
    

    for (int i = n-1; i>=0; i--){
        for (int j = i+2; j < n; j++){ // here j started from i+2 because from this we can make triangles

            int ans = INT_MAX;
            for (int k = i+1; k<j ;k++){
                ans = min(ans, v[i]*v[k]*v[j] + dp[i][k] + dp[k][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n-1];
}



// driver function
int min_triangulation_of_Polygon(vector<int> &values){
    int n = values.size();
// sol 1
    // return solveRec(values,0,n-1);

// sol 2
    // vector<vector<int>> dp(n,vector<int> (n,-1));
    // return solveMem(values,0,n-1,dp);

// sol 3
    return solveTab(values);
}

int main(){
    // here array values are in clockwise order
    vector<int> values = {1,2,3,4};
/*
    4 -------- 3
    |        / |
    |     /    |        => (1*2*3) + (1*4*3) = 18
    |  /       |
    1 -------- 2
*/
    cout<<min_triangulation_of_Polygon(values);
}