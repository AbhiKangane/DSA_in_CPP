// leetcode 863: Store All Nodes Distance K from given node in Binary Tree
#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
using namespace std;

class TreeNode{
    public: 
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

// sol 1
vector<int> ans;
// case 1 : find nodes in bellow node(i.e. in subtree)
void printSubtreeNodes(TreeNode *root, int k){
    if( root == NULL || k<0)
        return ;

    if(k == 0){
        ans.push_back(root->val);
        return;
    }

    // if (k>0)
    printSubtreeNodes(root->left, k-1); 
    printSubtreeNodes(root->right, k-1); 
}

// case 2 : find nodes in upper(or upper left or right) node(i.e. in ancestor)
int printNodes_At_k(TreeNode *root, TreeNode *target, int k){
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
            ans.push_back(root->val);
        else
            printSubtreeNodes(root->right, k-dis_left-2);

        return 1+dis_left;
    }

    //  for right subtree of root 
    int dis_right = printNodes_At_k(root->right, target, k);
    if(dis_right != -1){
        if(dis_right + 1 == k)
            ans.push_back(root->val);
        else
            printSubtreeNodes(root->left, k-dis_right-2);

        return 1+dis_right;
    }

    return -1;
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    printNodes_At_k(root, target, k);
    return ans;
}

// sol 2
// creating nodeToParent Map
void populateMap(TreeNode *curr, TreeNode *parent, unordered_map<TreeNode*,TreeNode*> &nodeToParentMap){
    if(!curr)
        return;
    nodeToParentMap[curr] = parent;
    populateMap(curr->left,curr,nodeToParentMap);
    populateMap(curr->right,curr,nodeToParentMap);
}

// finding all nodes at distance k
void printAtKDistance(TreeNode *curr, int k, set<TreeNode*> &s,
    unordered_map<TreeNode*, TreeNode*> nodeToParentMap, vector<int> &ans)
{
    if(!curr || s.find(curr)!=s.end() || k<0)
        return;
    s.insert(curr);
    if(k==0){
        ans.push_back(curr->val);
        return;
    }
    printAtKDistance(curr->left,k-1,s,nodeToParentMap,ans);//call left child
    printAtKDistance(curr->right,k-1,s,nodeToParentMap,ans);//call right child
    printAtKDistance(nodeToParentMap[curr],k-1,s,nodeToParentMap,ans);//call parent
    return;
}

vector<int> distanceK_2(TreeNode* root, TreeNode* target, int k) {
    vector<int> res;
    set<TreeNode*> s;
    unordered_map<TreeNode*,TreeNode*> nodeToParentMap;
    populateMap(root,NULL,nodeToParentMap);
    printAtKDistance(target,k,s,nodeToParentMap,res);
    return res;
}



int main(){
    TreeNode* root = NULL;
    // creating a tree
/*        1
        /   \
      2      3
     / \    /  \
    4  5   6   7
        \
        8
*/
    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    
    
    vector<int> ans = distanceK(root, root->left, 2);
    for(auto i: ans)
        cout<<i<<" ";
        
    cout<<endl;

    vector<int> res = distanceK_2(root, root->left, 2);
    for(auto i: res)
        cout<<i<<" ";

    return 0;
}
