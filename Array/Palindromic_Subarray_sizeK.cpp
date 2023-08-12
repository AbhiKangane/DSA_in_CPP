#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool isNumPalindrome(int n){
    int temp = n, number = 0;
    while (temp > 0){
        number = number*10 + temp%10;
        temp = temp/10;
    }
    
    if(number == n)
        return true;
    return 0;
}

// function for returning starting index of palindromic subarray of size k
int findPalindromicSubarray(vector<int> arr, int subarr_size){
    int num = 0;
    
    for (int i = 0; i < subarr_size; i++){
        num = num*10 + arr[i];
    }
    
    if(isNumPalindrome(num)){
        return 0;
    }

    for (int i = subarr_size; i < arr.size(); i++){
        num = (num % (int)pow(10, subarr_size-1)) * 10 + arr[i]; // for removing starting digit & adding last digit
    
        if(isNumPalindrome(num)){
            return i-subarr_size+1;
        }
    }

    return -1;  // no palindrome exist of given size 
}

int main(){
    vector<int> arr = {2,3,5,1,1,5};
    int subarr_size = 4;

    int ans = findPalindromicSubarray(arr,subarr_size);
    if(ans == -1)
        cout<<"No palindromic subarray of size k found\n";
    else
        for (int i = ans; i < ans+subarr_size; i++){
            cout<<arr[i]<<" ";
        }
    
    return 0;
}