#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        // constructor
        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        ~Node(){
            int value = this->data;
            // Memory free
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            cout<<"Memory is free for node with data "<<value<<endl;
        }
};

void insertNode(Node* &tail, int element, int data){
    // empty list
    if(tail == NULL){
        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }

    // insertion of a node after node containing element as a data
    else{ 
        // non-empty list & there is a node containing element as data

        Node* temp = tail;

        while (temp->data != element){
            temp = temp->next;
        }

        // after loop temp points to a node containing element as data
        Node* ptr = new Node(data);
        ptr->next = temp->next;
        temp->next = ptr;
    }
}

void printList(Node* tail){
    Node* temp = tail;
    if(tail == NULL){
        cout<<"List is empty."<<endl;
        return;
    }

    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp!=tail);
}

void deleteNode(Node* &tail, int value){
    // for empty list
    if(tail == NULL){
        cout<<"List is empty, please check again."<<endl;
        return;
    }

    else{
        // non-empty list & assuming that value node present in list
        Node* prev = tail;
        Node *temp = prev->next;
        
        while(temp->data != value){ 
            prev = temp;
            temp = temp->next;
        }
        // after loop temp points to the (valued) node
        prev->next = temp->next;
        // for list containing only one node
        if(temp == prev){
            tail = NULL;
        }

        else if(tail == temp){ // for deleting 1st node
            tail = tail->next;
        }

        temp->next = NULL;  // for calling destructor in well manner
        delete(temp);
    }
}

bool isCircularList(Node* head){
    // empty list
    if(head == NULL){
        return true;
    }

    Node* temp = head->next;
    while (temp != NULL && temp != head){  // handling both conditions SLL & CLL
        temp = temp->next;
    }

    if(head == head)
        return true;
    
    return false;
    
}

int main(){
    Node *tail = NULL;
    insertNode(tail,0,1); //initially element = any data
    insertNode(tail,1,2);
    insertNode(tail,2,3);
    insertNode(tail,3,5);
    insertNode(tail,3,4); 
    insertNode(tail,5,6); 
    insertNode(tail,6,7); 
    
    deleteNode(tail, 7); // deleting last node
    deleteNode(tail, 1); // deleting 1st node
    // deleteNode(head,4);
    printList(tail);

    if(isCircularList(tail))
        cout<<"\nList is circular"<<endl;
    else
        cout<<"\nList is not circular"<<endl;

    return 0;
}