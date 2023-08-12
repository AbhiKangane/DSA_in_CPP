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

// Function to find the vertical order traversal of Binary Tree.
vector<int> verticalOrder(node *root)
{
    map<int, map<int, vector<int>>> nodes;
    queue<pair<node *, pair<int, int>>> q;
    vector<int> ans;

    if (root == NULL)
        return ans;

    q.push(make_pair(root, make_pair(0, 0)));

    while (!q.empty())
    {
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();
        node *frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if (frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));

        if (frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
    }

    for (auto i : nodes)
    {

        for (auto j : i.second)
        {

            for (auto k : j.second)
            {
                ans.push_back(k);
            }
        }
    }
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
    vector<int> zigzag = verticalOrder(root);
    cout << "\nVertical traversal: ";
    for (int i = 0; i < zigzag.size(); i++)
    {
        cout << zigzag[i] << " ";
    }
    return 0;
}