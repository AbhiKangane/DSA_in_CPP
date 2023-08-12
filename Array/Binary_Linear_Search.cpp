#include <iostream>
using namespace std;

struct Array
{
    int A[10];
    int size;
    int length;
};

void display(struct Array arr)
{
    int i;
    cout << "\nElements are\n";

    for (i = 0; i < arr.length; i++)
        cout << arr.A[i] << " ";
}

// // function for swapping call by address
// void swap(int *x, int *y){
//     int temp = *x;
//     *x = *y;
//     *y = temp;
// }

// inserting at last
void Append(struct Array *arr, int value)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = value;
}

// linear search
int Linear(struct Array *arr, int value)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (value == arr->A[i])
            return i;
    }
    return -1;
}

// Binary search (Iterative)
int Binary_Iterative(struct Array *arr, int value)
{
    int l = 0, h = arr->length-1, mid;

    while(l<=h)
    {
        mid = (l+h)/2;
        if(value == arr->A[mid])
            return mid;
        else if(value > arr->A[mid])
            l= mid+1;
        else
            h= mid-1;
    }
    
    return -1;
}

// Binary search (Recursive)
int Binary_Recursive(struct Array *arr, int value, int l, int h)
{
    int mid=0;

    if(l<=h)
    {
        mid = (l+h)/2;
        if(value == arr->A[mid])
            return mid;
        else if(value > arr->A[mid])
            return Binary_Recursive(arr, value, mid+1, h);
        else
            return Binary_Recursive(arr, value, l, mid-1);
    }
    
    return -1;
}

int main()
{
    struct Array arr1 = {{3, 4, 5, 6, 7, 8, 9, 10}, 10, 8};
    // cout << Linear(&arr1, 7);

    // cout << Binary_Iterative(&arr1, 7);
    cout<<Binary_Recursive(&arr1, 7, 0, 7);
    return 0;
}