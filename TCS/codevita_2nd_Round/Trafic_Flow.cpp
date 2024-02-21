// Traffic Flow
// Problem Description
// A traffic flow grid is a conceptual representation used in transportation planning and traffic engineering to model and analyze the movement of vehicles through a network of intersections in the city called as junctions. A traffic flow grid is akin to a matrix, with rows and columns denoting various junctions, and matrix cell values symbolizing the traffic flow in that junction. In the era of screens and swipes, traffic's stage can be seen on mobile!

// Srihan finds himself caught in traffic on his way to the workplace. To speed up his journey, he opts to assess the traffic flow grid and chooses a quicker route. He currently resides at coordinates (i, j), and his office is located at coordinates (a, b) in the traffic grid. Given a rule that from a given junction, he can only go to right or down junction (junction is a cell, in terms of matrix). Could you assist him in finding a faster route to reach his workplace?

// Constraints
// Note that the provided positions in the input are indexed starting from 1, where left top is (1, 1).
// 1 <= n, m <= 100
// 0 <= traffic flow <= 10^3

// Input
// First line consists of two space separated integers n, m denoting the number of rows and columns in the traffic grid.
// Next n lines consists of m space separated integers denoting the traffic flow. The value at i, j indicates the traffic flow at junction i and j.
// Line n+2 consists of two space separated integers denoting the coordinates of Srihan's current position.
// Line n+3 consists of two separated integers denoting the coordinates of Srihan's workplace.

// Output
// Single integer denoting the the minimum traffic flow Srihan must navigate to reach his workplace. In case there is no path from his current location to workplace, print "-1".

// Time Limit (secs)
// 1

// Examples
// Example 1
// Input
// 4 4
// 3 1 9 2
// 12 3 10 1
// 11 10 14 2
// 5 4 3 7

// 1 2
// 4 4

// Output
// 22

// Explanation
// Srihan will choose the path - (1,2) -> (1,3) -> (1,4) -> (2,4) -> (3,4) -> (4,4)
// The total traffic flow Srihan navigated is 1 + 9 + 2 + 1 + 2 + 7 = 22 which is the minimum possible.

// Example 2
// Input
// 3 3
// 6 9 1
// 4 7 3
// 5 0 2

// 1 1
// 3 3

// Output
// 17

// Explanation
// Srihan will choose the path - (1,1) -> (2,1) -> (2,2) -> (3,2) -> (3,3)
// The total traffic flow Srihan navigated is 6 + 4 + 5 + 0 + 2 = 17 which is the minimum possible.

#include<bits/stdc++.h>
using namespace std;

int solveRec(int n, int m, vector<vector<int>>&mat, int srcX, int srcY, int destX, int destY){
    // Base case: reached the destination
    if (srcX == destX && srcY == destY) {
        return mat[srcX-1][srcY-1];
    }

    // Check if current coordinates are out of bounds
    if (srcX > destX || srcY > destY) {
        return numeric_limits<int>::max();
    }

    // Recursive calls for moving right or down
    int moveRight = solveRec(n, m, mat, srcX, srcY + 1, destX, destY);
    int moveDown = solveRec(n, m, mat, srcX+1, srcY, destX, destY);

    // Calculate the minimum traffic flow considering the current cell
    return mat[srcX-1][srcY-1] + min(moveRight, moveDown);
}

// Memoization
int solveMem(int n, int m, vector<vector<int>>&mat, int srcX, int srcY, int destX, int destY, vector<vector<int>>&dp){
    // Base case: reached the destination
    if (srcX == destX && srcY == destY) {
        return dp[srcX-1][srcY-1] = mat[srcX-1][srcY-1];
    }

    if(dp[srcX-1][srcY-1] != -1)
        return dp[srcX-1][srcY-1];

    // Check if current coordinates are out of bounds
    if (srcX > destX || srcY > destY) {
        return dp[srcX-1][srcY-1] = numeric_limits<int>::max();
    }

    // Recursive calls for moving right or down
    int moveRight = solveMem(n, m, mat, srcX, srcY + 1, destX, destY, dp);
    int moveDown = solveMem(n, m, mat, srcX+1, srcY, destX, destY, dp);

    // Calculate the minimum traffic flow considering the current cell
    return dp[srcX-1][srcY-1] = mat[srcX-1][srcY-1] + min(moveRight, moveDown);
}

// Tabulation
int solveTab(int n, int m, vector<vector<int>>&mat, int srcX, int srcY, int destX, int destY){
    vector<vector<int>>dp(n,vector<int>(m,0));
    // Base case: initialize the destination cell
    dp[destX-1][destY-1] = mat[destX-1][destY-1];

    // Initialize the last row
    for (int j = destY - 2; j >= 0; --j) {
        dp[destX-1][j] = mat[destX-1][j] + dp[destX-1][j+1];
    }

    // Initialize the last column
    for (int i = destX - 2; i >= 0; --i) {
        dp[i][destY-1] = mat[i][destY-1] + dp[i+1][destY-1];
    }

    // Fill the table in a bottom-up manner
    for (int i = destX - 2; i >= 0; --i) {
        for (int j = destY - 2; j >= 0; --j) {
            dp[i][j] = mat[i][j] + min(dp[i][j+1], dp[i+1][j]);
        }
    }

    // The result is in the top-left cell
    return dp[srcX-1][srcY-1];
}

int main(){
    int n, m;
    cout<<"Enter rows & cols : ";
    cin>>n>>m;
    vector<vector<int>> mat(n+1,vector<int>(m+1));

    cout<<"Enter values in matrix: \n";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }

    int srcX, srcY;
    cout<<"Enter srcX & srcY : ";
    cin>>srcX>>srcY;

    int destX, destY;
    cout<<"Enter destX & destY : ";
    cin>>destX>>destY;

    // Check if the src coordinates are valid
    if (srcX < 1 || srcX > n || srcY < 1 || srcY > m) {
        cout << "Invalid destination coordinates." << endl;
        return 1;
    }

    // Check if the dest coordinates are valid
    if (destX < 1 || destX > n || destY < 1 || destY > m) {
        cout << "Invalid destination coordinates." << endl;
        return 1;
    }

    // recursive sol
    // cout<<solveRec(n,m,mat,srcX,srcY,destX,destY);

    // memoized sol
    // vector<vector<int>> dp(n,vector<int>(m,-1));
    // cout<<solveMem(n,m,mat,srcX,srcY,destX,destY,dp);
    
    // tabulation
    cout<<solveTab(n,m,mat,srcX,srcY,destX,destY);
    return 0;
}