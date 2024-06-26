// solution for 
// leetcode 238 : https://leetcode.com/problems/implement-trie-prefix-tree/
// GFG : https://www.geeksforgeeks.org/problems/trie-insert-and-search0651/1

#include<iostream>
#include<vector>
using namespace std;

class Trie{
    public:
    class Node{
        public:
        bool end;
        Node* next[26];

        Node(){             // constructor for node
            end = false;
            for(int i=0; i<26; i++)
                next[i] = NULL;
        }    
    };

    Node* trie;             // creating object of Node class

    Trie(){                 // constructor for Trie
        trie = new Node();
    }


    // function for inserting word into trie
    void insert(string word){
        int i=0;
        Node* it = trie;

        while (i<word.size()){
            if(it->next[word[i] - 'a'] == NULL){ // if node doesn't exist
                it->next[word[i] - 'a'] = new Node();
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        it->end = true;
    }

    // fuction for searchinf in trie
    bool search(string word){
        int i=0;
        Node* it = trie;

        while (i<word.size()){
            if(it->next[word[i] - 'a'] == NULL){ // if node doesn't exist
               return false;
            }
            it = it->next[word[i] - 'a'];
            i++;
        }
        return it->end;
    }

    // Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
    bool startsWith(string prefix) {
        int i=0;
        Node* it = trie;

        while (i<prefix.size()){
            if(it->next[prefix[i] - 'a'] == NULL){ // if node doesn't exist
               return false;
            }
            it = it->next[prefix[i] - 'a'];
            i++;
        }
        return true;
    }
};


int main(){
    Trie *myTrie = new Trie();
    vector<string> words = {"abhishek", "ajay", "appa", "aai"};

    for(auto e: words){
        myTrie->insert(e);
    }

    // for searching
    if(myTrie->search("akshay"))
        cout<<"akshay is found\n";
    else
        cout<<"akshay doesn't exist\n";


    if(myTrie->search("ajay"))
        cout<<"ajay is found\n";
    else
        cout<<"ajay doesn't exist\n";

    
}
