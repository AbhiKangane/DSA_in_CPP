#include<bits/stdc++.h>
using namespace std;

// Type 1: Storing all Permutations including duplicates
void permutation(int left, int right, string &s, vector<string> &ans){
    if (left == right){// reach the end of s
        ans.push_back(s);
        return ;
    } 

    for (int j=left; j<=right; j++){
        swap(s[left], s[j]);
        permutation(left+1, right, s, ans);
        swap(s[left], s[j]);     // backtrack
    }
}

vector<string> AllPerm(string &s){
    vector<string> ans;
    int n = s.size();
    sort(s.begin(), s.end());
    permutation(0,n-1,s,ans);

    return ans; 
}


// Type 2: Storing  unique permutations 
void FindUniquePerm(int left, int right, string &s, vector<string> &ans){
    if (left == right){// reach the end of s
        ans.push_back(s);          // if we use set<string> ans, then we need to insert instead of push_back
        return ;
    } 

    FindUniquePerm(left+1, right, s, ans);    // if we use set<string> ans, then we don't need this call

    for (int j=left+1; j<=right; j++){       // if we use set<string> ans, then we can start j from left
        // if we use set<string> ans, then don't need following condition
        if (s[left] != s[j]){        // checking for unique numbers
            swap(s[left], s[j]);
            FindUniquePerm(left+1, right, s, ans);
            swap(s[left], s[j]);     // backtrack
        } 
    }
}    

vector<string> permuteUnique(string &s) {
    vector<string> ans;
    int n = s.size();
    sort(s.begin(), s.end());
    FindUniquePerm(0,n-1, s, ans);

    // return vector<string>(ans.begin(), ans.end());     // if set<string> ans is used insted of vector

    return ans;
}


int main(){
    string str ="AAC";
    int n = str.size();

    cout<<"Printing all Permutations of string : \n";
    vector<string> perms = AllPerm(str);
    for (int i = 0; i < perms.size(); i++){
        cout<<perms[i]<<" ";
    }

    cout<<"\n\nPrinting unique Permutations of string : \n";
    vector<string> uniquePerm = permuteUnique(str);
    for (int i = 0; i < uniquePerm.size(); i++){
        cout<<uniquePerm[i]<<" ";
    }
        
    return 0;
}
