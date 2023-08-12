// subarrays : subset of continuous array elements
// subsequence : subset of ordered array elements
// all subarrays are subsequences but not vice versa

#include<iostream>
#include<map>
#include<vector>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vp vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second

signed main(){
    int n;
    cout<<"Enter size of array : ";
    cin>> n;

    vi arr(n);
    
    cout<<"Enter numbers in array : ";

    rep(i,0,n){
        cin>>arr[i];
    }

    map<int,int> cnt;
    int prefSum =0;

    rep(i,0,n){
        prefSum += arr[i];
        cnt[prefSum] ++;
    }

    int ans =0;
    map<int,int> :: iterator it;

    for(it=cnt.begin(); it!=cnt.end(); it++){
        int c = it->ss;

        ans += (c*(c-1))/2;

        if(it->ff == 0)
            ans += it->ss;
    }

    cout<<"The number of subarray with sum equals 0 are : "<<ans<<endl;
}