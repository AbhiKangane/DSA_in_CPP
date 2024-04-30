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
    cout<<"NULL"<<endl;
}

// /*
// GFG problem: Solution 1 
class Solution1{
private:
    // iterative reversing linked list
    Node* reverse(Node* &head){
	    Node *prev = NULL;
    	Node *curr = head;
	    Node *next = NULL;
	
    	while(curr != NULL){
	    	next = curr -> next;
	        curr -> next = prev;
    		prev = curr;
	    	curr = next;
	    }
        return prev;
    }

    void insertAtEnd(Node* &head, Node* &tail, int data){
        Node* temp = new Node(data);
        // if ll is empty
        if(head==NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }

    Node* add(Node* first, Node* second){
        int carry = 0;
        Node* ansHead = NULL;
        Node* ansTail = NULL;
        
        while(first != NULL && second != NULL){
            int sum = carry + first->data + second->data;
            int digit = sum%10;
            insertAtEnd(ansHead, ansTail, digit);
            carry = sum/10;
            first = first->next;
            second = second->next;
        }

        while(first != NULL){
            int sum = carry + first->data;
            int digit = sum%10;
            insertAtEnd(ansHead, ansTail, digit);
            carry = sum/10;
            first = first->next;
        }

        while(second != NULL){
            int sum = carry + second->data;
            int digit = sum%10;
            insertAtEnd(ansHead, ansTail, digit);
            carry = sum/10;
            second = second->next;
        }

        while(carry != 0){
            int sum = carry ;
            int digit = sum%10;
            insertAtEnd(ansHead, ansTail, digit);
            carry = sum/10;
        }
        return ansHead;
    }
    
public:
    struct Node* addTwoLists(struct Node* first, struct Node* second){
        while(first->data==0){
            first = first->next;
            if(!first)
                break;
        }
        while(second->data==0){
            second = second->next;
            if(!second)
                break;
        }
        // both are zeroes
        if(!first && !second){
            return new Node(0);
        }
        // first is 0
        else if(!first)
            return second;
        else if(!second)
            return first;
        
        // step 1: reversing input LL as while calculating sum we solve from right to left
        first = reverse(first);
        second = reverse(second);
        // printList(first);
        // printList(second);

        // step 2: adding two reversed LL
        Node* ans = add(first, second);

        // step 3: reversing ans LL
        ans = reverse(ans);

        return ans;
    }
};
// */

// GFG problem: Solution 2
class Solution2{
private:
    // iterative reversing linked list
    Node* reverse(Node* &head){
	    Node *prev = NULL;
    	Node *curr = head;
	    Node *next = NULL;
	
    	while(curr != NULL){
	    	next = curr -> next;
		    curr -> next = prev;
    		prev = curr;
	    	curr = next;
	    }

	    // return head of reverse linked list
	    return prev;
    }

    Node* add(Node* first, Node* second){
        int carry = 0, i=0;
         Node* ansHead = NULL;
         Node* ansTail = NULL;
        
        while(first != NULL || second != NULL || carry != 0){
            int val1 = 0;
            if(first != NULL){ val1 = first->data;}

            int val2 = 0;
            if(second != NULL){ val2 = second->data;}

            int sum = carry + val1 + val2;
            int digit = sum%10;
            
            insertAtIndex(ansHead, i, digit);
            carry = sum/10;

            if(first != NULL) first = first->next;
            if(second != NULL) second = second->next;
            i++;
        }

        return ansHead;
    }
    
public:
    struct Node* add_2_Num_LL(struct Node* first, struct Node* second){
	while(first->data==0 && first->next!=NULL)
            first = first->next;
        while(second->data==0 && second->next!=NULL)
            second = second->next;
            
        // both are zeroes
        if(!first && !second)
            return new Node(0);
        // first is 0
        else if(!first)
            return second;
        else if(!second)
            return first;
	    
        // step 1: reversing input LL as while calculating sum we solve from right to left
        first = reverse(first);
        second = reverse(second);
        // printList(first);
        // printList(second);

        // step 2: adding two reversed LL
        Node* ans = add(first, second);

        // step 3: reversing ans LL
        ans = reverse(ans);

        return ans;
    }

};

int main(){
    int arr1[] = {1,3,5},  arr2[] = {2,4,5};
    Node* head1 = NULL;
    Node* head2 = NULL;

    for(int i=0; i<3; i++){
        insertAtIndex(head1, i, arr1[i]);
    }
    printList(head1);

    for(int i=0; i<3; i++){
        insertAtIndex(head2, i, arr2[i]);
    }
    printList(head2);

    // Solution1 s1;                     // solution1 works only when equal no. of nodes present in both linked lists
    // Node* sum1 = s1.add_2_Num_LL(head1, head2);
    // printList(sum1);

    Solution2 s2;
    Node* sum2 = s2.add_2_Num_LL(head1, head2);
    printList(sum2);
    return 0;
}
