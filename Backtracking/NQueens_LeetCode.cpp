// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<char>> &board, int x, int y, int n){
    for(int row=0; row<x; row++) // checking in same row
        if(board[row][y] == 'Q')
            return false;

    int row = x, col = y;
    while(row>=0 && col>=0){  // checking left upper diagonal
        if(board[row][col] == 'Q')
            return false;
        
        row--; col--; 
    }

    row=x, col=y;
    while(row>=0 && col<n){ // checking for in right upper diagonal
        if(board[row][col] == 'Q')
            return false;

        row--; col++;
    }
    return true;
}

// Function to convert char board[] to string
vector<string> populate(vector<vector<char>> &board, int n){
    vector<string> ans;
    for(int i=0; i<n; i++){
        string temp = "";
        for(int j=0; j<n; j++){
            temp += board[i][j];
        }
        ans.push_back(temp);
    }
    return ans;
}

// recursive helper function for finding solutions
void helper(vector<vector<char>> &board, int curr_row, int n, vector<vector<string>> &ans){
    if(curr_row == n){
        vector<string> temp = populate(board,n);
        ans.push_back(temp);
        return;
    }

    for(int curr_col = 0; curr_col<n; curr_col++){
        if(isSafe(board,curr_row,curr_col,n)){
            board[curr_row][curr_col] = 'Q'; // placing queen on current cell
            helper(board,curr_row+1,n,ans);  // recursive calling for next row
            board[curr_row][curr_col] = '.'; // backtracking
        }
    }
}

// driver function
vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    vector<vector<char>> board(n, vector<char>(n,'.'));
    helper(board,0,n,ans);

    return ans;   // for NQueen-II problem => return ans.size();
}

int main(){
    int n = 5;
    vector<vector<string>> NQueensBoards = solveNQueens(n);

    cout<<"Printing all solutions : "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<NQueensBoards[i][j]<<endl;
        }
        cout<<endl;
    }

    return 0;
}