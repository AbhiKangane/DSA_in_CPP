#include<iostream>
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
// inserting nodes 
void takeInput(node* &root){
    int data;  cin>>data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}


// this que is slightly diffrent from following que
//  here we have to create bst which is sum of two bst
node* SumBST_1(node* root1, node* root2){
    // base case
    if(root1 == NULL)
        return root2;
    
    if(root2 == NULL)
        return root1;
    
    root1->data += root2->data;
    root1->left = SumBST_1(root1->left, root2->left);
    root1->right = SumBST_1(root1->right, root2->right);

    return root1;
}

// here we have create BST from 2 different BST by merging them
// solution 1 : using inorder & linked list
// step 1: find sorted LL (inorder) of given BST
void BST_Into_sortedLL(node* root, node* &head){
    if(root == NULL)    return ;

    BST_Into_sortedLL(root->right, head);
    root->right = head;

    if(head)
        head->left = root;

    head = root;
    
    BST_Into_sortedLL(root->left, head);
}

// step 2: merge 2 sorted LL
node* merge_LL(node* head1, node* head2){
    node* newHead = NULL;
    node* newTail = NULL;

    while(head1 && head2){
        if(head1->data < head2->data){
            if(newHead == NULL){
                newHead = head1;
                newTail = head1;
                head1 = head1->right;
            }
            else{
                newTail->right = head1;
                head1->left = newTail;
                newTail = head1;
                head1 = head1->right;
            }
        }

        else{
            if(newHead == NULL){
                newHead = head2;
                newTail = head2;
                head2 = head2->right;
            }
            else{
                newTail->right = head2;
                head2->left = newTail;
                newTail = head2;
                head2 = head2->right;
            }
        }
    }
    
    while(head1){
        newTail->right = head1;
        head1->left = newTail;
        newTail = head1;
        head1 = head1->right;
    }

    while(head2){
        newTail->right = head2;
        head2->left = newTail;
        newTail = head2;
        head2 = head2->right;
    }
    
    return newHead;
}


// step 3: finding total nodes in merge sorted LL
int countNodes(node* head){
    int cnt = 0;
    node* temp = head;
    while(temp){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

// step 4: merge sorted LL to BST
node* sortedLL_into_BST(node* &head, int n){
    // base case
    if(n <= 0 || head == NULL)
        return NULL;
    
    node* left = sortedLL_into_BST(head, n/2);
    node* root = head;
    node* right = sortedLL_into_BST(head, n/2 - 1);

    return root;
}

// driver function for all above functions
node* mergeBST(node* root1, node* root2){
    // step 1: find sorted LL (inorder) of given BST
    node* head1 = NULL;
    BST_Into_sortedLL(root1, head1);
    head1->left = NULL;
    
    node* head2 = NULL;
    BST_Into_sortedLL(root2, head2);
    head2->left = NULL;

    // step 2: merge 2 sorted LL
    node* newHead = merge_LL(head1, head2);

    // step 3: finding total nodes in merge sorted LL
    int total = countNodes(newHead);

    // step 4: merge sorted LL to BST
    return sortedLL_into_BST(newHead, total);
}


// solution 2: using array & inorder
// step 1: storing inorder of BST
void inorderBST(node* root, vector<int> &in){
    if(root == NULL)
        return;

    inorderBST(root->left, in);
    in.push_back(root->data);
    inorderBST(root->right, in);
}

// step 2: merging 2 arrays
vector<int> mergeArray(vector<int> &a, vector<int> &b){
    vector<int> ans(a.size() + b.size());
    int k = 0, i = 0, j = 0;

    while(i<a.size() && j<b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i++];
        }
        else
            ans[k++] = b[j++];
    }

    while(i < a.size()){
        ans[k++] = a[i++];
    }

    while(j < b.size()){
        ans[k++] = b[j++];
    }
    
    return ans; 
}

// step 3: inorder to BST
node* inorderToBST(int s, int e, vector<int> &in){
    // base case
    if(s > e)
        return NULL;

    int mid = (s+e)/2;
    node* root = new node(in[mid]);
    root->left = inorderToBST(s, mid-1, in);
    root->right = inorderToBST(mid+1, e, in);
    
    return root;
}

// driver function for all above functions
node* merge_2BST_usingVectors(node* root1, node* root2){
    // step 1: storing inorder of BST
    vector<int> bst1, bst2;
    inorderBST(root1, bst1);
    inorderBST(root2, bst2);

    // step 2: merging 2 arrays
    vector<int> merged_Array = mergeArray(bst1, bst2);

    // step 3: inorder to BST
    return inorderToBST(0, merged_Array.size()-1, merged_Array);
}


int main(){
    node *root1 = NULL, *root2 = NULL;
    cout<<"Enter data to build BST: \n";
    takeInput(root1);
    cout<<"\nEnter data to build BST: \n";
    takeInput(root2);

    node* sum_BST = SumBST_1(root1, root2);
    node* Merged_BST_1 = merge_2BST_usingVectors(root1, root2);
    node* Merged_BST_2 = mergeBST(root1, root2);

    vector<int> in_sum_BST;
    inorderBST(sum_BST, in_sum_BST);
    cout<<"Printing SumBST of 2 BST: \n";
    for (int i = 0; i < in_sum_BST.size(); i++){
        cout<<in_sum_BST[i]<<" ";
    }

    
    vector<int> M1;
    inorderBST(Merged_BST_1, M1);
    cout<<"\nPrinting Merged BST using vectors: \n";
    for (int i = 0; i < M1.size(); i++){
        cout<<M1[i]<<" ";
    }

    vector<int> M2;
    inorderBST(Merged_BST_2, M2);
    cout<<"\nPrinting Merged BST using linked lists: \n";
    for (int i = 0; i < M2.size(); i++){
        cout<<M2[i]<<" ";
    }

    return 0;
}