#include<bits/stdc++.h>
using namespace std;

int main(){
    string st;
    cout<<"Enter the string: ";
    cin>>st;
    vector<int> dict(128,-1);
    int maxLen = 0, start = -1;

    for(int i=0; i<st.length(); i++){
        if(dict[st[i]] > start)
            start = dict[st[i]];
        
        dict[st[i]] = i;
        maxLen = max(maxLen, i-start);
    }

    cout<<maxLen;
}