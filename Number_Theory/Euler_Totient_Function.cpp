// consider @(n) is a Euler totient function
// @(n) = {1 <= m < n} , where gcd(m,n) = 1
// @(A*B) = @(A) * @(B)

#include<iostream>
using namespace std;

const int N = 1e5 + 2;
int totient[N];

signed main(){
    for (int i = 0; i < N; i++){
        totient[i] = i;
    }
    
    for (int i = 2; i < N; i++){
        if(totient[i] == i){
            for(int j=2*i; j<N; j+=i){
                totient[j] *= i-1;
                totient[j] /= i;
            }
            totient[i] = i-1;
        }
    }

    for (int i = 2; i < 11; i++){
        cout<< totient[i] <<" ";
    }

    return 0;
}