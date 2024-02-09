#include<iostream>
using namespace std;

class node{
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

// Que 1) function for inorder for counting leaf nodes
void inorderForCount(node* root, int &countLeafs){
    if(root == NULL)
        return;

    inorderForCount(root->left, countLeafs);
    
    if(root->left == NULL && root->right == NULL)
        countLeafs++;

    inorderForCount(root->right, countLeafs);
}

// function for return leaf count
int LeafCount(node* root){
    int cnt=0;
    inorderForCount(root, cnt);
    return cnt;
}

// Que 2) function for height of binary tree
int height(node* root){
    if(root == NULL)
        return 0;
    
    int lh = height(root->left);
    int rh = height(root->right);

    int ht = max(lh, rh) + 1;

    return ht;
}


// 3) function for diameter of binary tree: 
// diameter of binary tree is longest distance between two end nodes(either leaf- leaf or root-leaf)  
// method 1: TC = o(n^2)
int diameter1(node* root){
    if(root == NULL)
        return 0;
    
    int op1 = diameter1(root->left);
    int op2 = diameter1(root->right);
    int op3 = height(root->left) + height(root->right) + 1;

    int dia = max(op1, max(op2, op3));

    return dia;
}
// Method 2: TC = O(n)
pair<int, int> diameterFast(node* root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0); //pair of (diameter, height)
        return p;
    }
    
    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int,int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}
int diameter2(node* root){
    return diameterFast(root).first;
}

// Que 3) check for height balance tree: height of left & right subtree is not more than 1 for all nodes
// Method 1: TC = O(n^2)
bool isBalance(node* root){
    if(root == NULL)
        return true;
    
    bool left = isBalance(root->left);
    bool right = isBalance(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(left && right && diff)
        return true;
    else
        return false;
}

// Method 2: TC= O(n)
pair<bool, int> isBalanceFast(node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(1,0); //pair of (check, height)
        return p;
    }
    
    pair<bool, int> left = isBalanceFast(root->left);
    pair<bool, int> right = isBalanceFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int> ans;
    ans.second = max(left.second, right.second) + 1;

    if(leftAns && rightAns && diff)
        ans.first = true;
    
    else
        ans.first = false;

    return ans;
}
bool isBalance2(node* root){
    return isBalanceFast(root).first;
}

// Que 4) function for checking two trees are identical or not
bool isIdentical(node* root1, node* root2){
    if(root1 == NULL && root2 == NULL)
        return true;
    
    if(root1 != NULL && root2 == NULL)
        return false;

    if(root1 == NULL && root2 != NULL)
        return false;
    
    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);

    bool val = root1->data == root2->data;

    if(left && right && val)
        return true;
    
    return false;
}

// Que 5) function for checking sum tree: Tree in which parent->data = (leftsub -> data + rightsub -> data)
// sol 1:
pair<bool,int> isSumTreeFast(node *root){
    // base case 1
    if(root == NULL){
        pair<bool,int> p = make_pair(true, 0);
        return p;
    }

    // base case 2 : for leaf nodes
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true, root->data);
        return p;
    }

    pair<bool,int> left = isSumTreeFast(root->left);
    pair<bool,int> right = isSumTreeFast(root->right);

    bool cond = root->data == (left.second + right.second);

    pair<bool,int> ans;
    if(left.first && right.first && cond)
        ans.first = true;

    else
        ans.first = false;

    return ans;
}

// sol 2:
bool isSumTree2(node* root){
    if(!root->left && !root->right)   // if child node
        return 1;
    
    if(root->left && root->right){   // if both child nodes are presents
        if(root->data != root->left->data + root->right->data)
            return 0;
        
        return isSumTree(root->left) && isSumTree(root->right);
    }
    
    else if(!root->left){           // if only right child node is present
        if(root->data != root->right->data)
            return 0;
        return isSumTree(root->right);
    }
    
    else{                           // if only left child node is present
        if(root->data != root->left->data)
            return 0;
        return isSumTree(root->left);
    }
        
}

bool isSumTree(node *root){
    // sol 1
    // return isSumTreeFast(root).first;

    // sol 2
    return isSumTree2(root);
}

int main(){
    node *root = NULL;
    // node *root1 = NULL, *root2 = NULL;

    // creating a tree
/*       1
       /  \
      2    3
     / \  /
    4  5  6
*/
    root = build_tree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1

    // cout<<"\nNumber of Leaves binary tree: "<<LeafCount(root);
    // cout<<"\nHeight of binary tree: "<<height(root);

    // cout<<"\nDiameter of binary tree: "<<diameter1(root);
    cout<<"\nDiameter of binary tree: "<<diameter2(root);

    // cout<<"\nisBalance Tree: "<<isBalance(root);
    // cout<<"\nisBalance2 Tree: "<<isBalance2(root);
    
    // cout<<"\nisSum Tree: "<<isSumTree(root);

    // cout<<"Enter nodes in first tree: \n";
    // root1 = build_tree(root);
    // cout<<"\nEnter nodes in second tree: \n";
    // root2 = build_tree(root);
    
    // cout<<"\nis above 2 trees are identical: "<<isIdentical(root1,root2);
    return 0;
}
