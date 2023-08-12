#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        // constructor
        Node(int data){
            this->data = data;
            this->prev = NULL;
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

// case 1: Insertion at start
void insertAtStart(Node* &head, int data){
    if(head == NULL){
        Node *temp = new Node(data);
        head = temp;
    }
    else{
        Node *temp = new Node(data);
        temp->prev = NULL;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
// case 2: Insertion at end
void insertAtEnd(Node* &head, int data){
    Node *ptr = new Node(data);
    Node *temp = head;
    while(temp->next!=NULL){ 
        temp = temp->next;
    }
    // after loop temp points to the last node
    temp->next = ptr;
    ptr->prev = temp;
    ptr->next = NULL;
}

// case 3: Insertion at index(0 based)
void insertAtIndex(Node* &head, int ind, int data){
    if(ind == 0){ //inserting at start
        insertAtStart(head,data);
        return;
    }

    Node *ptr = new Node(data);
    Node *temp = head;
    int i=0;

    while(i < ind-1){ 
        temp = temp->next;
        i++;
    }
    // after loop temp points to the (ind-1) node

    // if temp points to the last node
    if(temp->next == NULL){
        insertAtEnd(head, data);
        return;
    }
    
    ptr->next = temp->next;
    temp->next->prev = ptr;
    temp->next = ptr;
    ptr->prev = temp;
}

void printList(Node* &head){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL";
}

void deleteNode(Node* &head, int ind){
    // for starting node
    if(ind == 0){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;  // for calling destructor in well manner
        delete(temp);
    }

    else{
        Node* previous = head;
        Node *temp = head->next;
        int i=0;
        while(i < (ind-1)){ 
            previous = previous->next;
            temp = temp->next;
            i++;
        }
        // after loop temp points to the (ind)th node
        temp->prev = NULL;
        previous->next = temp->next;
        temp->next = NULL;  // for calling destructor in well manner
        
        delete(temp);
    }
}

int main(){
    Node *head = new Node(2);
    insertAtEnd(head,3);
    insertAtEnd(head,5);
    insertAtEnd(head,6);

    insertAtStart(head,1);

    insertAtIndex(head,0,0);  // inserting at start
    insertAtIndex(head,4,4); 
    insertAtIndex(head,7,7);

    deleteNode(head, 7); // deleting last node
    deleteNode(head, 0); // deleting 1st node
    deleteNode(head,4);
    printList(head);
}