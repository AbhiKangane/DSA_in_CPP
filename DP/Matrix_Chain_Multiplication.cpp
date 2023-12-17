// We have to find minimum no. of operations(multiplications) are required to multiply given n matrices of of any dimensions 
// Matrix multiplications is associative => A(BC) = (AB)C
// given arr[] represents the dimensions of matrices such that, Dimension of ith matrix = arr[i-1] * arr[i]
#include<iostream>
#include<vector>
using namespace std;

const int N=101, mod = 1e9;
int arr[N];


// sol 1 : recursion
int MCM_Rec(int i, int j, int ans){
    if(i==j)
        return 0;

    ans = mod;
    for(int k=i; k<j; k++){
        ans = min(ans, MCM_Rec(i,k,ans)+MCM_Rec(k+1,j,ans) + arr[i-1]*arr[k]*arr[j]);
    }
    
    return ans;
}

// sol 2 : Memoization
int MCM_Mem(int i, int j,vector<vector<int>> &dp){
    if(i==j)
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];
    
    dp[i][j] = mod;
    for(int k=i; k<j; k++){
        dp[i][j] = min(dp[i][j], MCM_Mem(i,k,dp)+MCM_Mem(k+1,j,dp) + arr[i-1]*arr[k]*arr[j]);
    }
    
    return dp[i][j];
}



// driver function
int MCM(int i, int j){
    // sol 1
    // return MCM_Rec(i,j,mod);

    // sol 2
    vector<vector<int>> dp(N,vector<int>(N,-1));
    return MCM_Mem(i,j,dp);

    
}

int main(){
    int n;
    cout<<"Enter the no. of matrices: ";
    cin>>n;                 // 5

    cout<<"\nEnter the values in array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];       // 10,20,30,20,30  => it means the matrices are of size => A(10*20), B(20*30), C(30*20), D(20*30)
    }

    cout<<MCM(1,n-1)<<endl;   // 18000


    // sol 2: Tabulation
    vector<vector<int>> dp(N,vector<int>(N,0));
    // for(int i=0; i<n; i++){
    //     dp[i][i] = 0;      // making diagonal elemnts equals to 0, if matrix isn't initialize with 0
    // }

    for(int l=2; l<=n; l++){
        for(int i=1; i<n-l+1; i++){
            int j=i+l-1;
            dp[i][j] = mod;
            for(int k=i; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
            }
        }
    }
    cout<<dp[1][n-1];
    return 0;
}