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

int solveRec(node*root, int &ans){
    if(root == NULL)
        return 0;
    
    int left = solveRec(root->left, ans);
    int right = solveRec(root->right, ans);

    int nodeMax = max(max(root->data, root->data +left+right),
                      max(root->data+left, root->data+right));

    ans = max(ans, nodeMax);
    int singlePathSum = max(root->data, max(root->data+left, root->data+right));
    return singlePathSum;
}

int maxPathSum(node *root){
    int ans = INT32_MIN;
    solveRec(root, ans);
    return ans;
}

int main(){
/*        1
        /   \
      2      3
     / \   /  \
    4  5  6   7
*/
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout<<maxPathSum(root); // ans = 5+2+1+3+7 = 18
    return 0;
}