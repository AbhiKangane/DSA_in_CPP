#include<iostream>
#include<queue>
using namespace std;

class Stack{
    int size;
    queue<int> q1;
    queue<int> q2;
    
public:
    Stack(){
        size = 0; //initialize size
    }

    void Push(int d){ // moving from 1st q to 2nd q 
        q2.push(d);
        size++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        // reversing  using swap
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void Pop(){ // removing from 1st q starting
        q1.pop();
        size--;
    }

    int Top(){
        return q1.front();
    }

    int Size(){
        return size;
    }
    
    bool Empty(){
        if(size == 0)
            return true;
        return false;
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