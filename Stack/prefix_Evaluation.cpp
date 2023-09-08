#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int prefixEval(string s){
    stack<int> st;

    for(int i=s.length()-1; i>=0; i--){ // here taking characters from rightwards(ie. reverse order) for prefix Evaluation 
                                        // for postfix Eval takes characters from leftwards(ie. given order).
        if(s[i]>='0' && s[i]<='9') // if character is a digit
            st.push(s[i]-'0'); // push int value of digit char

        else{ // for operators
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();
            
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            
            case '-':
                st.push(op1 - op2);
                break;
            
            case '*':
                st.push(op1 * op2);
                break;
            
            case '/':
                st.push(op1 / op2);
                break;
            
            case '^':
                st.push(op1 ^ op2);
                break;
            
            default:
                cout<<"Invalid character";
                break;
            }
        }
    }

    return st.top();
}

int main(){
    string str = "-+7*45+20";  // its infix = {7+(4*5)}-(2+0)

    cout<<prefixEval(str)<<endl;
    return 0;
}
