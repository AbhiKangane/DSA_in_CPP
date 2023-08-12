#include<bits/stdc++.h>

using namespace std;

int main(){
    int arrSize, wSize, x;
    cout<<"Enter size of array & window simultaneously: ";
    cin>>arrSize>>wSize;

    vector<int> a(arrSize);
    cout<<"Enter array elements: ";
    for(auto &i: a)
        cin>>i;
    
// following approach takes O(nlog(n)) time
    // multiset<int, greater<int>> ms;
    // vector<int> ans;
    // for(int i=0; i<wSize; i++){
    //     ms.insert(a[i]);
    // }

    // ans.push_back(*ms.begin());
    // for(int i=wSize; i<arrSize; i++){
    //     ms.erase(ms.lower_bound(a[i-x]));
    //     ms.insert(a[i]);
    //     ans.push_back(*ms.begin());
    // }

    // for(auto i: ans)
    //     cout<<i<<" ";

    deque<int> dq;
    vector<int> ans;

    for(int i=0; i<wSize; i++){
        while(!dq.empty() && a[dq.back()] < a[i]){
            dq.pop_back();
        }

        dq.push_back(i);
    }
    ans.push_back(a[dq.front()]);

    // for remaining windows
    for(int i=wSize; i<arrSize; i++){
        if(dq.front() == i-wSize){
            dq.pop_front();
        }

        while(!dq.empty() && a[dq.back()] < a[i]){
            dq.pop_back();
        }

        dq.push_back(i);
        ans.push_back(a[dq.front()]);
    }

    for(auto i: ans){
        cout<<i<<" ";
    }
}
