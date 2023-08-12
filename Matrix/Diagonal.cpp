#include<iostream>
using namespace std;

struct Matrix{
    int A[10];
    int size;;
};

void display(struct Matrix m){
    int i,j;
    cout<<"\nElements are\n";

    for(i=0; i<m.size;i++){
        for(j=0; j<m.size; j++){
            if(i==j)
                cout<<m.A[i]<<" ";
            
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

// setting diagonal elements
void set(struct Matrix *m, int row, int col, int value){
    if(row == col)
        m->A[row-1] =value;  
}

// Getting any element
int get(struct Matrix *m, int row, int col){
    if(row == col)
        return m->A[row-1];

    else 
        return 0;  
}

int main(){
    struct Matrix m1;
    m1.size =4;
    set(&m1,1,1,1);
    set(&m1,2,2,3);
    set(&m1,3,3,5);
    set(&m1,4,4,7);
    
    display(m1);
    // cout<<get(&m1,3,1);
    return 0;
}