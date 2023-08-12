#include<iostream>
using namespace std;

class Circular_Queue{
    private:
    int *arr, size;
    int front, rear;

    public:
    Circular_Queue(int s){  // initialization
        size = s;
        arr = new int[s];
        front = -1;
        rear = -1;
    }

    // Check if the queue is full
    int isFull() {
        if ((front == rear + 1) || (front == 0 && rear == size - 1)) 
            return 1;
        return 0;
    }

    // Check if the queue is empty
    int isEmpty() {
        if (front == -1) 
            return 1;
        return 0;
    }

    // Adding an element
    void enqueue(int element) {
        if (isFull())
            printf("\n Queue is full!! \n");

        else {
            if (front == -1)  // if q is empty
                front = 0;

            rear = (rear + 1) % size;
            arr[rear] = element;
            printf("\n Element Inserted -> %d", element);
        }
    }

    // Removing an element
    int dequeue() {
        int element;
        if(isEmpty()) {
            printf("\n Queue is empty !! \n");
            return (-1);
        } 

        else {
            element = arr[front];
            if (front == rear) {  // only 1 element
                front = -1;
                rear = -1;
            }

            else {
                front = (front + 1) % size; 
            }
            printf("\n Element Deleted -> %d \n", element);
            return (element);
        }
    }

    // Display the queue
    void display() {
        int i;
        if (isEmpty())
            printf(" \n Empty Queue\n");
        else {
            printf("\n Front -> %d ", front);
            printf("\n Items -> ");
            for (i = front; i != rear; i = (i + 1) % size) {
                printf("%d ", arr[i]);
            }
            printf("%d ", arr[i]);
            printf("\n Rear -> %d \n", rear);
        }
    }
};

int main(){
    Circular_Queue Q(5);
    Q.display();

    Q.enqueue(1);
    Q.display();

    Q.enqueue(2);
    Q.display();
    
    Q.enqueue(3);
    Q.display();
    
    Q.enqueue(4);
    Q.display();
    
    Q.enqueue(5);
    // cout<<"\nAfter inserting all elements: ";
    Q.display();

    cout<<"\nTry to insert: ";
    Q.enqueue(6);
    Q.display();


    Q.dequeue();
    cout<<"\nAfter deleting a element: ";
    Q.display();

    cout<<"\nTry to insert after delete first element: ";
    Q.enqueue(7);  // cicularly insert at 0th index
    Q.display();

    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();
    Q.dequeue();  
    Q.display();  //  after deleting all elements

    Q.dequeue(); // try to delete, after deleting all elements
    
    cout<<"\nInsertion, after empty Queue: ";
    Q.enqueue(1); 
    Q.display();

    return 0;
}