// Given the root of a binary tree, find the all nodes that don't have any siblings

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int data){
        val = data;
        left=NULL;
        right=NULL;
    }
};

// Cousins in Binary Tree I
void findNodes(TreeNode* root, vector<int>&ans)
{
    if(!root || (!root->left && !root->right))   return;

    // both braches are present
    if(root->left && root->right){
        findNodes(root->left, ans);
        findNodes(root->right, ans);
    }

    // if only left branch
    else if(root->left){
        ans.push_back(root->left->val);
        findNodes(root->left, ans);
    }
    else{
        ans.push_back(root->right->val);
        findNodes(root->right, ans);
    }
}

vector<int> noSiblings(TreeNode *root){
    vector<int> ans;
    findNodes(root, ans);
    if (ans.size()==0) 
        ans.push_back(-1);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
/*
          1             
        /   \           
       2     3          
     /  \     \      => 7, 6
    4    5     6            
   /    / \                
  7    8   9         
*/
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);

    vector<int> ans = noSiblings(root);
    for(auto i: ans)
        cout<<i<<" ";

    return 0;
}