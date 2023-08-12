#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l2 {10,20,90,40,30};
    
    l2.sort();
    // list<int> :: iterator p = l2.begin();
    // cout<<"After Sorting: ";
    // while(p != l2.end()){
    //     cout<<*p<<" ";
    //     p++; 
    // }

    l2.remove(90);
    l2.reverse();
    list<int> :: iterator q = l2.begin();
    cout<<"\nAfter Reversing: ";
    while(q != l2.end()){
        cout<<*q<<" ";
        q++; 
    }
/*    list<string> l1 {"Abhishek", "Ajay", "Harshad", "Mayuri"};
    l1.push_front("Samarth");
    l1.push_back("Siddhi");
    
    list<string> :: iterator i = l1.begin();

    while(i != l1.end()){
        cout<<*i<<"  ";
        i++;
    }
    cout<<"\nSize of list l1: "<<l1.size();
*/    
}