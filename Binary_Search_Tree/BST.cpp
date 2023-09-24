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


void level_order_traversal(node* root){  // same as BFS
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){ // last level traversal completed
            cout<<endl;
            if(!q.empty())  // queue still have some child nodes
                q.push(NULL);
        }

        else{
            cout<<temp->data<<" ";

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }    
    }
}

void preorder(node* root){
    if(root == NULL)
        return;

    else{
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root){
    if(root == NULL)
        return;

    else{
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void postorder(node* root){
    if(root == NULL)
        return;

    else{
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}


// node contains minimum value
node* minVal(node* root){
    node* temp = root;
    while(temp->left)       temp = temp->left;
    return temp;
}
// node contains maximum value
node* maxVal(node* root){
    node* temp = root;
    while(temp->right)      temp = temp->right;
    return temp;
}


// insertion in BST
node* insertIntoBST(node* root, int d){
    // base case
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(d < root->data)
        root->left = insertIntoBST(root->left, d);

    else if(d > root->data)
        root->right = insertIntoBST(root->right, d);

    return root;
}

// deletion in BST
node* deleteFromBST(node* root, int val){
    // base case
    if(root == NULL)
        return root;
    
    if(root->data == val){
        // case 1: for leaf node
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }

        // case 2: for single child;
        // a) for left child
        if(root->left && !root->right){
            node* temp = root->left;
            delete root;
            return temp;
        }
        // b) for right child
        if(!root->left && root->right){
            node* temp = root->right;
            delete root;
            return temp;
        }

        // case 3: for intermediate node
// this node is either replaced by inorder predecesor(max node from left subtree) or successor(min node from right subtree)
        if(root->left && root->right){
            int min = minVal(root->right) -> data; // inorder sucessor
            root->data = min;
            root->right = deleteFromBST(root->right, min);
            return root;
        }
    }

    else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
        return root;
    }

    else{
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}


// function for checking is valid BST
bool isBST(node* root, int min, int max){
    if(root == NULL)
        return true;
    
    if(root->data >= min && root->data <= max){
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);

        return (left && right);
    }

    else 
        return false;
}


// problem: function for generating BST from preorder
node* solve(vector<int> &preorder, int  mini, int maxi, int &i){
    // base cases
    if(i > preorder.size() || preorder[i] > maxi || preorder[i] < mini)
        return NULL;

    node* root = new node(preorder[i++]);
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);

    return root;
} 

node* preorder_To_BST(vector<int> &preorder){
    int mini = INT32_MIN;
    int maxi = INT32_MAX;
    int i = 0;

    return solve(preorder, mini, maxi, i);
}
// ends


void takeInput(node* &root){
    int data;  cin>>data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}



int main(){
    node* root = NULL;

/*  // for preorder to bst function  
    vector<int> v = {10,5,3,8,15,12,17};
    node* preTo_bst = preorder_To_BST(v); 
    cout<<"\nPrinting level order: \n";
    level_order_traversal(preTo_bst);

    cout<<"\nPrinting Inorder: \n";
    inorder(preTo_bst)
*/

    // creating a BST
/*        10
        /    \
       5      15
     / \    /  \
    3   8  12   17
*/

    cout<<"Enter data to build BST: \n";
    takeInput(root);


    cout<<"\nPrinting level order: \n";
    level_order_traversal(root);

    cout<<"\nPrinting Inorder: \n";
    inorder(root);

    node* minNode = minVal(root);
    node* maxNode = maxVal(root);

    cout<<"\nIs Valid BST: "<<isBST(root, minNode->data, maxNode->data);

    return 0;
}
