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
int findPosition(int in[], int inorderStart, int inorderEnd, int element, int size){
    for(int i=inorderStart; i<=inorderEnd; i++){
        if(element == in[i])
            return i;
    }
    return -1;
}

node* Solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int size){
    //  base case
    if(index >= size || inorderStart > inorderEnd)
        return NULL;
    
    int element = pre[index++];
    node* root = new node(element);
    int position = findPosition(in,inorderStart,inorderEnd,element, size);  // finding position of root in inorder

    // recursive calls
    root->left = Solve(in, pre, index, inorderStart, position-1, size);
    root->right = Solve(in, pre, index, position+1, inorderEnd, size);

    return root;
}

node* buildTree(int in[], int pre[], int size){
    int preOrderIndex = 0;
    node* ans = Solve(in, pre, preOrderIndex, 0, size-1, size);

    return ans;
}
//  sol 1 ends


// Solution 2:
void createMapping(int in[], map<int,int> &nodeToIndex, int size){
    for(int i=0; i<size; i++)
        nodeToIndex[in[i]] = i;
}

node* Solve2(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int size, map<int,int> &nodeToIndex){
    //  base case
    if(index >= size || inorderStart > inorderEnd)
        return NULL;
    
    int element = pre[index++];
    node* root = new node(element);

    int position = nodeToIndex[element];  // finding position of root in inorder

    // recursive calls
    root->left = Solve2(in, pre, index, inorderStart, position-1, size, nodeToIndex);
    root->right = Solve2(in, pre, index, position+1, inorderEnd, size, nodeToIndex);

    return root;
}

node* BuildTree2(int in[], int pre[], int size){
    int preOrderIndex = 0;

    // step 1: create mapping
    map<int,int> nodeToIndex;
    createMapping(in, nodeToIndex, size);

    node* ans = Solve2(in, pre, preOrderIndex, 0, size-1, size, nodeToIndex);

    return ans;
}
// sol 2 ends


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
    int in[] = {1,6,8,7};
    int pre[] = {1,6,7,8};
// post[] = {8,7,6,1}

    // creating a tree
    // root = BuildTree(in, pre, 4);    //using  1st approach
    root = BuildTree2(in, pre, 4);  // using 2nd appproach 

    cout<<"PostOrder: ";
    postorder(root);

    return 0;
}
