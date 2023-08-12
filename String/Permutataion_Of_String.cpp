#include<bits/stdc++.h>
using namespace std;

void permutation(string &s, int left, int right){
    if(left == right)
        cout<<s<<endl;

    else{
        for (int i = left; i <= right ; i++){
            swap(s[left], s[i]);
            permutation(s,left+1,right);
            swap(s[left], s[i]); // backtrack
        }
    }
    
}

int main(){
    string str ="ABC";
    int n = str.size();

    permutation(str, 0, n-1);
    return 0;

}