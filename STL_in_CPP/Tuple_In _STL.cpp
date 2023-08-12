#include<iostream>
#include<tuple>
using namespace std;

int main(){
    tuple <const char*, const char*, int> t1;
    t1 = make_tuple("Abhishek","Kangane", 100);
    cout<<get<0>(t1)<<endl;  // This code is working gives fattal error Don't know
    cout<<get<1>(t1)<<endl;
    cout<<get<2>(t1)<<endl;

    return 0;
}