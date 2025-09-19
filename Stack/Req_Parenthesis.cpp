// NVIDIA coding round 2nd ques
// Calculating required parenthesis for making all parenthesis are balanced

#include<iostream>
#include<stack>
using namespace std;

int Req_Parenthesis(string s){
    stack<char> st;
        
    for(auto i: s){
        if(i=='(')
            st.push(i);
        else{
            if(!st.empty() && st.top()=='(')
                st.pop();
            else
                st.push(i);
        }
    }
    return st.size();
}

int main(){
    string s = ")))(()(((()))))))(";   // req = 6
    
    int req = Req_Parenthesis(s);
    cout<<req;
        
    return 0;

}
