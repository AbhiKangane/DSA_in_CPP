#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Queue{
private:
    Node* front;
    Node* rear;

public:
    Queue(){
        front = NULL;  // for pointing first node
        rear = NULL;  // for pointing last node
    }

    void push(int val){  //insert at last
        Node* p = new Node(val);
        // if q is empty
        if(front == NULL){
            rear = p;
            front = p;
            return;
        }

        rear->next = p;
        rear = p;
    }

    void pop(){   // delete from start
        if(front == NULL){
            cout<<"\nCan't delete, Queue is empty"<<endl;
            return;
        }

        Node* delNode = front;
        front = front->next;
        delete delNode;
    }

    int peek(){  // returns first->data
        if(front == NULL){
            cout<<"\nNo element in queue"<<endl;
            return -1;
        }
        return front->data;
    }

    bool empty(){
        if(front == NULL){
            cout<<"\nQueue is empty"<<endl;
            return true;
        }
        return false;
    }
};

int main(){
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.empty();
    return 0;
}