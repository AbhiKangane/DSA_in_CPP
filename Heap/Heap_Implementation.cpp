#include<iostream>
using namespace std;

// heap is a complete binary tree

class heap{
    public:
        int arr[100];
        int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size += 1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){  // for max heap
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;            
        }
    }

    void deleteRootFromHeap(){  
        if(size == 0){
            cout<<"Can't delete, Heap is empty";
            return;
        }

        // step 1: put last element into 1st
        arr[1] = arr[size];  // for 1 based indexing

        // step 2: remove last element
        size--;

        // step 3: take root node to its correct position
        int i = 1;
        while(i<size){
            int left_Child = 2*i;
            int right_Child = 2*i + 1;

            if(left_Child <= size && arr[i] < arr[left_Child]){
                swap(arr[i], arr[left_Child]);
                i = left_Child;
            }

            else if(right_Child <= size && arr[i] < arr[right_Child]){
                swap(arr[i], arr[right_Child]);
                i = right_Child;
            }

            else{
                return;
            }
        }
    }

    void PrintHeap(){
        for(int i = 1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(5);
    // h.PrintHeap();
    
    h.deleteRootFromHeap();
    h.PrintHeap();

    return 0;
}