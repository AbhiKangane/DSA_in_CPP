#include<iostream>
using namespace std;

int main(){
    int rows, col, i, j;
    cout<<"Enter no. of rows & columns in matrix: ";
    cin>>rows>>col;

    int arr[rows][col];
    cout<<"Enter numbers in matrix: ";
    
    for(int i=0; i<rows; i++)
        for(int j =0; j<col; j++)
            cin>>arr[i][j];  

    cout<<"Entered Matrix: \n";

    for(int i=0; i<rows; i++){
        for(int j =0; j<col; j++)
            cout<<arr[i][j]<<" ";

        cout<<endl;
    }     

    // Spiral order printing
    int top_row = 0, bottom_row = rows-1, left_Col = 0, right_Col = col-1;
    
    while(top_row <= bottom_row && left_Col <= right_Col){
        // for top_row 
        for(j=left_Col; j<=right_Col; j++){
            cout<<arr[top_row][j]<<" ";
        }
        top_row++;

        // for right_Col 
        for(i=top_row; i<=bottom_row; i++){
            cout<<arr[i][right_Col]<<" ";
        }
        right_Col--;

        // for bottom_row
        for(j=right_Col; j>=left_Col; j--){
            cout<<arr[bottom_row][j]<<" ";
        }
        bottom_row--;

         // for left_Col 
        for(i=bottom_row; i>=top_row; i--){
            cout<<arr[i][left_Col]<<" ";
        }
        left_Col++;

    }
    

    return 0;
}     
