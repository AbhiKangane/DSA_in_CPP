#include<iostream>

using namespace std;

class stack{
    public:
    int *arr;
    int size;
    int top;

    stack(int s){
        this->size = s;
        arr = new int[size];
        top = -1;
    }

    void push(int data){
        if(size-top > 0){
            top++;
            arr[top] = data;
        }
        else
            cout<<"stack overflow"<<endl;
    }

    int pop(){
        if(top >= 0){
            int popped_element = arr[top];
            top--;
            return popped_element;
        }
        else{
            cout<<"stack underflow"<<endl;
            return -1;
        }
    }

    int peak(){
        if(top >= 0)
            return arr[top];

        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }

    void display(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return;
        }

        int t = top;
        while(t >= 0){
            cout<<arr[t]<<" ";
            t--;
        }
        cout<<endl;
    }
};



int main(){
    stack s(4); //creating & initialising stack of size 5(indexing starts from 0)
    s.push(1);
    // cout<<s.top;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout<<"Popped Element: "<<s.pop()<<endl;
    s.push(6);
    
    cout<<"Display Stack: ";
    s.display();

    s.push(7);
    cout<<"Popped Element: "<<s.pop()<<endl;
    cout<<"Popped Element: "<<s.pop()<<endl;
    cout<<"Popped Element: "<<s.pop()<<endl;
    cout<<"Popped Element: "<<s.pop()<<endl;
    cout<<"Popped Element: "<<s.pop()<<endl;
    
    cout<<"Display Stack: ";
    s.display();

    cout<<"Popped Element: "<<s.pop()<<endl;
    
    return 0;
}
