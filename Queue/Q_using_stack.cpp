#include<iostream>
#include<stack>
using namespace std;

class Queue{
    stack<int> s1;
    stack<int> s2;
    
public:
    Queue(){}

    void enqueue(int d){ // inserting 1st stack
        s1.push(d);
    }

    int dequeue(){ // moving from 1st stack to 2nd stack then poping from 2nd stack
        if(s1.empty() && s2.empty()){
            cout<<"\nQueue is empty"<<endl;
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topVal = s2.top();
        s2.pop();
        return topVal;        
    }

    bool isEmpty(){
        if(s1.empty() && s2.empty())
            return true;
        
        return false;
    }
};


int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout<<q.dequeue()<<endl<<endl;

    q.enqueue(4);
    q.enqueue(5);

    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.dequeue()<<endl;
    return 0;
}