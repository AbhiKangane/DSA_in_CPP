#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
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

// leetcode 995 : Cousins in Binary Tree I  
// Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, 
// return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.
// Two nodes of a binary tree are cousins if they have the same depth with different parents.

void findNodes(TreeNode* root, int node1, int node2, int level[2], int parent[2], int currLevel, TreeNode* currParent)
{
    if(!root)   return;
    if(root->val == node1){
        level[0] = currLevel;
        parent[0] = currParent->val;
    }
    
    if(root->val == node2){
        level[1] = currLevel;
        parent[1] = currParent->val;
    }

    findNodes(root->left,node1,node2,level,parent,currLevel+1,root);
    findNodes(root->right,node1,node2,level,parent,currLevel+1,root);
}
// sol 1:
bool isCousins1(TreeNode* root, int x, int y){
    int level[2] = {-1,-1};
    int parent[2] = {-1,-1};
    findNodes(root,x,y,level,parent,0,new TreeNode(-1));


    if(level[0]==level[1] && parent[0]!=parent[1]) 
        return 1;
    return 0;
}

// sol 2: using DFS
bool isCousins2(TreeNode* root, int x, int y) {
    queue<TreeNode*> q;
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_map<TreeNode*, int> depth;

    if (root==NULL) return false;

    TreeNode *left=NULL, *right=NULL;

    parent[root]=NULL;
    depth[root]=0;
    q.push(root);

    while (!q.empty()) {
        TreeNode *root = q.front();

        if (root->val==x) left=root;
        else if (root->val==y) right=root;

        if (root->left) {
            q.push(root->left);
            parent[root->left]=root;
            depth[root->left]=depth[root]+1;
        }
        if (root->right) {
            q.push(root->right);
            parent[root->right]=root;
            depth[root->right]=depth[root]+1;
        }
        
        q.pop();

        if (left && right){
            if (parent[left]!=parent[right] && depth[left]==depth[right]) {
                return true;
            }
        }
    }
    return false;
}

// leetcode 2641 : Cousins in Binary Tree II
// Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins' values.
// Two nodes of a binary tree are cousins if they have the same depth with different parents.
// Return the root of the modified tree.

/*
          1                      0
        /   \                   / \
       2     3                 0   0
     /  \     \      =>      /  \   \
    4    5     6            6    6   9
   /    / \                /    / \
  7    8   9             17    7   7

  Here cousins are : (4,6) (5,6) (7,8) (7,9)
*/
vector<int> depthsum;

// Function to find the depth of each element.
void findDepthSum(TreeNode* root, int d){
    if(root==NULL) 
        return;

    if(d>=depthsum.size()) 
        depthsum.push_back(root->val);
    else 
        depthsum[d] += root->val;

    findDepthSum(root->left, d+1);
    findDepthSum(root->right, d+1);
}

// Function to recreate the tree 
void modifyTree(TreeNode* root, int d){  
    if(root==NULL) return;
    int minus = 0;

    // storing the value of children of current node in minus which to be deducted.
    if(root->left) 
        minus += root->left->val;
    if(root->right) 
        minus += root->right->val;

    // then assigning the sum of all nodes at that depth and subtracting it's own value and the value of its siblings which are stored in ded
    if(root->left) 
        root->left->val = depthsum[d+1] - minus;
    if(root->right) 
        root->right->val = depthsum[d+1] - minus;
    
    // then recursively do the same for all the nodes.
    modifyTree(root->left, d+1);
    modifyTree(root->right, d+1);
    
}

TreeNode* replaceValueInTree(TreeNode* root) {
    if(root==NULL) return NULL;
    root->val=0;
    findDepthSum(root, 0); // Function to find the depth of each element.
    modifyTree(root, 0); // Function to recreate the tree 
    return root;    
}

void inorder(TreeNode *root){
    if(!root)   return;
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

    cout<<isCousins1(root,4,6)<<endl;
    cout<<isCousins2(root,4,6)<<endl;

    TreeNode *AfterReplacing = replaceValueInTree(root);
    inorder(AfterReplacing);

    return 0;
}