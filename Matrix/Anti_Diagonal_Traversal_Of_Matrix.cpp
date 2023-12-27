// Give a N*N square matrix, return an array of its anti-diagonals in top-leftmost to bottom-rightmost order. 
// In an element of a anti-diagonal (i, j), surrounding elements will be (i+1, j-1) and (i-1, j+1). Look at the examples for more clarity.

// author : A.K.
#include<iostream>
#include<vector>
using namespace std;

vector<int> antiDiagonalPattern(vector<vector<int>> matrix) {
    vector<int> ans;
    int n = matrix.size();
    
    int i=0, j=0;
    ans.push_back(matrix[i][j]);    // inserting top leftmost number

    while(i<n && i>=0 && j<n && j>=0){
        int maxCol = j+1, maxRow = i+1;  // for updating i & j after printing diagonal
        
        if(maxCol < n){
            j++;
            ans.push_back(matrix[i][j]);  // inserting topmost-right number after printing diagonal
        }
        else if(maxRow < n){  // after completing 1st row i.e maxCol == n
            i++;
            ans.push_back(matrix[i][j]);  // inserting topmost-right number after printing diagonal
        }
        
        // printing diagonal
        while(i<n-1 && j>0){
            i++;
            j--;
            ans.push_back(matrix[i][j]);
        }
        
        // if we traverse 1st row completely
        if(maxCol == n-1){
            i = maxRow-1;
            j = n-1;
        }
        else{
            // for traversing 1st row
            if(maxCol < n-1){
                j = maxCol;
                i = 0;
            }
            else{   // if we reach end of 1st row then shift to next row with last col
                j = n-1;
                i = maxRow;
            }
        }
    }
    return ans;
}


int main(){
    vector<vector<int>> matrix = {{1,2,3,4},
                                  {5,6,7,8},
                                  {9,10,11,12},
                                  {13,14,15,16}};
    vector<int> ans = antiDiagonalPattern(matrix);
    cout<<"Printing Anti_Diagonal_Traversal of matrix\n";
    for(auto i:ans)
        cout<<i<<" ";

    return 0;
}