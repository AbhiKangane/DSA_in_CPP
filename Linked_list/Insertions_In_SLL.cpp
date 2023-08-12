#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node * next;
};


void linkedListTraversal(struct Node* temp){
    while(temp != NULL){
        cout<<temp->data;

        if(temp->next != NULL)
            cout<<" -> ";

        temp = temp->next;
    }
}

// Case 1
struct Node * insertAtFirst(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = head;
    return ptr; 
}

// Case 2
struct Node * insertAtIndex(struct Node *head, int data, int index){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    struct Node * p = head;
    int i = 0;

    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Case 3
struct Node * insertAtEnd(struct Node *head, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node * p = head;

    while(p->next!=NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Case 4
struct Node * insertAfterNode(struct Node *head, struct Node *prevNode, int data){
    struct Node * ptr = (struct Node *) malloc(sizeof(struct Node));
    ptr->data = data;

    if (prevNode == NULL)
  {
    cout<<"\nCan't insert after NULL Node\n";
  }

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    
    return head;
}


int main(){
    struct Node *head;
    // struct Node *second;
    // struct Node *third;
    // struct Node *fourth;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    // second = (struct Node *)malloc(sizeof(struct Node));
    // third = (struct Node *)malloc(sizeof(struct Node));
    // fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 7;
    head->next = NULL;
    // head->next = second;

    // Link second and third nodes
    // second->data = 11;
    // second->next = third;

    // Link third and fourth nodes
    // third->data = 41;
    // third->next = fourth;

    // Terminate the list at the third node
    // fourth->data = 66;
    // fourth->next = NULL;

    printf("Linked list before insertion\n");
    linkedListTraversal(head);
    // head = insertAtFirst(head, 8);
    // head = insertAtIndex(head, 5, 1);
    // head = insertAtEnd(head, 6);
    head = insertAfterNode(head, head, 333);
    printf("\nLinked list after insertion\n");
    linkedListTraversal(head);

    
    return 0;
}