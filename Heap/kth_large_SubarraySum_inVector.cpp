// find the kth largest subarray sum in vector  
#include<bits/stdc++.h>
using namespace std;


// approach 1: TC= O(n^2) + O(n * log n),   SC = O(n^2)
int kth_Large_SubarraySum(vector<int> &a, int k){
    vector<int> sumStore;

    for(int i=0; i<a.size(); i++){
        int Subarray_Sum = 0;
        for(int j=i; j<a.size(); j++){
            Subarray_Sum += a[j];
            sumStore.push_back(Subarray_Sum);
        }
    }

    sort(sumStore.begin(), sumStore.end());  // sorting vector which stores all aubarray's sum

    return sumStore[sumStore.size() - k];  //return kth largest subarray sum
}


// approach 2: TC= O(n^2),   SC = O(k)
int kth_Large_SubarraySum_Using_PQ(vector<int> &a, int k){
    // creating minHeap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for(int i=0; i<a.size(); i++){
        int Subarray_Sum = 0;
        for(int j=i; j<a.size(); j++){
            Subarray_Sum += a[j];

            if(minHeap.size() < k){
                minHeap.push(Subarray_Sum);
            }
            else{
                if(Subarray_Sum > minHeap.top()){
                    minHeap.pop();
                    minHeap.push(Subarray_Sum);
                }
            }
        }
    }

    return minHeap.top();
}


int main(){
    vector<int> a = {1,2,3,4,5};
    int k = 3;

    cout<<"kth largest subarray sum: "<<kth_Large_SubarraySum_Using_PQ(a, k);
}