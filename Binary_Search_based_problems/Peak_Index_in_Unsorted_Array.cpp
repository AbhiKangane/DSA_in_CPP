// Given unsorted array return the index of any of peak number which is strictly greater than its neighbours
#include<iostream>
#include<vector>
using namespace std;

int findPeak(vector<int> &arr){
    int n = arr.size();
    int low=0, high=n-1;
    while (low <= high){
        int mid = low + (high-low)/2;

        if(mid==0){
            if(arr[mid] > arr[mid+1])
                return 0;
            else
                return 1;
        }

        else if(mid==n-1){
            if(arr[mid] > arr[mid-1])
                return n-1;
            else
                return n-2;
        }

        else{
            if(arr[mid-1] < arr[mid] and arr[mid] > arr[mid+1])
                return mid;
            else if(arr[mid-1] < arr[mid])   // if arr[mid] lies on increasing curve
                low = mid+1;
            else                             // if arr[mid] lies on decreasing curve
                high = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,1,2,5,10,4,2};   // indices of peak elements are : 1,5
    cout<<findPeak(arr);

    return -1;
}