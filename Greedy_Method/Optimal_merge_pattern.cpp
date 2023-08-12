#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)

int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter numbers in array : ";
    for(int i = 0; i<n; i++)
        cin>>arr[i];

    // creating minheap
    priority_queue<int, vector<int>, greater<int>> minheap;
    rep(i,0,n){
        minheap.push(arr[i]);
    }

    int ans = 0;
    while (minheap.size() > 1){
        int e1 = minheap.top();
        minheap.pop();
        int e2 = minheap.top();
        minheap.pop();

        ans += e1+e2;
        minheap.push(e1+e2);
    }
    cout<<"Minimum Cost of merging : "<<ans;
    return 0;   
}