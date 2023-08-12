// ex: arr[] = {1,2,3}, N=3, Target=4
// solutions: {1,1,1,1}, {1,1,2}, {2,1,1}, {1,2,1}, {2,2}, {1,3}, {3,1}
// no. of ways = 7
#include<bits/stdc++.h>
using namespace std;

// recursive sol
int solveRec(vector<int> &num, int tar){
    // base case
    if(tar<0)
        return 0;
    if(tar==0)
        return 1;
    
    int ans = 0;
    for (int i = 0; i < num.size(); i++){
        ans += solveRec(num, tar-num[i]);
    }
    
    return ans;
}

// recursion + memoization
int solveMem(vector<int> &num, int tar, vector<int> &dp){
    // base case
    if(tar<0)
        return 0;
    if(tar==0)
        return 1;
    
    if(dp[tar] != -1)
        return dp[tar];

    int ans = 0;
    for (int i = 0; i < num.size(); i++){
        ans += solveMem(num, tar-num[i],dp);
    }
    
    dp[tar] = ans;

    return dp[tar];
}


// tabulation
int solveTab(vector<int> &num, int tar){
    vector<int> dp(tar+1,0);
    dp[0] = 1;
    
    // traversing from 1 to target
    for (int i = 1; i<=tar; i++){
        // traversing on num vector
        for (int j = 0; j < num.size(); j++)     
            if(i-num[j] >= 0)
                dp[i] += dp[i-num[j]];
    }
    
    return dp[tar];
}

// driver function
int no_Of_Ways(vector<int> &num, int tar){
// sol 1
    // return solveRec(num,tar);

// sol 2
    // vector<int> dp(tar+1, -1);
    // return solveMem(num,tar,dp);

// sol 3
    return solveTab(num,tar);
}

int main(){
    vector<int> num = {3,1,2};
    int target = 4;
    cout<<no_Of_Ways(num,target); // 7
    return 0;
}