#include<iostream>
#include<queue>
using namespace std;

class node{
    public: 
    int data;
    node* left;
    node* right;

    node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node* build_tree(node* root){  // traversal is a preorder
    int data;
    cout<<"Enter data for node: ";
    cin>> data;
    root = new node(data);

    if(data == -1)
        return NULL; // if node->data is empty

    cout<<"\nEnter data for left child of "<<data<<endl;
    root->left = build_tree(root->left);
    cout<<"\nEnter data for right child of "<<data<<endl;
    root->right = build_tree(root->right);

    return root;
}


int sumAtk(node* root, int k){
    if(root == NULL)    return -1;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level = 0, sum = 0;

    while (!q.empty()){
        node* Node = q.front();

        if(Node != NULL){
            if(level == k)      sum += Node->data;
            if(Node->right)     q.push(Node->left);
            if(Node->left)      q.push(Node->right);
        }

        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
}


void sumReplacement(node* root){
    if(root == NULL)        return;

    sumReplacement(root->left);
    sumReplacement(root->right);

    if(root->left)      root->data += root->left->data; 
    if(root->right)     root->data += root->right->data; 
}

void preorder(node* root){
    if(root == NULL)        return;
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}



int main(){
    node* root = NULL;
    // creating a tree
/*        1
        /   \
      2      3
     / \   /  \
    4  5  6   7
*/
    root = build_tree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout<<"\n"<<endl;
    preorder(root);

    sumReplacement(root);
    cout<<"\n"<<endl;
    preorder(root);
    return 0;
}