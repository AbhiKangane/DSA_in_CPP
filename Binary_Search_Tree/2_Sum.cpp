#include<iostream>
#include<vector>
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

// insertion in BST
node* insertIntoBST(node* root, int d){
    // base case
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(d < root->data)
        root->left = insertIntoBST(root->left, d);

    else
        root->right = insertIntoBST(root->right, d);

    return root;
}


void takeInput(node* &root){
    int data;  cin>>data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

// inorder
void inorderBST(node* root, vector<int> &in){
    if(root == NULL)
        return;

    inorderBST(root->left, in);
    in.push_back(root->data);
    inorderBST(root->right, in);
}

// check that is there are two nodes present such that their data's sum equal target value
bool twoSum(node* root, int target){
    vector<int> inorder;
    inorderBST(root, inorder);
    int i=0, j=inorder.size()-1;


   while(i<j){
        int sum = inorder[i] + inorder[j];
        if(sum == target){
            cout<<"\n"<<inorder[i]<<" + "<<inorder[j]<<" = "<<sum;
            return true;
        }
        else if(sum > target)
            j--;
        
        else 
            i++;
   }
   return false;
}



int main(){
    node* root = NULL;
    // creating a BST
/*        10
        /    \
       5      15
     / \    /  \
    3   8  12   17
*/
    cout<<"Enter data to build BST: \n";
    takeInput(root);

    cout<<"\nIs there sum of two nodes data equal 20 present: "<<twoSum(root, 20);

}