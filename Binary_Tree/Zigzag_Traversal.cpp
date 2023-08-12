// Que: printing nodes in left to right & right to left from 1st level to last level alternatively
#include<bits/stdc++.h>
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

//  Zizag traversal
vector <int> zigZagTraversal(node* root)
{
    vector<int> result;
	if(root == NULL)
  	    return result;
    	
   	queue<node*> q;
   	q.push(root);
    	
    bool leftToRight = true;
    	
    while(!q.empty()) {
    	    
        int size = q.size();
        vector<int> ans(size);
    	    
        //Level Process
        for(int i=0; i<size; i++) {
            
            node* frontNode = q.front();
            q.pop();
    	        
            //normal insert or reverse insert 
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode -> data;
            
            if(frontNode->left)
                q.push(frontNode -> left);
    	            
            if(frontNode->right)
                q.push(frontNode -> right);
        }
    	    
        //direction change karni h
        leftToRight = !leftToRight;
    	   
        for(auto i: ans) {
            result.push_back(i);
    	}  
    }
    return result;
}


// solution 2: using 2 stacks
void zigzag(node* root){
    // base condition
    if(root == NULL)        return;

    stack<node*> currLevel;
    stack<node*> nextLevel;
    bool leftToRight = true;

    currLevel.push(root);

    while (!currLevel.empty()){
        node* temp = currLevel.top();
        currLevel.pop();

        if(temp){
            cout<<temp->data<<" ";
        
            if(leftToRight){  // for right direction
                if(temp->left)      nextLevel.push(temp->left);
                if(temp->right)     nextLevel.push(temp->right);
            }

            // for left directon
            else{
                if(temp->right)      nextLevel.push(temp->right);
                if(temp->left)      nextLevel.push(temp->left);
            }
        }
        
        // changing direction & swapping stacks 
        if(currLevel.empty()){  
            leftToRight = !leftToRight;
            swap(currLevel, nextLevel);
        }
    }
}


void level_order_traversal(node* root){  // same as BFS
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){ // last level traversal completed
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }

        else{
            cout<<temp->data<<" ";

            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }    
    }
}

int main(){
    node* root = NULL;
    // creating a tree
/*        1
        /   \
      2      3
     / \   /  \
    4  5  6   7
*/
    root = build_tree(root);
    // 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
    cout<<"\n"<<endl;
    level_order_traversal(root);

    vector<int> v = zigZagTraversal(root);
    cout<<"\n"<<endl;
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    

    cout<<endl<<endl;
    zigzag(root);
    return 0;
}