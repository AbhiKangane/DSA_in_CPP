// similar problem to minimum pages allocation
#include<iostream>
using namespace std;

int find_Feasible(int boards[], int n, int limit){
    int sum=0, painters=1;
    for (int i = 0; i < n; i++){
        sum += boards[i];
        if(sum > limit){
            sum = boards[i];
            painters++;
        }
    }
     return painters;
}

int paintersPartition(int boards[], int n, int No_of_Painters){
    int totalLength = 0, k = 0;
    for (int i = 0; i < n; i++){
        k = max(k, boards[i]);  // k will give length of largest board
        totalLength += boards[i];
    }
    
    int low = k, high = totalLength;
    
    while (low < high){
        int mid = (low+high)/2;
        int painters = find_Feasible(boards, n, mid);
        if (painters <= No_of_Painters){
            high = mid; // for left part
        }
        else
            low = mid+1; // for right part
    }
    
    return low;
}

int main(){
    int boards[] = {10,20,30,40};
    int n=4, no_of_Painters = 2;

    cout<<"Minimum time to paint boards : "<<paintersPartition(boards, n, no_of_Painters);
    return 0;
}