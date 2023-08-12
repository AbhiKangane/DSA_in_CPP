// houses are situated in circular way & find max. amount of money can rob here only non adajacent houses are robbed,

#include<bits/stdc++.h>
using namespace std;

// dp(space optimization) : same as maximum sum of nonadjacent elements
int solve_SO(vector<int> &nums, int n){
    if(n==0)    return 0;
    int prev2 = 0;
    int prev1 = nums[0];

    for(int i=1; i<n; i++){
        int incl = prev2 + nums[i];
        int excl = prev1;
        int ans = max(incl, excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}


// driver function
int house_Robber(vector<int> &house_val){
    int n = house_val.size();
    if(n==0)    return 0;
    if(n==1)    return house_val[0];

    vector<int> first, second;
    for(int i=0; i<n; i++){
        if(i !=- n-1)
            first.push_back(house_val[i]);
        if(i != 0)
            second.push_back(house_val[i]);
    }

    return max(solve_SO(first,n-1), solve_SO(second,n-1));
} 


int main(){
    vector<int> house_Val = {3,4,8,10,13};
    cout<<house_Robber(house_Val);
}