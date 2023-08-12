// rotated array Ex = {30,40,50,10,20}    here 50 is pivot element
#include<iostream>
using namespace std;

int search_In_Rotated_Array(int arr[], int key, int left, int right){
    if(left > right)
        return -1;
    
    int mid = (left+right)/2;
    if(arr[mid] == key)
        return mid;
    
    if(arr[left] <= arr[mid]){ // if increasing ie. no pivot element present in range left->mid
        if(arr[left] <= key && key <= arr[mid])
            return search_In_Rotated_Array(arr,key,left,mid-1);
        else
            return search_In_Rotated_Array(arr,key,mid+1,right);
    }

    else{ // if pivot present in range left->mid
        if(arr[mid] <= key && key <= arr[right])
            return search_In_Rotated_Array(arr,key,mid+1,right);
        else
            return search_In_Rotated_Array(arr,key,left,mid-1); 
    }
}

int main(){
    int arr[] = {4,5,6,7,8,9,1,2,3};
    int n = 9, key = 3;

    cout<<"Number is present at index : "<<search_In_Rotated_Array(arr,key,0,n-1);
    return 0;
}