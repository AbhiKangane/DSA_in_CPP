#include<iostream>
#include<vector>
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

// sol 1 : Iterative function for flat a tree 
void Flatten(node* root){
    node* curr = root;
    while(curr != NULL){
        if(curr->left){
            node* pred = curr->left;
            
            while(pred->right)
                pred = pred->right;
            
            pred->right = curr->right;   // predecesor's right points root's right
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

// sol 2: Recursive sol
void flattenRec(node *root){
    if(!root->left && !root->right)
        return;
    
    if(root->left){
        flattenRec(root->left);
        
        node* storesRight = root->right;
        root->right = root->left;
        root->left = NULL;
        
        node* storesOrgLeft = root->right; // it actually stores original left node
        
        while(storesOrgLeft->right){
            storesOrgLeft = storesOrgLeft->right;
        }
        
        storesOrgLeft->right = storesRight;
    }
    
    flattenRec(root->right);
}


// sol 3: starts
// inorder
void inorderBST(node* root, vector<int> &in){
    if(root == NULL)
        return;

    inorderBST(root->left, in);
    in.push_back(root->data);
    inorderBST(root->right, in);
}


//  this function creates a flatten tree in form of LL in the order of inorder of Binary tree
node* inorder_flatten_Tree(node* root){
    vector<int> in;
    inorderBST(root, in);
    int n = in.size();

    node* newRoot = new node(in[0]);
    node* curr = newRoot;

    // 2nd step
    for(int i = 1; i < n; i++){
        node* temp = new node(in[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    
    // 3rd step
    curr->left = NULL;
    curr->right = NULL;

    return newRoot;
}


// printing Flatten LL
void PrintLL(node* root){
    node *temp = root;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->right;
    }
}

int main(){
    node* root = NULL;

    // creating a tree
/*        1
       /    \
      2      3
     / \    /  \
    4  5   6   7
   / \
  8   9

  Flatten LL => 1, 2, 4, 8, 9, 5, 3, 6, 7
*/
    root = build_tree(root);
    // 1 2 4 8 -1 -1 9 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    Flatten(root);
    cout<<"\nPrinting Flatten LL of tree: \n";
    PrintLL(root);

    flattenRec(root);
    cout<<"\nPrinting Flatten LL of tree: \n";
    PrintLL(root);

    cout<<endl;
    PrintLL(inorder_flatten_Tree(root));

}
