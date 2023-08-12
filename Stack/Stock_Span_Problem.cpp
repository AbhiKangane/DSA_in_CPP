// in this problem for given input array, for each array element we have to find how many previos array elements are lesser than current array element
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

int main(){
    vector<int> v = {100,80,60,70,60,75,85};
    vector<int> res = Stock_Span(v);

    
    for(auto &i: Stock_Span(v))
        cout<<i<<" ";

    return 0;
}