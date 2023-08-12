#include <bits/stdc++.h>
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

bool containsDuplicate(int* a, int size){
    int max = 10000;
    int ind[max+1], i;
    for(i=0;i<=max;i++)
        ind[i] = 0;
    
    for(i=0;i<size;i++){
        ind[a[i]]++;
    }
    
    // cout<<"Duplicate numbers are: ";
    for(i=0;i<=max;i++){
        if(ind[i] > 1){
            // cout<<i<<" is appearing "<<a[i]<<" times"<<endl;
            return true;
        }
    }
    return false;
}

int main(){
    int i=0, j=0, size, count;
    cout<<"Enter number of elements in array: ";
    cin>>size;

    int a[size];
    cout<<"Enter numbers in array: ";
    for(i=0; i<size; i++)
        cin>>a[i];
     
    //  method 1: it requires sorted array
 /*   int lastDuplicate = 0;
    for(int i=0; i<size; i++){
        if(a[i]==a[i+1] && a[i] != lastDuplicate){

            for(j=i+1; a[i]==a[j]; j++){}
            
            cout<<a[i]<<" is appearing "<<j-i<<" times\n";
            i=j-1;
            
            // cout<<a[i]<<" ";
            // lastDuplicate = a[i];
        }
    }
*/

// Method 2 also known as hashing techinque: this doesn't need sorted array
/*    int max = maximum(a, size);
    int ind[max+1];
    for(i=0;i<=max;i++)
        ind[i] = 0;
    
    for(i=0;i<size;i++){
        ind[a[i]]++;
    }
    
    cout<<"Duplicate numbers are: ";
    for(i=0;i<=max;i++){
        if(ind[i] > 1)
            cout<<i<<" is appearing "<<a[i]<<" times"<<endl;
    }

    // cout<<endl;
    // printArray(ind, max+1);
*/

    cout<<containsDuplicate(a,size);

// Method 3: Time complexity = O(n^2)
    // for(i=0; i<size-1; i++){
    //     count = 1;
    //     if(a[i] != -1){
    //         for(j=i+1; j<size; j++){
    //         if(a[i] == a[j]){
    //             count++;
    //             a[j] = -1;
    //         }
    //     }
    //     if(count>1)
    //             cout<<"Number "<<a[i]<<" is duplicates "<<count<<" times"<<endl;
    //     }
    // }

    return 0;
}
    