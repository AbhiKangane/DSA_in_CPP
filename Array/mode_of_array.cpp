#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int mode(vector<int> &arr){
    unordered_map<int, int> count;
    int n = arr.size();

    int maxFreq = 0, maxAns = 0;
    for (int i = 0; i < n; i++){
        count[arr[i]] ++;
        maxFreq = max(count[arr[i]], maxFreq);
    }

    for (int i = 0; i < n; i++){
        if(maxFreq == count[arr[i]]){ //when frequency of more than 1 numbers are same then it will returns 1st numbers in array
            maxAns = arr[i];
            break;
        }
    }
    
    return maxAns;
}

int main(){
    vector<int> arr{5,1,3,2,1,4,1,2,5,3,5,1,5,5}; 
    cout<<"Mode of given array: "<<mode(arr);
    return 0;
}