#include<iostream>
#include<vector>
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



    //  main solution starts
    void print_Suggestions(TrieNode* curr, vector<string> &temp, string prefix){
        if(curr->is_Terminal)
            temp.push_back(prefix);

        for(char ch = 'a'; ch <= 'z'; ch++){
            TrieNode *next = curr->children[ch - 'a'];

            if(next != NULL){
                prefix.push_back(ch);
                print_Suggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> get_Suggestions(string str){
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for(int i=0; i<str.length(); i++){
            char last_char = str[i];

            prefix.push_back(last_char);

            // check for last_char
            TrieNode *curr = prev->children[last_char - 'a'];

            // if not found
            if(curr == NULL)
                break;

            // if found
            vector<string> temp;
            print_Suggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        return output;
    }
};

vector<vector<string>> phone_Directory(vector<string> &contact_List, string &query_Str){
    // creation of trie
    Trie *t = new Trie();

    // insert all contact in Trie
    for(int i=0; i<contact_List.size(); i++){
        string str = contact_List[i];
        t->insert_Word(str);
    }

    // return ans
    return t->get_Suggestions(query_Str);
}


int main(){
    vector<string> contact_List = {"cod", "coding", "codding", "code", "coly", "codingninja"};
    string query_str = "codingn";

    vector<vector<string>> suggestions = phone_Directory(contact_List, query_str);

    for(int i=0; i<7; i++){
        for(int j=0; j<suggestions[i].size(); j++){
            cout<<suggestions[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}