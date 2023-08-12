#include<iostream>
#include<cstdlib>
using namespace std;

struct Matrix{
    int *A;
    int size;;
};

void display_Col_Major(struct Matrix M1){
    int i,j;
    cout<<"\nLower Triangular Matrix: \n";

    for(i=1; i<=M1.size;i++){
        for(j=1; j<=M1.size; j++){
            if(i>=j)
                cout<<M1.A[M1.size*(j-1) + (j-2)*(j-1)/2 + (i-j)]<<" ";
            
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

void display_Row_Major(struct Matrix M1){
    int i,j;
    cout<<"\nMatrix: \n";

    for(i=1; i<=M1.size;i++){
        for(j=1; j<=M1.size; j++){
            if(i>=j)
                cout<<M1.A[i*(i-1)/2 + (j-1)]<<" ";
            
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}

// setting lower Triangular elements (column major)
void set_Col_Major(struct Matrix *M1, int i, int j, int value){
    if(i >= j)
        M1->A[M1->size*(j-1) + (j-2)*(j-1)/2 + (i-j)] =value;  
}

// Getting any element
int get_Col_Major(struct Matrix *M1, int i, int j){
    if(i >= j)
        return M1->A[M1->size*(j-1) + (j-2)*(j-1)/2 + (i-j)];

    else 
        return 0;  
}

// setting lower Triangular elements (row major)
void set_Row_Major(struct Matrix *M1, int i, int j, int value){
    if(i >= j)
        M1->A[i*(i-1)/2 + (j-1)] =value;  
}

// Getting any element
int get_Row_Major(struct Matrix *M1, int i, int j){
    if(i >= j)
        return M1->A[i*(i-1)/2 + (j-1)];

    else 
        return 0;  
}

int main(){
/*    struct Matrix M1;
    int i, j, val;

    cout<<"Enter no of rows & columns: ";
    cin>>M1.size;

    // M1.A = (int *)malloc(M1.size*(M1.size + 1)/2 * sizeof(int));
    M1.A = new int [M1.size*(M1.size + 1)/2];
    cout<<"Enter all elements: \n";
    
    for(i=1; i<=M1.size; i++)
        for(j=1; j<=M1.size; j++){
            cin>>val;
            set_Col_Major(&M1,i,j,val);
        }

    display_Col_Major(M1);
*/

    struct Matrix M2;
    int i, j, val;

    cout<<"Enter no of rows & columns: ";
    cin>>M2.size;

    M2.A = new int [M2.size*(M2.size + 1)/2];
    cout<<"Enter all elements: \n";
    
    for(i=1; i<=M2.size; i++)
        for(j=1; j<=M2.size; j++){
            cin>>val;
            set_Row_Major(&M2,i,j,val);
        }

    display_Row_Major(M2);
    return 0;
}