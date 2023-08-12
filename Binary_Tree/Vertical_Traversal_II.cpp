#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void getVeticalOrder(Node *root, int hdis, map<int, vector<int>> &m){
    if(root == NULL)
        return;
    
    m[hdis].push_back(root->data);
    getVeticalOrder(root->left, hdis-1, m);
    getVeticalOrder(root->right, hdis+1, m);
}

int main(){
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    // creating a tree
    /*       1
           /   \
          2     3
         / \   / \
        4  5  6  7
    */


    map<int, vector<int>> m;
    int hdis = 0;

    getVeticalOrder(root, hdis, m);

    map<int, vector<int>> :: iterator it;
    for (it = m.begin(); it != m.end(); it++){
        for(int i=0; i < it->second.size(); i++){
            cout<< it->second[i] <<" ";
        }
        cout<<endl;
    }
    
    return 0;
}