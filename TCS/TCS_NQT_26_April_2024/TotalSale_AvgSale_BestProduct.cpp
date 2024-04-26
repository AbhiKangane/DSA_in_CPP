// Given List 'Sale_Info' of transaction contains (ProductName, Val, Quantity)
// Find the Total_Sales, Avg_Sales, Best_Product from the 'Sale_Info',  where
// Total_Sales = Sum of Product of Each (Val, Quantity) from each 'Sale_Info[i]'
// Avg_Sales = Total_Sales / No. of Transactions
// Best_Product = ProductName which has maximum sum of (Val * Quantity)) for that Product

// Example: 
// Input: 6
//       Apple, 1.5, 4
//       Banana, 3, 5
//       Orange, 2.0, 10
//       Banana, 2.5, 5
//       Apple, 5, 6
//       Orange, 4, 5
// Output: 
// Total_Sales  = 103.5
// Avg_Sales    = 17.25
// Best_Product = Orange


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    cout<<"Enter totaL no. of transactions: ";
    int n; 
    cin>>n;

    string ProductName; float Val; int Quantity;

    vector<pair<string,pair<float,int>>> Sale_Info(n);
    for(int i=0;i<n;i++){
        cin>>ProductName>>Val>>Quantity;

        Sale_Info[i].first         = ProductName;
        Sale_Info[i].second.first  = Val;
        Sale_Info[i].second.second = Quantity;

        // cout<<Sale_Info[i].first<<" "<<Sale_Info[i].second.first<<" "<<Sale_Info[i].second.second<<endl;
    }

    float Total_Sales, Avg_Sales;
    string Best_Product;
    for(int i=0; i<n; i++)
        Total_Sales += (Sale_Info[i].second.first * Sale_Info[i].second.second);
    
    Avg_Sales = Total_Sales/n;

    // For finding best_Product, we use unordered_map because ProductName in Sale_Info may repeats
    unordered_map<string,float> mp;
    float maxSale = 0;
    for(int i=0; i<n; i++){
        mp[Sale_Info[i].first] += (Sale_Info[i].second.first * Sale_Info[i].second.second);
        if(maxSale < mp[Sale_Info[i].first]){
            maxSale = mp[Sale_Info[i].first];
            Best_Product = Sale_Info[i].first;
        }
    }

    printf("Total Sale: %0.2f Average Sale: %0.2f ", Total_Sales, Avg_Sales);
    cout<<"Best Product: "<<Best_Product;

    return 0;
}