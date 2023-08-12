#include<bits/stdc++.h>
using namespace std;

int main(){
    int size, i;
    cout<<"Enter size of array: ";
    cin>>size;

    int arr[size];
    cout<<"Enter numbers in array: ";
    for(i=0; i<size; i++)
        cin>>arr[i];

    int max = 100;
    bool check[max];
    for(i=0; i<max; i++)
        check[i] = false;

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