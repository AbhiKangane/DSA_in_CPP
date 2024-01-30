// in this problem for given input array, for each array element we have to find how many previos array elements are less than or equal to current array element
// ex: a[] = {100,80,60,70,60,75,85}
//      ans[] = {1,1,1,2,1,4,6}

#include<bits/stdc++.h>
using namespace std;

vector<int> Stock_Span(vector<int> prices){
    vector<int> ans;
    stack<pair<int,int>> st;

    for(auto price: prices){
        int days = 1;  // setting initial span
        while(!st.empty() && st.top().first <= price){
            days += st.top().second;
            st.pop();
        }
        st.push(make_pair(price,days)); // st.push({price,days})
        ans.push_back(days);
    }
    return ans;
}

// sol 2
vector<int> Stock_Span2(vector<int> prices){
    int n=prices.size();
    vector<int> ans(n);
    stack<int> st;

    st.push(0);
    ans[0] = 1;

    for(int i=1; i<n; i++){
        int price = prices[i];
        while(!st.empty() && prices[st.top()] <= price){
            st.pop();
        }
        if(st.empty())
            ans[i] = i+1;
        else
            ans[i] = i-st.top();

        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> v = {90,80,60,70,60,75,95};
    // vector<int> res1 = Stock_Span(v);
    vector<int> res = Stock_Span2(v);

    
    for(auto &i: res)
        cout<<i<<" ";

    return 0;
}