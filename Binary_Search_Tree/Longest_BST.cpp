#include<iostream>
#include<queue>
using namespace std;

class node{  // for creating binary tree
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

// creating binary tree
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

// solution starts
class info{
public:
    int maxi, mini; 
    bool isBST;
    int size;
};

info solve(node* root, int &ans){
    // base case
    if(root == NULL)
        return {INT32_MIN, INT32_MAX, true, 0};
    
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if(left.isBST && right.isBST && (root->data < right.mini) && (root->data > left.maxi)){
        currNode.isBST = true;
   }
    else{
        currNode.isBST = false;
    }

    if(currNode.isBST)
        ans = max(ans, currNode.size);

    return
        currNode;         
}

int LongestBST(node* root){
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;  // no. of nodes in BST
}
// ends


int main(){
    node* root = NULL;

// creating a BST
/*            3
            /   \
          10     5
        /   \
       5     15
     / \    /  \
    2   8  12   17
*/

    // creating a tree
    root = build_tree(root);
    // 3 10 5 2 -1 -1 8 -1 -1 15 12 -1 -1 17 -1 -1 5 -1 -1

    cout<<"Size of longest BST in binary tree is: "<<LongestBST(root);
}
