// A celebrity is a person, who is known everyone & knows none.
// Given a square matrix M. Find celebrity person
// if ith person knows jth person then M[i][j]=1, else 0
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int celebrity(vector<vector<int>>&M, int n){
    stack<int> st;
    for(int i=0; i<n; i++)
        st.push(i);
    
    // check & if he may be a celebrity then push into stack
    while(st.size() > 1){
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        // if bath persons knows each other, then they couldn't be celebtity
        if(M[a][b] == 1 && M[b][a]==1)
            continue;
        else if(M[a][b]==1) // a knows b
            st.push(b);
        else if(M[b][a]==1) // b knows a
            st.push(a);
    }

    if(st.empty())
        return -1; // no celebrity
    
    int celeb = st.top();
    for(int i=0; i<n; i++){
        // if i person doesn't knows celeb or celeb knows anyone
        if((i!=celeb) && (M[i][celeb]==0 || M[celeb][i]==1))
            return -1;
    }
    return celeb;
}

int main(){
    vector<vector<int>> mat = {{0,0,0},{1,0,1},{1,1,0}};
    cout<<celebrity(mat,3);
}