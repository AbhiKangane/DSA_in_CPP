/*


Given a N x N 2D matrix Arr representing an image. Rotate the image by 90 degrees (anti-clockwise direction). You need to do this in place. 
Note that if you end up using an additional array, you will only receive the partial score.

Input:
N = 3
Arr[][] = {{1,  2,  3}
           {4,  5,  6}
           {7,  8,  9}}
Output:
 3  6  9 
 2  5  8 
 1  4  7 
Explanation: The given matrix is rotated
by 90 degree in anti-clockwise direction.
*/

class Solution{
public:	
	void rotateMatrix(vector<vector<int>>& arr, int n) {
	     for(auto &i: arr){
	        // reversing each row
	         reverse(i.begin(),i.end());
	     }
	     
	     // Taking transpose of matrix
	     for(int i=0; i<n; i++){
	         for(int j=i+1; j<n; j++){
	             swap(arr[i][j], arr[j][i]);
	         }
	     }
	}
};
