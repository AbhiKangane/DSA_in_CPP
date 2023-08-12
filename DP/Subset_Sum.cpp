// Here is the top-down approach of
// dynamic programming
#include <bits/stdc++.h>
using namespace std;
 
// function for checking that given array contains subsets of given target or not
bool checkSubset(int arr[], int target, int n){
    // creating 2d dp array
    bool dp[n+1][target+1];
    
    for(int i=0; i<n+1; i++){
        for(int j=0; j<target+1; j++){
            if(i == 0 & j != 0)  // if given set( or arr) is empty
                dp[i][j] = false;
            
            if(j == 0)   // for target = 0 
                dp[i][j] = true;

            else if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]]/*number included*/ || dp[i-1][j] /*number not included*/;

            else if(arr[i-1] > j) // if arr[i-1] is greater than target then number isn't included
                dp[i][j] = dp[i-1][j];
        }
    }

    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<target+1; j++)
    //         cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }cout<<endl;


    return dp[n][target];
}


int main()
{
    int arr[] = {1,1,1,1,1,4};
    int target = 9;
    int size = sizeof(arr)/sizeof(arr[0]);

    cout<<checkSubset(arr, target, size);
    return 0;
}