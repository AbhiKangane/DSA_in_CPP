#include<iostream>
using namespace std;

class queue{
    private:
    int *arr, size;
    int front, rear;

    public:
    queue(int s){
        size = s;
        arr = new int(size);
        front = 0;
        rear = 0;
    }

    void enqueue(int data){
        if(rear == size){
            cout<<"Can't insert, Queue is Full"<<endl;
        }

        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue(){
        if(front == rear){
            cout<<"Can't delete, Queue is empty"<<endl;
            return -1;
        }

        else{
            int del = arr[front];
            arr[front] = -1;
            front++;
            if(front == rear){  // if memory free but queue is empty(as front = rear)
                front = 0;  // memory utilization
                rear = 0;
            }
            return del;
        }
    }

    bool isEmpty(){
        if(front == rear){
            cout<<"Queue is empty!!!"<<endl;
            return true;
        }

        else{
            cout<<"Queue is not empty!!!"<<endl;
            return false;
        }
    }

    void display(){
        if(front == rear){
            cout<<"Queue is empty"<<endl;
            return;
        }

        else{
            for(int i = front; i<rear; i++)
                cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }
};

int main(){
    queue Q(5);
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    cout<<"After inserting all elements: ";
    Q.display();

    cout<<"\nTry to insert: ";
    Q.enqueue(6);
    Q.display();


    cout<<"\nElement deleted: "<<Q.dequeue();
    cout<<"\nAfter deleting a element: ";
    Q.display();

    cout<<"\nTry to insert after delete first element: ";
    Q.enqueue(7);  // space is available but can't insert
    Q.display();

    cout<<"\nElement deleted: "<<Q.dequeue();
    cout<<"\nElement deleted: "<<Q.dequeue();
    cout<<"\nElement deleted: "<<Q.dequeue();
    cout<<"\nAfter Deleting some elements: ";
    Q.isEmpty();

    cout<<"\nAfter Deleting all elements: ";
    Q.dequeue();  // deleting all elements
    Q.isEmpty();

    cout<<"\nElement deleted: "<<Q.dequeue(); // try to delete, after deleting all elements

    cout<<"\nInsertion, after empty Queue: ";
    Q.enqueue(1); 
    Q.enqueue(2);
    Q.display();

    return 0;
}