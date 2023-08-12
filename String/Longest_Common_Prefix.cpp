#include <bits/stdc++.h>
using namespace std;

// approach 1
string longestCommonPrefix(string arr[] , int n) {
    // base case
    // if (n == 0) return "";
    
    for(int i=0; i<n; i++)
        if (arr[i] == "") 
            return "";

    for (int i = 0; i < arr[0].length(); i++) {
        for (int j = 1; j < n; j++) {
            if (i >=arr[j].length() || arr[j][i] != arr[0][i]) {
                if (i == 0) return "-1";
                
                return arr[0].substr(0, i);
            }
        }
    }
    return arr[0];
}


// approach 2
string LC_Prefix(vector<string> &arr, int n){
    string ans = "";

// for traversing all characters of 1st string
    for(int i=0; i<arr[0].length(); i++){
        char ch = arr[0][i];

        bool match = true;

        // for comparing ch with rest as the strings
        for(int j = 1; i < n; j++){
            // cases for character not match
            if(arr[j].size() < i || ch != arr[j][i]){
                match = false;
                break;
            }
        }
        if(match == false)
            break;
        else 
            ans.push_back(ch);
    }
    return ans;
}


int main() {
    // int n;
    // cin >> n;
    // string strs[n];
    vector<string> arr = {"abhi", "ab", "abhishek", "abhijeet"};

    // for (int i = 0; i < n; i++)
    //     cin >> strs[i];

    // cout << "Longest Common Prefix: " <<longestCommonPrefix(strs, n)<<endl;
    string lcp = LC_Prefix(arr, 4);
    cout << "Longest Common Prefix: "<< lcp <<endl;  // didn't print lcp ?
    return 0;
}
