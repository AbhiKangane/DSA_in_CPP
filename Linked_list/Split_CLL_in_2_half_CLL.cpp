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
        printf("%d-> ", temp->data);
        temp = temp->next;
    }while(temp!=tail);
    cout<<"head";
}

// finding middle node of CLL
Node* findMid(Node* tail){
    Node* slow = tail;
    Node* fast = tail->next;

    while (fast != tail && fast->next != tail){
        slow = slow->next;
        fast = fast->next->next;
    }

    // cout<<"\n"<<slow->data<<endl;
    return slow;
}

// dividing a linked list
void split_CLL(Node* head){
    // base case
    if(head == NULL){
        cout<<"NULL";
    }

    else if(head->next == head){
        cout<<head->data;
    }

    Node* mid = findMid(head);

    Node* lefthead = head; //starting of left half CLL
    Node* righthead = mid->next; //starting of right half CLL
    mid->next = lefthead; // breaking of original CLL & link mid to lefthead

    // for finding last node of 2nd half CLL
    Node* tempRight = righthead;
    while (tempRight->next != head){
        tempRight = tempRight->next;
    }
    // after loop tempRight points at last node
    tempRight->next = righthead;
    
    // printing two splitted CLL
    printList(lefthead);
    cout<<endl;
    printList(righthead);
    cout<<endl;
}

int main(){
    int arr[] = {1,5,3,7,11,13};
    Node* tail = NULL;
    insertNode(tail, -1, arr[0]); // for inserting start node
    
    for(int i=1; i<6; i++){
        insertNode(tail, arr[i-1], arr[i]);
    }
    printList(tail);
    cout<<"\nAfter splitting given CLL into two CLLs"<<endl;
    
    split_CLL(tail);
    
    return 0;
}