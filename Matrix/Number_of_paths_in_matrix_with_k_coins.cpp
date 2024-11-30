/*
GFG : https://www.geeksforgeeks.org/problems/number-of-paths-in-a-matrix-with-k-coins2728/1

Given a n x n matrix such that each of its cells contains some coins. Count the number of ways to collect exactly k coins 
while moving from top left corner of the matrix to the bottom right. From a cell (i, j), you can only move to (i+1, j) or (i, j+1).

Input:
k = 12, n = 3
arr[] = [[1, 2, 3], 
       [4, 6, 5], 
       [3, 2, 1]]
Output: 
2
Explanation: 
There are 2 possible paths with exactly 12 coins, (1 + 2 + 6 + 2 + 1) and (1 + 2 + 3 + 5 + 1).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // recursion
    long long solveRec(int i, int j, int n, int k, vector<vector<int>> &arr){
        if(i>=n || j>=n)
            return 0;
            
        if(i==n-1 && j==n-1)
            return (k-arr[i][j] == 0);
            
        if(k-arr[i][j]>=0){
          return solveRec(i+1,j,n,k-arr[i][j],arr) + solveRec(i,j+1,n,k-arr[i][j],arr);
        }
        return 0;
    }
    
    
    // memoization
    long long solveMem(int i, int j, int n, int k, vector<vector<int>> &arr, 
                        vector<vector<vector<long long>>>&dp)
    {
        if(i>=n || j>=n)
            return 0;
            
        if(i==n-1 && j==n-1)
            return (k-arr[i][j] == 0);
        
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
            
        if(k-arr[i][j]>=0){
          return dp[i][j][k] = solveMem(i+1,j,n,k-arr[i][j],arr,dp) + 
                               solveMem(i,j+1,n,k-arr[i][j],arr,dp);
        }
        return 0;
    }
    
    
    long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        // sol 1
        // return solveRec(0,0,n,k,arr);
        
        // sol 2
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(k+1,-1)));
        return solveMem(0,0,n,k,arr,dp);
    }
};

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
        
    cout << "~" << "\n";
    }
}
