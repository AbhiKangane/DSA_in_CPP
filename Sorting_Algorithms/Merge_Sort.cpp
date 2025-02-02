// All Sorting Algorithms LeetCode:
// Link => https://leetcode.com/problems/sort-an-array/discuss/1401412/C%2B%2B-Clean-Code-Solution-or-Fastest-or-All-(15%2B)-Sorting-Methods-or-Detailed

#include <iostream>
using namespace std;

// defining macro for loop
#define rep(i,a,b) for(int i=a; i<b; i++)

void printArray(int *A, int n){
    rep(i,0,n)
        cout<<A[i]<<" ";
    printf("\n");
}

void merge(int A[], int mid, int low, int high){
    int i, j, k, n=high-low+1;
    int B[n];
    i = low;
    j = mid + 1;
    k = 0;

    while (i <= mid && j <= high){
        if (A[i] < A[j]){
            B[k] = A[i];
            i++;
            k++;
        }
        else{
            B[k] = A[j];
            j++;
            k++;
        }
    }

    while (i <= mid){
        B[k] = A[i];
        k++;
        i++;
    }

    while (j <= high){
        B[k] = A[j];
        k++;
        j++;
    }

    rep(i,0,n)
        A[i+low] = B[i];
}

void mergeSort(int A[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid); // This will sort the array from A[low] to A[mid]
        mergeSort(A, mid+1, high); // This will sort the array from A[mid+1] to A[high]
        merge(A, mid, low, high);
    }
}

int main()
{
    // int A[] = {9, 14, 4, 8, 7, 5, 6};
    int A[] = {9, 1, 4, 14, 4, 15, 6};
    int n = 7;

    printf("Array before sorting: ") ;
    printArray(A, n);

    mergeSort(A, 0, n - 1);
    
    printf("\nArray after sorting: ");
    printArray(A, n);
    
    return 0;
}
