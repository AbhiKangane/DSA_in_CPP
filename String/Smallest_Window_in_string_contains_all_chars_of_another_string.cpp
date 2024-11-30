// https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
/*
Given two strings s1 and s2. Find the smallest window in the string s1 consisting of all the characters(including duplicates) of the string s2. 
Return "-1" in case no such window is present. If there are multiple such windows of the same length, return the one with the least starting index.
Note: All characters are in lowercase letters. 

Examples:

Input: s1 = "timetopractice", s2 = "toc"
Output: "toprac"
Explanation: "toprac" is the smallest substring in which "toc" can be found.

*/

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        vector<int> mpp(26,0);
        for(char ch: p){
            mpp[ch-'a']++;
        }
        
        int req=p.length();
        int st=0, end=0, i=0;
        int n=s.length();
        
        if(req > n) return "-1";
        
        int minSize = INT_MAX;
 
        while(end < n){
            if(mpp[s[end]-'a'] > 0) req--;
            mpp[s[end]-'a']--; // -ve -> extra hai
            
            while(req==0){ // possible ans & window shrink -> st++
                int currSize = end-st+1;
                if(currSize < minSize){ // possible ans ki window/substring
                    minSize = currSize;
                    i = st;
                }
                
                mpp[s[st]-'a']++;
                if(mpp[s[st]-'a'] > 0){
                    req++;
                }
                st++;
            }
            end++;
        }
        
        return minSize == INT_MAX ? "-1" : s.substr(i,minSize);
    }
};
