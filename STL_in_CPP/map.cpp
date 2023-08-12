#include<iostream>
#include<map>

using namespace std;

int main(){
    // 1st method of creating map
    map<int, string> customer;
    customer[100] = "ajay";
    customer[110] = "mayuri";
    customer[120] = "abhishek";
    customer[130] = "harshad";
    
    // 2nd method of creating map
    map <int, string> c{
        {100, "monya"}, {110, "sonya"}, {120, "abhishek"}, {130, "soma"}
    };

    // cout<<customer.at(100)<<endl;
    // cout<<customer[110]<<endl;

// Iteration is done in ascending order according to the keys
    customer.insert(pair<int, string> (90, "xyz"));
    
    map <int, string> :: iterator p = customer.begin();
    while (p != customer.end())
    {
        cout<<p->first<<" -> "<<p->second<<endl;
        p++;
    }
    
    cout<<customer.empty(); // it gives 0 if map is empty else gives 1
    
    return 0;
}