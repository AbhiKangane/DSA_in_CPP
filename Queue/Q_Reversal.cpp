#include<bits/stdc++.h>
using namespace std;

queue<int> revQ(queue<int> q){
    stack<int> st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    return q;
}

queue<int> rev_1st_K_Elements(queue<int> q, int k){
    // step 1: pop 1st k elements from Q & put into stack
    stack<int> st;
    for(int i=0; i<k; i++){
        int val = q.front();
        q.pop();
        st.push(val); 
    }

    // step 2: fetch from stack & push into q
    while(!st.empty()){
        int val = st.top();
        st.pop();
        q.push(val);
    }
    
    // step 3: fech 1st (n-k) elements from q and push_back
    int t = q.size()-k;
    while(t--){
        int val = q.front();
        q.pop();
        q.push(val);
    }
    return q;
}

int main(){
    queue<int> q;
    q.push(5);
    q.push(4);
    q.push(3);
    q.push(2);
    q.push(1);

    queue<int> rq = revQ(q);
    cout<<"\nAfter reversing : ";
    while(!rq.empty()){
        cout<<rq.front()<<" ";
        rq.pop(); 
    }

    // original q = 5,4,3,2,1
    queue<int> rkq = rev_1st_K_Elements(q,3);
    cout<<"\nAfter reversing first 3 elements: ";
    while(!rkq.empty()){
        cout<<rkq.front()<<" ";
        rkq.pop(); 
    }
    return 0;
}