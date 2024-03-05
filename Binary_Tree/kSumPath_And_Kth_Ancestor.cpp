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

// 1) K sum path
void solve(node *root, int k, int &count, vector<int> path)
{
    // base case
    if (root == NULL)
        return;

    path.push_back(root->data);

    // left
    solve(root->left, k, count, path);
    // right
    solve(root->right, k, count, path);

    // check for K Sum

    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        if (sum == k)
            count++;
    }

    path.pop_back();
}
// leetCode 437 : Path Sum III 
int K_sum_path(node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}



// 2) function for finding kth ancestor for a node
node *solve(node *root, int &k, int nd)
{
    // base case
    if (root == NULL)
        return NULL;

    if (root->data == nd)
    {
        return root;
    }

    node *leftAns = solve(root->left, k, nd);
    node *rightAns = solve(root->right, k, nd);

    // wapas
    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            // answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }

    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            // answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int kthAncestor(node *root, int k, int nodeVal)
{
    node *ans = solve(root, k, nodeVal);
    if (ans == NULL || ans->data == nodeVal)
        return -1;
    else
        return ans->data;
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
    int k = 7;
    cout << "\nNo. of paths having sum equals " << k << " are: " << K_sum_path(root, k);

    cout << "\n2nd Ancestor of node 5: " << kthAncestor(root, 2, 5);  // 1

    return 0;
}