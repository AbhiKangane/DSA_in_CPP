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

int length(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

// function for rotating last 'k' nodes
Node* RotateK(Node* head, int k){
    Node* newHead;
    Node* newTail;
    Node* tail = head;

    int l = length(head);
    k %= l; 
    int count = 1;

    while (tail->next != NULL){
        if(count == l - k){
            newTail = tail; // setting newTail
        }

        if(count == l - k + 1){
            newHead = tail; // setting newHead
        }
        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    Node* head = NULL;
    

    for(int i=0; i<10; i++){
        insertAtIndex(head, i, arr[i]);
    }
    printList(head);
    cout<<endl;

    Node* ans = RotateK(head, 3);
    printList(ans);
    return 0;
}
