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
    int prefSum = 0;
    bool ans = false;
    cnt[prefSum] = 1;

    rep(i,0,n){
        prefSum += arr[i];
        // 1) if we include following if block then we didn't need following loop & iteration
        if(cnt[prefSum] > 0){
            ans = 1;
            break;
        }
        cnt[prefSum] ++;
    }

    // 2) following method is also works if we didn't include if statement in above loop 
    // map<int,int> :: iterator it;

    // for(it=cnt.begin(); it!=cnt.end(); it++){
    //     if(it->ss > 1){
    //         ans = true;
    //         break;
    //     }
    // }

    cout<<"Is there subarray of sum 0 present? : "<<ans<<endl;
}