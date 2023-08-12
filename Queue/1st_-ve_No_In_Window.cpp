#include<bits/stdc++.h>
using namespace std;

vector<long long> Print_1st_Neg(long long int arr[], long long int size, long long int k){
    
    deque<long long int> dq;
    vector<long long> ans;

    // process 1st window of k size
    for(int i=0; i<k; i++){
        if(arr[i] < 0)
            dq.push_back(i);  // storing index of -ve numbers
    }

    // storing ans of first k size window
    if(dq.size() > 0)     ans.push_back(arr[dq.front()]);
    else                  ans.push_back(0); 

    // processing remaining numbers
    for(int i=k; i<size; i++){
        // removal
        if(!dq.empty() && i-dq.front() >= k)
            dq.pop_front();   // increasing front

        // addition
        if(arr[i] < 0)
            dq.push_back(i);  // storing index of -ve numbers

        // storing ans
        if(dq.size() > 0)     ans.push_back(arr[dq.front()]);
        else                  ans.push_back(0); 
    }
    return ans;
}

int main(){
    long long int arr[] = {-8,3,1,-6,4};

    vector<long long> ans = Print_1st_Neg(arr,5,2);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}