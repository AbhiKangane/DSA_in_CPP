// Print smallest positive missing number from given array
// ex: arr={-1,3,0,-4,5,1}
// output: 2
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, i;
    cout<<"Enter size of array: ";
    cin>>size;

    vector<int> arr(n);
    cout<<"Enter numbers in array: ";
    for(i=0; i<n; i++)
        cin>>arr[i];

    int max = *max_element(arr.begin(), arr.end());;
    vector<bool> check(max);

    for(i=0; i<size; i++){
        if(arr[i] >= 0){
            check[arr[i]] = true;
        }
    }
     
    int ans = -1;
    for(i=1; i<max; i++){
        if(check[i] == false){
            ans = i;
            break;
        }
    }

    cout<<"Smallest Missing Positive Number is: "<<ans;
    return 0;
}
