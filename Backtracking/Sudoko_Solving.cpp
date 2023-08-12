#include<bits/stdc++.h>
using namespace std;

// solution 1 : recursive backtracking
bool is_Safe(int row, int col, vector<vector<int>> &board, int val){
    for(int i = 0; i < board.size(); i++){
        // check in same row
        if(board[row][i] == val)
            return false;

        // check in same col
        if(board[i][col] == val)
            return false;

        // check in same grid(3*3)
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val)
            return false;
    }
    return true;
}

bool solve_Sudoko(vector<vector<int>> &board){
    int n = board[0].size();

    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            // if cell is empty
            if(board[row][col] == 0){
                for(int val=1; val<=9; val++){
                    if(is_Safe(row, col, board, val)){
                        board[row][col] = val;

                        // recursive call for solution for next empty cell
                        bool next_Empty_Cell = solve_Sudoko(board);
                        if(next_Empty_Cell)
                            return true;
                        
                        else
                            // backtrack
                            board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}


// solution 2 : Hashing
void helper(int r, int c, vector<vector<int>> &a, map<pair<int,int>, map<int,int>> &mp, vector<map<int,int>> &rows, vector<map<int,int>> &col){
    // base cases
    if(r==9) // after checking all rows pring ans
        for(auto it: a){
            for(auto i: it){
                cout<<i<<" ";
            }
            cout<<endl;
        }

    if(c == 9){ // after checking all col go to next row
        helper(r+1,0,a,mp,rows,col);
        return;
    }

    if(a[r][c] != 0){ // if cell not empty
        helper(r,c+1,a,mp,rows,col);
        return;
    }

// updating empty cells
    for(int i=1; i<=9; i++){
        int rw = r/3, cl = c/3;
        if(!mp[{rw,cl}][i]  and !rows[r][i] and !col[i][c]){
            // updating new value for empty cell 
            mp[{rw,cl}][i] = 1;
            rows[r][i] = 1;
            col[i][c] = 1;
            a[r][c] = i;

            // for solving next
            helper(r,c+1,a,mp,rows,col);

            // backtracking
            mp[{rw,cl}][i] = 0;
            rows[r][i] = 0;
            col[i][c] = 0;
            a[r][c] = 0;
        }

    }
}


void solveSudoko_2(vector<vector<int>> &a){
    map<pair<int,int>, map<int,int>> mp; // map for grid
    vector<map<int,int>> row(9);  // for rows
    vector<map<int,int>> col(9);  // for col

    for (int i = 0; i < 9; i++){
        for(int j=0; j<9; j++){
            if(a[i][j] != 0){
                mp[{i/3, j/3}] [a[i][j]] = 1;
                row[i][a[i][j]] = 1;
                col[j][a[i][j]] = 1;
            }
        }
    }
    
    helper(0,0,a,mp,row,col);
}

int main(){
    // 0 indicates empty cell
    vector<vector<int>> sudoko = {{0,0,0, 0,7,1, 9,5,0},
                                  {7,0,2, 5,8,0, 4,6,3},
                                  {0,0,9, 0,2,6, 0,1,0},
                                  {8,0,3, 7,0,0, 5,9,6},
                                  {5,0,7, 8,0,0, 2,3,1},
                                  {0,9,1, 0,3,5, 0,0,7},
                                  {0,3,5, 2,4,7, 0,0,9},
                                  {9,7,0, 1,0,8, 0,0,0},
                                  {4,2,8, 0,0,3, 0,0,5}};
    // sol 1
    if(solve_Sudoko(sudoko)){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++)
                cout<<sudoko[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl<<endl;
    }

    else
        cout<<"No solution exist"<<endl;

    // sol 2
    solveSudoko_2(sudoko);
    

    return 0;
}