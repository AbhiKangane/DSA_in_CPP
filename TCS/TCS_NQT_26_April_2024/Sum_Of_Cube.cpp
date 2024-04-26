// Given 2 integers N & M, find them sum of cubes of integers lies within the range N & M (including both N & M)
// Ex : 
// Input : 2 5
// Output: 
// Explanation: 8+27+64+125 = 224

#include<iostream>
using namespace std;

int main(){
    int N, M;
    cout<<"Enter N & M: ";
    cin>>N>>M; 

    int ans = 0;
    // Sol 1: O(N)
    // for(int i=N; i<M+1; i++)
    //     ans += (i*(i*i));


    // sol 2: O(1)
    // using formula of sum of cubes of 1st N natural numbers = [ (n(n+1)) / 2 ] ^ 2
    int sumOfCube_M = (M*(M+1)) * (M*(M+1))/ 4;
    int sumOfCube_N_1 = ((N-1)*(N)) * ((N-1)*(N)) / 4;
    ans = sumOfCube_M - sumOfCube_N_1;

    // cout<<sumOfCube_M<<" "<<sumOfCube_N_1<<endl;
    cout<<ans;

    return 0;
}
