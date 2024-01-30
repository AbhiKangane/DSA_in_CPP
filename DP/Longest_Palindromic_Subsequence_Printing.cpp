#include<bits/stdc++.h>
using namespace std;

bool check(string &s, int i, int j){
    while(i<j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}            

// Sol 1 : brute force:  T.C. = O(n^3)
string longestPalindrome1(string s) {
    int n = s.size();
    int starting_index = 0;
    int max_len = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if(check(s, i, j)){
                if(j-i+1 > max_len){
                    max_len = j-i+1;
                    starting_index = i;
                }
            }
        }
    }
    return s.substr(starting_index, max_len);
}


// Sol 2 : brute force:  T.C. = O(n^2)
string longestPalindrome2(string s) {
    int n = s.size();
    vector<string> allSubstrings;

    for(int i=0; i<n; i++){
        string temp = "";
        for(int j=i; j<n; j++){
            temp = temp + s[j];
            allSubstrings.push_back(temp);
        }
    }

    int maxlen = allSubstrings[0].size();
    string ans = allSubstrings[0];

    for(int i=0; i<allSubstrings.size(); i++){
        int len = allSubstrings[i].size();
        if(check(allSubstrings[i], 0, len-1)){
            if(maxlen < len){
                ans = allSubstrings[i];
            }
        }
    }
    return ans;
}

int main(){
    string str = "abcdefedcrte" ;  // longest Palindromic subsequence = "cdefedc"

    string ans = longestPalindrome1(str);
    cout<<ans<<endl;
    string ans2 = longestPalindrome1(str);
    cout<<ans2<<endl;
    
}
