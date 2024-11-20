// given array contains only 0 & 1 AND we can convert 0s into 1s number of k times
// return length of longest contiguous subarray that contains only ones
// ie. we have to find longest subarray with at most k 0s 

#include<bits/stdc++.h>
using namespace std;

int main(){
    int size, k;
    cout<<"Enter the size of array & value of 'k': ";
    cin>>size>>k;

    vector<int> a(size);
    cout<<"Enter the numbers: ";
    for(auto &i: a)
        cin>>i;
    
    int zero_Count = 0, ans=0, j=0;  
    for (int i = 0; i < size; i++){
        if(a[i] == 0)
            zero_Count++;
        
        while(zero_Count > k){ 
            if(a[j] == 0)
                zero_Count--;

            j++; 
        }
        // zero_Count <= k
        ans = max(ans, i-j+1); // here subarray is from a[j] to a[i]
    }
    cout<<ans;
}
