#include<iostream>
using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr){
    int i;
    cout<<"\nElements are\n";

    for(i=0; i<arr.length;i++)
        cout<<arr.A[i]<<" ";
}

// inserting at last
void Append(struct Array *arr, int value){
    if(arr->length < arr->size)
        arr->A[arr->length++] = value;
}

// inserting at index
void Insert(struct Array *arr, int index, int value){
    int i;
    if(index >= 0 && index <= arr->length){
        for(i=arr->length; i>index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = value;
        arr->length++;
    }
}

// deleting from index
int Delete(struct Array *arr, int index){
    int i, x=0;
    if(index >= 0 && index <= arr->length){
        x = arr->A[index];
        for(i=index; i<arr->length-1; i++){
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
    return 0;
}

int main(){
    struct Array arr1 = {{3,4,5,6,7}, 10,5};
    // arr1.A[] = {11,33,44, 55};  //gives error
    Append(&arr1, 10);
    Insert(&arr1, 3, 55);

    Delete(&arr1, 3);
    display(arr1);
    
    return 0;
}