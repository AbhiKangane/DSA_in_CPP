// GFG Hard Problem: 
// In this each node in LL has 2 pointers
// one pointer -> next node & other -> random any node
#include <iostream>
#include <unordered_map>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *random;
};

// solution1 of problem: using unordered map  : Time & space complexity = O(n)
// this class not work properly, I need fix issues
class Solution1{
    private:
    void inserAtTail(node* &head, node* &tail, int data){
        node* temp = new node;  // creating a new node
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
            return;
        }
    }


    public:
    node* clone_LL(node* head){
        // step 1: create a clone LL
        node* cloneHead = NULL;
        node* cloneTail = NULL;

        node* temp = head; // for traversing original LL
        while (temp != NULL){
            inserAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // step 2: create unordered_map
        unordered_map<node*, node*> oldToNewNode; 

        node* originalNode = head;
        node* cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL){
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        // step 3: setting random pointers
        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != NULL){
            cloneNode->random = oldToNewNode[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        cout<<cloneHead->data;
        return cloneHead;
    }
};



// solution2 of problem: adjusting next & random pointers: Time complexity= O(n) & space complexity = O(1)
// this class not work properly, I need fix issues
class Solution2{
    private:
    void inserAtTail(node* &head, node* &tail, int data){
        node* temp = new node;  // creating a new node
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail->next = temp;
            tail = temp;
            return;
        }
    }


    public:
    node* clone_LL(node* head){
        // step 1: create a clone LL
        node* cloneHead = NULL;
        node* cloneTail = NULL;

        node* temp = head; // for traversing original LL
        while (temp != NULL){
            inserAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // step 2: cloneNodes add in between original LL
        node* originalNode = head;
        node* cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL){
            node* nextNode = originalNode->next; // for keeping track of original node
            originalNode->next = cloneNode;
            originalNode = nextNode;

            nextNode = cloneNode->next; // now for keeping track of clone node
            cloneNode->next = originalNode;
            cloneNode = nextNode;         
        }

        // step 3: random pointer copy
        temp = head;
        while (temp != NULL){
            if(temp->next != NULL){
                temp->next->random = temp->random ? temp->random->next : temp->random;
            }
            temp = temp->next->next;
        }
    
        // step 4: revert changes done in step 2
        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != NULL && cloneNode != NULL){
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if(originalNode != NULL)
                cloneNode->next = originalNode->next;
            cloneNode = cloneNode->next;         
        }

        // step 5: returning cloneHead
        return cloneHead;
    }
};

void printlist(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d-> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

int main()
{
    // Method 1: using structure pointers
    struct node *head = new node;
    struct node *second = new node;
    struct node *third = new node;
    struct node *fourth = new node;
    struct node *fifth = new node;

    head->data = 1;
    head->next = second;
    head->random = third;


    second->data = 2;
    second->next = third;
    second->random = head;

    third->data = 3;
    third->next = fourth;
    third->random = fifth;

    fourth->data = 4;
    fourth->next = fifth;
    fourth->random = third;

    fifth->data = 5;
    fifth->next = NULL;
    fifth->random = second;

    cout<<"Printing before clone:\n";
    cout<<"Using next ptr: ";
    printlist(head);  // printing LL using next ptr
    // printing random link nodes
    cout<<"\n"<<head->random->data<<"->"<<second->random->data<<"->"<<third->random->data<<"->"
                <<fourth->random->data<<"->"<<fifth->random->data;

    // cout<<"\n\nPrinting after clone:\n";
    // Solution1 s1;
    // node* cloneHead1 = s1.clone_LL(head);
    // printlist(cloneHead);   // this goes in  infinite loop, I don,t know
    
    
    cout<<"\n\nPrinting after clone:\n";
    Solution2 s2;
    node* cloneHead2 = s2.clone_LL(head);
    printlist(cloneHead2);   // this prints same address 5 times, I don,t know
    
    return 0;
}