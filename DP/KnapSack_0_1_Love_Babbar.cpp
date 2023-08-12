#include<iostream>
#include<vector>
using namespace std;


// recursive sol
int  Knapsack1(vector<int> &value, vector<int> &weight, int n, int capacity){
    // base case : only one item
    if(n==0){
        if(weight[0] <= capacity)       return value[0];
        else                            return 0;
    }

    int include = 0;
    if(weight[n] <= capacity)
        include = Knapsack1(value,weight,n-1,capacity-weight[n]) + value[n];
    
    int exclude = Knapsack1(value,weight,n-1,capacity);

    return max(include, exclude);
}


// DP (recursion + Memoization : top down approach)
int KnapSack2(vector<int> &value, vector<int> &weight, int n, int capacity, vector<vector<int>> &dp)
{
    // base case : only one item
    if(n==0){
        if(weight[0] <= capacity)       return value[0];
        else                            return 0;
    }

    if(dp[n][capacity] != -1)           return dp[n][capacity];

    int include = 0;
    if(weight[n] <= capacity)
        include = KnapSack2(value,weight,n-1,capacity-weight[n], dp) + value[n];
    
    int exclude = KnapSack2(value,weight,n-1,capacity, dp);

    dp[n][capacity] = max(include, exclude);

    return dp[n][capacity];
}


//  DP(iterative sol: Tabulation- bottom up)
int  Knapsack3(vector<int> &value, vector<int> &weight, int n, int capacity){
    // step 1: creating 2d matrix
    vector<vector<int>> dp(n, vector<int>(capacity+1, 0));

    // step 2: analyse base cases
    for(int w=weight[0]; w<capacity; w++){
        if(weight[0] <= capacity)       dp[0][w] = value[0];
        else                            dp[0][w] = 0;
    }

    // step 3: remaining recursive calls
    for(int index=1; index<n; index++){
        for (int w = 0; w <= capacity; w++){
            int include = 0;
            if(weight[index] <= w)
                include = dp[index-1] [w-weight[index]] + value[index];
    
            int exclude = dp[index-1] [w];

            dp[index][w] = max(include, exclude);
        }
    }
    return dp[n-1][capacity];
}

// space optimization 1 : using 2 vectors
int  Knapsack_SO_1(vector<int> &value, vector<int> &weight, int n, int capacity){
    vector<int> prev(capacity+1);
    vector<int> curr(capacity+1);

    for(int w=weight[0]; w<capacity; w++){
        if(weight[0] <= capacity)       prev[w] = value[0];
        else                            prev[w] = 0;
    }

    for(int index=1; index<n; index++){
        for (int w = 0; w <= capacity; w++){
            int include = 0;
            if(weight[index] <= w)
                include = prev[w-weight[index]] + value[index];
    
            int exclude = prev[w];

            curr[w] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[capacity];
}


// space optimization 2 : using 1 vector
int  Knapsack_SO_2(vector<int> &value, vector<int> &weight, int n, int capacity){
    vector<int> curr(capacity+1);

    for(int w=weight[0]; w<capacity; w++){
        if(weight[0] <= capacity)       curr[w] = value[0];
        else                            curr[w] = 0;
    }

    for(int index=1; index<n; index++){
        for (int w = capacity; w >= 0 ; w--){
            int include = 0;
            if(weight[index] <= w)
                include = curr[w-weight[index]] + value[index];
    
            int exclude = curr[w];

            curr[w] = max(include, exclude);
        }
    }
    return curr[capacity];
}



// driver function for all recursive function
int knapSack_all_Sol(vector<int> &value, vector<int> &weight, int n, int capacity){
// sol 1
    // return Knapsack1(value,weight,n,capacity);
// sol 2 
    // vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
    // return KnapSack2(value,weight,n-1,capacity,dp);
// sol 3 
    // return Knapsack3(value,weight,n,capacity);
// sol 4 
    // return Knapsack_SO_1(value, weight,n,capacity);
// sol 5 
    return Knapsack_SO_2(value, weight,n,capacity);
}

int main(){
    vector<int> value = {15, 5 , 10, 20};
    vector<int> weight = {3, 2, 1, 3};
    int n=4, capacity= 5;

    cout<<knapSack_all_Sol(value, weight, n, capacity)<<endl;   

    return 0;
}