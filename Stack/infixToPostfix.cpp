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

string infixToPostfix(string s){
    // reverse(s.begin(), s.end());   // this is used for infix to prefix
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
                st.pop();  // poping '(' from stack
            }
        }
        else{
            while(!st.empty() && precedence(st.top()) >= precedence(s[i])){
                result += st.top(); // concatenating in result
                st.pop();
            }
            st.push(s[i]);  // if(prec[st.top] < prec[s[i]]) then push(s[i]) 
        }
    }

    while (!st.empty()){
        result += st.top();
        st.pop(); 
    }

    // reverse(result.begin(), result.end());  // this is used for infix to prefix
    return result;
}

int main(){
    cout<<infixToPostfix("(a+b)/(c-d*e)");
    return 0;
}