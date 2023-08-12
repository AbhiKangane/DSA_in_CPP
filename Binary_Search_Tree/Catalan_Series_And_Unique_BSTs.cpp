// given integer n return catalan number of nth position
// => (2n !) / [(n+1 !)* (n !)]  => (n+2)*(n+3)*...(2n) / n!  => sum of product of((n+k)/k) terms where 2 <= k <= n
// => 1, 1, 2, 5, 14, ....           for n = 0 to ...

/*
Applications:
1) Possible BSTs
2) Paranthesis or bracket combinations
3) Possible forests
4) Ways of triangulations
5) Possible paths in matrix
6) Dividing a circle using n chords
7) Dyck words of given length
*/
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

// for constructing unique bst
vector<node*> ConstructTrees(int start, int end){
    vector<node*> trees;
    if(start > end){
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i<=end; i++){
        vector<node*> leftSubtrees  = ConstructTrees(start, i-1); // consider i as a mid or root
        vector<node*> rightSubtrees = ConstructTrees(i+1, end);

        for (int j = 0; j<leftSubtrees.size(); j++){
            node* leftNode = leftSubtrees[j];
            for(int k=0; k<rightSubtrees.size(); k++){
                node* rightNode = rightSubtrees[k];
                node* newNode = new node(i);
                newNode->left = leftNode;
                newNode->right = rightNode;
                trees.push_back(newNode);
            }
        }
    }
    return trees;
}

// preorder
void preorder(node* root){
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// function for catalan numbers
int catalan(int n){
    if(n<=1){
        return 1;
    }
    int res = 0;
    for (int i = 1; i<=n-1; i++){
        res += catalan(i) * catalan(n-i);
    }
    return res;
}

int main(){
    cout<<"Catalan series upto 10 elements: "<<endl;
    for (int i = 1; i <= 10; i++){
        cout<<catalan(i)<<" ";
    }

    cout<<"\nPrinting all bst of 3 nodes: "<<endl;    
    vector<node*> trees = ConstructTrees(1,3);
    for(int i=0; i<trees.size(); i++){
        preorder(trees[i]);
        cout<<endl;
    }

}