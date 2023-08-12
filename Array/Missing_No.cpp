#include <iostream>
using namespace std;

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int maximum(int a[], int size){
    int max=a[0];
    for(int i=0; i< size; i++){
        if(a[i] > max)
            max= a[i];
    }
    return max;
}

int main(){
    int i=0, size;
    cout<<"Enter number of elements in array: ";
    cin>>size;

    int a[size];
    cout<<"Enter numbers in array: ";
    for(i=0; i<size; i++)
        cin>>a[i];

    int diff = a[0]-0; // a[0]-0=2
    
    // 1) for single missing number : requires sorted array
 /*   for(int i=0; i<5; i++){
        if(a[i] - i != diff) {
            printf("Missing number is: %d", i+diff); 
            break;   
        }
    }
*/
    
    // 2) for many missing numbers : requires sorted array, checking starts from smallest no. 
/*    printf("Missing numbers are: \n") ;
    for(int i=0; i<size; i++){
        if(a[i] - i != diff) {
            while(diff < (a[i]-i)){
                printf("%d\n", i+diff); 
                diff++;
            }
        }
    }
*/
    // 3) for any(sorted or unsorted) array : checks missing no. from 1
    int max = maximum(a, size);
    int ind[max];
    for(i=1;i<=max;i++)
        ind[i] = 0;
    
    for(i=0;i<size;i++){
        ind[a[i]] = 1;
    }

    printArray(ind, max+1);
    
    printf("Missing numbers are: \n") ;
    for(i=1;i<=max;i++){
        if(ind[i] == 0)
            printf("%d ", i);
    }
    
    return 0;
}
    