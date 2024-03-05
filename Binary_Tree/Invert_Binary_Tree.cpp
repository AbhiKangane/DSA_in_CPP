// Invert given binary tree 
/*
          1                      1
        /   \                   / \
       2     3                 3   2
     /  \     \      =>      /    /  \
    4    5     6            6     5   4
   /    / \                      / \   \
  7    8   9                    9   8   7
*/

#include<iostream>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int data){
        val = data;
        left = NULL;
        right = NULL;
    }
};



TreeNode* invertTree(TreeNode* root) {
    if(!root)
        return root;

    TreeNode *leftSubtree = invertTree(root->left);
    TreeNode *rightSubtree = invertTree(root->right);

    root->left = rightSubtree;
    root->right = leftSubtree;

    return root;
}

void inorder(TreeNode *root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);

    inorder(root);
    cout<<endl;
    TreeNode *ans = invertTree(root);
    inorder(ans);

    return 0;
}