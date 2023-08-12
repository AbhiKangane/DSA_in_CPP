// given array of coins OR notes & value x.
// Find minimum no. of coins required to make value x

#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> coins ={1,2,5,10,20,50,100,200,500,1000,2000};
    int amount;
    cout<<"Enter amount : ";
    cin>>amount;

//    sorting vector coins in decreasing order
    sort(coins.begin(), coins.end(), greater<int>());

    int ans = 0;

    for (int i=0; i<coins.size(); i++){
        ans += amount/coins[i];
        amount -= amount/coins[i]  * coins[i];
    }
    
    cout<<"Minimum no. of coins required : "<<ans;
}