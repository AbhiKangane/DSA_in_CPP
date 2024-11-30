/*
GFG : https://www.geeksforgeeks.org/problems/path-in-matrix3805/1

  Given a n x n matrix of positive integers. There are only three possible moves from a cell mat[r][c].
  mat[r+1] [c]
  mat[r+1] [c-1]
  mat [r+1] [c+1]
  Starting from any column in row 0 return the largest sum of any of the paths up to row n -1. Return the highest maximum path sum.
  
  Note : We can start from any column in zeroth row and can end at any column in (n-1)th row.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> mat)
    {
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<n; j++){  
                int sum = INT_MIN;
                if(j-1 >= 0)
                    sum = max(sum, mat[i+1][j-1]);
                
                sum = max(sum, mat[i+1][j]);
                
                if(j+1 < n)
                    sum = max(sum, mat[i+1][j+1]);
                
                mat[i][j] += sum;
            }
        }
        
        int ans = mat[0][0];
        for(int j=1; j<n; j++)
            ans = max(ans, mat[0][j]);
        
        return ans;
    }
};

int main(){
    int t;
    cout<<"Enter the no. of testcases : ";
    cin>>t;
    while(t--){
        int N;
        cout<<"Enter the size of matrix : ";
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        cout<<"Enter the values in matrix :\n ";
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<"Maximum path sum in given matrix is: "<<ob.maximumPath(N, Matrix)<<"\n";
    
        cout << "~" << "\n";
    }
    return 0;
}
