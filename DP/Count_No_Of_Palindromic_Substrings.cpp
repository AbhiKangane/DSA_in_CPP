#include<iostream>
#include<vector>
using namespace std;

bool isPalindrome(int i, int j, char s[]){
    while(i < j){
        if(s[i] != s[j])
            return false;
        i++; j--;
    }    
    return true;
}

int countMem(int i, int j, char s[], vector<vector<int>>& dp){
    if(i < 0){
        if(j == 0 || j == 1)
            return 0;

        if(j > 0){
           j = j-1;
           i = j-1;
        }
    }
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    int left = 0;
    int right = 0;
    
    if(isPalindrome(i , j , s) && j-i+1 >= 2)
        left = 1 + countMem(i-1 , j , s , dp); 
    
    else
        right = countMem(i-1 , j , s , dp);
    
    return dp[i][j] = left + right;
}

int CountPS(char s[], int n){
    
    if(n == 0 || n == 1)
        return 0;
    
    // sol 1
    // vector<vector<int>> dp(n , vector<int> (n , -1));
    // return countMem(n-2 , n-1 , s , dp);

    // sol 2
    int ans = 0;
    for(int i=0; i<n; i++){
         // for even length string
           int left = i, right = i+1;
           while(left >=0 && right < n && s[left] == s[right]){
                ans++;
                left--;
                right++;
           }
          // for odd length string
           left = i-1, right = i+1;
           while(left >=0 && right < n && s[left] == s[right]){
                ans++;
                left--;
                right++;
           }
    }
    
    return ans;
}


int main(){
    // char s[] = {'a','b','b','a','a','a','a'};4
    char s[] = "abbaaaa";
    cout<<CountPS(s, 7);

    return 0;
}