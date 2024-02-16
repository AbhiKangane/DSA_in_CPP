#include<iostream>
#include<vector>
using namespace std;

class Node{
    public: 
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* build_tree(Node* root){  // traversal is a preorder
    int data;
    cout<<"Enter data for node: ";
    cin>> data;
    root = new Node(data);

    if(data == -1)
        return NULL; // if node->data is empty

    cout<<"\nEnter data for left child of "<<data<<endl;
    root->left = build_tree(root->left);
    cout<<"\nEnter data for right child of "<<data<<endl;
    root->right = build_tree(root->right);

    return root;
}

// sol 1 : Brute Force
// insertion in BST
Node* insertIntoBST(Node* root, int d){
    // base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    root->right = insertIntoBST(root->right, d);
    return root;
}

void inorderGen(Node* root, vector<int> &in){
    if(!root)
        return ;
    inorderGen(root->left, in);
    in.push_back(root->data);
    inorderGen(root->right, in);
}

Node *flattenBST(Node *root){
    vector<int> in;
    inorderGen(root, in);
    
    Node *newRoot=NULL;
    for(int i=0; i<in.size(); i++){
        newRoot = insertIntoBST(newRoot, in[i]);
    }  
    return newRoot;
}
// sol 1 ends


// sol 2 : optimal sol
void inorder2(Node* root, Node* &prev){
    if(!root)
        return ;
    inorder2(root->left, prev);
    prev->left = NULL;
    prev->right = root;
    prev = root;
    inorder2(root->right, prev);
}

Node *flattenBST_Optimal(Node *root){
    Node *newRoot = new Node(-1);
    Node *prev = newRoot;
    inorder2(root, prev);
    
    // for last (right most or maximum) node
    prev->left = NULL;
    prev->right = NULL;
    
    return newRoot->right;
}
// sol 2 ends

// preorder
void Preorder(Node* root){
    if(!root)
        return ;
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

int main(){
    Node* root = NULL;

    // creating a BST
/*        6
        /   \
      4      8
     / \    /  \
    2   5  7    9
   / \
  1   3

  original preorder :  6,4,2,1,3,5,8,7,9
  after Flatten to LL preorder => 1,2,3,4,5,6,7,8,9
*/
    root = build_tree(root);
    // 6 4 2 1 -1 -1 3 -1 -1 5 -1 -1 8 7 -1 -1 9 -1 -1

    cout<<"Preorder of original BST : ";
    Preorder(root);

    Node* ans = flattenBST(root);
    cout<<"\n\nPrinting Flatten LL of tree by creating new BST: ";
    Preorder(ans);

    Node* ans2 = flattenBST_Optimal(root);
    cout<<"\n\nPrinting Flatten LL of tree using optimal approach: ";
    Preorder(ans2);

    return 0;
}
