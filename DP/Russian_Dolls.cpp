/*
 leetcode 354  Russian Doll Envelopes
given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.
Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).
*/

// this problems uses Longest Increasing Subsequence problem sol strategy
// step 1: sort envelopes w.r.t. width in increasing order
// step 2: if envelopes having same width are present then sort this envelopes decreasing order w.r.t. their height
// step 3: Apply Longest Subsequence logic on envelopes w.r.t. their height consider as array.

#include<bits/stdc++.h>
using namespace std;


static bool comp(vector<int> &a, vector<int> &b){
    if(a[0] == b[0]){
        return a[1] > b[1];
    }
    return a[0] < b[0];  // for sorting w.r.t. width of envelopes in increasing order
}

int solve(int n, vector<vector<int>>& envelopes ){
    if(n == 0)
        return 0;

    vector<int> ans;
    ans.push_back(envelopes[0][1]);  // After sorting 1st envelope always push into ans because it doesn't need to compare

    for(int i=1; i<n;i++){
        if(envelopes[i][1] > ans.back())
            ans.push_back(envelopes[i][1]);

        else{ // if envelopes[i][1] < last element of ans
            // finding index of just greater number
            int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
            ans[index] = envelopes[i][1];
        }
    }
    return ans.size();
}

int maxEnvelopes(vector<vector<int>>& envelopes) {
    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), comp); // sorting envelopes w.r.t. their width in increasing order

    return solve(n, envelopes);
}


int main(){
    vector<vector<int>> envelopes = {{5,4},{6,4},{6,7},{2,3}};
    // The maximum number of envelopes you can Russian doll is 3     ([2,3] => [5,4] => [6,7]).

    cout<<maxEnvelopes(envelopes);
}