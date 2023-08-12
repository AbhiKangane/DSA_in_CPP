// N candies of price = candies[i]
// If you buy a single candy then you will get any 2 candies free
// Task: You have to find minimum & maximum amount of money required to buy all candies

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> candyStore(int candies[], int N, int k){
    sort(candies, candies+N);
    // for minimum amount
    int mini = 0;
    int buy = 0;
    int free = N-1;
    while (buy <= free){
        mini += candies[buy];
        buy++;
        free -= k; 
    }
    
    // for minimum amount
    int maxi = 0;
    buy = N-1;
    free = 0;
    while (buy >= free){
        maxi += candies[buy];
        buy--;
        free += k; 
    }

    vector<int> ans;
    ans.push_back(mini);
    ans[1] = maxi;

    return ans;
}

int main(){
    int candies[] = {3,2,1,4};
    int N = 4, k = 2;

    vector<int> ans = candyStore(candies, N, k);
    cout<<"Minimum & Maximum amount required are: "<<ans[0]<<" & "<<ans[1];
}