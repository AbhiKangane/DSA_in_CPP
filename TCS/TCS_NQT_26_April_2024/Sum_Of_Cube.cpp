// Given 2 integers N & M, find them sum of cubes of integers lies within the range N & M (including both N & M)
// Ex : 
// Input : 2 5
// Output: 
// Explanation: 8+27+64+125 = 224

#include<iostream>
using namespace std;

int main(){
    int N, M;
    cin>>N>>M; // Entering N & M

    int ans = 0;
    for(int i=N; i<M+1; i++)
        ans += (i*(i*i));

    cout<<ans;

    return 0;
}