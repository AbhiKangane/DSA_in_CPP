#include<iostream>
#include<queue>
using namespace std;

void heapify(vector<int> &arr, int n, int i){  // for 0 based indexing
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest] , arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b){
    // step 1: merge vectors
    vector<int> ans;
    for(auto i: a)
        ans.push_back(i);
    
    for(auto i: b)
        ans.push_back(i);
    

    // step 2: building heap using merged vector
    int size = ans.size();
    for(int i=size/2 - 1; i>=0; i--){
        heapify(ans, size, i);
    }
    return ans;
}


// Que. 2: Minimum cost of ropes(GFG)
long long minCost(long long arr[], long long n){
    // create a min heap
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(int i=0; i<n; i++)
        pq.push(arr[i]);

    long long cost = 0;
    while(pq.size() > 1){
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        long long sum = a+b;
        cost += sum;
        pq.push(sum);
    }
    return cost;
}


int main(){
    vector<int> a = {10, 5, 6, 2}, b = {12,7,9};

    vector<int> merged_Heap = mergeHeaps(a,b);
    for(int i = 0; i<merged_Heap.size(); i++){
        cout<<merged_Heap[i]<<" ";
    }
    return 0;
}