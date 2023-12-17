// Given 2 integers N & K, the task is to find string S of minimum length 
// such that it contains all possibel strings of size N as substring.
// The characters of string should be from integers ranging from 0 to K-1.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void dfs(string &curr, string &ans, unordered_map<string,int> &mp, int k){
    string temp;
    for(int i=k-1; i>=0; i--){
        temp = curr.substr(1);
        temp += char(i+48);

        if(mp.find(temp) == mp.end()){
            mp[temp] = 1;
            ans += char(i+48);
            dfs(temp,ans,mp,k);
            return;
        }
    }
}

string findString(int n, int k){
    string ans = "", temp = "";
    unordered_map<string,int> mp;

    for(int i=0; i<n; i++){
        ans += '0';
    }

    temp = ans; 
    mp[temp] = 1;
    dfs(temp, ans, mp, k);
    return ans;
}

int main(){
    int N=2, K=2;
    string s = findString(N, K);
    cout<<s;
}