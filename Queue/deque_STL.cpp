#include<iostream>
#include<queue>
using namespace std;

int main(){
    deque<int> dq;
    // queue<int> q;
    // q.push(1);
    // q.push(2);
    // q.push(3);
    


    dq.push_front(2);
    dq.push_front(1);
    dq.push_back(3);
    dq.push_back(4);
    dq.push_back(5);
    dq.push_back(10);
    cout<<"\nfront: "<<dq.front()<<" back: "<<dq.back()<<endl;

    dq.pop_front();
    cout<<"\nfront: "<<dq.front()<<" back: "<<dq.back()<<endl;

    if(dq.empty())
        cout<<"Q is empty"<<endl;
    else
        cout<<"Q is not empty"<<endl;
    
    cout<<"Size: "<<dq.size()<<endl;
    
    deque<int> :: iterator q = dq.begin();
    cout<<"\nPrinting Q : ";
    while(q != dq.end()){
        cout<<*q<<" ";
        q++; 
    }

    cout<<"\nAt index 3: "<<dq.at(3)<<endl;
}