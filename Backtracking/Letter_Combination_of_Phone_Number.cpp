// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
// 2 -> abc, 3->def, 4->ghi, 5->jkl, 6->mno, 7->pqrs, 8->tuv, 9->wxyz
// Example 1:
// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

#include<bits/stdc++.h>
using namespace std;

void findAll(map<char,string> &mp, string digits, vector<string> &ans, string &comb, int currIdx){
    if(currIdx >= digits.length()){
        ans.push_back(comb);
        return;
    }

    char currNum = digits[currIdx];
    string alpha = mp[currNum];

    for(int i=0; i<alpha.size(); i++){
        comb.push_back(alpha[i]);                  // inserting char into combination
        findAll(mp, digits, ans, comb, currIdx+1); // for inserting next digits char
        comb.pop_back();                           // removing last char ie. for backtracking or trying new comb with alpha[i+1]
    }
    return;
}

vector<string> letterCombinations(string digits){
    map<char,string> mp{{'1',""}, {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
                        {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}};
    string comb = "";
    vector<string> ans;

    // edge case
    if(digits.size() == 0)
        return ans;
    
    findAll(mp, digits, ans, comb, 0);
    return ans;
}

int main(){
    string digits = "23";

    vector<string> ans = letterCombinations(digits);
    cout<<"Printing all combinations :\n";
    for(auto i: ans){
        cout<<i<<" ";
    }

    return 0;
}