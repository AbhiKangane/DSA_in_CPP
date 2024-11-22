//  GFG : https://www.geeksforgeeks.org/problems/replace-os-with-xs0052/1
// Given a matrix mat of size N x M where every element is either 'O' or 'X'. Replace all 'O' or a group of 'O' with 'X' that are surrounded by 'X'.
// A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below, just above, just left and just right of it.
/*
Input: 
n = 5, m = 4
mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Output: 
ans = {{'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}}
Explanation: 
Following the rule the above matrix is the resultant matrix. 
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void change(vector<vector<char>> &matrix, int x, int y){
        matrix[x][y] = '*';
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
    
        for (int i = 0; i < 4; i++){
            int cx = dx[i] + x;
            int cy = dy[i] + y;
    
            if(cx>=0 && cx<matrix.size() and cy>=0 && cy<matrix[0].size() and matrix[cx][cy] == 'O')
                change(matrix, cx, cy);
        }
    }

    vector<vector<char>> fill(int row, int col, vector<vector<char>> matrix)
    {
        for (int i = 0; i < row; i++)
            for(int j=0; j<col; j++)
            // if 'O' presents at boundary of matrix then check all directions
                if(i==0 || i==row-1 || j==0 || j==col-1)
                    if(matrix[i][j] == 'O')
                        change(matrix, i, j);
        
        for (int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(matrix[i][j] == 'O')
                    matrix[i][j] = 'X';  // actual replacing surrounding region
        
        for (int i=0; i<row; i++)
            for(int j=0; j<col; j++)
                if(matrix[i][j] == '*')
                    matrix[i][j] = 'O';  // converting back to non surroundinng region
    
        return matrix;
    }
};

// Print matrix
void Print(vector<vector<char>> matrix){
    for(auto i: matrix){
        for(auto j: i)
            cout<<j<<" ";
        cout<<endl;
    }
}


int main(){
    int t;
    cout<<"Enter the no. of testcases: ";
    cin>>t;
    while(t--){
        int n, m;
        cout<<"Enter no. of rows & col : ";
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        cout<<"Enter 'O's or 'X's into matrix : \n";
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        cout<<"Printing output matrix: \n";
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    
cout << "~" << "\n";
}
    return 0;
}
