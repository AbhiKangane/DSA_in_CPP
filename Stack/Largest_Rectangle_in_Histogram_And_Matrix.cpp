#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

// 2nd approach using stack
int get_Max_Area(vector<int> a){
    int n = a.size(), ans=0, i=0;
    a.push_back(0);  // for making last bar of '0' height
    stack<int> st;

    while(i<n){
        while(!st.empty() && a[st.top()] > a[i]){
            int t = st.top();
            int height = a[t];
            st.pop();
            if(st.empty()){  // then there is minimum height
                ans = max(ans, i*height);
            }
            else{
                int len = i-st.top()-1;
                ans = max(ans, len*height);
            }
        }
        st.push(i);
        i++;
    }

    return ans;
}

// 3rd approach : Love Babbar
class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }

public:
// for largest rectangle area in histogram
    int largestRectangleArea_inHistogram(vector<int>& heights) {
        int n= heights.size();

        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = INT32_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];

            if(next[i] == -1) {
                next[i] = n;
            }
             int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }

// for largest rectangle area in histogram
    int largestRectangleArea_inMatrix(vector<vector<int>>& matrix){
        int maxi = INT32_MIN;
        int maxWidth = matrix[0].size();
        vector<int> histogram(maxWidth, 0);

        for (int i = 0; i<matrix.size(); i++){
            // creating histogram vector
            for (int j = 0; j < histogram.size(); j++){
                if(matrix[i][j] == 1)
                    histogram[j] ++;
                else
                    histogram[j] = 0;
            }
            maxi = max(maxi, largestRectangleArea_inHistogram(histogram));
        }

        return maxi;
    }
};

int main(){
    vector<int> a = {2,1,5,6,2,3,5};
    vector<vector<int>> matrix = {{1,0,0,1},
                                  {1,0,1,1},
                                  {1,1,1,1},
                                  {1,0,1,1}};  // 6
    // 1. Brute Force 
    int ans=0;

    for(int i=0; i<a.size(); i++){
        int minH = INT32_MAX;
        for (int j=i; j < a.size(); j++){
            minH = min(a[j],minH);
            int len = j-i+1;
            ans = max(ans, minH*len);
        }
    }
    // cout<<"Area of largest rectangle: "<<ans<<endl;

    // cout<<"Area of largest rectangle: "<<get_Max_Area(a)<<endl;


    Solution s;
    cout<<"Area of largest rectangle in histogram: "<<s.largestRectangleArea_inHistogram(a)<<endl;

    cout<<"Area of largest rectangle in matrix: "<<s.largestRectangleArea_inMatrix(matrix)<<endl;

}