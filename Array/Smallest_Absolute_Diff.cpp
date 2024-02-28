// from given array of integers return pair of two integers such that absolute diff between them in minimum

#include<bits/stdc++.h>
using namespace std;

vector<int> samllestAbsoluteDiff(vector<int> arr){
    int n= arr.size();
    if (n < 2) {
        return {-1, -1}; 
    }

    set<int> negative;

    for(int i=0; i<n; i++){
        if(arr[i] < 0){
            arr[i] = abs(arr[i]);
            negative.insert(arr[i]);
        }
    }

    sort(arr.begin(), arr.end());

    vector<int> ans(2,0);

    int miniDiff = INT_MAX;
    for(int i=0; i<n-1; i++){
        if(miniDiff > (arr[i+1]-arr[i])){
            miniDiff = arr[i+1] - arr[i];
            ans[0] = arr[i];
            ans[1] = arr[i+1];
        }
    }

    if(negative.find(ans[0]) != negative.end()){
        ans[0] = 0 - ans[0];
    }
    if(negative.find(ans[1]) != negative.end()){
        ans[1] = 0 - ans[1];
    }

    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    vector<int> arr = {3,-8, 10, 13,-4};
    vector<int> ans = samllestAbsoluteDiff(arr);

    cout<<ans[0]<<" "<<ans[1];

    return 0;
}
