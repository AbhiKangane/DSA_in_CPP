// GFG : https://www.geeksforgeeks.org/problems/missing-number4257/1
// Ritu has all numbers from 2 to n in an array, arr of length n-1 except one number. You have to return the missing number, Ritu doesn't have from 1 to n.
// Note: Don't use Sorting

#include<bits/stdc++.h>
using namespace std;

class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};

class Solution {
  public:
    int missingNumber(int n, vector<int> &arr) {
        int sum = accumulate(arr.begin(),arr.end(),0);
        int realSum = n*(n+1)/2;
        
        return realSum-sum;
    }
};

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        
        vector<int> arr(n-1);
        Array::input(arr,n-1);
        
        Solution obj;
        int res = obj.missingNumber(n, arr);
        
        cout<<res<<endl;
        cout << "~" << "\n";
    }
}
