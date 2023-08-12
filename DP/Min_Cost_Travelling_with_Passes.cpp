#include<bits/stdc++.h>
using namespace std;

// recursive sol
int solveRec(int n, vector<int> &days, vector<int> &cost, int index){
    if(index >= n)
        return 0;
    
    // 1 day pass
    int option1 = cost[0] + solveRec(n,days,cost,index+1);

    int i = 0;
    // 7 days pass
    for (i=index; i<n && days[i] < days[index]+7; i++);
    int option2 = cost[1] + solveRec(n,days,cost, i);

    // 30 days pass
    for(i=index; i<n && days[i] < days[index]+30; i++);
    int option3 = cost[2] + solveRec(n,days,cost, i);

    return min(option1, min(option2, option3));
}

// recursion + memoization
int solveMem(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp){
    if(index >= n)
        return 0;
    
    if(dp[index] != -1)
        return dp[index];

    // 1 day pass
    int option1 = cost[0] + solveMem(n,days,cost,index+1, dp);

    int i = 0;
    // 7 days pass
    for (i=index; i<n && days[i] < days[index]+7; i++);
    int option2 = cost[1] + solveMem(n,days,cost, i,dp);

    // 30 days pass
    for(i=index; i<n && days[i] < days[index]+30; i++);
    int option3 = cost[2] + solveMem(n,days,cost, i,dp);

    return dp[index] = min(option1, min(option2, option3));
}

// tabulation
int solveTab(int n, vector<int> &days, vector<int> &cost){
    vector<int> dp(n+1, INT_MAX);
    dp[n] = 0;

    for(int k=n-1; k>=0; k--){
        // 1 day pass
        int option1 = cost[0] + dp[k+1];

        int i;
        // 7 days pass
        for (i=k; i<n && days[i] < days[k]+7; i++);
        int option2 = cost[1] + dp[i];

        // 30 days pass
        for(i=k; i<n && days[i] < days[k]+30; i++);
        int option3 = cost[2] + dp[i];

        dp[k] =  min(option1, min(option2, option3));
    }

    return dp[0];
}


// space optimization
int solve_SO(int n, vector<int> &days, vector<int> &cost){
    int ans=0;
    queue<pair<int,int>> month;
    queue<pair<int,int>> week;

    for(int d: days){
        // step 1: remove expired days
        while (!month.empty() && month.front().first + 30 <= d){
             month.pop();
        }

        while (!week.empty() && week.front().first + 7 <= d){
             week.pop();
        }
        
        // step 2: add cost to current day
        week.push(make_pair(d, ans+cost[1]));
        month.push(make_pair(d, ans+cost[2]));

        // step 3: update answer
        ans = min(ans+cost[0], min(week.front().second, month.front().second));
    }
    return ans;
}


// driver function
int minimum_Cost_Tickets(int n, vector<int> &days, vector<int> &cost){
// sol 1
    // return solveRec(n,days,cost,0);

// sol 2
    // vector<int> dp(n+1,-1);
    // return solveMem(n,days,cost,0, dp);
    
// sol 3
    return solveTab(n,days,cost);
// sol 4
    return solve_SO(n,days,cost);
}

int main(){
    vector<int> days = {1,7,12,15};
    vector<int> cost = {4,6,15};
    int n = days.size();

    cout<<minimum_Cost_Tickets(n,days,cost); // 12

    return 0;
}