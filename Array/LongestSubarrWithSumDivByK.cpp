#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    int sum = 0;
	    unordered_map<int,int> suffix;
	    suffix[0] = n;
	    
	    int ans = 0;
	    
	    for(int i = n - 1; i > -1; i--){
	        sum = (sum + (arr[i] % k) + k) % k;
	        
	        if(!suffix.count(sum))
	            suffix[sum] = i;
	        else
	            ans = max(ans, suffix[sum] - i);
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
  cout<<"Enter the no. of test  cases: ";
	cin>>t;
	while(t--)
	{
  	int n,k,i;
    cout<<"Enter the size of array & value of k :";
  	cin>>n>>k; int arr[n];
  	for(i=0;i<n;i++)
    	cin>>arr[i];
  	Solution ob;
  	cout<<"Size of longest subarraay with sum divisible by k : "<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}
