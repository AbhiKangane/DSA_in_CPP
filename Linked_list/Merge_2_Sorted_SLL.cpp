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

// for merging there must be two sorted LL
Node* merge(Node* &head1, Node* &head2){
    Node* p1 = head1;
    Node* p2 = head2;
    Node* dummyNode = new Node(-1);
    Node* p3 = dummyNode;
    
    while (p1 != NULL && p2 != NULL){
        if(p1->data < p2->data){
            p3->next = p1;
            p1 = p1->next;
        }
        else{ // this codition is for if p1->data >= p2->data
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while (p1 != NULL){
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    
    while (p2 != NULL){
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    
    // printing merged linked list
    // dummyNode = dummyNode->next; // for removing 1st dummy node
    // while(dummyNode!=NULL){
    //     cout<<dummyNode->data<<"->";
    //     dummyNode = dummyNode->next;
    // }
    // cout<<"NULL";
    return dummyNode->next; // returning address of 1st node of merged list
}


// recursive Merging two sorted linked lists
Node* RecursiveMerge(Node* &head1, Node* &head2){
    // base cases 
    if(head1 == NULL)
        return head2;
    
    if(head2 == NULL)
        return head1;
    
    Node* result;
    if(head1->data < head2->data){
        result = head1;
        result->next = RecursiveMerge(head1->next, head2);
    }
    else{ // for (head1->data >= head2->data)
        result = head2;
        result->next = RecursiveMerge(head1, head2->next);
    }
    return result;
}


int main(){
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

    // Node* ans = merge(head1, head2);
    // printList(ans);
    
    Node* ans = RecursiveMerge(head1, head2);
    printList(ans);
    return 0;
}