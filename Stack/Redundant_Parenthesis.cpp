// this problem is related to is there extra brackets are used in expression

#include<bits/stdc++.h>
using namespace std;

bool check(string s){
    stack<char> st;

    for(int i=0; i<s.size(); i++){
        if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
            st.push(s[i]);
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            if(st.top() == '(')  // if immediately closing prenthesis found then theu0 will be redundant parenthesis 
                return true;

            while(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'){
                st.pop();
            }
            st.pop();  // removing opening parenthesis
        }
    }

    return false;
}

int main(){
    string s = "((a+b))";

    if(check(s))
        cout<<"There will be redundant parenthesis present"<<endl;
    else
        cout<<"No redundant parenthesis found"<<endl;
    return 0;
}