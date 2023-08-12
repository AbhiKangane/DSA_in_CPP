#include<iostream>
#include<cstdlib>
using namespace std;

struct Matrix{
    int *A;
    int size;;
};

void display_Row_Major(struct Matrix M1){
    int j,i;
    cout<<"\nUpper Triangular Matrix: \n";

    for(i=1; i<=M1.size;i++){
        for(j=1; j<=M1.size; j++){
            if(j>=i)
                cout<<M1.A[M1.size*(i-1) + (i-2)*(i-1)/2 + (j-i)]<<" ";
            
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

void display_Col_Major(struct Matrix M1){
    int j,i;
    cout<<"\nMatrix: \n";

    for(j=1; j<=M1.size;j++){
        for(i=1; i<=M1.size; i++){
            if(j>=i)
                cout<<M1.A[j*(j-1)/2 + (i-1)]<<" ";
            
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

// setting lower Triangular elements (column major)
void set_Row_Major(struct Matrix *M1, int i, int j, int value){
    if(j >= i)
        M1->A[M1->size*(i-1) + (i-2)*(i-1)/2 + (j-i)] =value;  
}

// Getting any element
int get_Row_Major(struct Matrix *M1, int i, int j){
    if(j >= i)
        return M1->A[M1->size*(i-1) + (i-2)*(i-1)/2 + (j-i)];

    else 
        return 0;  
}

// setting lower Triangular elements (row major)
void set_col_Major(struct Matrix *M1, int i, int j, int value){
    if(j >= i)
        M1->A[j*(j-1)/2 + (i-1)] =value;  
}

// Getting any element
int get_col_Major(struct Matrix *M1, int i, int j){
    if(j >= i)
        return M1->A[j*(j-1)/2 + (i-1)];

    else 
        return 0;  
}

int main(){
/*    struct Matrix M1;
    int x, y, val;

    cout<<"Enter no of rows & columns: ";
    cin>>M1.size;

    // M1.A = (int *)malloc(M1.size*(M1.size + 1)/2 * sizeof(int));
    M1.A = new int [M1.size*(M1.size + 1)/2];
    cout<<"Enter all elements: \n";
    
    for(x=1; x<=M1.size; x++)
        for(y=1; y<=M1.size; y++){
            cin>>val;
            set_Col_Major(&M1,x,y,val);
        }

    display_Col_Major(M1);
*/

    struct Matrix M2;
    int x, y, val;

    cout<<"Enter no of rows & columns: ";
    cin>>M2.size;

    M2.A = new int [M2.size*(M2.size + 1)/2];
    cout<<"Enter all elements: \n";
    
    for(x=1; x<=M2.size; x++)
        for(y=1; y<=M2.size; y++){
            cin>>val;
            set_Row_Major(&M2,x,y,val);
        }

    display_Row_Major(M2);
    return 0;
}