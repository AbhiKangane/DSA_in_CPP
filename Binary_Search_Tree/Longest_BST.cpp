// GFG Problem:
// Given a binary tree. Find the size of its largest subtree that is a Binary Search Tree.
// Note: Here Size is equal to the number of nodes in the subtree.

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

// solution 1 starts
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

int LargestBST(node* root){
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;  // no. of nodes in BST
}
// ends


// solution 2 made by me starts here
int isBSTUtil(node* root, int min, int max){
    if (root == NULL)
        return 1;
    
    if (root->data < min || root->data > max)
        return 0;
    
    return isBSTUtil(root->left, min, root->data - 1)
            && isBSTUtil(root->right, root->data + 1,max); 
}
// for check subtree is BST
bool isBST(node* root) {
    return (isBSTUtil(root, INT32_MIN, INT32_MAX));
}

// for counting no. of nodes in BST
int countNodes(node* root){
    //base case
    if(root==NULL)
        return 0;

    //recursive call to left child and right child and
    // add the result of these with 1 ( 1 for counting the root)
    return 1 + countNodes(root->left) + countNodes(root->right);
}
    
int largestBst_Util(node* root){
    if(root== NULL)
        return 0;
    
    if(isBST(root))
        return countNodes(root);
    
    int forleft = largestBst_Util(root->left);
    int forright = largestBst_Util(root->right);
    
    return max(forleft, forright);
}

/*You are required to complete this method */
// Return the size of the largest sub-tree which is also a BST
int largestBst_2(node *root)
{
    return largestBst_Util(root);
}


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

    // cout<<"Size of longest BST in binary tree is: "<<LargestBST(root);
    cout<<"Size of longest BST in binary tree is: "<<largestBst_2(root);
}
