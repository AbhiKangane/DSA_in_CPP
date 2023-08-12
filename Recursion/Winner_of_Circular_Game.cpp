// n friend sitting around a circular table in clockwise order
// rules of game:
// 1. start at 1st friend.
// 2. count next k friends in clockwise order including friend you started at. It may count some friends more than once.
// 3. last friend you counted leaves circle & loss the game.
// 4. The last friend in circle win the game.

#include<iostream>
using namespace std;

int solve(int n, int k){
    if(n==1)
        return 0;
    
    return (solve(n-1, k) + k) % n;
}


int findWinner(int n, int k){
    int ans = solve(n, k) + 1;
    return ans;
}

int main(){
    int total_Friends = 5, k = 2;
    cout<<"Find Winner : "<<findWinner(5, 2);

    return 0;
}