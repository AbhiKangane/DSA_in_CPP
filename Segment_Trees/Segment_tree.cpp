#include<vector>
#include <iostream>
using namespace std;

vector<int> nums = {1,2,3,4};
int n = nums.size();
vector<int> segTree(4*n,0);
/*
        10
       /  \
      3    7
     / \  /  \
    1  2  3   4
*/

// build Segment Tree
void buildSegTree(int i, int l, int r){
    if(l==r){
        segTree[i] = nums[r];
        return;
    }

    int mid = (l+r)/2;
    buildSegTree(2*i+1, l, mid);
    buildSegTree(2*i+2, mid+1, r);

    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

// update Segment Tree
void updateSegTree(int idx, int val, int i, int l, int r){
    if(l==r){
        segTree[i] = val;
        return;
    }

    int mid = (l+r)/2;
    
    if(idx <= mid){ // left child
        updateSegTree(idx,val,2*i+1,l,mid);
    }
    else            // right child
        updateSegTree(idx,val,2*i+2,mid+1,r);

    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

int main(){
    // building Segment Tree
    buildSegTree(0,0,n-1);
    for(auto i: segTree){
        cout<<i<<" ";   // 10 3 7 1 2 3 4 0 0 0 0 0 0 0 0 0
    }cout<<endl;

    // updateSegTree
    int idx=2, val=8;
    updateSegTree(idx,val,0,0,n-1);
    for(auto i: segTree){
        cout<<i<<" ";   // 15 3 12 1 2 8 4 0 0 0 0 0 0 0 0 0
    }

    return 0;
}