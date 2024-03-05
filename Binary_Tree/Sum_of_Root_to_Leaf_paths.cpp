// Given binary tree conatains only binary values
// return the sum of all root->leaf paths represented in binary form.
/*
         1          
       /   \        
      0     1      
     / \     \      = (100) + (1010) + (110) = 4+10+6 = 20
    0   1     0     
       /         
      0          
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

void rootToLeaf(TreeNode *root, string currStr, vector<string> &allPaths, int &ans){
    if(!root->left && !root->right){
        currStr += to_string(root->data);
        allPaths.push_back(currStr);
        // stoi() can takes upto 3 parameters, the 2nd parameter is for starting index & 3rd parameter is for base of input no.  
        ans += stoi(currStr, 0, 2);
        return;
    }

    string curr = to_string(root->data);
    if(root->left)
        rootToLeaf(root->left, currStr+curr, allPaths, ans);
    if(root->right)
        rootToLeaf(root->right,currStr+curr, allPaths, ans);
}
int sumRootToLeaf(TreeNode *root){
    vector<string> allPaths;
    int ans = 0;
    rootToLeaf(root, "", allPaths, ans);
    for(auto i: allPaths)
        cout<<i<<" ";
    cout<<endl;

    return ans;
}

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(0);
    root->left->right->left = new TreeNode(0);

    // printing ans
    cout<<sumRootToLeaf(root);

    return 0;
}