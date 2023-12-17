#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;

class TreeNode{
    public: 
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data){
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// 1. largest value in each level
vector<int> largestValues(TreeNode* root) {
    queue<TreeNode*> q;
    vector<int> temp;
    vector<vector<int>> ans;
    if(root == NULL) 
        return temp;
    q.push(root);
    
    while(q.empty() != true)
    {   vector<int>v;
        int n = q.size();
        for(int i=0;i<n;i++)
        {   TreeNode* t = q.front();
            q.pop();
            v.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        ans.push_back(v);
        int maxi = v[0];
        for(int i=1;i<v.size();i++)
            maxi = max(maxi,v[i]);
        temp.push_back(maxi);

        /*
        double total=0;
         for(int j=0;j<v.size();j++)
             total+=v[j];
         double r=total/v.size();   // for finding avg of each level (leetcode 637)
         temp.push_back(r);
         */
    }
    return temp;
}


// 2. level order traversal (Leetcode 102)
vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    if(root==NULL) 
        return ans;
    q.push(root);

    while(q.empty()!=true)
    {   vector<int>v;
        int n=q.size();
        for(int i=0;i<n;i++)
        {   TreeNode* t=q.front();q.pop();
            v.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        ans.push_back(v);
    }
    // reverse(ans.begin(),ans.end()); // for bottom-up level order traversal(leetcode 107)
    return ans;
}


// 3. N-ary level order traversal (Leetcode 429)
class Node{
    public: 
    int val;
    vector<Node*> children;

    Node(int data, vector<Node*> &child){
        this->val = data;
        this->children = child;
    }
};
vector<vector<int>> levelOrder(Node* root) {
    queue<Node*>q;
    vector<vector<int>>ans;
    if(root==NULL) return ans;
    q.push(root);
    while(q.empty()!=true)
    {   vector<int>v;
        int n=q.size();
        for(int i=0;i<n;i++)
        {   Node* t=q.front();q.pop();
            v.push_back(t->val);
            for(int j=0;j<t->children.size();j++)
                q.push(t->children[j]);
        }
        ans.push_back(v);
    }
    return ans; 
}


//  4. Zigzag level order traversal (leetcode 103)
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    if(root==NULL) 
        return ans;
    q.push(root);
    int j=0;

    while(q.empty()!=true)
    {   vector<int>v;
        int n=q.size();
        for(int i=0;i<n;i++)
        {   TreeNode* t=q.front();
            q.pop();
            v.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        if(j%2==1)
            reverse(v.begin(),v.end());
        j++;
        ans.push_back(v);
    }
    return ans;
}


// 5. even odd tree (leetcode 1609)
bool isEvenOddTree(TreeNode* root) {
    queue<TreeNode*>q;
    vector<vector<int>>ans;
    if(root==NULL) 
        return true;
    q.push(root);
    int j=0;
    
    while(q.empty()!=true)
    {   vector<int>v;
        int n=q.size();
        for(int i=0;i<n;i++)
        {   TreeNode* t=q.front();q.pop();
            v.push_back(t->val);
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }
        if(j%2==0)
        {
            for(int k=0;k<v.size()-1;k++)
            {
                if(v[k]%2==0)        // if level contains even valued node
                    return false;
                if(v[k]>=v[k+1])     // nodes in level aren't strictly increasing
                    return false;
            }
            if(v[v.size()-1]%2==0)   // if level contains odd no. nodes
                return false;
        }
        else
        {
            for(int k=0;k<v.size()-1;k++)
            {
                if(v[k]%2==1)       // if level contains odd valued node
                    return false;
                if(v[k]<=v[k+1])    // nodes in level aren't strictly decreasing
                    return false;
            }
            if(v[v.size()-1]%2==1)   // if level contains even no. nodes
                return false;
        }
        j++;
        ans.push_back(v);
    }
    return true;
}



int main(){
/*
            1
          /   \
        3      2
      /  \      \
     5    3      9
*/

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);


    cout<<"largest nodes at each level are : ";
    vector<int> largest = largestValues(root);
    for(int i=0; i<largest.size(); i++){
        cout<<largest[i]<<" ";
    }

    cout<<"\nLevel order traversal : ";
    vector<vector<int>> LOT = levelOrder(root);
    for(int i=0; i<LOT.size(); i++){
        cout<<"[ ";
        for (int j = 0; j <LOT[i].size(); j++){
            cout<<LOT[i][j]<<" ";
        }
        cout<<"]\t";
    }

    cout<<"\nZigzag order traversal : ";
    vector<vector<int>> zigzag = zigzagLevelOrder(root);
    for(int i=0; i<zigzag.size(); i++){
        cout<<"[ ";
        for (int j = 0; j <zigzag[i].size(); j++){
            cout<<zigzag[i][j]<<" ";
        }
        cout<<"]\t";
    }
}