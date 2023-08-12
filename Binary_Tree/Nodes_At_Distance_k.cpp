#include<iostream>
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

// case 1 : find nodes in bellow node(i.e. in subtree)
void printSubtreeNodes(node *root, int k){
    if( root == NULL || k<0)
        return ;
    
    if(k == 0){
        cout<<root->data<<" ";
        return;
    }
     
    // if (k>0)
    printSubtreeNodes(root->left, k-1); 
    printSubtreeNodes(root->right, k-1); 
}

// case 2 : find nodes in upper(or upper left or right) node(i.e. in ancestor)
int printNodes_At_k(node *root, node *target, int k){
    if(root == NULL)
        return -1;

    if(root == target){
        printSubtreeNodes(root, k);
        return 0;
    }

    // for left subtree of root
    int dis_left = printNodes_At_k(root->left, target, k);
    if(dis_left != -1){
        if(dis_left + 1 == k)
            cout<<root->data<<" ";
        else
            printSubtreeNodes(root->right, k-dis_left-2);

        return 1+dis_left;
    }

    //  for right subtree of root 
    int dis_right = printNodes_At_k(root->right, target, k);
    if(dis_right != -1){
        if(dis_right + 1 == k)
            cout<<root->data<<" ";
        else
            printSubtreeNodes(root->left, k-dis_right-2);

        return 1+dis_right;
    }

    return -1;
}

int main(){
    node* root = NULL;
    // creating a tree
/*        1
        /   \
      2      3
     / \    /  \
    4  5   6   7
        \
        8
*/
    root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->right->right = new node(8);
    
    
    printNodes_At_k(root, root->left, 2);
    return 0;
}