/*
    Given 3 strings named p,q,r. The string r is called super-sequence if it follows below conditions
1) r contains each characters(with freq) of p & q. i.e  r = p U q
2) The order of characters in p & q is preserved in r also.

Ex 1) p="tcs", q="nqt" r="tncsqt"
output : true

Ex 2) p="tcs", q="nqt" r="tqncsnt"
output : false
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// sol 1 : not checks all possibilities
bool isSuper_Sequence1(string p, string q, string r){
    // for checking 1st condition
    unordered_map<char,int> mp;
    for(auto i: p)
        mp[i]++;
    for(auto i: q)
        mp[i]++;
    
    for(auto i: r)
        if(mp[i] > 0)
            mp[i]--;

    for(auto i: mp)
        if(i.second != 0)
            return false;
    
    int i=0, j=0; 
    for(int k=0; k<r.size(); k++){
        if(i < p.size() && p[i]==r[k]){
            i++;
        }
        else if(j < p.size() && q[j]==r[k]){
            j++;;
        }
    }

    return i==p.size() && j==q.size();
}


// sol 2 : Recursive helper function with memoization
bool isSupersequenceHelper(const string &p, const string &q, const string &r, int i, int j, int k, vector<vector<vector<int>>> &dp) {
    // Base cases
    if (i == p.size() && j == q.size() && k == r.size()) {
        return true; // All characters matched
    }
    if (k == r.size()) {
        return false; // `r` exhausted before `p` or `q`
    }

    // Check if already computed
    if (dp[i][j][k] != -1) {
        return dp[i][j][k];
    }

    bool res = false;

    // Match `p[i]` with `r[k]`
    if (i < p.size() && p[i] == r[k]) {
        res |= isSupersequenceHelper(p, q, r, i + 1, j, k + 1, dp);
    }

    // Match `q[j]` with `r[k]`
    if (j < q.size() && q[j] == r[k]) {
        res |= isSupersequenceHelper(p, q, r, i, j + 1, k + 1, dp);
    }

    // Store the result in memo table
    dp[i][j][k] = res;
    return res;
}

// Main function to check if `r` is a supersequence of `p` and `q`
bool isSuperSequence(const string &p, const string &q, const string &r) {
    int n = p.size(), m = q.size(), o = r.size();

    // Initialize memoization table with -1
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(o + 1, -1)));

    // Start recursion
    return isSupersequenceHelper(p, q, r, 0, 0, 0, dp);
}


int main(){
    string p,q,r;
    cout<<"Enter the strings p, q, r: ";
    cin>>p>>q>>r;

    if(isSuper_Sequence1(p,q,r))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}
