#include<iostream>
using namespace std;

int main(){
    int rows, col, num, i, j;
    bool found = false;
    cout<<"Enter no. of rows & columns in matrix: ";
    cin>>rows>>col;

    int arr[rows][col];
    cout<<"Enter numbers in ascending order in rows & columns of matrix: \n";
    
    for(int i=0; i<rows; i++)
        for(int j =0; j<col; j++)
            cin>>arr[i][j];  

    cout<<"Enter number for searching in matrix: ";
    cin>>num;

    // Method 1: Linear search (time complexity = O(n^2))
    // this method does not need ascending matrix
    // for(int i=0; i<rows; i++){
    //     for(int j=0; j<col; j++){
    //         if(arr[i][j] == num){
    //             found = true;
    //             break;
    //         }
    //     }
    // }

    // Method 2: Brute force approach (time complexity = O(n)) This method need ascending matrix only
    int r=0, c=col-1;
    while(r<rows and c>=0){
        if(arr[r][c] == num){
            found=true;
            break;
        }      
        else if(arr[r][c] > num)
            c--;
        
        else
            r++;
    }  

    if(found == true)
        cout<<"Number is found";
    else
        cout<<"Number is not found";

    return 0; 
}