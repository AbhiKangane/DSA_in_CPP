//I : Given arr[] & target. Find total ways combination_aum of arr[i] such that combination_aum = target, where arr[i] can be repeated or not.
// II : Each number in candidates may only be used once in the combination. ie. repeatation not allowed

#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

void totalWays(vector<int> &arr, int target, int curr,
               vector<vector<int>> &ans, vector<int> &temp){
    if(curr == arr.size()){
        if(target == 0)
            ans.push_back(temp);
        return;
    }

    // feasible only if curr value <= target
    if(arr[curr] <= target){
        temp.push_back(arr[curr]);
        totalWays(arr, target-arr[curr], curr, ans, temp);
        temp.pop_back();
    }
    // back-tracking
    totalWays(arr, target, curr+1, ans, temp);
}

vector<vector<int>> Combination_Sum(vector<int> &arr, int target){
    vector<vector<int>> ans;
    vector<int> temp;
    totalWays(arr, target, 0, ans, temp);
    return ans;
}

// Part II : Each number in candidates may only be used once in the combination.
void findAll(vector<int> &arr, int target, int curr,
               vector<vector<int>> &ans, vector<int> &temp){
    if(target == 0){
        ans.push_back(temp);
        return;
    }

    for(int i=curr; i<arr.size(); i++){
        // avoid duplicates
        if(curr<i && arr[i] == arr[i-1])
            continue;
        
        if(arr[curr] <= target){
            temp.push_back(arr[i]);
            findAll(arr,target-arr[i],i+1,ans,temp);
            temp.pop_back();
        }
    }
}  

vector<vector<int>> Combination_Sum_II(vector<int> &arr, int target){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    findAll(arr, target, 0, ans, temp);
    return ans;
}


// Part III :Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
// Only numbers 1 through 9 are used.
// Each number is used at most once.
void findAll3(vector<int> &arr, int target, int curr,
             vector<vector<int>> &ans, vector<int> &temp, int k)
{
    if(target == 0){
        if(temp.size() == k)
            ans.push_back(temp);
        return;
    }

    for(int i=curr; i<arr.size(); i++){
        // avoid duplicates
        if(curr<i && arr[i] == arr[i-1])
            continue;

        if(arr[curr] <= target){
            temp.push_back(arr[i]);
            findAll3(arr,target-arr[i],i+1,ans,temp, k);
            temp.pop_back();
        }
    }
}  


vector<vector<int>> Combination_Sum_III(int k, int target) {
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> ans;
    vector<int> temp;
    findAll3(arr, target, 0, ans, temp, k);
    return ans;
}

int main(){
    int target = 8;
    vector<int> arr = {2,3,5};

    cout<<"Combination_Sum : \n";
    vector<vector<int>> ans = Combination_Sum(arr,target);
    for(int i=0; i<ans.size(); i++){
        for(int j = 0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"\nCombination_Sum_II : \n";
    vector<vector<int>> ans2 = Combination_Sum_II(arr,target);
    for(int i=0; i<ans2.size(); i++){
        for(int j = 0; j<ans2[i].size(); j++){
            cout<<ans2[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"\nCombination_Sum_III : \n";
    vector<vector<int>> ans3 = Combination_Sum_III(3,9);
    for(int i=0; i<ans3.size(); i++){
        for(int j = 0; j<ans3[i].size(); j++){
            cout<<ans3[i][j]<<" ";
        }
        cout<<endl;
    }
}