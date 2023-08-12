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

// Function to return a list containing elements of left view of the binary tree.
void solve(node *root, vector<int> &ans, int level)
{
    // base case
    if (root == NULL)
        return;

    // we entered into a new level
    if (level == ans.size())
        ans.push_back(root->data);

    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

vector<int> leftView(node *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}

// Function to return list containing elements of right view of binary tree.
void solve2(node *root, vector<int> &ans, int level)
{
    // base case
    if (root == NULL)
        return;

    // we entered into a new level
    if (level == ans.size())
        ans.push_back(root->data);

    solve2(root->right, ans, level + 1);
    solve2(root->left, ans, level + 1);
}
vector<int> rightView(node *root)
{
    vector<int> ans;
    solve2(root, ans, 0);
    return ans;
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
    vector<int> left = leftView(root);
    cout << "\nLeft View: ";
    for (int i = 0; i < left.size(); i++)
    {
        cout << left[i] << " ";
    }

    vector<int> right = rightView(root);
    cout << "\nRight View: ";
    for (int i = 0; i < right.size(); i++)
    {
        cout << right[i] << " ";
    }
    return 0;
}