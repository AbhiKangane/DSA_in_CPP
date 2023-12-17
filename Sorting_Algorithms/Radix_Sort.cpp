#include<iostream>
#include<vector>
using namespace std;

// count sort time complexity : O(n)
void CountSort(vector<int> &arr, int pos){
    int n = arr.size();
    
    // creating freq array for digits 0-9
    vector<int> freq(10,0);
    for(int i=0; i<n; i++){
        freq[(arr[i]/pos)%10]++;
    }

    // calulating cumulative frequency
    for(int i=1; i<10; i++){
        freq[i] += freq[i-1];
    }

    // creating ans array
    vector<int> ans(n);
    for(int i=n-1; i>=0; i--){
        ans[--freq[(arr[i]/pos)%10]] = arr[i];
    }

    // copying ans array into arr
    for(int i=0; i<n; i++){
        arr[i] = ans[i];
    }
}


void RadixSort(vector<int> &arr){
    int max_Ele = arr[0];
    for(int i=1; i<arr.size(); i++){
        max_Ele = max(arr[i], max_Ele);
    }

    for(int pos=1; max_Ele/pos > 0; pos*=10){
        CountSort(arr, pos);
    }
}

int main(){
    int i, j, n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements in array: ";
    for(i=0; i<n; i++)
        cin>>arr[i];

    RadixSort(arr);
    // printing after count sort
    for(i=0; i<n; i++)
        cout<<arr[i]<<" ";
}