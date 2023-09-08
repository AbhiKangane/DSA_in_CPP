#include<bits/stdc++.h>
using namespace std;

int Trap_Water(vector<int> a){
    int ans = 0, n=a.size();
    stack<int> st;

    for(int i=0; i<n; i++){
        while(!st.empty() && a[st.top()] < a[i]){  // then container will made for water
            int curr = st.top();
            st.pop();
            if(st.empty()){ // then container isn't closed both sides
                break; 
            }
            
            else{
                int diff = i-st.top()-1; // this will be length of container
                ans += (min(a[st.top()] , a[i]) - a[curr]) * diff;
            }
        }
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout<<"Water Trapped: "<<Trap_Water(v);
}