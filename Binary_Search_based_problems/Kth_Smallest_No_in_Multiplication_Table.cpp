// GFG Que : https://www.geeksforgeeks.org/problems/kth-smallest-number-in-multiplication-table/1
// Given three integers m, n and k. Consider a grid of m * n, where mat[i][j] = i * j (1 based index). 
// The task is to return the kth smallest element in the m * n multiplication table.
#include<iostream>
using namespace std;

// Time complexity : O(m*log(m*n))
int kthSmallest(int m, int n, int k) {
    int low = 1;
    int high = m*n;
    int ans = m*n;
    
    while(low <= high){
        int mid = low + (high - low)/2;
        int count = 0; // stores no. of values less than or equal to mid
        
        // traverse all rows & add no. of values less than or equal to mid to the count
        for(int i = 1; i <= m; i++)
            count += min(mid/i, n); 
        
        if(count >= k){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    int m,n,k;
    cout<<"Enter no. of rows, columns & k: ";
    cin>>m>>n>>k;

    // 1 2 3 4
    // 2 4 6 8
    // 3 6 9 12

    cout<<"Kth smallest number : "<<kthSmallest(m,n,k);
}
