// vector is consider as a dynamic array in which size of array is doubles when additional memory needed 
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int>v;
    vector<int>v1 {1,2,3};
    vector<string>v2 (5); //creates vector of 5 length
    vector<float>v3 (5,10); //creates vector of size 5 of value 10
    
    cout<<"Initial capacity of vector v: "<<v.capacity()<<endl;
    for(int i=1; i<=5; i++){
        v.push_back(10*i);
        cout<<"Added element at index: "<<i<<" & capacity: "<<v.capacity()<<endl;
    }
    

    for(int i=0; i<5; i++)
        cout<<v[i]<<" ";

    v.pop_back();
    v.pop_back();
    cout<<"\nAfter pop capacity: "<<v.capacity(); // ie. capacity of vector not reduces
    cout<<"\nSize or total elements: "<<v.size();

    // v.clear();
    // cout<<"\nAfter pop capacity: "<<v.capacity(); // ie. capacity of vector not reduces
    // cout<<"\nSize or total elements: "<<v.size();

    cout<<"\nvalue at index 2: "<<v.at(1);
    cout<<"\nvalue at first: "<<v.front();
    cout<<"\nvalue at last: "<<v.back()<<endl;

    vector<int> :: iterator i = v.begin();
    v.insert(i+2, 333);
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    
}