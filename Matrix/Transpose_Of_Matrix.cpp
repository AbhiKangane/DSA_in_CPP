#include<iostream>
using namespace std;

int main(){
    int rows, col, i, j;
    cout<<"Enter no. of rows & columns in matrix: ";
    cin>>rows>>col;

    int arr[rows][col];
    cout<<"Enter numbers in matrix: \n";
    
    for(int i=0; i<rows; i++)
        for(int j =0; j<col; j++)
            cin>>arr[i][j];  

    // for transpose of matrix
    cout<<"Transpose of matrix is: \n";
    for(int i=0; i<rows; i++){
        for(int j=i; j<col; j++){
            // swap a[i][j] with a[j][i]
            int temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }

    // for printing transpose of matrix:
    for(int i=0; i<col; i++){
        for(int j =0; j<rows; j++)
            cout<<arr[i][j]<<" ";

        cout<<endl;
    }     

    return 0; 
}