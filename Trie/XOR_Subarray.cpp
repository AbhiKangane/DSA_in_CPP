// find maximum XOR of two numbers in array
// ex : arr[] = {1,2,8};
// 1^2 = (01) ^ (10) = (11) = 3            ,    1^8 = (0001) ^ (1000) = (1001) = 9
// 2^8 = (0010) ^ (1000) = (1010) = 10
// ans = 10

#include<bits/stdc++.h>
using namespace std;

// brute force
int max_XOR(vector<int> &a){
    int ans = 0;
    for (int i = 0; i < a.size()-1; i++){
        for(int j=i+1; j<a.size(); j++)
            ans = max(ans, a[i]^a[j]);
    }
    return ans;
}


// using Trie
int int_size = 32;

class TrieNode{
    public:
    TrieNode *next[2];

    TrieNode(){
        next[0] = NULL;  // if cur_bit is 0 act as left
        next[1] = NULL;  // if cur_bit is 1 act as right
    }
};


// function for inserting word into trie
TrieNode* buildtrie(vector<int> &a){
    TrieNode* root = new TrieNode();
    int n = a.size();

    for (int i = 0; i<n; i++){
        int num = a[i];
        TrieNode *cur = root;

        for (int i = 31; i >= 0; i--){
            int bit = (num>>i) & 1;     // finding current bit
            if(cur->next[bit] == NULL){
                cur->next[bit] = new TrieNode();     // creating new trienode
            }
            cur = cur->next[bit];
        }
    }
    return root;
}


// function for returning maximum XOR
int helper(TrieNode *root, vector<int> &a) {
    int res = 0;

    for (int i = 0; i < a.size(); i++){
        int num = a[i];
        TrieNode *it = root;
        int cur_max = 0;

        for(int i = 31; i >= 0; i--){
            // use ternary operator instead of using following coditional lines
            int bit = ((num>>i) & 1) ? 0 : 1;
/*
            int cur_bit = (num>>i) & 1 ;     // finding current bit
            if(cur_bit == 1)
                cur_bit = 0;                 // we have to set opposite bit for finding maximum XOR sum
            else
                cur_bit = 1;
*/          
            if(it->next[bit]){            // for going in opposite direction
                cur_max <<= 1;               // adding contribution to cur_max
                cur_max |= 1;
                it = it->next[bit];
            }

            else{
                cur_max <<= 1;
                cur_max |= 0;                   // this is optional it can't affect
                it = it->next[bit xor 1];   // we have to go opposite bit
            }
        }
        res = max(res, cur_max);
    }
    return res;
}

int main(){
    // int n;
    // cout<<"Enter the size of array: ";
    // cin>>n;

    // cout<<"Enter numbers in array: ";
    vector<int> v = {1,2,8};
    // for (int i = 0; i < n; i++){
    //     cin>>v[i];
    // }

    // using brute force
    // cout<<"Maximum XOR of 2 numbers in array is: "<<max_XOR(v);

    TrieNode *root = buildtrie(v);
    cout<<"Maximum XOR of 2 numbers in array is: "<<helper(root, v);
    return 0;
}