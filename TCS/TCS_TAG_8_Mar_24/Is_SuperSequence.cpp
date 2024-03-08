/*
    Given 3 strings named p,q,r. The string r is called super-sequence if it follows below conditions
1) r contains each characters(with freq) of p & q. i.e  r = p U q
2) The order of characters in p & q is preserved in r also.

Ex 1) p="tcs", q="nqt" r="tncsqt"
output : true

Ex 2) p="tcs", q="nqt" r="tqncsnt"
output : false
*/
#include<iostream>
#include<unordered_map>
using namespace std;

bool isSuper_Sequence(string p, string q, string r){
    // for checking 1st condition
    unordered_map<char,int> mp;
    for(auto i: p)
        mp[i]++;
    for(auto i: q)
        mp[i]++;
    
    for(auto i: r)
        if(mp[i] > 0)
            mp[i]--;

    for(auto i: mp)
        if(i.second != 0)
            return false;
    
    int i=0, j=0; 
    for(int k=0; k<r.size(); k++){
        if(p[i]==r[k]){
            i++;
        }
        else if(q[j]==r[k]){
            j++;;
        }
    }

    return i==p.size() && j==q.size();
}

int main(){
    string p,q,r;
    // cout<<"Enter the strings p, q, r: ";
    // cin>>p>>q>>r;

    if(isSuper_Sequence(p,q,r))
        cout<<"True";
    else
        cout<<"False";

    return 0;
}