#include<bits/stdc++.h>
using namespace std;

//  this functions returns all permutations without removing duplicated permutations
void permute(int left, int right, vector<int> &nums, vector<vector<int>> &ans){
    if (left == right){// reach the end of nums
        ans.push_back(nums);
        return ;
    } 

    for (int j=left; j<=right; j++){
        swap(nums[left], nums[j]);
        permute(left+1, right, nums, ans);
        swap(nums[left], nums[j]);     // backtrack
    }
}    

vector<vector<vector<int>>> PermsCollection(vector<int>& nums) {
    vector<vector<int>> allPerms;    // for storing all permutations, contains duplicates also
    int n = nums.size();
    sort(nums.begin(), nums.end());
    permute(0,n-1, nums, allPerms);


    // for uniue permutations, duplicates removed
    set<vector<int>> unique(allPerms.begin(), allPerms.end());
    vector<vector<int>> uniquePerms(unique.begin(), unique.end());

    vector<vector<vector<int>>> finalCollection;
    finalCollection.push_back(allPerms);
    finalCollection.push_back(uniquePerms);

    return finalCollection;
}


int main(){
    vector<int> arr = {2,2,1,1};
    int n = arr.size();

    vector<vector<vector<int>>> Perms = PermsCollection(arr);
    cout<<"Printing All Permutations of array: "<<endl;
    for (int i = 0; i < Perms[0].size(); i++){
        for(int j=0; j<n; j++){
            cout<<Perms[0][i][j];
        }
        cout<<" ";
    }    

    cout<<"\n\nPrinting unique Permutations of array: "<<endl;
    for (int i = 0; i < Perms[1].size(); i++){
        for(int j=0; j<n; j++){
            cout<<Perms[1][i][j];
        }
        cout<<" ";
    }
    
    return 0;

}