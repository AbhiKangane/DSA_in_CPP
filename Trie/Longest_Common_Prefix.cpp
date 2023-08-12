#include<iostream>
#include<vector>
using namespace std;

class TrieNode{
    public: 
    char data;
    TrieNode* children[26];
    int child_Count;
    bool is_Terminal;

    TrieNode(char ch){
        data = ch;
        for (int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        child_Count = 0;
        is_Terminal = false;
    }
};

class Trie{
    public:
    TrieNode *root;

    Trie(char ch){ // creating TrieNode with null data
        root = new TrieNode('\0');
    }


    // insertion in trie
    void Help_Insert(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            root->is_Terminal = true;
            return;
        }

        // assumption word contains small letters
        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if(root->children[index] != NULL)
            child = root->children[index];

        else{  // absent
            child = new TrieNode(word[0]);
            root->child_Count ++;
            root->children[index] = child;
        }

        // recursion
        Help_Insert(child, word.substr(1));
    }

    void insert_Word(string word){
        Help_Insert(root, word);
    }

    void lcp(string str, string &ans){
        for(int i=0; i<str.length(); i++){
            char ch = str[i];

            if(root->child_Count == 1){
                ans.push_back(ch);
                // continue forward
                int index = ch -'a';
                root = root->children[index];
            }
            else
                break;
            
            if(root->is_Terminal)
                break;
        }
    }
};

string Longest_Common_Prefix(vector<string> &arr, int n){
    Trie *t = new Trie('\0');

    // insert strings into Trie
    for(int i = 0; i < n; i++){
        t->insert_Word(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first, ans);
    return ans;
}


int main(){
    vector<string> st {"abhi", "abhishek", "abhijeet", "ab"};

    cout<<"Longest Common Prefix: "<<Longest_Common_Prefix(st, 4);
}