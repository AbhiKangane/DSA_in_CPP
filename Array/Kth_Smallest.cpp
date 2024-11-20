#include<iostream>
#include<queue>
using namespace std;

// O(n*n)
int kth_Smallest(int a[], int start, int end, int k){
    bool swapped;
    // Sort the given array using bubble sort
    for (int i = 0; i < end; i++) // For number of pass
    {
        swapped = false;
        for (int j = 0; j < end-i ; j++) // For comparison in each pass
        {
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp; 
                swapped = true;
            }
        }  
        // If no two elements were swapped by inner loop, then break
        if (swapped == false)
            break;
    } 
    
    return a[k-1];
    // return a[size-k] ; // this is for k'th largest element of an  array
}

// O(n * log n)
// kth smallest using heap
int kth_small(int arr[], int st, int end, int k){
    priority_queue<int> pq;

    // step 1: push 1st k array elements in pq
    for(int i=0; i<k; i++){
        pq.push(arr[i]);
    }

    // step 2:
    for(int i=k; i<=end; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}

// O(log n) : based on quick sort
int partition(int arr[], int st, int end){
    int pivot = arr[end];
    int i=st;
    for(int j=st; j<end; j++){
        if(arr[j] < pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i],arr[end]);
    return i;
}

int Optimized_Kth_Smallest(int arr[], int st, int end, int k){
    if(k>0 && k<=end-st-1){
        int pos = partition(arr,st,end);
        if(pos-st == k-1)
            return arr[pos];

        else if(pos-st > k-1)
            return Optimized_Kth_Smallest(arr,st,pos-1,k);
        
        else
            return Optimized_Kth_Smallest(arr,pos+1,end, k-pos+st-1);
    }
    return INT32_MAX;
}


int main(){
    int a[] = {12,22, 43, 2, 4,7,19};
    int n= sizeof(a)/sizeof(a[0]), k=5;  // here array is in 0 based indexed
    
    cout<<"k'th smallest elment of array is: "
        <<kth_Smallest(a,0,6,k)<<" "
        <<kth_small(a,0,6,k)<<" "
        <<Optimized_Kth_Smallest(a,0,6,k);
    return 0;
}
