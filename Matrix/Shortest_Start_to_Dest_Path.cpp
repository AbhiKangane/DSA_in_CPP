/*
GFG: https://www.geeksforgeeks.org/problems/shortest-source-to-destination-path3544/1
Given a 2D binary matrix A(0-based index) of dimensions N x M. 
Find the minimum number of steps required to reach from (0,0) to (X, Y).
Note: You can only move left, right, up and down, and only through cells that contain 1.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // sol 1 : accepted
    int shortestDistance(int N, int M, vector<vector<int>> grid, int X, int Y) {
        // base cases
        if(grid[0][0] == 0)     return -1;
        if(X == 0 && Y == 0)    return 0;
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{0,0}});  // (distance, (from,to))
        
        vector<vector<int>> dist(N,vector<int>(M,INT_MAX));
        dist[0][0] = 0;
        
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        
        // performing BFS
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int from = it.second.first;
            int to = it.second.second;
            int dis = it.first;
            
            for(int i = 0; i < 4; i++)
            {
                int nrow = from + dr[i];
                int ncol = to + dc[i];
                // check validity & new distace is less than prev distance
                if(nrow>=0 && nrow<N && ncol>=0 && ncol<M &&
                   grid[nrow][ncol] == 1 && dis+1 < dist[nrow][ncol])
                {
                    if(nrow == X && ncol == Y)
                        return dis+1;
                    dist[nrow][ncol] = 1+dis;       // update distance
                    q.push({1+dis,{nrow,ncol}});    // pushing neighbour
                }
            }
        }
        return -1;
    }

    // sol 2 : TLE
    // solution from Rat in Maze problem
    void findAllPaths(int row, int col, int n, int m, int X, int Y, vector<vector<int>>&maze, string path, int &ans)
    {
        if(row<0 || row>=n || col<0 || col>=m || maze[row][col]==0)
            return;
        
        if(row==X && col==Y){
            int sz = path.size();
            ans = min(ans, sz);
            return;
        }

        maze[row][col] = 0;
        findAllPaths(row+1, col, n, m, X, Y, maze, path+"D", ans);
        findAllPaths(row, col-1, n, m, X, Y, maze, path+"L", ans);
        findAllPaths(row, col+1, n, m, X, Y, maze, path+"R", ans);
        findAllPaths(row-1, col, n, m, X, Y, maze, path+"U", ans);
        maze[row][col] = 1;

        return ;
    }

    
    int shortestDistance2(int N, int M, vector<vector<int>> maze, int X, int Y) {
        string path = "";
        int ans=INT_MAX;
        findAllPaths(0,0,N,M,X,Y,maze,path,ans);
        
        return ans==INT_MAX ? -1 : ans;
    }
};

int main() {
/*
Example:
N=3, M=4
A=[[1,0,0,0], 
   [1,1,0,1],
   [0,1,1,1]]
X=2, Y=3 
Output:
5
*/

    int t;
    cout<<"Enter no. of testcases: ";
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cout<<"\nEnter N & M: ";
        cin >> N >> M;
        vector<vector<int>> grid(N, vector<int>(M));
        cout<<"Enter values in the matrix:\n";
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) 
                cin >> grid[i][j];
        cout<<"Enter destination cell Coordinates: ";
        cin >> x >> y;
        Solution ob;
        cout<<"Minimum no. of steps required to reach dest from start: "<<ob.shortestDistance(N,M,grid,x,y)<<"\n";
    }
}
