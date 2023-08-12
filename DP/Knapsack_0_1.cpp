#include<iostream>
#include<vector>
using namespace std;


// recursive knapsack problems sol (here we dont need of 2d matrix)
int  Knapsack1(int value[], int weight[], int n, int MaxWeight){
    if(n==0 || MaxWeight == 0){
        return 0;
    }
    
    if(weight[n-1] > MaxWeight){  // if weight of item is greater than MaxWeight then item isn't included
        return Knapsack1(value, weight, n-1, MaxWeight);
    }

    else if(weight[n-1] <= MaxWeight)
        return max( Knapsack1(value, weight, n-1, MaxWeight - weight[n-1]) + value[n-1], //item is included
                Knapsack1(value, weight, n-1, MaxWeight));     // item not included
}


//  DP based iterative knapsack Problems sol: Tabulation- bottom up
int  Knapsack2(int value[], int weight[], int n, int MaxWeight){
    // creating 2d matrix
    int dp[n+1][MaxWeight+1];
    
    for(int i=0; i<n+1; i++){
        for(int j=0; j<MaxWeight+1; j++){
            if(i==0 || j == 0)
                dp[i][j] = 0;

            else if(weight[i-1] <= j)
                dp[i][j] = max(value[i-1] + dp[i-1][j-weight[i-1]]/*item included*/ , dp[i-1][j] /*item not included*/);

            else if(weight[i-1] > j) // if weight of item is greater than MaxWeight then item isn't included
                dp[i][j] = dp[i-1][j];
        }
    }

    // cout<<"\nPrinting 2d dp matrix:\n";
    // for(int i=0; i<n+1; i++){
    //     for(int j=0; j<n+1; j++)
    //         cout<<dp[i][j]<<"  ";

    //     cout<<endl;
    // }cout<<endl;

    return dp[n][MaxWeight];
}


// DP based recursive knapsack problems sol (Memoization or top down approach)
int knapSackRec(int W, int wt[], int val[], int i, int** dp)
{
    // base condition
    if (i < 0)
        return 0;
    if (dp[i][W] != -1)
        return dp[i][W];
 
    if (wt[i] > W) {
 
        // Store the value of function call
        // stack in table before return
        dp[i][W] = knapSackRec(W, wt, val, i - 1, dp);
        return dp[i][W];
    }
    else {
        // Store value in a table before return
        dp[i][W] = max(val[i]
                           + knapSackRec(W - wt[i], wt, val,
                                         i - 1, dp),
                       knapSackRec(W, wt, val, i - 1, dp));
 
        // Return value of table after storing
        return dp[i][W];
    }
}


// driver function for above recursive function
int knapSack3(int W, int wt[], int val[], int n)
{
    // double pointer to declare the
    // table dynamically
    int** dp;
    dp = new int*[n];
 
    // loop to create the table dynamically
    for (int i = 0; i < n; i++)
        dp[i] = new int[W + 1];
 
    // loop to initially filled the
    // table with -1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    return knapSackRec(W, wt, val, n - 1, dp);
}

int main(){
    int value[] = {15, 5 , 10, 20};
    int weight[] = {3, 2, 1, 3};
    int n=4, capacity= 5;

    // cout<<Knapsack1(value, weight, n, capacity)<<endl;

    // cout<<Knapsack2(value, weight, n, capacity)<<endl;
    
    cout<<knapSack3(capacity, weight, value, n)<<endl;   

    return 0;
}