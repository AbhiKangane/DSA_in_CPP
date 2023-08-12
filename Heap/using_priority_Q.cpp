#include<iostream>
#include<queue>
using namespace std;

int main(){
    // priority q is array representation of max heap
    priority_queue<int> pq; 

    pq.push(10);
    pq.push(30);
    pq.push(40);
    pq.push(20);
    pq.push(5);

    cout<<"Root Element: "<<pq.top()<<endl;
    pq.pop();
    cout<<"Root Element: "<<pq.top()<<endl;
    
    cout<<"Size of pq: "<<pq.size()<<endl;


    cout<<"Minheap using priority_queue: "<<endl;
    priority_queue<int, vector<int>, greater<int>> minheap;
    minheap.push(10);
    minheap.push(30);
    minheap.push(40);
    minheap.push(20);
    minheap.push(5);

    cout<<"Root Element: "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"Root Element: "<<minheap.top()<<endl;
    
}