#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;

    Node(int val){
        data = val;
        left = NULL;
        right= NULL;
    }
};

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcPointers(Node *root, Node **first, Node **mid, Node **last, Node **prev){
    if(root == NULL)
        return;
    
    calcPointers(root->left, first, mid, last, prev);

    if(*prev && root->data < (*prev)->data){
        if(!*first){             // BST Property violates 1st time
            *first = *prev;
            *mid = root;
        }
        else                    // BST Property violates 2nd time
            *last = root;
    }
    *prev = root;

    calcPointers(root->right, first, mid, last, prev);
}

void restoreBST(Node *root){
    Node *first, *mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;

    calcPointers(root, &first, &mid, &last, &prev);

    // case 1 : Consider inorder : {1,|8|,3,4,5,6,7,|2|}
    // first : previous node where 1st number < previous [8]
    // mid : no. where 1st number < previous [3]
    // last : 2nd node where no. < previous [2]
    if(first && last){
        swap(&(first->data), &(last->data));
    }
    // case 2 : Consider inorder : {1,2,|4|,|3|,5,6,7,8}
    // first : previous node where 1st number < previous [4]
    // mid : no. where 1st number < previous [3]
    // last : NULL
    else if(first && mid){
        swap(&(first->data), &(mid->data));
    }
}


void inorder(Node *root){
    if(!root)   return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
/*
             6
           /  \
          9    3
        /  \    \
       1    4    13
*/

    Node *root = new Node(6);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(13);

    cout<<"Inorder of destructured BST : ";
    inorder(root);

    restoreBST(root);
    cout<<"\nInorder of restored BST : ";
    inorder(root);

    return 0;
}