#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int precedence(char c){
    if(c == '^')
        return 3;
    
    else if(c == '/' || c == '*')
        return 2;
    
    else if(c == '+' || c == '-')
        return 1;

    else
        return -1;
}

string infixToPrefix(string s){
    reverse(s.begin(), s.end());
    string result;
    stack<char> st;

    for(int i=0; i<s.length(); i++){
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
            result += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                result += st.top();
                st.pop();
            }
            if(!s.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && precedence(st.top()) >= precedence(s[i])){
                result += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty()){
        result += st.top();
        st.pop(); 
    }

    reverse(result.begin(), result.end());
    return result;
}

int main(){
    cout<<infixToPrefix("a+b*c");
    return 0;
}