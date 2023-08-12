#include<iostream>
#include<queue>
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

// insertion in BST
node* insertIntoBST(node* root, int d){
    // base case
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(d < root->data)
        root->left = insertIntoBST(root->left, d);

    else
        root->right = insertIntoBST(root->right, d);

    return root;
}


void takeInput(node* &root){
    int data;  cin>>data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}


// problem 1: finding kth minimum
int kth_min(node* root, int &i, int k){
    // base condition
    if(root == NULL)
        return -1;
    
    // check kth min is in left part
    int left = kth_min(root->left, i , k);
    if(left != -1)
        return left;

    i++;
    if(i == k)
        return root->data;

    // check for right part
    return kth_min(root->right, i, k);
}


// Problem 2: finding predecessor & successor of given node
pair<int,int> predSucc(node* root, int key){
    // find key
    node* temp = root;
    int pred = -1, succ = -1;

    while(temp->data != key){
        if(temp->data > key){
            succ = temp->data;
            temp = temp->left;
        }
    
        else{
            pred  = temp->data;
            temp = temp->right;
        }
    }

    // for predecessor
    node* leftTree = temp->left;
    while(leftTree){
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // for sucessor
    node* rightTree = temp->right;
    while(rightTree){
        succ = rightTree->data;
        rightTree = rightTree->left;
    }   

    pair<int, int> ans = make_pair(pred, succ);
    return ans;
}


// Problem 3: finding LCA of given nodes
node* LCA_in_BST(node* root, node* p, node* q){
    // base case
    if(root == NULL)
        return NULL;
    
    if(root->data < p->data && root->data < q->data)
        return LCA_in_BST(root->right, p, q);

    else if(root->data > p->data && root->data > q->data)
        return LCA_in_BST(root->left, p, q);

    return root; // this is for (root->data > p->data && root->data < q->data) || (root->data < p->data && root->data > q->data)

    // iterative code of above
/*    while(root){
        if(root->data < p->data && root->data < q->data)
            root = root->right;

        else if(root->data > p->data && root->data > q->data)
            root = root->left;

        else 
            return root;
    }
*/
}

// Problem 4: isBST
int isBSTUtil(node* Node, int min, int max){
    if (Node == NULL)
        return 1;
    
    if (Node->data < min || Node->data > max)
        return 0;
    
    return isBSTUtil(Node->left, min, Node->data - 1)
            && isBSTUtil(Node->right, Node->data + 1,max); 
}

bool isBST(node* root) {
    return (isBSTUtil(root, INT32_MIN, INT32_MAX));
}

int main(){
    node* root = NULL;
    // creating a tree
/*        10
        /    \
       5      15
     / \    /  \
    3   8  12   17
*/
    cout<<"Enter data to build BST: \n";
    takeInput(root);

    pair<int, int> ans = predSucc(root, 5);
    cout<<"\nPredcessor: "<<ans.first<<"\nSuccessor: "<<ans.second;

    int i=0, k=2;
    cout<<"\n\n2nd min of BST: "<<kth_min(root, i, k);

}