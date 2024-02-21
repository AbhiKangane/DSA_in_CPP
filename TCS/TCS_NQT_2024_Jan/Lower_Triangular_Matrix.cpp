// Write a program for converting matrix of dimension n*n into lower triangular matrix
// Input:
// 1st line takes n as a no. of rows & columns in matrix
// from 2nd line takes input for space seperated values in rows of matrix such that each line contains single row

// Output :
// Single line prints the space seperated values in each row of matrix & each row is seperated by comma

// Note:
// Don't use extra space after values last column & Don't use new line after printing last row

// Example:
// Input:
// 3
// 1 2 3
// 4 5 6
// 7 8 9

// Output:
// 1 0 0,4 5 0,7 8 9

// constraints :
// 1 <= N <= 10^4
// -10^4 <= mat[i][j] <= 10^4


#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;          // taking input for dimension of matrix

    int mat[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
        }
    }

    // converting matrix to Lower_Triangular_Matrix
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            mat[i][j] = 0;
        }
    }

    // Printing output
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<mat[i][j];
            if(j!=n-1)         // for not printing space after last colume
                cout<<" ";
        }
        if(i!=n-1)             // for not printing comma after last colume
            cout<<",";
    }

    return 0;
}