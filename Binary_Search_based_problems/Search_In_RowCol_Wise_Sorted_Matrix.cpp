// search the target vlaue in matrix of n*m dimension & return 1 if found, else 0.
// matrix has following properties
// 1. each row & column are sorted ascending order
// 2. first integer of each row > last integer of previous row

#include<iostream>
#include<vector>
using namespace std;

bool isPresent(vector<vector<int>> &mat, int target){
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = n*m-1;
    while (low <= high){
        int mid = low + (high-low)/2;
        int x=mid/m;
        int y=mid%m;

        if(mat[x][y] == target)
            return 1;
        else if(mat[x][y] < target)
            low = mid+1;
        else
            high = mid-1;
    }
    return 0;
}

int main(){
    vector<vector<int>> mat = {{1, 3, 5, 7},
                               {10,11,16,20},
                               {23,30,34,60}};
    int target = 8;
    isPresent(mat, target) ? cout<<"Target is present" : cout<<"Target is not present";

    return 0;
}