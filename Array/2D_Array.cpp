#include<iostream>
using namespace std;

int main(){

    int A[3][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    int *B[3];
    int **C;

    B[0]= new int [4];
    B[1]= new int [4];
    B[2]= new int [4];
    
// in C
/*
    B[0] = (int *) malloc (4*sizeof(int));    
    B[1] = (int *) malloc (4*sizeof(int));
    B[2] = (int *) malloc (4*sizeof(int));
    
    C = (int **) malloc (3*sizeof(int *));
        C[0] = (int *) malloc (4*sizeof(int));
        C[1] = (int *) malloc (4*sizeof(int));    
        C[2] = (int *) malloc (4*sizeof(int));
*/

    C = new int *[3];
    C[0]= new int [4];
    C[1]= new int [4];
    C[2]= new int [4];

    for(int i=0; i<3; i++)
        for(int j =0; j<4; j++)
            // cin>>B[i][j];
            cin>>C[i][j];            

    for(int i=0; i<3; i++){
        for(int j =0; j<4; j++)
            // cout<<B[i][j]<<" ";
            cout<<C[i][j]<<" ";

        cout<<endl;
    }
}