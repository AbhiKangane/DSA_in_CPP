#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// GFG Problem of printing paths(in directions ex: DDRDR) for rat
class Solution{
    // Solution 1 starts
    private:
    bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> maze){
        if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y] == 0 && maze[x][y] == 1) 
            return true;
        return false;
    }

    void solve1(vector<vector<int>> &maze, int n, vector<string> &ans, int x, int y, vector<vector<int>> visited, string path){
        // rat is reached (x,y) cell

        // base case
        if(x == n-1 && y == n-1){
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;
        // 4 directions : D, L, U, P

        // 1: down
        int newX = x+1, newY = y;
        if(isSafe(newX, newY, n , visited, maze)){
            path.push_back('D');
            solve1(maze,n,ans,newX,newY,visited,path);
            path.pop_back(); // for finding new path we have clear previous path
        }

        // 2: left
        newX = x, newY = y-1;
        if(isSafe(newX, newY, n , visited, maze)){
            path.push_back('L');
            solve1(maze,n,ans,newX,newY,visited,path);
            path.pop_back(); // for finding new path we have clear previous path
        }

        // 3: up
        newX = x-1, newY = y;
        if(isSafe(newX, newY, n , visited, maze)){
            path.push_back('U');
            solve1(maze,n,ans,newX,newY,visited,path);
            path.pop_back(); // for finding new path we have clear previous path
        }

        // 4: right
        newX = x, newY = y+1;
        if(isSafe(newX, newY, n , visited, maze)){
            path.push_back('R');
            solve1(maze,n,ans,newX,newY,visited,path);
            path.pop_back(); // for finding new path we have clear previous path
        }

        visited[x][y] = 0;
    }

    public:
    // solution 1
    vector<string> findPath1(vector<vector<int>> &maze, int n ){
        vector<string> ans;
        if(maze[0][0] == 0  || maze[n-1][n-1] == 0){
            return ans; //empty vector
        }

        int srcX = 0, srcY = 0;
        vector<vector<int>> visited = maze; // creating 2D array
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                visited[i][j] = 0; // initializing with 0
            
        string path = "";
        solve1(maze,n,ans,srcX,srcY,visited,path);
        sort(ans.begin(), ans.end());

        return ans;
    }
    // solution 1 ends

    // solution 2 starts
    void allPaths(int row, int col, int n, vector<vector<int>>&maze, string ans, vector<string> &res){
        if(row<0 || row>=n || col<0 || col>=n || maze[row][col]==0)
            return;
        
        if(row==n-1 && col==n-1){
            res.push_back(ans);
            return;
        }

        maze[row][col] = 0;
        allPaths(row+1, col, n, maze, ans+"D", res);
        allPaths(row, col-1, n, maze, ans+"L", res);
        allPaths(row, col+1, n, maze, ans+"R", res);
        allPaths(row-1, col, n, maze, ans+"U", res);
        maze[row][col] = 1;

        return ;
    }

    vector<string> findPath2(vector<vector<int>> &maze, int n ){
        vector<string> res;
        string ans = "";
        allPaths(0,0,n,maze,ans,res);
        sort(res.begin(),res.end());

        return res;
    }
    // end of solution 2
};

// solution 2
bool isSafe(int **arr, int x, int y, int n){
    if(x<n && y<n && arr[x][y] == 1)
        return true;
    return false;
}

bool ratInMaze(int **arr, int x, int y, int n, int **SolArray){
    // base condition
    if(x == n-1 && y == n-1){
        SolArray[x][y] = 1;
        return true;
    }

    if(isSafe(arr,x,y,n)){
        SolArray[x][y] = 1;
        
        if(ratInMaze(arr,x+1,y,n,SolArray)) // moving same row in rightwards
            return true;

        if(ratInMaze(arr,x,y+1,n,SolArray)) // moving same column in downwards
            return true;

        SolArray[x][y] = 0; // backtracking
        return false;
    }
    return false;
}



int main(){

    // int n;
    // cout<<"Enter side of maze: ";
    // cin>>n;

    // input           output(ans)         // here 0 stands for blockages
    // 1,1,0,1,0       1,1,0,0,0
    // 0,1,1,1,0       0,1,1,1,0
    // 1,0,0,1,0  =>   0,0,0,1,0
    // 1,1,0,1,1       0,0,0,1,1
    // 0,1,0,0,1       0,0,0,0,1


    // cout<<"Enter the input mazerix: "<<endl;
    // int **arr = new int*[n];
    // for(int i=0; i<n; i++)
    //     arr[i] = new int[n];
    
    // for(int i=0; i<n; i++)
    //     for(int j=0; j<n; j++)
    //         cin>>arr[i][j];

    // int **SolArr = new int*[n];
    // for(int i=0; i<n; i++){
    //     SolArr[i] = new int[n];
    //     for(int j=0; j<n; j++)
    //         SolArr[i][j] = 0;
    // }

    // // solution 2
    // ratInMaze(arr, 0, 0, n, SolArr);
    // cout<<"After finding path: "<<endl;
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++)
    //         cout<<SolArr[i][j]<<" ";
    //     cout<<endl;
    // }

    vector<vector<int>> maze = {{1,0,0,0},
                                {1,1,0,1},
                                {1,1,0,0},
                                {0,1,1,1}};
    Solution s;
    vector<string> ans = s.findPath2(maze, 4);

    cout<<"Paths for rat in given maze: "<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}
