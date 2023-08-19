// leetcode 438 

#include<bits/stdc++.h>
using namespace std;

bool isVectorsEqual(vector<int> freq1, vector<int> freq2){
    for(int i=0; i<26; i++)
        if(freq1[i] != freq2[i])
            return false;
        
    return true;
}

vector<int> findAnagrams(string s2, string s1) {
    vector<int> ans;
    int len1 = s1.size() ;
    int len2 = s2.size() ;
    if(len1 > len2)  // if 1st string is greater than 2sd string
        return ans;

    vector<int> Freq1(26,0); // for storing frequency of chars in s1
    
    for (int i = 0; i<len1; i++) {
            Freq1[s1[i]-'a']++;
    }

    int start=0, end=len1-1;
    vector<int> Freq2(26,0);  // for storing frequency of chars in window of size len1 in string s2
    
    for(int i=0; i<len2; i++){
        Freq2[s2[i]-'a'] ++;
        if(i >= len1-1 && end < len2){    // for all windows of size len1
            if(isVectorsEqual(Freq1, Freq2)){  // checking if(s2 is anagram with curr window)
                    ans.push_back(start);
            }
            Freq2[s2[start]-'a'] --;  // removing freq of starting element of window
            start++; 
            end++;
        }
    }
    return ans;
}


int main(){
    string s = "cbaebabacd", p = "abc";
    vector<int> ans = findAnagrams(s,p);

    for (int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}