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

// solution starts
void traverseLeft(node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->data);
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

void traverseLeaf(node *root, vector<int> &ans)
{
    // base case
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

void traverseRight(node *root, vector<int> &ans)
{
    // base case
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);

    // wapas aagye
    ans.push_back(root->data);
}

vector<int> boundary_Traversal(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    // left part print/store
    traverseLeft(root->left, ans);

    // traverse Leaf Nodes

    // left subtree
    traverseLeaf(root->left, ans);
    // right subtree
    traverseLeaf(root->right, ans);

    // traverse right part
    traverseRight(root->right, ans);

    return ans;
}
// solution ends

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
    vector<int> boundary = boundary_Traversal(root);
    cout << "\nBoundary traversal: ";
    for (int i = 0; i < boundary.size(); i++)
    {
        cout << boundary[i] << " ";
    }
    return 0;
}