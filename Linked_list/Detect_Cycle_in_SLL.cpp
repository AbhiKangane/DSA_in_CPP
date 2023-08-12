#include <cstddef> 
#include <iostream>

using namespace std; 

struct node {
	int data; 
	struct node * next;
}; 

// insert at end
struct node* append(struct node * head, int new_data) {
    struct node * new_node = (struct node * ) malloc(sizeof(struct node));
    new_node->data = new_data;
    struct node * temp =  head;
    
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new_node;
	new_node->next = NULL;

	return head;
}


void display(struct node* temp){
    while(temp != NULL){
        cout<<temp->data;

        if(temp->next != NULL)
            cout<<" -> ";

        temp = temp->next;
    }
}

bool detectCycle(node* &head){
    node *slow = head;
    node *fast = head;

    while(fast != NULL && fast->next !=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(fast==slow)
            return true;
    }
    return false;
}

void makeCycle(node* head, int pos){
    node* temp = head;
    node* startNode;
    int count =1;

    while (temp->next != NULL)
    {
        if(count == pos)    startNode=temp;
        temp= temp->next;
        count++;
    }

    temp->next = startNode;
}

// assuming that there is a cycle in SLL
void removeCycle(node* &head){
    node *slow = head;
    node *fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;
    }while(fast != slow);

    fast= head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    // after this loop we get, slow->next = fast->next = Starting point of cycle
    // for breaking cylce
    slow->next = NULL;

}


int main() { 
				
	struct node * head;
	head->data = 1;
	head->next = NULL;

	head = append(head,2);
	head = append(head,3);
	head = append(head,4);
	head = append(head,5);
	head = append(head,6);

    cout<<"Before creating cycle\n";
	display(head);
    bool cycle = detectCycle(head);
    cout<<"\nCycle exist or not: "<<cycle<<endl;

    cout<<"\nAfter creating cyle\n";
    makeCycle(head,3);
    // display(head);
    
    cout<<"\nCycle Present or not: "<<detectCycle(head)<<endl;

    cout<<"\nAfter removing cyle\n";
    removeCycle(head);
    display(head);
    cout<<"\nCycle Present or not: "<<detectCycle(head)<<endl;

	return 0;
}