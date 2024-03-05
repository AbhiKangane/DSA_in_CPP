// leetCode 112 : Path Sum I
// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path 
// such that adding up all the values along the path equals targetSum...

//  leetCode 113 : Path Sum II
// Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values 
// in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

#include<iostream>
#include<vector>
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

// leetcode 112
bool rootToLeafPathSum(TreeNode* root, int targetSum, int sum){
    if(root == nullptr)
        return false;
    if(root -> left == nullptr && root -> right == nullptr){
        if(sum+root->val == targetSum)
            return true;   
    }
    return rootToLeafPathSum(root->left, targetSum, sum+root->val) || rootToLeafPathSum(root->right, targetSum, sum+root->val);
}
bool hasPathSum(TreeNode* root, int targetSum) {
    int sum = 0;
    return rootToLeafPathSum(root, targetSum, sum);
}

// leetCode 113
void rootToLeaf(TreeNode *root, int currSum, int targetSum, vector<int> currPath, vector<vector<int>> &ans){
    if(!root)
        return;
    
    if(!root->left && !root->right){
        if(currSum+root->val == targetSum){
            currPath.push_back(root->val);
            ans.push_back(currPath);
        }
        return;
    }
    
    currPath.push_back(root->val);
    currSum += root->val;
    
    if(root->left)
        rootToLeaf(root->left, currSum, targetSum, currPath, ans);
    if(root->right)
        rootToLeaf(root->right, currSum, targetSum, currPath, ans);
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> currPath;
    int currSum = 0;
    rootToLeaf(root, currSum, targetSum, currPath, ans);
    
    return ans;
}

int main(){
/*
         1          
       /   \        
      2     3      
     / \     \      = 11 & 14
    4   5     6     
       / \         
      7   8      
*/
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(2);
    root->left->right->right = new TreeNode(8);

    // path sum I
    cout<<hasPathSum(root, 12)<<endl;

    vector<vector<int>> paths = pathSum(root, 1);
    for(auto i: paths){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}