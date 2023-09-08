// NVIDIA coding round 2nd ques
// Calculating required parenthesis for making all parenthesis are balanced

#include<iostream>
#include<stack>
using namespace std;

int Req_Parenthesis(string s){
    stack<char> st;
    int count =0;
    
    int i = 0;
    while (s[i] == ')'){  // while starting parenthesis are closed
        count++;
        i++;
    }

    while(i<s.length()){
        if(s[i] == '(')
            st.push(s[i]);
        
        else if(s[i] == ')' && st.empty())    // closing parenthesis found & stack is empty
            count++;

        else if(s[i] == ')' && st.top()=='(')    // closing parenthesis found after opening
            st.pop();

        i++;
    }
    return count + st.size();
}

int main(){
    string s = ")))(()(((()))))))(";   // req = 6
    
    int req = Req_Parenthesis(s);
    cout<<req;
        
    return 0;
}