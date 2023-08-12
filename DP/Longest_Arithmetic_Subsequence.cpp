// gfg question
#include<bits/stdc++.h>
using namespace std;

// recursive sol
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

// recursive memoization sol
int solveMem(int index, int diff, int A[], unordered_map<int,int> dp[]){
    // backward check
    if(index < 0)
        return 0;

    if(dp[index].count(diff))
        return dp[index][diff];

    int ans = 0;
    for (int i = index-1; i>=0; i--){
        if(A[index] - A[i] == diff)
            ans = max(ans, 1+solveRec(i, diff, A));
    }
    
    return dp[index][diff] = ans;
}

// iterative tabulation
int solveTab(int A[], int n){
    int ans = 0;
    unordered_map<int,int> dp[n+1];

    for (int i = 1; i < n; i++){
        for(int j=0; j<i; j++){
            int diff = A[i] - A[j];
            int cnt = 1;

            // check if answer already present 
            if(dp[j].count(diff))
                cnt = dp[j][diff];
            
            dp[i][diff] = 1 + cnt;
            ans = max(ans, dp[i][diff]);
        }
    }
    return ans;
}

int LengthOfLongestAP(int A[], int n){
    if(n <= 2)
        return n;
    
    int ans = 0;

// for sol 2
    unordered_map<int,int> dp[n+1];

    for (int i = 0; i < n; i++){
        for(int j=i+1; j<n; j++){
// sol 1
            // ans = max(ans, 2+solveRec(i, A[j]-A[i], A));
// sol 2
            ans = max(ans, 2+solveMem(i, A[j]-A[i],A,dp));
            // ans = max(ans, 2+solveRec(i, A[j]-A[i], A));
        }
    }
    return ans;
}


int main(){
    int arr[] = {1,7,10,13,14,19},
            n = 6;

    cout<<LengthOfLongestAP(arr,n);
}