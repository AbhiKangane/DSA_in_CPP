#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
}*head = NULL;

void convert(int arr[], int size){
    struct node *temp, *last;

    // creating first node
    head = (struct node*) malloc(sizeof(struct node));
    head->data = arr[0];
    head->next = NULL;
    last = head; // for keeping track of previous node

    for(int i=1; i<size; i++){
        temp = (struct node*) malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void display(struct node* temp){
    while(temp != NULL){
        cout<<temp->data;

        if(temp->next != NULL)
            cout<<" -> ";

        temp = temp->next;
    }
}

int main(){
    int a[] = {1,2,3,4,5};
    convert(a,5);
    display(head);

    return 0;
}