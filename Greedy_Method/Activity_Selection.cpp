// 2 questions is solved here
// <i> Activity selection problem
// <ii> Maximum meetings in one room gfg question

// You are given n activities with their start & finish time
// select maximum no. of activities that can be performed by a single person,
// assuming that a person can only work on a single activity at a time
#include<bits/stdc++.h>
using namespace std;

vector<int> maxMeetings(int n, vector<int> &start, vector<int> &end){
    vector<pair<pair<int,int>, int>> v;
    // Enter meetings int pair(start & end time) in array : ";
    for (int i = 0; i < n; i++){
        v.push_back({{start[i],end[i]}, i});  // here i takes for storing original activity number
    }

    // sorting activites w.r.t. end time
    sort(v.begin(), v.end(), [&](pair<pair<int,int>, int> &a, pair<pair<int,int>, int> &b){
        return a.first.second < b.first.second;  // for sorting in ascending order
    });

    int take = 1;  // always take 1st activity after sorting w.r.t. end time
    int endTime = v[0].first.second;  // end time of 1st activity
    
    // creating vector for storing selected activity number
    vector<int> ans;
    ans.push_back(v[0].second+1);

    for (int i = 1; i < n; i++){
        if(v[i].first.first > endTime){   // prev activity ka endTime < curr activity ka start
            take ++;
            ans.push_back(v[i].second+1);
            endTime = v[i].first.second;
        }
    }
    
    sort(ans.begin(), ans.end());
    
    return ans;
}

int main(){
    int n; cout<<"Enter the no. of meetings or activities : "; 
    cin>>n;

    vector<int> start(n), end(n);
    cout<<"Enter acivities or meetings time into start & end array : ";
    for (int i = 0; i < n; i++){
        int st, e;
        cin>>st>>e;
        start[i] = st;
        end[i] = e;
    }

    vector<int> ans = maxMeetings(n, start, end);

    cout<<"Max number of activities selected are: "<<ans.size()<<endl; // this is sol for Activity selection problem
    
    cout<<"Following activities are selected : "<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";                                 // this is sol for "Maximum meetings in one room gfg question"
    }
}
