#include <bits/stdc++.h>
using namespace std;

void InsertAtBottom(stack<int> &S, int X){
    // base case
    if (S.empty()){
        S.push(X);
        return;
    }

    int num = S.top();
    S.pop();

    // recursive call
    InsertAtBottom(S, X);

    S.push(num);
}

// TC = O(n^2) & SC = O(1)
void Reverse1(stack<int> &St){
    // base case
    if (St.empty())
        return;

    int num = St.top();
    St.pop();

    Reverse1(St);

    InsertAtBottom(St, num);
}

// TC = O(n) & SC = O(n)
void Reverse2(stack<int> &st){
    queue<int> q;
    int n = st.size();
    
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
}

int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
   
//    before reversing
    // while (!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    // Reverse1(st);

    Reverse2(st);

    while (!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    
}