// Reverse the given string S, without reversing individual words seperated buy dots
#include<bits/stdc++.h>
using namespace std;

string reverseWords(string s){
    string ans = "";
    string temp = "";

    for (int i = s.size(); i >= 0; i--){
        if(s[i] == '.'){
            reverse(temp.begin(), temp.end());
            ans += temp;
            ans.push_back('.');
            temp = "";
        }
        else{
            temp.push_back(s[i]);
        }
    }

// for handling 1st word
    reverse(temp.begin(), temp.end());
    ans += temp;
    return ans;
}

int main(){
    string s = "i.am.abhishek";

    cout<<reverseWords(s);
}