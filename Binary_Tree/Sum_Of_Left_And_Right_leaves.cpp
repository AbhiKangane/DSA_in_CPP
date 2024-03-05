// Given Binary tree return the sum of all left leaf nodes & sum of all right leaf nodes.
/*
         1          
       /   \        
      2     3      
     / \     \      = 11 & 14
    4   5     6     
       / \         
      7   8      
*/
#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
public:
    int data;
    TreeNode *left, *right;

    TreeNode(int val){
        data = val;
        left=NULL;
        right=NULL;
    }
};

int leftHelper(TreeNode* root, bool left){
    if(!root)
        return 0;
    if(!root->left && !root->right && left)
        return root->data;
    
    return leftHelper(root->left, true) + leftHelper(root->right, false);
}

int sumOfLeftLeaves(TreeNode* root){
    return leftHelper(root,false);
}

int rightHelper(TreeNode* root, bool right){
    if(!root)
        return 0;
    if(!root->left && !root->right && right)
        return root->data;
    
    return rightHelper(root->left, false) + rightHelper(root->right, true);
}

int sumOfRightLeaves(TreeNode* root){
    return rightHelper(root,false);
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);

    // printing ans
    cout<<sumOfLeftLeaves(root)<<endl;
    cout<<sumOfRightLeaves(root)<<endl;

    return 0;
}