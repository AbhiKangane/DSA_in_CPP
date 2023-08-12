#include<bits/stdc++.h>
using namespace std;

void check(int arr[], int size, int Pair_Sum){
    // brute force approach: Time complexity = O(n)
    // for this method we need already sorted(ascending order)
    int low= 0;
    int high= size-1;

    while(low<high){
        if(arr[low] + arr[high] == Pair_Sum){
            cout<<arr[low]<<" + "<<arr[high]<<" = "<<Pair_Sum<<endl;
            low++;
            high--;
        }

        else if(arr[low]+arr[high] > Pair_Sum)
            high--;
        
        else
            low++;
    }
}

int maximum(int a[], int size){
    int max=a[0];
    for(int i=0; i< size; i++){
        if(a[i] > max)
            max= a[i];
    }
    return max;
}

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(){
    int size, i, j, pair_sum;
    cout<<"Enter the size of array: ";
    cin>>size;

    int arr[size];
    cout<<"Enter the numbers in array: ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    cout<<"Enter the pair_sum for finding in array: ";
    cin>>pair_sum;

    // approach 1: It has time complexity = O(n^2) 
    // for(i=0; i<size; i++)
    //     for(j=i+1; j<size; j++){
    //         if(arr[i] + arr[j] == pair_sum)
    //             cout<<"True\n"<<arr[i]<<" + "<<arr[j]<<" = "<<pair_sum;
    //     }

//  Approach 2: hashing technique  time complexity= o(n)
    int max = maximum(arr, size);
    int ind[max+1] = {0}; // initialize all array elements equal to zero
    // printArray(ind, max+1); //for checking
    // for(int i=0;i<=max;i++)
    //     ind[i] = 0;
    

    for(i=0;i<size;i++){
        ind[arr[i]] = 1;
    }

    // printArray(ind, max+1); //for checking
    
    for(int i=0;i<size;i++){
        if(ind[ pair_sum - arr[i] ] != 0){
            cout<<arr[i]<<" + "<<pair_sum-arr[i]<<" = "<<pair_sum<<endl;
        }
    }

    // check(arr, size, pair_sum);
    return 0;
}