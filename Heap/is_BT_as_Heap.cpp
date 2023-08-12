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

int Count_Nodes(node* root){
    // base case
    if(root == NULL)
        return 0;
    
    int count = 1 + Count_Nodes(root->left) + Count_Nodes(root->right);
    return count;
}

bool isCBT(node* root, int index, int count){
    if(root == NULL){
        return true;
    }

    if(index >= count)
        return false;
    
    else{
        bool left = isCBT(root->left, 2*index + 1, count);
        bool right = isCBT(root->right, 2*index + 2, count);

        return (left&&right);
    }
}

bool is_Max_Order(node* root){
    // leaf node
    if(root->left == NULL && root->right == NULL)
        return true;
     
    if(root->right == NULL){ // for only left child
        if(root->data > root->left->data)
            return true;
    }

    else{
        bool left = is_Max_Order(root->left);
        bool right = is_Max_Order(root->right);

        if(left && right && (root->data > root->left->data) && (root->data > root->right->data)){
            return true;
        }
        else
            return false;
    }

}

bool is_heap(node* root){
    int index = 0;
    int total_Count = Count_Nodes(root);

    if(isCBT(root, index, total_Count) && is_Max_Order(root))
        return true;
    return false;
}

int main(){
    node* root = NULL;

    // creating a tree
/*        7
        /   \
      4      6
     / \   / 
    3  2  5   
*/
    root = build_tree(root);
    // 7 4 3 -1 -1 2 -1 -1 6 5 -1 -1 -1 

    cout<<"\nIs Binary tree Heap?\n=> "<<is_heap(root);
    return 0;
}