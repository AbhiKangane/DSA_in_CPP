#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int start=0;
       int end=s.size()-1;
       while(start<=end){
           if(!isalnum(s[start])){start++; continue;}
           if(!isalnum(s[end])){end--;continue;}
           if(tolower(s[start])!=tolower(s[end]))return false;
           else{
               start++;
               end--;
           }
       }
       return true;
}

int main(){
    string s = "race a car";
    // cout<<s[0]<<endl;
    // cout<<'a'+1;
    cout<<isPalindrome(s);
    return 0;
}