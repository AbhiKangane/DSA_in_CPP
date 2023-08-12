#include <iostream>
using namespace std;

void printArray(int *A, int n){
    for (int i = 0; i < n; i++)
        cout<<A[i]<<" ";

    cout<<endl;
}


int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do{
        while (A[i] <= pivot)
            i++;

        while (A[j] > pivot)
            j--;

        if (i < j){  // swap A[i] & A[j]
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    // Swap A[low] and A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j; // returning partionIndex
}

void quickSort(int A[], int low, int high)
{
    int partitionIndex; // Index of pivot after partition

    if (low < high){
        partitionIndex = partition(A, low, high); 
        // printf("\nPartition_Index : %d\n",partitionIndex);
        // printf("Array after calling each partition: ");
        // printArray(A, 9) ;       // for just checking
       
        quickSort(A, low, partitionIndex - 1);  // sort left subarray 
        quickSort(A, partitionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    //int A[] = {3pivot, 5i, 2, 13, 12, 3, 2, 13, 45j}; initially
    // 3pivot, 5i, 2, 13, 12, 3, 2j, 13, 45   //after that swap A[i] & A[j]
    // 3pivot, 2, 2, 13i, 12, 3j, 5, 13, 45
    // 3pivot, 2, 2, 3i, 12, 13j, 5, 13, 45
    // 3pivot or low, 2, 2, 3j, 12i, 13, 5, 13, 45 --> first call to partition returns 3 & swap A[j] with A[low]
    
    // for second call
    // {3, 2, 2, 3} & {12, 13, 5, 13, 45}
    
    int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};
    int n = 9;
    
    printf("Array before sorting: ") ;
    printArray(A, n);

    quickSort(A, 0, n - 1);
    
    printf("\nArray after sorting: ");
    printArray(A, n);
    
    return 0;
}
    