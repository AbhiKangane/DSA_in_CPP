#include<iostream>
using namespace std;

// codeStudio problem
class N_stacks{
    int *arr, *top, *next;
    int n, s;
    int freespot;

    public:
    N_stacks(int N, int S){
        n = N; // number of stacks
        s = S; // size of stacks
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // initialize top
        for(int i=0; i<n; i++){
            top[i] = -1;
        }
        
        // initialize next
        for(int i=0; i<s; i++){
            next[i] = i+1;
        }
        next[s-1] = -1;  // update last index

        freespot = 0;
    }

    bool push(int x, int m){
        // check for overflow
        if(freespot == -1)
            return false;
        
        // find index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // insert element into array
        arr[index] = x;

        // update next
        next[index] = top[m-1];

        // update top
        top[m-1] = index;

        return true;
    }

    int pop(int m){
        // check for underflow
        if(top[m-1] == -1)
            return -1;
        
        int index = top[m-1];

        top[m-1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};