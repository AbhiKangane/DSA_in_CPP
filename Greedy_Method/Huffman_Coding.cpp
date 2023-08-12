// given string s, f[] contains frequency of each characters in the string
// we have to find Huffman codes for each character from the string
// here generating binary tree is same as Optima Merge Pattern question
// then give, 0 for left edges & 1 for right edges

#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)

class Node{
    public:
    int data;
    Node *left, *right;

    Node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

class cmp{
    public:
    bool operator()(Node *a, Node *b){
        return a->data > b->data;
    }
};

// function for traversing tree
void Traverse(Node* root, vector<string> &ansCodes, string tempStr){
    // base case
    if(!root->left && !root->right){
        ansCodes.push_back(tempStr);
        return;
    }

    Traverse(root->left, ansCodes, tempStr+'0');
    Traverse(root->right, ansCodes, tempStr+'1');
}

// function for storing Huffman codes
vector<string> Huffman_Codes(string s, vector<int> freq, int N){
    // creating minheap
    priority_queue<Node*, vector<Node*>, cmp> minheap;
    rep(i,0,N){
        Node *temp = new Node(freq[i]);
        minheap.push(temp);
    }

    while (minheap.size() > 1){
        Node* leftNode = minheap.top();
        minheap.pop();
        Node* rightNode = minheap.top();
        minheap.pop();

        Node* newNode = new Node(leftNode->data + rightNode->data);
        // connecting newNode with left & right Nodes
        newNode->left = leftNode;
        newNode->right = rightNode;

        minheap.push(newNode);
    }

    Node *root = minheap.top(); // only 1 node is remains

    vector<string> ansCodes;
    string tempStr = "";
    Traverse(root, ansCodes, tempStr);

    return ansCodes;
}

int main(){
    string S = "abcdef";
    int n = S.size();

    vector<int> freq = {5,9,12,13,16,45};
    // cout<<"Enter frequency of each char in string : ";
    // rep(i,0,n)
    //     cin>>freq[i];


    cout<<"Printing Huffman Codes : ";
    vector<string> Codes = Huffman_Codes(S, freq, n);

    rep(i,0,n){
        cout<<Codes[i]<<" ";
    }
    
    return 0;   
}