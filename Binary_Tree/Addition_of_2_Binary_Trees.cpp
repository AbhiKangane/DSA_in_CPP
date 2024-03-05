// given 2 binary trees return the root of the sum of both trees
/*
         2                   3                     5
       /   \               /  \                 /    \
      4     7      +     10    1      =       14      8
     / \     \          /    /  \            /  \    /  \
    8  11    13        4    2    6          12  11  2   19
            /                     \                    /  \
           9                       7                  9   7 
*/

#include<iostream>
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

TreeNode* mergeHelp(TreeNode *root1, TreeNode *root2){
    // base cases
    if(!root1 && !root2)    return NULL;
    if(!root1)              return root2;
    if(!root2)              return root1;

    // creaating new node to store sum
    TreeNode *newNode = new TreeNode(root1->data + root2->data);

    // recursive calls
    newNode->left = mergeHelp(root1->left, root2->left);
    newNode->right = mergeHelp(root1->right, root2->right);

    return newNode;
}

TreeNode* MergeTrees(TreeNode *root1, TreeNode *root2){
    return mergeHelp(root1, root2);
}

// inorder
void inorder(TreeNode* root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    TreeNode *root1 = new TreeNode(2);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(7);
    root1->left->left = new TreeNode(8);
    root1->left->right = new TreeNode(11);
    root1->right->right = new TreeNode(13);
    root1->right->right->left = new TreeNode(9);

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(10);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    TreeNode* ans = MergeTrees(root1, root);

    // printing addition tree
    inorder(ans);

    return 0;
}