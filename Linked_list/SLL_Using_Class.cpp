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

// case 1: Insertion at start
void insertAtStart(Node* &head, int data){
    if(head == NULL){
        Node *temp = new Node(data);
        head = temp;
    }
    else{
        Node *temp = new Node(data);
        temp->next = head;
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
    ptr->next = temp->next;
    temp->next = ptr;
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
        temp->next = NULL;  // for calling destructor in well manner
        delete(temp);
    }

    else{
        Node* prev = head;
        Node *temp = head->next;
        int i=0;
        while(i < (ind-1)){ 
            prev = prev->next;
            temp = temp->next;
            i++;
        }
        // after loop temp points to the (ind)th node
        prev->next = temp->next;
        temp->next = NULL;  // for calling destructor in well manner
        delete(temp);
    }
}


int main(){
/*
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
    // deleteNode(head,4);
    printList(head);
*/
    int arr1[] = {1,3,5,7,9,10,11},  arr2[] = {2,4,5,8,10,11};
    Node* head1 = NULL;
    Node* head2 = NULL;

    for(int i=0; i<7; i++){
        insertAtIndex(head1, i, arr1[i]);
    }
    printList(head1);
    cout<<endl;

    for(int i=0; i<6; i++){
        insertAtIndex(head2, i, arr2[i]);
    }
    printList(head2);
    cout<<endl;

    return 0;
}