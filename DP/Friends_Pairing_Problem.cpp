// Given N friends, each one can remain single or can be paired up with some other friend.
// Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int mod = 1e9+7;
    // recursion
    long long int solveRec(int n){
        if(n==1 || n==2){
            return n;
        }
        
        return (solveRec(n-1)%mod + ((n-1)*solveRec(n-2)%mod)%mod)%mod;
    }
    
    
    // memoization
    long long int solveMem(int n, vector<long long int>& dp) {
        if (n == 0 || n == 1) {
            return 1;
        }
    
        if (dp[n] != -1) {
            return dp[n];
        }
    
        // The friend can either remain single or pair up with one of the remaining (n-1) friends
        return dp[n] = (solveMem(n-1,dp)%mod + ((n-1)*solveMem(n-2,dp)%mod )%mod )%mod;
    }
    
    // tabulation
    long long int solveTab(int n){
        vector<long long int> dp(n+1, 0);
        dp[1]=1; dp[2]=2;
        
        for(int i=3; i<=n; i++){
            dp[i] = (dp[i-1]%mod + ((i-1)*dp[i-2]%mod)%mod)%mod;
        }
        
        return dp[n];
    }
    
    
    // space optimization
    long long int solve_SO(int n){
        if (n == 0 || n == 1) {
            return 1;
        }
    
        long long int prev1 = 2;
        long long int prev2 = 1;
        
        for(int i=3; i<=n; i++){
            long long curr = (prev1 %mod + ((i-1)* prev2 %mod)%mod)%mod;
            prev2 = prev1;
            prev1 = curr;
        }
        
        return prev1;
    }

    int countFriendsPairings(int n) 
    { 
        // sol 1
        // return solveRec(n);
        
        // sol 2
        // vector<long long int> dp(n+1, -1);
        // return solveMem(n,dp);
        
        // sol 3
        // return solveTab(n);
        
        // sol 4
        return solve_SO(n);
    }
};   

int main(){
  int t;
  cout<<"Enter no. of testcases : ";
  cin>>t;
  while(t--){
    int n;
    cout<<"Enter no. of friends : ";
    cin>>n;

    Solution ob;
    cout<<ob.countFriendsPairings(n)<<endl;
  }
  return 0;
}
