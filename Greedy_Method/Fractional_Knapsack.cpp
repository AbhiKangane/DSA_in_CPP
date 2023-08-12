#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
    double v1 = (double) p1.first/p1.second;
    double v2 = (double) p2.first/p2.second;

    return v1>v2;
}

signed main(){
    int n, capacity;
    cout<<"Enter no. of items & capacity of bag : ";
    cin>>n>>capacity;

    vector<pair<int,int>> a(n);
    cout<<"Enter value & weight of each item : \n";
    for (int i = 0; i < n; i++){
        cin>>a[i].first>>a[i].second;
    }
    
    // sorting a w.r.t. value/weight in descending order
    sort(a.begin(), a.end(), compare);

    int ans=0;

    for (int i = 0; i < n; i++){
        if(capacity >= a[i].second){
            ans += a[i].first;        // adding value to ans
            capacity -= a[i].second;  // removing weight from capacity
            continue;
        }
        
        else{ // if(a[i].second > capacity)    // i.e. weight exceeds than capacity then we can take only fractions
            // finding value/weight of curr item
            double vw = (double) a[i].first/a[i].second;
            ans += vw * capacity;        // adding fractional value of curr item
            capacity = 0;                // finally capacity becomes 0
            break;
        }
    }

    cout<<"Maximum profit : "<<ans;
}