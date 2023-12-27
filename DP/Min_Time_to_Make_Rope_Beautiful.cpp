// Given 'n' balloons arranged on a rope. 
// You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.
// A rope is colorful if no two consecutive balloons to be of the same color
// We can remove some balloons from the rope to make it colorful. Given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that needs to remove the ith balloon from the rope.
// Return the minimum time Bob needs to make the rope colorful.
#include<iostream>
#include<vector>
using namespace std;

// ṛecursive solution
int solveRec(int i, string colors, vector<int>& neededTime, char prevColor, int prevMinTime){
    
    if(i < 0)
        return 0;
    
    // if current color is same as prevColor then add minNeededTime
    if(colors[i] == prevColor)
        return min(neededTime[i], prevMinTime) + 
                solveRec(i-1,colors,neededTime,colors[i],max(prevMinTime, neededTime[i]));
    
    // if colors[i]!=prevColor then pass neededTime[i] as prevMinTime & don't ant time in the answer
    else
        return solveRec(i-1, colors, neededTime, colors[i], neededTime[i]);
}


// ṛecursive Memoization solution
int solveMem(int i, string &colors, vector<int>& neededTime, char prevColor, int prevMinTime, vector<int> &dp){
    
    if(i < 0)
        return 0;
    
    if(dp[i] != -1)
        return dp[i];
    
    if(colors[i] == prevColor)
        return dp[i] = min(neededTime[i], prevMinTime) + 
                solveMem(i-1, colors, neededTime, colors[i], max(prevMinTime, neededTime[i]), dp);
    
    else
        return dp[i] = solveMem(i-1, colors, neededTime, colors[i], neededTime[i], dp);
}


// iterative Tabulation
int solveTab(string colors, vector<int>& neededTime, int n) {
    vector<int> dp(n+1,0);
    int prevMinTime = 0;
    char prevColor = 'X';
    
    
    for(int i=1; i<n+1; i++){
        if(colors[i-1] == prevColor){
            dp[i] = min(neededTime[i-1], prevMinTime) + dp[i-1];
            prevMinTime = max(neededTime[i-1], prevMinTime);
        }
        else{
            dp[i] = dp[i-1];    
            prevMinTime = neededTime[i-1];
            prevColor = colors[i-1];
        }
    }
    
    return dp[n];
}


int minCost(string colors, vector<int>& neededTime) {
    int n = colors.size();
    
    // 1. Recursive sol : Gives TLE
    // return solveRec(n-1, colors, neededTime, 'A', neededTime[n-1]);
    
    // 2. Recursive Memoization
    // vector<int> dp(n,-1);
    // return solveMem(n-1, colors, neededTime, 'A', neededTime[n-1], dp);

    // 3. Iterative Tabulation
    // return solveTab(colors, neededTime, n);

    // 4. Without DP
    int ans = 0;
    for(int i=0; i<colors.size()-1; i++){
        // for storing sum of neededTime for removing same colored ballons in sequence
        int sum = neededTime[i];      
        
    // for storing maxNeededTime of removing ballon from sequence of same color ballon
        int maxNeededTime = neededTime[i];   
        
        // while there is sequence of same color ballon find sum & maxNeededTime
        while(colors[i] == colors[i+1]){    
            sum += neededTime[i+1];
            maxNeededTime = max(maxNeededTime, neededTime[i+1]);
            i++;
        }
        ans += sum - maxNeededTime;  // add to ans neededTime of all same color ballons from sequence of ballon except 1 ballon who requires maxNeededTime for removal
    }    
    return ans;   
}

int main(){
    string colors1 = "abaac";
    vector<int> neededTime1 = {1,2,3,4,5};     // Output: 3
    cout<<minCost(colors1, neededTime1)<<endl;

    string colors2 = "abc";
    vector<int> neededTime2 = {1,2,3};         // Output: 0
    cout<<minCost(colors2, neededTime2)<<endl;

    string colors3 = "aabaa";
    vector<int> neededTime3 = {1,2,3,4,1};     // Output: 2
    cout<<minCost(colors3, neededTime3);

    return 0;
}