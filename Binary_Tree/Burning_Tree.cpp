#include<iostream>
#include<map>
#include<queue>
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

node* build_tree(node* root){  // traversal is a preorder
    int data;
    cout<<"Enter data for node: ";
    cin>> data;
    root = new node(data);

    if(data == -1)
        return NULL; // if node->data is empty

    cout<<"\nEnter data for left child of "<<data<<endl;
    root->left = build_tree(root->left);
    cout<<"\nEnter data for right child of "<<data<<endl;
    root->right = build_tree(root->right);

    return root;
}


// create mapping of node with it's parent using level order traversal
node* createParentMapping(node* root, int target, map<node*, node*> &nodeToParent){
    node* res = NULL;
    queue<node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty()){
        node* front = q.front();
        q.pop();

        if(front->data == target)
            res = front;
        
        if(front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }

        if(front->right){
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

// burning tree: if a node is burn then its adjacent nodes(left, right, parent) are burn in 1 sec
int burnTree(node* root, map<node*, node*> &nodeToParent){
    map<node*, bool> visited;
    queue<node*> q;

    q.push(root);
    visited[root] = true;

    int ans = 0;

    while(!q.empty()){
        bool flag = 0;
        int size = q.size();

        for(int i=0; i<size; i++){
            // process neighbouring nodes
            node* front =  q.front();
            q.pop();

            if(front->left && !visited[front->left]){  // for left unvisited node
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }

            if(front->right && !visited[front->right]){  // for right unvisited node
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]]){  // for parent unvisited node
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }
        if(flag == 1)
            ans++;
    }
    return ans;
}

// calcultating minimum time required for burn tree completely
int minTime(node* root, int target){
    // step 1: create nodeToParent mapping
    // step 2: find target node
    map<node*, node*> nodeToParent;
    node* targetNode = createParentMapping(root, target, nodeToParent);

    // step 3: burn tree in minimum time
    int ans = burnTree(targetNode, nodeToParent);

    return ans;
}


int main(){
    node* root = NULL;

    // creating a tree
/*        1
       /    \
      2      3
     / \    /  \
    4  5   6   7
   / \
  8   9

  Flatten LL => 1, 2, 4, 8, 9, 5, 3, 6, 7
*/
    root = build_tree(root);
    // 1 2 4 8 -1 -1 9 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1

    int target = 8;

    cout<<"\nMinimum Time required for burning tree from target node "<<target<<" is : "<<minTime(root,target);
}