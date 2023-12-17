#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// bucketSort1 for sorting numbers between [0,1)
void bucketSort1(float arr[], int size){
    vector<vector<float>> bucket(size, vector<float>());

    // step 1 : Inserting elements into bucket
    for(int i=0; i<size; i++){
        int index = arr[i]*size;
        bucket[index].push_back(arr[i]);
    }

    // step 2 : Sorting individual buckets
    for(int i=0; i<size; i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(), bucket[i].end());
        }
    }

    // step 3 : Combining elements from buckets
    for(int i=0, k=0; i<size; i++)
        for(int j = 0; j<bucket[i].size(); j++,k++)
            arr[k] = bucket[i][j];    
}

// bucketSort2 for sorting numbers between any range
void bucketSort2(float arr[], int size){
    vector<vector<float>> bucket(size, vector<float>());

    // step 1 : finding range
    float max_ele = INT32_MIN;
    float min_ele = INT32_MAX;
    for(int i=0; i<size; i++){
        max_ele = max(max_ele, arr[i]);
        min_ele = min(min_ele, arr[i]);
    }

    float range = (max_ele - min_ele)/size;

    // step 2 : Inserting elements into bucket
    for(int i=0; i<size; i++){
        int index = (arr[i]-min_ele) / range;
        // boundary elements
        float diff = (arr[i]-min_ele) / range - index;
        if(diff==0 && arr[i]!=min_ele)
            bucket[index-1].push_back(arr[i]);
        else
            bucket[index].push_back(arr[i]);
    }

    // step 3 : Sorting individual buckets
    for(int i=0; i<size; i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(), bucket[i].end());
        }
    }

    // step 4 : Combining elements from buckets
    for(int i=0, k=0; i<size; i++)
        for(int j = 0; j<bucket[i].size(); j++,k++)
            arr[k] = bucket[i][j];    
}

int main(){
    float arr1[] = {0.13, 0.45, 0.12, 0.89, 0.75, 0.63, 0.85, 0.39};
    float arr2[] = {6.13, 8.45, 0.12, 1.89, 4.75, 2.63, 7.85, 10.39};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);   // 8 here
    int size2 = sizeof(arr2) / sizeof(arr2[0]);   // 8 here

    bucketSort1(arr1, size1);
    cout<<"After sorting array for range [0,1): \n";
    for(int i=0; i<size1; i++){
        cout<<arr1[i]<<" ";
    }
    
    bucketSort2(arr2, size2);
    cout<<"\n\nAfter sorting array for range[0,x], where x>1: \n";
    for(int i=0; i<size2; i++){
        cout<<arr2[i]<<" ";
    }
    
    return 0;
}