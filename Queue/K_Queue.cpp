#include<bits/stdc++.h>
using namespace std;

class K_Queue
{
public:
    int n, k, freeSpot;
    int *front, *rear, *arr, *next;
   
public:
    K_Queue(int n, int k){
        this-> n  = n;
        this-> k = k;
        front = new int[k];
        rear = new int[k];
        
        for(int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }

        next = new int[n];
        for(int i=0; i<n; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        arr = new int [n];
        freeSpot = 0;
    }

    void enqueue(int data, int qn){
        // overflow
        if(freeSpot == -1){
            cout<<"No empty space is available"<<endl;
            return;
        }

        // find first free index
        int index  = freeSpot;

        // update freespot
        freeSpot = next[index];

        // check whether 1st element
        if(front[qn-1] == -1)
            front[qn-1] = index;

        else  // link new element to prev element
            next[rear[qn-1]] = index;

        // update next
        next[index] = -1;

        // update rear
        rear[qn-1] = index;

        // push element
        arr[index] = data;
    }

    int dequeue(int qn){
        // underflow
        if(front[qn-1] == -1){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }

        // find index to pop
        int index = front[qn-1];

        // incrementing front
        front[qn-1] = next[index];

        // manage freespot
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }
};

int main(){
    K_Queue kq(10,3);
    kq.enqueue(10,1);
    kq.enqueue(15,1);
    kq.enqueue(20,2);
    kq.enqueue(25,1);

    cout<<kq.dequeue(1) << endl;
    cout<<kq.dequeue(1) << endl;
    cout<<kq.dequeue(1) << endl;
    cout<<kq.dequeue(1) << endl;

    cout<<kq.dequeue(1) << endl;
    
    return 0;
}