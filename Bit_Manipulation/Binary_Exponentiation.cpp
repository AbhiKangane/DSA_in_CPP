// Properties of modulo operation:
// 1) (a+b) % m = (a%m) + (b%m)
// 2) (a*b) % m = (a%m) * (b%m)
// 3) (a-b) % m = (a%m) - (b%m)
// 4) (a/b) % m = (a%m) * ((1/b)%m)

#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;

int power(int a, int n){

    int ans =1;
    while (n>0){
        if(n&1)
            ans = (ans * a) % MOD;
        a = (a*a) % MOD;
        n = n >> 1; // right shifting
    }
    return ans;
}

int powerREC(int a, int n){
    if(n==0)
        return 1;
    
    int p = powerREC(a, n/2) % MOD;
    if(n&1)// if bit is 1
        return (((p*p) % MOD) * a) % MOD;
    else
        return (p*p) % MOD;
}

signed main(){
    int a, n;
    cin>> a>> n;
    a %= MOD;

    cout<<power(a,n)<<endl;
    cout<<powerREC(a,n)<<endl;
}