// Print 1st subarray of size k having sum divisible by k.

#include<iostream>
#include<vector>
using namespace std;

void Compute_Num_from_subarray(vector<int> arr, int subarray_Size){
    pair<int,int> ans;
    int sum=0;

    for (int i = 0; i < subarray_Size; i++){
        sum += arr[i];
    }
    
    bool found = 0;
    if(sum%3 == 0){
        ans = make_pair(0,subarray_Size-1);
        found = 1;
    }

    for (int i = subarray_Size; i < arr.size(); i++){
        if(found) // ans found in 1st subarray
            break;

        sum = sum + arr[i] - arr[i-subarray_Size];  // sliding window technique
        if(sum%3 == 0){
            ans = make_pair(i-subarray_Size+1, i);
            found = 1;
        }
    }
    
    if(!found)
        ans = make_pair(-1, 0);

    if(ans.first == -1)
        cout<<"no such subarray exist!"<<endl;

    else
        for (int i = ans.first; i <= ans.second; i++)
            cout<<arr[i]<<" ";
    
}

int main(){
    vector<int> arr = {8,23,45,12,56,4};
    int subarray_size = 3;

    Compute_Num_from_subarray(arr, subarray_size);
    return 0;
}
