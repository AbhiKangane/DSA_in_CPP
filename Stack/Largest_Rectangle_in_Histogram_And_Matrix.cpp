#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

// 1st approach using stack
int largestRectangleArea_inHistogram_1(vector<int>& heights) {
    int n = heights.size();
    vector<int> leftsmall(n), rightsmall(n);
    stack<int> st;
    
    // computing left small array
    for(int i=0;i<n;i++){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        if(st.empty()) leftsmall[i] = 0;
        else leftsmall[i] = st.top() + 1;
        
        st.push(i);
    }
    // clear the stack
    while(!st.empty()) st.pop();
    // computing right small array
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }
        if(st.empty()) rightsmall[i] = n-1;
        else rightsmall[i] = st.top() - 1;
        
        st.push(i);
    }
    
    // computing final ans
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        int temp = (rightsmall[i] - leftsmall[i] + 1) * heights[i];
        maxi = max(maxi,temp);
    }
    return maxi;
}

// 2nd approach : using stack
int largestRectangleArea_inHistogram_2(vector<int>& hist) {
    int n= hist.size();
    stack<int> s; 
  
    int max_area = 0; // Initialize max area 
    int tp; // To store top of stack 
    int area_with_top; // To store area with top bar as the smallest bar 
  
    int i = 0; 
    while (i < n) { 
        // If this bar is higher than the bar on top stack, push it to stack 
        if (s.empty() || hist[s.top()] <= hist[i]) 
            s.push(i++); 
  
        // If this bar is lower than top of stack, then calculate area of rectangle with stack top as the smallest (or minimum height) bar. 
        // 'i' is 'right index' for the top and element before top in stack is 'left index' 
        else { 
            tp = s.top();
            s.pop();
  
            // Calculate the area with hist[tp] stack as smallest bar 
            area_with_top = hist[tp] * (s.empty() ? i : i - s.top() - 1); 
            
            if (max_area < area_with_top) 
                max_area = area_with_top; 
        } 
    } 
  
    // Now pop the remaining bars from stack and calculate area with every popped bar as the smallest bar 
    while (s.empty() == false) { 
        tp = s.top(); 
        s.pop(); 
        area_with_top 
            = hist[tp] * (s.empty() ? i : i - s.top() - 1); 
  
        if (max_area < area_with_top) 
            max_area = area_with_top; 
    } 
  
    return max_area; 
}


// 3rd approach : By Love Babbar using nextSmallerElement & prevSmallerElement
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

// for largest rectangle area in matrix
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
