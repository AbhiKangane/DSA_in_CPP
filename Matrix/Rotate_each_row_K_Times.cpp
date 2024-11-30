/*
GFG : https://www.geeksforgeeks.org/problems/left-rotate-matrix-k-times2351/1

You are given an integer k and matrix mat. Rotate the elements of the given matrix to the left k times and return the resulting matrix.
Examples:
Input: k=1, mat=[[1,2,3]
                 [4,5,6]
                 [7,8,9]]
Output: [[2, 3, 1]
         [5, 6, 4]
         [8, 9, 7]]
Explanation: Rotate the matrix by one
1 2 3       2 3 1
4 5 6  =>   5 6 4
7 8 9       8 9 7
*/

class Solution {
  public:
    vector<int> rotateArray(vector<int> arr, int n, int k){
        reverse(arr.begin(), arr.begin()+k);
        reverse(arr.begin()+k, arr.end());
        reverse(arr.begin(), arr.end());
        
        return arr;
    }
    
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        int n = mat[0].size();
        k = k%n;
        vector<vector<int>> ans;
        
        for(vector<int> arr : mat){
            vector<int> row = rotateArray(arr, n, k);
            ans.push_back(row);
        }
        
        return ans;
    }
};
