#include<iostream>
#include<vector>
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
    cout<<"NULL\n";
}

// recursive Merging two sorted linked lists
Node* RecursiveMerge2LL(Node* &head1, Node* &head2){
    // base cases 
    if(head1 == NULL)
        return head2;
    
    if(head2 == NULL)
        return head1;
    
    Node* result;
    if(head1->data < head2->data){
        result = head1;
        result->next = RecursiveMerge2LL(head1->next, head2);
    }
    else{ // for (head1->data >= head2->data)
        result = head2;
        result->next = RecursiveMerge2LL(head1, head2->next);
    }
    return result;
}

// for merging there must be two sorted LL
Node* merge2LL(Node* &head1, Node* &head2){
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
    
    return dummyNode->next; // returning address of 1st node of merged list
}


// Merging K sorted Linked Lists
Node* merge_KSortedLL(vector<Node*> &heads){
    if(heads.size()==0)
        return NULL;

    while (heads.size()>1){
        Node *mergedHead = merge2LL(heads[0], heads[1]);
        heads.push_back(mergedHead);   // pushing merged LL of 1st 2 LL
        // removing 1st 2 LL
        heads.erase(heads.begin());  
        heads.erase(heads.begin());
    }
    return heads[0];
}


int main(){
    vector<int> arr1 = {1,3,7,10,11},
                arr2 = {2,4,5,8},
                arr3 = {6,12,14}, 
                arr4 = {9,13,15};
    vector<Node*> heads(4,NULL);
    // creating linked list 1
    for(int i=0; i<arr1.size(); i++)
        insertAtIndex(heads[0], i, arr1[i]);
    printList(heads[0]);

    // creating linked list 2
    for(int i=0; i<arr2.size(); i++)
        insertAtIndex(heads[1], i, arr2[i]);
    printList(heads[1]);
    
    // creating linked list 3
    for(int i=0; i<arr3.size(); i++)
        insertAtIndex(heads[2], i, arr3[i]);
    printList(heads[2]);

    // creating linked list 4
    for(int i=0; i<arr4.size(); i++)
        insertAtIndex(heads[3], i, arr4[i]);
    printList(heads[3]);

    // cout<<"Printing Merged 2 Sorted Linked List: ";
    // Node* ans1 = merge2LL(heads[0], heads[1]);
    // printList(ans1);
    // cout<<endl;

    // cout<<"Printing Merged 2 Sorted Linked List: ";
    // Node* ans2 = RecursiveMerge2LL(heads[1], heads[2]);
    // printList(ans2);

    cout<<"Printing Merged K Sorted Linked List: ";
    Node* ans = merge_KSortedLL(heads);
    printList(ans);
    return 0;
}