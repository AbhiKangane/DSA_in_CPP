// Raju and Rani like playing with strings, exploring the interesting patterns of smaller parts within them, called substrings.
// Presently, they are engrossed in a string-centric game and it is Raju's turn. His task involves two strings provided by Rani, namely S1 and S2. Raju is tasked with dividing the first string S1 into the fewest possible substrings, ensuring that all resulting substrings, whether in their original or reversed order, are present in S2 while also aiming for maximizing the length of current substring.

// For example, if S1 = "vanaja" and S2 = "rvanpnaja", then the output will be van|aja rather than va|naja.
// Note : The letter in the ith position in S1 can be used in exactly one substring of S1. The letters from S2 can be reused any number of times but the letters from S1 can be used only once. The letters are case sensitive in both the strings.

// Constraints
// 1 <= S1, S2 <= 10000
// The two strings S1, S2 consist of lower and upper case characters only.

// Input
// First line consists of a string S1.
// Second line consists of string S2.

// Output
// Print the string S1 as a concatenation of sub strings separated by '|'.

// Time Limit (secs)
// 1

// Examples
// Example 1
// Input
// VaisHnavI
// VIvekanandaJasHnavi

// Output
// V|a|i|sHnav|I

// Explanation
// Every sub string that is present in V|a|i|sHnav|I is also present in S2 in original or reversed order. No other way of doing sub strings on S1 will give less number of sub strings than this. Hence, we print V|a|i|sHnav|I.

// Example 2
// Input
// sudHanShu
// qniwprvAvnaHSsH

// Output
// Impossible
// Explanation
// As we can see, its impossible to sub string the string S1 based given conditions, thus we print "Impossible".

#include<bits/stdc++.h>
using namespace std;

bool isSubstringPresent(const string& substring, const string& S2) {
    if(S2.find(substring) != string::npos)
        return true;
    return false;
}

string substring_Quest(const string& S1, const string& S2) {
    unordered_map<char,int> mp1,mp2;
    for(char i:S1){
        mp1[i]++;
    }
    for(auto i:S2){
        mp2[i]++;
    }
    for(auto i:mp1){
        if(mp2[i.first]==0)
            return "Impossible";
    }

    vector<string> ans;
     long unsigned int i = 0;

    while (i < S1.length()) {
         long unsigned int j = i;

        while (j < S1.length()) {
            string currSubstr = S1.substr(i, j - i + 1);
            // for debugging
            // cout<<currSubstr<<" ";
            string revSubstr = currSubstr;
            reverse(revSubstr.begin(), revSubstr.end());

            if (isSubstringPresent(currSubstr, S2) || isSubstringPresent(revSubstr, S2)) {
                j++;
            } else {
                break;
            }
        }

        ans.push_back(S1.substr(i, j - i));

        i = j;
    }


    string finalAns;
    for (long unsigned int i=0; i<ans.size(); i++) {
        finalAns += ans[i];
      	if(i!=ans.size()-1)
          finalAns += '|';
    }
   
    return finalAns;
}


int main(){
    string s1, s2;
    cin>>s1>>s2;

    cout<<substring_Quest(s1,s2);
}