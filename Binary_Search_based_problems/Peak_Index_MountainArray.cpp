// Mountain Array Ex: {1, 4, 8, 5, 2}  peak = 8
// i.e 1) From starting to peak point : arr[i] < arr[i+1]
//     2) at peak point : arr[p-1] < arr[p] > arr[p+1]
//     3) From peak to end point : arr[i] > arr[i+1]

#include<iostream>
#include<vector>
using namespace std;

class Peak_Index{
    public:

    int peak(vector<int> arr){

        int start=0, end=arr.size()-1;
        int mid = start + (end - start)/2;

        while (start < end)
        {
            if(arr[mid] < arr[mid+1]){  
                start = mid + 1;
            }

            else{
                end= mid;
            }

            mid = start + (end - start)/2;
        } 
        return start;
    }
};

int main(){
    Peak_Index p;
    vector<int> mountain {1, 4, 8, 9, 5, 2};
    cout<<"Peak_Index of above Mountain array: "<<p.peak(mountain);
    return 0;
}