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

    void insert_Word(string word){
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

    bool Search_Word(string word){
        return Help_Search(root, word);
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