// problem GFG: https://www.geeksforgeeks.org/problems/circular-tour-1587115620/1
// 1) petrol[i] => amount of petrol at every petrol pump
// 2) distance[i] => distance from petrol pump to next petrol pump
// You have a car with an unlimited petrol tank. You begin the journey with an empty tank from one of the gas stations. 
// Return the index of the starting gas station if it's possible to travel around the circuit without running out of petrol at any station in a clockwise direction. 
// If there is no such starting station exists, return -1.
// Note: If a solution exists, it is guaranteed to be unique.
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
