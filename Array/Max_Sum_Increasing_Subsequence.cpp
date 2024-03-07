// from given array, return the maximum sum of increasing subsequence
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxSumIS(int arr[], int n)  
    {  
        int msis[n];
        msis[0] = arr[0];
        int res = msis[0];
    
        for(int i = 1; i < n; i++) {
            msis[i] = arr[i];
            for(int j = 0; j < i; j++) {
                // updating msis[i]
                if (arr[i] > arr[j] && msis[i] < msis[j] + arr[i]) {
                    msis[i] = msis[j] + arr[i];
                }
            }
            res = max(res, msis[i]);
        }
        // for debuggging
        // for(int i=0; i<n; i++)
        //     cout<<msis[i]<<" ";

        return res;
    }
};

int main(){
    cout<<"Enter the no. of testcases: ";
   	int t;
    cin >> t;
    while(t--)
    {
        cout<<"\nEnter the size of array: ";
        int n;
        cin >> n;

        int a[n];
        cout<<"Enter the values in array: ";
        for(int i = 0; i < n; i++)
        	cin >> a[i];

	    Solution ob;
	    cout<<"Maximum sum of increasing subsequence from array is : "<< ob.maxSumIS(a, n) << "\n";
    }
    return 0;
}
