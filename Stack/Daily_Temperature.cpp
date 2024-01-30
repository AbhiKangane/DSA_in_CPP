// leetcode 739 : "https://leetcode.com/problems/daily-temperatures/"
// Given an array of integers temperatures represents the daily temperatures, 
// return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
// If there is no future day for which this is possible, keep answer[i] == 0 instead.

#include<bits/stdc++.h>
using namespace std;

// time complexity : O(N^2)
vector<int> dailyTemperaturesTLE(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n,0);
        
        for(int i=0; i<n-1; i++){
            int j=i+1;
            while(j<n && temp[i] >= temp[j]){
                j++;
            }
            if(j!=n)
                ans[i] = (j-i);
        }
        
        return ans;
    }

// this problem is similar to the find Index of Next Greater Number in array
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    stack<int> st;      // here stack is used for storing indices of next greater temperature
    vector<int> ans(n);

    for(int i=n-1; i>=0 ; i--) {
        
        while(!st.empty() && temperatures[st.top()] <= temperatures[i])
            st.pop();
        
        if(!st.empty())
            ans[i] = st.top()-i;
        
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> temperatures = {73,74,75,71,69,72,76,73}
  // Output: [1,1,4,2,1,1,0,0]

    vector<int> ans = dailyTemperatures(temperatures);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";

    return 0;
}
