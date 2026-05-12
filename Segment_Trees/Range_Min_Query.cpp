#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> nums = {1,3,2,4,5};
int n = nums.size();
vector<int> segTree(4*n,0);

/*
        1
       /  \
      1    2
     / \  /  \
    1  3  2   4
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

    segTree[i] = min(segTree[2*i+1] , segTree[2*i+2]);
}

// finding minimum number in given range(st,end)
int rangeMin(int st, int end, int i, int l, int r){
    if(r<st || l>end)   // out of bound
        return INT32_MAX;

    if(l>=st && r<=end)
        return segTree[i];
    
    // overlapping
    int mid = l + (r-l)/2;
    return min(rangeMin(st,end,2*i+1,l,mid) , rangeMin(st,end,2*i+2,mid+1,r));
}

int main(){
    // building Segment Tree
    buildSegTree(0,0,n-1);
    for(auto i: segTree){
        cout<<i<<" ";
    }cout<<endl;

    int st = 1, end = 3;
    cout<<"Minimum no. in range between index "<<st<<" & "<<end<<" : "<<rangeMin(st,end,0,0,n-1);

    return 0;
}