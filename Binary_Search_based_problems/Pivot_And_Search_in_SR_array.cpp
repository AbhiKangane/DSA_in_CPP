// Sorted Rotated Array Ex: {5, 7, 9, 2, 4}  pivot = 2 & its index = 3
// pivot is smallest number in Sorted Rotational Array

#include<iostream>
#include<vector>
using namespace std;

class Get_Pivot{
    public:

    int binary_search(vector<int> arr, int s, int e, int key){

        int start=s, end=e;
        int mid = start + (end - start)/2;

        while (start <= end)
        {
            if(arr[mid] == key){  
                return mid;
            }

            else if(arr[mid] > key){
                end = mid-1;
            }

            else{
                start = mid+1;
            }

            mid = start + (end - start)/2;
        } 
        return -1;
    }

    int pivot_index(vector<int> arr){

        int start=0, end=arr.size()-1;
        int mid = start + (end - start)/2;

        while (start < end)
        {
            if(arr[mid] >= arr[0]){  
                start = mid + 1;
            }

            else{
                end= mid;
            }

            mid = start + (end - start)/2;
        } 
        return start;
    }

    int find_position(vector<int>arr, int key){
        int pivot = pivot_index(arr);
        if(key >= arr[pivot] && key <= arr[arr.size() - 1]){ // this is for 2nd sorted part i.e from  pivot to end
            return binary_search(arr, pivot, arr.size()-1, key);
        }

        else
            return binary_search(arr, 0, pivot-1, key);    
    }
};

int main(){
    Get_Pivot p;
    vector<int> SR_array {5, 7, 9, 12, 4};
    cout<<"Pivot_Index of above Sorted Rotated array: "<<p.pivot_index(SR_array)<<endl;
    
    cout<<"Index of 12 in above Sorted Rotated array: "<<p.find_position(SR_array, 12)<<endl;
    // cout<<"Index of 1 in above Sorted Rotated array: "<<p.find_position(SR_array, 1)<<endl;

    return 0;
}