#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
    int value, weight;
};

// for sorting in decreasing order
static bool compare(pair<double,Item> p1, pair<double,Item> p2){
    return p1.first > p2.first;  // comapring with double i.e. value/weight
}

double fractional_Knapsack(int capacity, Item arr[], int n){
    vector<pair<double, Item>> v;

    // adding values in v
    for (int i = 0; i < n; i++){
        double perUnitValue = (1.0 * arr[i].value) / arr[i].weight;
        pair<double, Item> p = make_pair(perUnitValue, arr[i]);
        v.push_back(p);
    }
    

    // sorting 'v' w.r.t. value/weight in descending order
    sort(v.begin(), v.end(), compare);

    double ans = 0;

    for (int i = 0; i < n; i++){
        if(v[i].second.weight > capacity){    // i.e. weight exceeds than capacity then we can take only fractions
            ans += v[i].first * capacity;     // adding fractional value of curr item
            capacity = 0;                     // finally capacity becomes 0
            break;
        }

        else{ //  if(capacity >= v[i].second.weight)
            ans += v[i].second.value;        // adding value to ans
            capacity -= v[i].second.weight;  // removing weight from capacity
            continue;
        }
    }

    return ans;
}

signed main(){
    int n, capacity;
    cout<<"Enter no. of items & capacity of bag : ";
    cin>>n>>capacity;

    Item a[n];  // creationg array of items contains (value, weight) pairs
    cout<<"Enter value & weight of each item : \n";
    for (int i = 0; i < n; i++){
        cin>>a[i].value>>a[i].weight;
    }
    
    double ans = fractional_Knapsack(capacity, a, n);
    cout<<"Maximum profit : "<<ans;
}