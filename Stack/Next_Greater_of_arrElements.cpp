#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr, int n)
{
    stack<int> s;
    vector<int> ans(n);

    for(int i=n-1; i>=0 ; i--) {
        int curr = arr[i];
        while(!s.empty() && s.top() <= curr){
            s.pop();
        }
        //ans is stack ka top
        ans[i] = s.empty() ? -1 : s.top();
        s.push(curr);
    }
    return ans;
}

int main(){
    vector<int> v = {3,2,1,4,1,6,5};
    
    vector<int> ans = nextGreaterElement(v, v.size());
    for(auto & i: ans){
        cout<<i<<" ";
    }
}
