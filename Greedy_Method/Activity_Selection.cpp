// 2 questions is solved here
// <i> Activity selection problem
// <ii> Maximum meetings in one room gfg question

// You are given n activities with their start & finish time
// select maximum no. of activities that can be performed by a single person,
// assuming that a person can only work on a single activity at a time
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cout<<"Enter the size of array : "; cin>>n;

    vector<pair<pair<int,int>, int>> v;
    cout<<"Enter acivities int pair(start & time) in array : ";
    for (int i = 0; i < n; i++){
        int start, end;
        cin>>start>>end;
        v.push_back({{start,end}, i});  // here i takes for storing original activity number
    }

    // sorting activites w.r.t. end time
    sort(v.begin(), v.end(), [&](pair<pair<int,int>, int> &a, pair<pair<int,int>, int> &b){
        return a.first.second < b.first.second;  // for sorting in ascending order
    });

    int take = 1;  // always take 1st activity after sorting w.r.t. end time
    int end = v[0].second;  // end time of 1st activity
    
    // creating vector for storing selected activity number
    vector<int> ans;
    ans.push_back(v[0].second+1);

    for (int i = 1; i < n; i++){
        if(v[i].first.first > end){   // prev activity ka end time < curr activity ka start
            take ++;
            ans.push_back(v[i].second+1);
            end = v[i].first.second;
        }
    }
    cout<<"Max number of activities selected are: "<<take<<endl; // this is sol for Activity selection problem
    
    cout<<"Following activities are selected : "<<take<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";                                 // this is sol for "Maximum meetings in one room gfg question"
    }
}
