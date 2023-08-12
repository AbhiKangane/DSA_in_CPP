// there is only 1 shop on island & it is open on all days except sunday
// N - Max. food can buy each day
// S - No. of days require to suvive
// M - Food required each day to survive
// Now currently monday & you need to survive for next 'S' days
// Task : Find minimum no. of dayson whichyou need to buy food from shop so than you can survive for next 'S' days

#include<bits/stdc++.h>
using namespace std;

int minimumDays(int S, int N, int M){
    int sunday = S/7;
    int buyingDays = S - sunday;  
    int totalFood = S*M;
    int ans = 0;

    if(totalFood % N == 0)
        ans = totalFood/N;

    else
        ans = totalFood/N + 1;

    if(ans <= buyingDays) 
        return ans;
    
    else
        return -1;
}

int main(){
    int s=10, n=16, m=4;

    cout<<"Minimum no. days required for buying food : "<<minimumDays(s,n,m);
}