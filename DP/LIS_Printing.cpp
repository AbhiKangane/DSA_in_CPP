#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector<int> longestIncreasingSubsequence(vector<int> &arr) {
    int n = arr.size();
    vector<int> dp(n, 1); // Initialize a DP array to store the length of LIS ending at each index
    vector<int> prev(n, -1); // To reconstruct the LIS

    int maxLength = 1, endIndex = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;

                if (dp[i] > maxLength) {
                    maxLength = dp[i];
                    endIndex = i;
                }
            }
        }
    }

    vector<int> longestSubsequence;
    while (endIndex != -1) {
        longestSubsequence.push_back(arr[endIndex]);
        endIndex = prev[endIndex];
    }

    reverse(longestSubsequence.begin(), longestSubsequence.end());
    return longestSubsequence;
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    vector<int> lis = longestIncreasingSubsequence(arr);

    cout << "Longest Increasing Subsequence: ";
    for (int num : lis) {
        cout << num << " ";
    }

    return 0;
}
