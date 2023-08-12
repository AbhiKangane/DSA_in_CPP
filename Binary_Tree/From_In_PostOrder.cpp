#include<iostream>
#include<map>
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

// Solution 1:
//  for finding positon in innorder array
int findPosition(int in[], int element, int size){
    for(int i=0; i<size; i++){
        if(element == in[i])
            return i;
    }
    return -1;
}

node* Solve(int in[], int post[], int index, int inorderStart, int inorderEnd, int size){
    //  base case
    if(index < 0 || inorderStart > inorderEnd)
        return NULL;
    
    int element = post[index--]; // starting from end of PreOrder
    node* root = new node(element);
    int position = findPosition(in,element, size);  // finding position of root in inorder

    // recursive calls
    root->right = Solve(in, post, index, position+1, inorderEnd, size);  // in this we first to consider right subtree 1st
    root->left = Solve(in, post, index, inorderStart, position-1, size);

    return root;
}

node* BuildTree(int in[], int post[], int size){
    int postOrderIndex = size-1;
    node* ans = Solve(in, post, postOrderIndex, 0, size-1, size);

    return ans;
}
//  sol 1 ends


// Solution 2:
void createMapping(int in[], map<int,int> &nodeToIndex, int size){
    for(int i=0; i<size; i++)
        nodeToIndex[in[i]] = i;
}

node* Solve2(int in[], int post[], int &index, int inorderStart, int inorderEnd, int size, map<int,int> &nodeToIndex){
    //  base case
    if(index < 0 || inorderStart > inorderEnd)
        return NULL;
    
    int element = post[index--];
    node* root = new node(element);

    int position = nodeToIndex[element];  // finding position of root in inorder

    // recursive calls
    root->right = Solve2(in, post, index, position+1, inorderEnd, size, nodeToIndex);  // in this we first to consider right subtree 1st
    root->left = Solve2(in, post, index, inorderStart, position-1, size, nodeToIndex);

    return root;
}

node* BuildTree2(int in[], int post[], int size){
    int postOrderIndex = size-1;

    // step 1: create mapping
    map<int,int> nodeToIndex;
    createMapping(in, nodeToIndex, size);

    node* ans = Solve2(in, post, postOrderIndex, 0, size-1, size, nodeToIndex);

    return ans;
}
// sol 2 ends


void PreOrder(node* root){
    if(root == NULL)
        return;

    else{
        cout<<root->data<<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}


int main(){
    node* root = NULL;
    int in[] = {4,2,5,1,6,3,7};
    int post[] = {4,5,2,6,7,3,1};
    // pre[] = {1,2,4,5,3,6,7}

// int in[] = {2,1,3} , post[] = {2,3,1};
// pre[] = {1,2,3}
    


    // creating a tree
    // root = BuildTree(in, post, 7);    //using  1st approach  // solution not works properly
    root = BuildTree2(in, post, 7);  // using 2nd appproach 

    cout<<"PreOrder: ";
    PreOrder(root);

    return 0;
}