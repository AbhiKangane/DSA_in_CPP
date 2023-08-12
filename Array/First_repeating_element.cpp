#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i;
    // cout<<INT_MAX;
    cout<<"Enter number of elements in array: ";
    cin>>n;

    int a[n];
    cout<<"Enter numbers in array: ";
    for(i=0; i<n; i++)
        cin>>a[i];

    const int N = 1e3; // 1e3 = 10^3
    int idx[N];   // default value of array elements is '0'
    // idx[N] is a array of indices where value at a[i] (value at index i in array 'a' is index in 'idx' array) is initialise with 'i'
    // Ex: a[n] = {1,5,3,4,3,5,6}
    //     idx[N] = {-1, 0, -1, 2, 3, 1, 6, -1}  indexing starts from 0
    //               0,  1,  2, 3, 4, 5, 6,  7

    for(int i=0; i<N; i++)
        idx[i] = -1;

    int minidx = INT_MAX;
    for(i=0; i<n; i++){
        if(idx[a[i]] != -1)
            minidx = min(minidx, idx[a[i]]);
        
        else
            idx[a[i]] = i;
    }

    if(minidx == INT_MAX) // if there no repeated numbers available
        cout<<"-1"<<endl;
    
    else
        cout<<minidx + 1<<endl;

    return 0;
}