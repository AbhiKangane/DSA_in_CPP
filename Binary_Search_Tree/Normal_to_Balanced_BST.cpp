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



// inorder of BST
void inorderBST(node* root, vector<int> &in){
    if(root == NULL)
        return;

    inorderBST(root->left, in);
    in.push_back(root->data);
    inorderBST(root->right, in);
}

// function for creating BST from inorder (which is always balanced)
node* inorderToBST(int s, int e, vector<int> &in){
    // base case
    if(s > e){
        return NULL;
    }

    int mid = (s+e)/2;
    node* root = new node(in[mid]);
    root->left = inorderToBST(s, mid-1, in);
    root->right = inorderToBST(mid+1, e, in);
    
    return root;
}

node* balance_BST(node* root){
    vector<int> in;
    inorderBST(root, in);
    int s = 0, e = in.size()-1;

    return inorderToBST(s, e, in);
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

    cout<<"\nPrinting level order traversal before conversion: \n";
    level_order_traversal(root);
    
    cout<<"\n\nPrinting level order traversal after conversion: \n";
    node* bal_BST = balance_BST(root);
    level_order_traversal(bal_BST);

}