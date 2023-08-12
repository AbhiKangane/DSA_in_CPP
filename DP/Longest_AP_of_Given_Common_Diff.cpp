#include<bits/stdc++.h>
using namespace std;

int longestAP_of_Given_CD(vector<int> &arr, int difference){
    unordered_map<int,int> dp;
    int ans = 0;

    for (int i = 0; i < arr.size(); i++){
        int temp = arr[i] - difference;
        int tempAns = 0;

        // check answer exist for temp already or not
        if(dp.count(temp))
            tempAns = dp[temp];

        // update curr ans
        dp[arr[i]] = 1+tempAns;

        // update max ans
        ans = max(ans, dp[arr[i]]);
    }
    return ans;
}


int main(){
    vector<int> v = {1,5,7,8,5,3,4,2,1};
    int diff = -2;

    cout<<longestAP_of_Given_CD(v, diff);// 4 => {7,5,3,1}

    return 0;
}