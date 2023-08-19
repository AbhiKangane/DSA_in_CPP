// leetcode : 

#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    
    for(auto x: strs){
        string word = x;
        sort(word.begin(), word.end());    // sorting the word & use it key
        mp[word].push_back(x);             // pushing anagrams of word into vector as values related to key
    }
    
    vector<vector<string>> ans;
    for(auto x: mp){
        ans.push_back(x.second);          // inserting vector related key of mp
    }
    return ans;
}


int main(){
    vector<string> strs = {"bat", "eat", "nam", "ate", "tea", "man"};
    vector<vector<string>> Groups =  groupAnagrams(strs);     // Groups = {{"bat"}, {"eat","ate","tea"}, {"nam","man"}};

    for (int i = 0; i < Groups.size(); i++){
        for(int j=0; j<Groups[i].size(); j++)
            cout<<Groups[i][j]<<" ";
        cout<<endl;
    }
    
    return 0;
}