#include<iostream>
#include<queue>
using namespace std;

class Stack{
    int size;
    queue<int> q;
    
public:
    Stack(){ }

    void Push(int d){
        q.push(x);
        for(int i=0; i<q.size()-1; i++){
            q.push(q.front());
            q.pop();
        }
    }

    void Pop(){ // removing from q starting
        int del = q.front();
        q.pop();
        return del;
    }

    int Top(){
        return q.front();
    }

    int Size(){
        return q.size();
    }
    
    bool Empty(){
        return q.size()==0;
    }
};


int main(){
    Stack st;
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Push(5);

    cout<<st.Top()<<endl;
    st.Pop();
    cout<<st.Top()<<endl;
    st.Pop();
    cout<<st.Top()<<endl;
    st.Pop();
    cout<<st.Top()<<endl;
    st.Pop();
    cout<<st.Top()<<endl;
    st.Pop();

    cout<<"Size of stack: "<<st.Size();
    return 0;
}
