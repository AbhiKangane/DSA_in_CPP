// in this problem we have to find smallest range in which at least one element of each sorted sorte list is lies 

#include<bits/stdc++.h>
#include<queue>
using namespace std;

class node{
    public:
    int data, row, col;

    node(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};

class compare{
    public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

int K_Sorted(vector<vector<int>> &a, int k, int n){
    int mini = INT32_MAX, maxi = INT32_MIN;
    // step 1: create min Heap for starting element of each list & tracking mini/maxi values
    priority_queue<node*, vector<node*>, compare > minHeap;

    for(int i = 0; i < k; i++){
        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minHeap.push(new node(element, i, 0));
    }

    int start = mini;
    int end = maxi;

    while(! minHeap.empty()){
        node *temp = minHeap.top();
        minHeap.pop();

        mini = temp->data;

        // range or answer updation
        if(maxi-mini < end-start){
            start = mini;
            end = maxi;
        }

        // next element exists
        if(temp->col + 1< n){
            maxi = max(maxi, a[temp->row][temp->col+1]);
            minHeap.push(new node(a[temp->row][temp->col+1], temp->row, temp->col+1));
        }

        else   // next element doesn't exist
            break;
    }
    // returning diff. of range values
    cout<<"\nSmallest Range: ["<<start<<","<<end<<"]"<<endl;
    return (end - start) + 1;
}

int main(){
    // int row, col;
    // cout<<"Enter number of rows & columns: ";
    // cin>>row>>col;

    vector<vector<int>> a = {
        {1,2,5},
        {3,8,14}
    };

    // vector<vector<int>> a(row, vector<int>(col));

    // for(int i=0; i<col; i++){
    //     for(int j=0; j<row; j++)
    //         cin>>a[i][j];
    // }

    cout<<"Smallest Diff. bet range values "<<K_Sorted(a, 2, 3);
    return 0;
}