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

void level_order_traversal(node* root){  // same as BFS
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){ // last level traversal completed
            cout<<endl;
            if(!q.empty())
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

void build_from_levelOrderTraversal(node* &root){
    queue<node*> q;
    cout<<"Enter data for root: ";
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<": ";
        int leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<": ";
        int rightData;
        cin>>rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
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


int main(){
    node* root = NULL;

    // creating a tree
/*        1
        /   \
      2      3
     / \   /  \
    4  5  6   7
*/
    root = build_tree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    // printing level order or BFS
    cout<<"\nLevel order of tree: \n";
    level_order_traversal(root);  

    // printing inorder traversal 
    // cout<<"\n\nInorder of tree: ";
    // inorder(root);   

    // build_from_levelOrderTraversal(root);
    // cout<<"\nLevel order of tree: "<<endl;
    // level_order_traversal(root);  

    return 0;
}