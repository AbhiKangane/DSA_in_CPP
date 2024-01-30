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