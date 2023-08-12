#include<iostream>
using namespace std;

bool isSafe(int **arr, int x, int y, int n){
    for(int row=0; row<x; row++) // checking in same row
        if(arr[row][y] == 1)
            return false;

    int row = x, col = y;
    while(row>=0 && col>=0){  // checking left diagonal
        if(arr[row][col] == 1)
            return false;
        
        row--; col--; 
    }

    row=x, col=y;
    while(row>=0 && col<n){ // checking for in right diagonal
        if(arr[row][col] == 1)
            return false;

        row--; col++;
    }
    return true;
}

bool NQueens(int **arr, int x, int n){
    // base condition
    if(x >= n){
        return true;
    }

    for(int col=0; col<n; col++){
        if(isSafe(arr,x,col,n)){
            arr[x][col] = 1;

            if(NQueens(arr,x+1,n))
                return true;
            
            arr[x][col] = 0; // backtracking
        }
    }

    return false;
}

int main(){
    int n;
    cout<<"Enter side of chessboard: ";
    cin>>n;

    // input         output(ans)
    // 0,0,0,0,      0,1,0,0
    // 0,0,0,0       0,0,0,1
    // 0,0,0,0  =>   1,0,0,0
    // 0,0,0,0       0,0,1,0

    int **arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[n];
        for(int j=0; j<n; j++)
            arr[i][j] = 0;
    }

    NQueens(arr, 0, n);
    cout<<"After placing N queens: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}