// Given arr[], Finding minimum no. of jumps required to reach to the end of array. At any index 'i' we can jump maximum arr[i] steps.
#include<iostream>
#include<vector>
using namespace std;
const int inf = 1e9;


int minJumps(vector<int> &arr){
    int n = arr.size();
    vector<int> jump(n, inf);


    if(arr[0] == 0)
        return -1;    // we can't reach at end

    jump[0] = 0;

    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(i <= (j+arr[j]))
                jump[i] = min(jump[i], jump[j]+1);
        }
    }

    return jump[n-1];
}

int main(){
    vector<int> arr = {1,5,2,3,4,2,3};   // ans = 2

    cout<<"Minimum no. jumps required to reach at end : "<<minJumps(arr);

    return 0;
}