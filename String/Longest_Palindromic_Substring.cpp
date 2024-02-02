// Given a string S, find the longest palindromic substring in S. 
// Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S).
/*
 Input:
S = "aaaabbaa"
Output:
aabbaa
*/

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

// brute force
string longestPalindrome(string s) {
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


// sol 2:
static string help(string s, int st, int end) {
    int n = s.length();
    while (st >= 0 && end < n) {
        if (s[st] == s[end]) {
            st--;
            end++;
        } else {
            break;
        }
    }
    return s.substr(st + 1, end - st - 1);
}

string longestPalindrome2(string s) {
    string ans;
    int n = s.length();
    int len = 0;        
    
    for (int i = 0; i < n; i++) {
        string curr = help(s, i, i); // odd
        if (curr.length() > len) {
            ans = curr;
            len = curr.length();
        }

        curr = help(s, i, i + 1); // even
        if (curr.length() > len) {
            ans = curr;
            len = curr.length();
        }
    }

    return ans;
}


int main(){
    string s = "aaaabbaa";
    cout<<longestPalindrome(s)<<endl;
    cout<<longestPalindrome2(s)<<endl;

    return 0;
}