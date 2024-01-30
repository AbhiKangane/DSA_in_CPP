#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &board){
    for(auto i:board){
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
}

void KnightTour(vector<vector<int>> &board, int curr_row, int curr_col, int upComingVal, int n){
    if(upComingVal == n){
        display(board);
        cout<<"\n";
        return;
    }

    if(curr_row<0 || curr_row>=n || curr_col<0 || curr_col>=n || board[curr_row][curr_col] != 0)
        return;
    
    board[curr_row][curr_col] = upComingVal;

    KnightTour(board, curr_row-2, curr_col-1, upComingVal+1, n);
    KnightTour(board, curr_row-2, curr_col+1, upComingVal+1, n);
    KnightTour(board, curr_row+2, curr_col-1, upComingVal+1, n);
    KnightTour(board, curr_row+2, curr_col+1, upComingVal+1, n);
    KnightTour(board, curr_row-1, curr_col-2, upComingVal+1, n);
    KnightTour(board, curr_row-1, curr_col+2, upComingVal+1, n);
    KnightTour(board, curr_row+1, curr_col-2, upComingVal+1, n);
    KnightTour(board, curr_row+1, curr_col+2, upComingVal+1, n);

    board[curr_row][curr_col] = 0;
    return;
}

int main(){
    int n; cin>>n;
    vector<vector<int>> board(n,vector<int>(n,0));
    cout<<"Printing Knight Tour : "<<endl;
    KnightTour(board,0,0,1,n);                 // code didn't print or works
    // for(auto i:board){
    //     for(auto j:i)
    //         cout<<j<<" ";
    //     cout<<endl;
    // }
    return 0;
}