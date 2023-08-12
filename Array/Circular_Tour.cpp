// problem GFG: given two arrays 
// 1) petrol => amount of petrol at every petrol pump
// 2) distance => distance from petrol pump to next petrol pump
// we have to starting point of circular tour
// assuming in 1 ltr petrol vehicle goes 1 unit distance

#include<bits/stdc++.h>
using namespace std;

int Circular_Tour(vector<int> petrol, vector<int> distance){
    int start = 0;
    int deficit = 0, balance = 0;

    for (int i = 0; i < petrol.size(); i++){
        balance += petrol[i] - distance[i];
        if(balance < 0){
            deficit += balance;
            start = i+1;
            balance = 0;
        }
    }
    
    if(deficit + balance >=0)
        return start;
    
    return -1;
}

int main(){
    vector<int> petrol = {4,6,7,4};
    vector<int> distance = {6,5,3,5};

    cout<<"Starting index of tour: "<<Circular_Tour(petrol,distance);  // here indexing is 0 based
}