// Fermat's_Little_Theorem stateds that if p is a prime no. then for anny integer 'a', then no. (a^p - a) % p = 0
// => a^p = a % p
// Case 1 : if 'a' is not divisible by p, then theorem is equivalent to statement that (a^(p-1) - 1) % p = 0
// => a^(p-1) = 1 % p   => a^(p-2) = (1/a) % p

// Wilson Theorem => (p-1)! = p-1 (mod p)  here = denotes congniant 

// Problem_Stmt : Given prime No. P & integer N(close to N), find (N! % P)
// Constraints : 1 < P <= 2*10^9 ,   1 <= N <= 2*10^9 ,    Abs(N-P) <= 1000

#include<iostream>
using namespace std;

#define int long long

int power(int x, int y, int p){
    int res = 1;
    x %= p;
    while (y>0){
        if(y & 1)
            res = (res*x) % p;

        y = y >> 1;
        x = (x*x) % p;
    }
    return res;
}

int modInverse(int a, int p){
    return power(a, p-2, p);
}

int modFactorial(int n, int p){
    int res = (p-1);
    if(n>=p)
        return 0;
    
    else{
        for (int i = n+1; i < p; i++){
            res = (res* modInverse(i,p)) % p;
        }
        return res;
    }
}

int32_t main(){
    int n , p;
    cout<<"Enter number & nearest Prime number : ";
    cin>>n>>p;

    cout<<modFactorial(n,p)<<endl;
}