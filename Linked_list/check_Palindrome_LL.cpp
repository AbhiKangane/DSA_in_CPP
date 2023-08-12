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
    cout<<"NULL"<<endl;
}

// this is a GFG problem: Solution 1
// its time & space complexity O(n)
class Solution1
{
private:
    bool check(vector<int> ll){
        for (int i = 0, j = ll.size()-1; i < j; i++, j--){
            if(ll[i] == ll[j])
                return true;
        }
        return false;
    }

public:
    bool isPalindrome(Node* head){
        vector<int> arr;
        Node* temp = head;

        while(temp != NULL){
            arr.push_back(temp->data);
            temp = temp->next;
        }

        return check(arr);
    }
};
// end solution

// this is a GFG problem: Solution 2
// its time complexity O(n) & space complexity O(1)
class Solution2
{
private:
    // finding middle node of LL
    Node* findMid(Node* head){
        Node* slow = head;
        Node* fast = head->next;

        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        cout<<"Middle node: "<<slow->data<<endl;
        return slow;
    }

    // iterative reversing linked list
    Node* Reverse(Node* &head){
	    Node *prev = NULL;
    	Node *curr = head;
	    Node *next ;
	
    	while(curr != NULL){
	    	next = curr -> next;
		    curr -> next = prev;
    		prev = curr;
	    	curr = next;
	    }

	    // return head of reverse linked list
        // cout<<endl;
        // printList(prev);
	    return prev;
    }

public:
    bool isPalindrome(Node* head){
        if (head->next == NULL){
            return true;
        }
        
        // step 1: finding mid
        Node* mid = findMid(head);

        // step 2: for reversing second half LL
        Node* secHead = mid->next;  // original head of 2nd half LL
        mid->next = Reverse(secHead); // reversing 2nd half LL
        
        Node* firstHead = head;
        Node* newSecHead = mid->next;  // start of reversed 2nd half LL 

        // step 3: comparing first half LL with reversed 2nd half LL 
        while (newSecHead != NULL){
            if (firstHead->data != newSecHead->data){
                return false;
            }
            firstHead = firstHead->next;
            newSecHead = newSecHead->next;
        }

        // step 4; restoring original LL (i.e. Reversing 2nd half of LL)
        secHead = mid->next;
        mid->next = Reverse(secHead);  // start of reversed 2nd half LL 
        // printList(head); // printing original LL for checking

        return true;
    }
};
// end solution



int main(){
    int arr[] = {1,5,3,7,3,5,1};
    Node* head = NULL;

    for(int i=0; i<7; i++){
        insertAtIndex(head, i, arr[i]);
    }
    
    cout<<"Given Linked List: "<<endl;
    printList(head);
    cout<<endl;

    Solution1 s1;
    if (s1.isPalindrome(head)) 
        cout<<"\nLinked list is palindrome"<<endl;
    else
        cout<<"\nLinked list is not palindrome"<<endl;

    Solution2 s2;
    if (s2.isPalindrome(head)) 
        cout<<"\nLinked list is palindrome"<<endl;
    else
        cout<<"\nLinked list is not palindrome"<<endl;
    // cout<<s2.isPalindrome(head);
    return 0;
}