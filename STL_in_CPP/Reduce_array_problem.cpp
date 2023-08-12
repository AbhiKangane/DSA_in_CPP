// in this problem given array of integer is reduced in the form of their increasing number in sorted array
// ex given array a[] = {30, 20, 10, 50, 40}
// ṛeduced array = {3, 2, 1, 5, 4}

#include<iostream>
#include<vector>
using namespace std;

bool myCompare(pair<int, int> p1, pair<int, int> p2){
    return p1.first < p2.first;
}

int main(){
    int i, j, n, arr[10];
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the elements in array: ";
    for(i=0; i<n; i++)
        cin>>arr[i];

    vector<pair<int, int>> v;

    for(int i=0; i<n; i++)
        v.push_back(make_pair(arr[i], i));

    // sort(v.begin(), v.end(), myCompare);
    for(int i=0; i<v.size(); i++)
        arr[v[i].second] = i;

    for(int i=0; i<v.size(); i++)
        cout<<arr[i]<<" ";

    return 0;
}