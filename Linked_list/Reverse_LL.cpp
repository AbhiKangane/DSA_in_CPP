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


// iterative reversing linked list
Node* Reverse(Node* &head){
	Node *prev = NULL;
	Node *curr = head;
	Node *next;
	
	while(curr != NULL){
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}

	// return head of reverse linked list
	return prev;
}

// recursively reversing linked list  // code from apna college CPP playlist works properly
Node* RecursiveReverse(Node* &head){
	// base condition
	if(head == NULL || head->next == NULL)
		return head;

    Node* newHead = head;
    // cout<<"newHead: "<<newHead->data<<endl;
	newHead = RecursiveReverse(head->next);
    head->next->next = head;  
	head->next = NULL;  // 1st node of original LL points to NULL

	// return new head of reverse linked list
	return newHead;
}

// reversing linked list in groups containing k elements
Node * ReverseK(Node* &head, int k){
	// base condition
	if(head == NULL)
		return NULL;
	
	// step 1: reverse k nodes
	Node *prev = NULL;
	Node *curr = head;
	Node *next;
	int count = 0;

	// reversing k nodes
	while(curr != NULL && count != k){
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
		count++;
	}

	if(next != NULL)
		head->next = ReverseK(next, k);

	// return head of reverse linked list
	return prev;
}


int main(){
    int arr1[] = {1,3,5,7,9,11,13};
    Node* head = NULL;

    for(int i=0; i<7; i++){
        insertAtIndex(head, i, arr1[i]);
    }
    printList(head);
    cout<<endl;

	// cout<<"\nAfter reversing nodes in k groups"<<endl;
	// int k=2;
	// Node* newList = ReverseK(head, k);
	// printList(newList);

    // cout<<"\nPrinting iterative reverse LL: "<<endl;
	// Node* ReverseList = Reverse(head);
	// printList(ReverseList);

    cout<<"\nPrinting recursive reverse LL: "<<endl;
	Node* RecursiveRevList = RecursiveReverse(head);
	printList(RecursiveRevList);
    
    return 0;
}