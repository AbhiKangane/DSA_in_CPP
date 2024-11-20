// https://www.geeksforgeeks.org/problems/duplicate-elements/1
#include <bits/stdc++.h>
using namespace std;

// O(n*log(n))
vector<int> DuplicateNumbers1(vector<int>arr, int n){
    sort(arr.begin(), arr.end());

    vector<int> ans;

    for(int i=0; i<n-1; i++) {
        if(arr[i] == arr[i+1]) {
            ans.push_back(arr[i]);
            while(i<n-1 && arr[i] == arr[i+1]) i++; // Skip all duplicates
        }
    }

    return ans;
}

// O(n)
vector<int> DuplicateNumbers2(vector<int>arr, int n){
    unordered_map<int,int> mp;
    vector<int> ans;

    for(auto i: arr){
        mp[i]++;
    }

    for(auto i: mp){
        // cout<<i.first<<" "<<i.second<<endl;
        if(i.second > 1)
            ans.push_back(i.first);
    }

    return ans;
}

int main(){
    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter numbers in array: ";
    for(int i=0; i<n; i++)
        cin>>arr[i];

    vector<int> ans = DuplicateNumbers1(arr,n);
    sort(ans.begin(), ans.end());
    
    if(ans.size()>0){
        cout<<"Duplicated no. in array are: ";
        for(auto i:ans)
            cout<<i<<" ";    
    }

    else
        cout<<"No Duplicated number is present ";

    return 0;
}
