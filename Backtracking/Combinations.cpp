//Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
// You may return the answer in any order.
// Input: n = 4, k = 2
// Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
// Explanation: There are 4 choose 2 = 6 total combinations.
// Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

#include<bits/stdc++.h>
using namespace std;

void solveRec(int val, int size, int n, int k, vector<vector<int>> &ans, vector<int> &curr)
{
    // base cases
    if(size<=0){
        if(curr.size()==k){
            ans.push_back(curr);
        }
        return;
    }
    if(val>n) return;
    
    // include val
    curr.push_back(val);
    solveRec(val+1, size-1, n, k, ans, curr);
    curr.pop_back();
    
    // exclude val
    solveRec(val+1, size, n, k, ans, curr);
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ans;
    vector<int> temp;
    solveRec(1, k , n, k, ans, temp);
    
    return ans;
}

int main(){
    int n=5, k=3;
    vector<vector<int>> ans = combine(n,k);

    for(auto vec:ans){
        for(auto num:vec){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}