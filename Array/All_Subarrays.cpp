#include<bits/stdc++.h>
using namespace std;

// leetcode 78 problem
class Solution
{
private:
    void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>> &ans){
        // base case
        if(index >= nums.size()){
            ans.push_back(output);
            return;
        }

        // for exclude ith number
        solve(nums, output, index+1, ans);
        
        // for include ith number
        output.push_back(nums[index]);
        solve(nums, output, index+1, ans);
    }

public:
    vector<vector<int>> subsets(vector<int> &nums){
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
    }
};
// end of solution

int main(){
    vector<int> arr = {1,2,3};
    Solution s;
    vector<vector<int>> ans = s.subsets(arr);

    cout<<"All subsets in given array: "<<endl; // this will include empty subset
    for(int i=0; i<ans.size(); i++){
        for(int j=0 ; j<ans[i].size(); j++)
                cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    // int size, i, j, k;
    // cout<<"Enter the size of array: ";
    // cin>>size;

    // int arr[size];
    // cout<<"Enter the numbers in array: ";
    // for(int i=0; i<size; i++){
    //     cin>>arr[i];
    // }

    // for(i=0; i<size; i++)
    //     for(j=i; j<size; j++){
    //         for(k=i; k<=j; k++){
    //             cout<<arr[k]<<" ";
    //         }
    //         cout<<endl;
    //     }

    return 0;
}