#include<iostream>
#include<stack>
using namespace std;

bool check_Balance(string s){
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        if(s[i] == '{' || s[i]=='(' || s[i]=='[')
            st.push(s[i]);
        
        else{
            if(s[i]=='}' && s[i]=='{' ||
               s[i]==']' && s[i]=='[' ||
               s[i]==')' && s[i]=='('
            )   
                return false;

            st.pop();
        }
    }
    return st.empty();
}

int main(){
    string s = "{([}])}";
    
    if(check_Balance(s))
        cout<<"Valid string\n";

    else
        cout<<"Invalid string\n";
        
    return 0;
}
