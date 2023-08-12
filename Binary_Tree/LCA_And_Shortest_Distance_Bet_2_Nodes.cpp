#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

node *build_tree(node *root)
{ // traversal is a preorder
    int data;
    cout << "Enter data for node: ";
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL; // if node->data is empty

    cout << "\nEnter data for left child of " << data << endl;
    root->left = build_tree(root->left);
    cout << "\nEnter data for right child of " << data << endl;
    root->right = build_tree(root->right);

    return root;
}


// 1)Function to return the lowest common ancestor in a Binary Tree.
node *lca(node *root, int n1, int n2)
{
    // base case
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    node *leftAns = lca(root->left, n1, n2);
    node *rightAns = lca(root->right, n1, n2);

    if (leftAns != NULL && rightAns != NULL)
        return root;

    else if (leftAns != NULL && rightAns == NULL)
        return leftAns;

    else if (leftAns == NULL && rightAns != NULL)
        return rightAns;

    else // here (leftAns == NULL && rightAns == NULL)
        return NULL;
}

int distanceFrom_LCA(node* LCA, int nodeVal, int dist){
    if(LCA == NULL)
        return -1;

    if(LCA->data == nodeVal)
        return dist;
    
    int left = distanceFrom_LCA(LCA->left, nodeVal, dist+1);
    if(left != -1)  // if nodeVal lie in left subtree
        return left;

    else
        return distanceFrom_LCA(LCA->right, nodeVal, dist+1); // nodeVal lie in right subtree

}

int distance_bet2_Nodes(node*root, int n1, int n2){
    node *lowest_CA = lca(root, n1,n2);

    int d1 = distanceFrom_LCA(lowest_CA, n1, 0);
    int d2 = distanceFrom_LCA(lowest_CA, n2, 0);

    return d1+d2;
}

int main()
{
    node *root = NULL;
    // node *root1 = NULL, *root2 = NULL;

    // creating a tree
    /*       1
           / \
          2    3
         / \  /
        4  5  6
    */
    root = build_tree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 -1

    cout<<"LCA of 2 & 5 is: "<< lca(root, 2,5)->data <<endl;
    cout<<"distance between node 2 & 6 is: "<< distance_bet2_Nodes(root, 2,6) <<endl;

    return 0;
}