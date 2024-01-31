// leetcode 208: https://leetcode.com/problems/implement-trie-prefix-tree/
/*
Implement the Trie class:
    1) Trie() Initializes the trie object.
    2) void insert(String word) Inserts the string word into the trie.
    3) boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
    4) boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
*/
#include<iostream>
using namespace std;

class TrieNode{
    public: 
    char data;
    TrieNode* children[26];
    bool is_Terminal;

    TrieNode(char ch){
        data = ch;
        for (int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        is_Terminal = false;
    }
};

class Trie{
    public:
    TrieNode *root;

    Trie(){ // creating TrieNode with null data
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
            root->children[index] = child;
        }

        // recursion
        Help_Insert(child, word.substr(1));
    }

    void insert(string word){
        Help_Insert(root, word);
    }


    // searching in trie
    bool Help_Search(TrieNode* root, string word){
        // base case
        if(word.length() == 0){
            return root->is_Terminal;
        }

        // assumption word contains small letters
        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if(root->children[index] != NULL)
            child = root->children[index];

        else{  // absent
            return false;
        }

        // recursion
        return Help_Search(child, word.substr(1));
    }

    bool search(string word){
        return Help_Search(root, word);
    }

    
    bool Help_startsWith(TrieNode* root, string word)
    {
        if(word.length()==0) 
            return true;
        
        int index=word[0]-'a';
        
        if(root->children[index]!=NULL)
            return Help_startsWith(root->children[index],word.substr(1));
        
        return false;
    }
    bool startsWith(string prefix) {
        return Help_startsWith(root, prefix);
    }
};
int main(){
    Trie t;
    t.insert_Word("abcd");
    t.insert_Word("abhishek");
    t.insert_Word("ajay");
    t.insert_Word("abhijeet");

    cout<<t.Search_Word("ajayk")<<endl;

    return 0;
}
