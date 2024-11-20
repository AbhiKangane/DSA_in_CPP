#include<bits/stdc++.h>
using namespace std;

int Find1stRepeating(vector<int>arr, int n){
    unordered_map<int,int> mp;

    for(auto i: arr){
        mp[i]++;
        if(mp[i]==2)
            return i;
    }
    return -1;
}

int main(){
    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter numbers in array: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<"1st repeating number in array: "<<Find1stRepeating(arr,n);

    return 0;
}
