// Given sorted array find first & last occurence of target number if present else return [-1,-1]
#include<iostream>
#include<vector>
using namespace std;

// function to find 1st occurence
int lowerBound(vector<int> arr, int target){ // return 1st index, where arr[index] >= target
    int lo = 0, hi = arr.size()-1;
    int ans = -1;
    while (lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(arr[mid] >= target){
            ans = mid;
            hi = mid-1;  // for searching left half
        }
        else
            lo = mid+1;   // searching in right half
    }
    return ans;
}

// function to find last occurence
int upperBound(vector<int> arr, int target){ // return 1st index, where arr[index] > target
    int lo = 0, hi = arr.size()-1;
    int ans = -1;
    while (lo <= hi){
        int mid = lo + (hi-lo)/2;
        if(arr[mid] > target){
            ans = mid;
            hi = mid-1;  // for searching left half
        }
        else
            lo = mid+1;   // searching in right half
    }
    return ans;
}

int main(){
    vector<int> arr = {0,1,1,1,1,3,5,6,7,7,8,8,8,8,9};
    int target = 3;

    vector<int> ans(2);
    ans[0] = lowerBound(arr, target);
    ans[1] = upperBound(arr, target)-1;

    cout<<"first & last occurence of target : "<<ans[0]<<" "<<ans[1];

    return 0;
}