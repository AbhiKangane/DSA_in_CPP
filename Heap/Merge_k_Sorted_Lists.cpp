#include<bits/stdc++.h>
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


class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};


Node* merge_KSorted_Lists(vector<Node*> &list_Array){
    // creating minheap of node type
    priority_queue<Node*, vector<Node*>, compare> minheap;
    int k = list_Array.size();

    if(k == 0)
        return NULL;
    
    // step 1: inserting 1st node of each list in minheap
    for(int i = 0; i < k; i++){
        if(list_Array[i] != NULL)
            minheap.push(list_Array[i]);
    }
    
    // for merged_List
    Node* head = NULL;
    Node* tail = NULL;

    // for remaining nodes
    while(minheap.size() >0){
        Node* top = minheap.top();
        minheap.pop();

        if(top->next != NULL)
            minheap.push(top->next);
        
        // initially merged _List is empty
        if(head == NULL){ // insertion in merged_List at 1st time
            head = top;
            tail = top;
        }

        else{// if merged _List is not empty
            tail->next = top;
            tail = top;
        }
    }
    return head;
}

int main(){
    int arr1[5] = {1,3,5,7,9},
        arr2[5] = {2,4,5,8,10},
        arr3[5] = {6,8,10,11,12};

    Node *head1 = NULL, *head2 = NULL, *head3 = NULL;

    for(int i=0; i<5; i++){
        insertAtIndex(head1, i, arr1[i]);
        insertAtIndex(head2, i, arr2[i]);
        insertAtIndex(head3, i, arr3[i]);
    }
    // printList(head1);
    // cout<<endl;
    
    // printList(head2);
    // cout<<endl;

    // printList(head3);
    // cout<<endl;

    vector<Node*> list_Array;
    list_Array.push_back(head1);
    list_Array.push_back(head2);
    list_Array.push_back(head3);

    Node* Merged_List = merge_KSorted_Lists(list_Array);
    printList(Merged_List);
}