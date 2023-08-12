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

int intersection(Node* &head1, Node* &head2){
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;

    Node *ptr1, *ptr2;
    if(l1 > l2){ // if 1st LL is large
        d = l1 - l2;
        ptr1 = head1; // ptr1 points for largest LL
        ptr2 = head2;
    }

    else{ // if 2nd LL is large or equal to 1st LL
        d = l2 - l1;
        ptr1 = head2; // ptr1 points for largest LL
        ptr2 = head1;
    }

    while(d){ // traversing large node till difference
        ptr1 = ptr1->next;
        if(ptr1 == NULL){
            return -1;
        }
        d--;
    }

    while (ptr1 != NULL && ptr2 != NULL){
        if(ptr1->data == ptr2->data)
            return ptr1->data;
        
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main(){
    int arr1[] = {0,1,3,5,7,9,10,11},  arr2[] = {2,4,6,8,10,11};
    Node* head1 = NULL;
    Node* head2 = NULL;

    for(int i=0; i<8; i++){
        insertAtIndex(head1, i, arr1[i]);
    }
    printList(head1);
    cout<<endl;

    for(int i=0; i<6; i++){
        insertAtIndex(head2, i, arr2[i]);
    }
    printList(head2);
    cout<<endl;

    int ans = intersection(head1, head2);
    cout<<"Intersection Node is: "<<ans;
    return 0;
}