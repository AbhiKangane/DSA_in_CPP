// print maximum nof all subarrays of size k
#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int maximum(vector<int> &arr, int st, int k){
        int maxi = 0;
        for(int i=0; i<k; i++){
            if(maxi < arr[st+i])
                maxi = arr[st+i];
        }
        return maxi;
    }
  
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(vector<int> &arr, int n, int k){
        vector<int> ans;
        int st = 0, maxi = 0;
        for(int i=0; i<k; i++){
            if(maxi < arr[i])
                maxi = arr[i];
        }
        
        ans.push_back(maxi);
        
        // performing sliding window
        for(int i=k; i<n; i++, st++){
            // if new element < start element
            if(arr[st] == maxi  && arr[st] > arr[i])
                maxi = maximum(arr, st+1, k);
            
            else if(maxi < arr[i])
                maxi = arr[i];
                
            // else if (arr[st] != maxi && arr[i]<maxi)  => then no change in maxi
            ans.push_back(maxi);
        }
        return ans;
    }
};

int main() {
	cout<<"Enter no. of testcases: ";
	int t;
	cin >> t;
	
	while(t--){
	    cout<<"\nEnter size of array & subarray size: ";
	    int n, k;
	    cin >> n >> k;
	    cout<<"Enter values in array: ";
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];

	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
        cout<<"Printing max of subarrays of size k: ";
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	}
	
	return 0;
}
