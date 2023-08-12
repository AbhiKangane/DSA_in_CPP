// In this each node in LL has 2 pointers
// one pointer -> next node & other -> random any node
#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    struct node *random;
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

    printlist(head);  // printing LL using next ptr
    // printing random link nodes
    cout<<"\n"<<head->random->data<<"->"<<second->random->data<<"->"<<third->random->data<<"->"
                <<fourth->random->data<<"->"<<fifth->random->data;

    /*
        // Method 2: using objects (without using structure pointers)
        struct node ob1; // Node1
        struct node ob2; // Node2
        struct node ob3; // Node2
        struct node ob4; // Node2
        struct node ob5; // Node2

        // Initialization
        ob1.next = NULL;
        ob1.random = NULL;
        ob1.data = 1;

        ob2.next = NULL;
        ob2.random = NULL;
        ob2.data = 2;

        ob3.next = NULL;
        ob3.random = NULL;
        ob3.data = 3;

        ob4.next = NULL;
        ob4.random = NULL;
        ob4.data = 4;

        ob5.next = NULL;
        ob5.random = NULL;
        ob5.data = 5;

        // Linking ob1 and ob2
        ob1.next = &ob2;
        ob2.next = &ob3;
        ob3.next = &ob4;
        ob4.next = &ob5;
        // ob5.next = NULL;

        ob1.random = &ob3;
        ob2.random = &ob1;
        ob3.random = &ob5;
        ob4.random = &ob3;
        ob5.random = &ob2;


        printf("%d ", ob1.random->data);
        printf("%d ", ob2.random->data);
        printf("%d ", ob3.random->data);
        printf("%d ", ob4.random->data);
        printf("%d ", ob5.random->data);
    */

    return 0;
}