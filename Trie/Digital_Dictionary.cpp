#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
        node *next[26];
        bool end;
    
    node(){
        for(int i=0; i<26; i++){
            next[i] = NULL;
        }
        end = false;
    }
};

class Trie{
    private:
        node *root;

    public:
    Trie(){
        root = new node();
    }

    void insert(string &s){
        node *it = root;
        for(auto c: s){
            if(!it->next[c-'a'])
                it->next[c-'a'] = new node();
            it = it->next[c-'a'];
        }
        it->end = true;
    }

    void find(string &s){
        node *it = root;
        for(auto c:s){
            if(!it->next[c-'a']){
                cout<<"NO Suggestions!!!\n";
                insert(s);
                return ;
            }
            it = it->next[c-'a'];
        }
        vector<string> res;
        printAll(it,s,res,"");

        for(auto c:res){
            cout<<s<<c<<"  ";
        } 
    }

    void printAll(node *it, string &s, vector<string> &res, string curr){
        if(it==NULL)
            return ;
        if(it->end)
            res.push_back(curr);
        for(int i=0; i<26; i++){
            if(it->next[i])
                printAll(it->next[i],s,res,curr+char('a'+i));
        }
    }
};


int main(){
    Trie T;
    int n; 
    cout<<"Enter Size of Dictionary : ";
    cin>>n;
    vector<string> dict(n);  // given dictionary like {pet,peter,rat,rack}
    cout<<"Enter words in Dictionary : ";
    for(auto &i: dict){
        cin>>i;
        T.insert(i);
    }

    // for queries
    int q; 
    cout<<"Enter Number of Queries : ";
    cin>>q;
    while (q--){
        string s;
        cout<<"Enter Query : ";    // like pe, pet, r, abc
        cin>>s;
        cout<<"Result : ";
        T.find(s);
        cout<<endl;
    }
    
    return 0;
}