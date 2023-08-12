#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int size;
    cout<<"Enter the number of elements: ";
    cin>>size;
    int target;
    cout<<"Enter the target sum: ";
    cin>>target;

    vector<int> a(size);
    cout<<"Enter the numbers: ";
    for(auto &i: a){
        cin>>i;
    }

    bool found = false;
    sort(a.begin(), a.end());

    for(int i=0; i<size; i++){
        int low = i+1, high = size-1;
        while (low < high){
            int current = a[i] + a[low] + a[high];
            if(current == target){
                cout<<a[i]<<" + "<<a[low]<<" + "<<a[high]<<" = "<<target<<endl;
                found = true;
            }

            if(current < target){
                low++;
            }

            else{
                high--;
            }
        }
    }

    // if(found = true)
    //     cout<<"3 elements are found having sum equals target sum."<<endl;
    // else
    //     cout<<"Elements are not found having sum equals target sum."<<endl;

}