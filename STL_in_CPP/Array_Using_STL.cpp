#include<iostream>
#include<array>

using namespace std;
int main(){
    array<int, 5> a = {1,2,3,4};
    array<int, 5> b = {6,7,8,9};

    // cout<<a.at(3)<<endl;
    // cout<<a.front()<<endl;
    // cout<<a.back()<<endl;
    // a.fill(11);
    // for(int i=0; i<5; i++)
    //     cout<<a[i]<<endl;

    // a.swap(b);
    // for(int i=0; i<5; i++)
    //     cout<<a[i]<<endl;
    
    // for(int i=0; i<5; i++)
    //     cout<<b[i]<<endl;

    cout<<a.size();


}