#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};


class Stack{
  private:
    Node* top=NULL;

  public:
    void push(int data){
        Node* temp = new Node(data);
        if(!temp){
            cout<<"\nStack Overflow!!!\n";
            exit(1);
        }
        // Add new node at top & change top as new node 
        temp->next = top;
        top = temp;
    }

    int isEmpty(){
        return top == NULL;
    }

    int peek(){
        if(!isEmpty())
            return top->data;
        else{   
            cout<<"\nstack is empty\n";
            return -1;
        }
    }

    void pop(){
        Node *temp;
        if(isEmpty()){
            cout<<"\nStack underflow\n";
        }
        else{
            temp = top;
            top = top->next;
            free(temp);
        }
    }
};


int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();

    st.push(6);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    
    // st.pop();      // STACK BECOMES EMPTY
    
    // cout<<st.peek()<<endl;   // TOP AFTER EMPTY STACK
    // st.pop();                // POP AFTER STACK IS EMPTY

    st.isEmpty() ? cout<<"STACK IS EMPTY" : cout<<"STACK IS NOT EMPTY";
    return 0;
}