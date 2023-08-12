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

// finding middle node of LL
Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// dividing a linked list
Node* MergeSort(Node* head){
    // base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* mid = findMid(head);

    Node* left = head; //starting of left half
    Node* right = mid->next; //starting of right half
    mid->next = NULL; // breaking of original LL

    left = MergeSort(left);
    right = MergeSort(right);

    Node* result = RecursiveMerge(left, right);
    return result;
}

int main(){
    int arr[] = {1,5,3,7,11,13,9};
    Node* head = NULL;

    for(int i=0; i<7; i++){
        insertAtIndex(head, i, arr[i]);
    }
    printList(head);
    cout<<"\nAfter Merge Sort: "<<endl;

    
    Node* ans = MergeSort(head);
    printList(ans);
    return 0;
}