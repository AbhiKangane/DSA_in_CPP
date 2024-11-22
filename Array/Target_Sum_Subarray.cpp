// Print the 1st & last index of subarray having sum equals to target sum
#include<bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int>arr, int n, long long reqsum){
    long long currsum = 0;
    vector<int> ans;
    
    int st=0;
    
    for(int end=0; end<n; end++){
        currsum += arr[end];
        while(currsum > reqsum && end>st){
            currsum -= arr[st];    // removing starting number of subarray
            st++;
        }

        if(currsum == reqsum){
            ans.push_back(st+1);
            ans.push_back(end+1);
            return ans;
        }
    }
    
    ans.push_back(-1);            // if such subarray not exist
    return ans;
}

int main(){
    int size, reqsum;
    cout<<"Enter the size of array & require sum of subarray: ";
    cin>>size>>reqsum;

    vector<int> arr(size);
    cout<<"Enter the numbers in array: ";
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }


    vector<int> ans = subarraySum(arr, size, reqsum);
    cout<<"Start & End index of req subarray: ";
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    
    return 0;
}
