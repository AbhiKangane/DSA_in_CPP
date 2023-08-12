#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data, i, j;

    node(int data, int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

vector<int> merge_K_Sorted_Arrays(vector<vector<int>> &kArrays, int k){
    // creating min heap of nodes
    priority_queue<node*, vector<node*>, compare> minheap;

    // step 1: insert 1st element of each array into minheap
    for(int i = 0; i < k; i++){
        node* temp = new node(kArrays[i][0], i, 0);
        minheap.push(temp);
    }

    vector<int> ans;

    // step 2 : for remaining elements
    while(minheap.size() > 0){
        node* temp = minheap.top();

        ans.push_back(temp->data);
        minheap.pop();

        int i = temp->i;
        int j = temp->j;

        // if next element in array is available
        if(j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1], i, j+1);
            minheap.push(next);
        }
    }
    
    return ans;
}

int main(){
    vector<vector<int>> v = {
        {2,5,7,9},
        {1,3,4,8},
        {6,10,11,12}
    };

    vector<int> ans = merge_K_Sorted_Arrays(v, 3);
    // cout<<"ans.size() : "<<ans.size();

    cout<<"Printing merge k sorted arrays: \n";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
}