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

// Insertion at any index(0 based)
void insertAtIndex(Node* &head, int ind, int data){
    if(ind == 0){ //inserting at start
        if(head == NULL){ // if list is empty
            Node *temp = new Node(data);
            head = temp;
        }
        else{
            Node *temp = new Node(data);
            temp->next = head;
            head = temp;
        }
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



Node* Remove_Duplicates(Node* head){
    // empty list
    if (head == NULL){
        return NULL;
    }

    // non-empty LL
    Node* temp = head;
    while (temp->next != NULL){ // if we take (temp!=NULL) as while condition then below if condition must add one condition (temp->next != NULL) 
        if(temp->data == temp->next->data){
            
            Node* ptr = temp->next;
            // Node* next_next = ptr->next;
            temp ->next = ptr->next;

            delete(ptr);
            // temp ->next = next_next;
        }
        else{
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    int arr[] = {1,2,2,2,3,3,4};
    Node* head = NULL;

    for(int i=0; i<7; i++){
        insertAtIndex(head, i, arr[i]);
    }
    printList(head);
    cout<<"\nAfter Removing Duplicated Nodes: "<<endl;

    
    Node* ans = Remove_Duplicates(head);
    printList(ans);
    return 0;
}