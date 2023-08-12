#include<bits/stdc++.h>
using namespace std;

// leetcode 78 problem
class Solution
{
private:
    void solve(string str, string output, int index, vector<string> &ans){
        // base case
        if(index >= str.length()){
            if(output.length() > 0)
                ans.push_back(output);
            return;
        }

        // for exclude ith number
        solve(str, output, index+1, ans);
        
        // for include ith number
        output.push_back(str[index]);
        solve(str, output, index+1, ans);
    }

public:
    vector<string> subsequences(string str){
        vector<string> ans;
        string output = "";
        int index = 0;
        solve(str, output, index, ans);
        return ans;
    }
};
// end of solution

int main(){
    string str = "Abhi";
    Solution s;
    vector<string> ans = s.subsequences(str);

    cout<<"All subsequences of given string: "<<endl; // this will not include empty subsequence
    for(int i=0; i<ans.size(); i++){
       cout<<ans[i]<<" ";
    }
    cout<<"\n"<<ans.size();
    return 0;
}