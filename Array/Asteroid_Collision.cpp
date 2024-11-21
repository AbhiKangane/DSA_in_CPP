// GFG: https://www.geeksforgeeks.org/problems/asteroid-collision/1
// Problem Statement : We are given an integer array asteroids of size N representing asteroids in a row. For each asteroid, the absolute value represents its size & 
// the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. 
// If both are of same size, both will explode. Two asteroids moving in the same direction will never meet.

// +ve => right direction
// -ve => left direction
// Only considered magnitude
// 1) if x & y collide then min(x,y) will removed
// 2) if x==y then both will be removed
// Ex: [10,6,-8,-8,8,9]
// output: [10,8,9]
#include<bits/stdc++.h>
using namespace std;

vector<int> asteriodCollision(vector<int> & arr){
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++){
        if(ans.empty() || arr[i]>0)
            ans.push_back(arr[i]);
        else{
            while(!ans.empty() && ans.back() > 0 && ans.back() < abs(arr[i])){
                ans.pop_back();
            }
            if(!ans.empty() && ans.back()+arr[i]==0)
                ans.pop_back();
            else if(ans.empty() || ans.back() < 0)
                ans.push_back(arr[i]);
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {10,6,-8,-8,8,9};
    vector<int> ans = asteriodCollision(arr);
    for(auto i:ans)
        cout<<i<<" ";

    return 0;
}
