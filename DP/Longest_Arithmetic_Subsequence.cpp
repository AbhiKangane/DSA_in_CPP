// gfg question & leetcode 1027
#include<bits/stdc++.h>
using namespace std;

// recursive sol : 169/220
int solveRec(int index, int diff, int A[]){
    // backward check
    if(index < 0)
        return 0;

    int ans = 0;
    for (int i = index-1; i>=0; i--){
        if(A[index] - A[i] == diff)
            ans = max(ans, 1+solveRec(i, diff, A));
    }
    
    return ans;
}


// recursive memoization sol : 126/220
int solveMem(int index, int diff, int A[], unordered_map<int,int> dp[]){
    // backward check
    if(index < 0)
        return 0;

    if(dp[index].count(diff))
        return dp[index][diff];

    int ans = 0;
    for (int i = index-1; i>=0; i--){
        if(A[index] - A[i] == diff)
            ans = max(ans, 1+solveMem(i, diff, A, dp));
    }
    
    return dp[index][diff] = ans;
}


// sol 3: Tabulation :
int solveTab(int A[], int n) {
    if(n <= 2)
        return n;
    
    int ans = 0;
    vector<vector<int>> dp(n+1, vector<int>(A[n-1] - A[0] +1, INT_MIN));

    for (int i = 1; i < n; i++){
        for(int j=0; j<i; j++){
            int diff = A[i] - A[j];
            int cnt = 1;

            // check if answer already present 
            if(dp[j][diff] != INT_MIN)
                cnt = dp[j][diff];
            
            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}

// driver function
int lengthOfLongestAP(int A[], int n) {
    // if(n <= 2)
    // return n;

    // int ans = 0;

    // // for sol 2
    // unordered_map<int,int> dp[n+1];

    // for (int i = 0; i < n; i++){
    //     for(int j=i+1; j<n; j++){
            
    //         ans = max(ans, 2+solveMem(i, A[j]-A[i],A,dp));
    //     }
    // }
    // return ans;
    
    // sol 3
    return solveTab(A, n);
}


// for leetcode solution
int longestArithSeqLength(vector<int>& nums, int n) {
    if(n <= 2)
        return n;
    
    int longest = 2;
    vector<unordered_map<int, int>> dp(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int diff = nums[i] - nums[j];
            dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
            longest = max(longest, dp[i][diff]);
        }
    }

    return longest;
}

int main(){
    int arr[] = {1,7,10,13,14,19},
            n = 6;

    cout<<lengthOfLongestAP(arr,n);  // 1 7 13 19
}
