#include<bits/stdc++.h>
using namespace std;

// for comparing dimensions(l,b,h) of base box & newBox
bool check(vector<int> base, vector<int> newBox){
    if(newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
        return true;
    else
        return false;
}
// space optimization : logic of longest Increasing Sub_Sequence
int solve_SO(int n, vector<vector<int>> &a){
    vector<int> currRow(n+1,0);
    vector<int> nextRow(n+1,0);

    for (int curr=n-1; curr>=0; curr--){
        for (int prev = curr-1; prev>=-1; prev--){
            // include
            int take = 0;
            if(prev == -1 || check(a[curr], a[prev]))
                take = a[curr][2] + nextRow[curr+1];
            
            // exclude
            int notTake = nextRow[prev+1];

            currRow[prev+1] = max(take, notTake);
        }
        nextRow = currRow;
    }
    return  nextRow[0];
}


// driver function
int maxHeight(vector<vector<int>> &cuboids){
    int n = cuboids.size();
    // step 1 : sort all dimensions(l,b,h) for every cuboid
    for(auto &a: cuboids)
        sort(a.begin(), a.end());

    // step 2 : sort all cuboids on basis of w or l
    sort(cuboids.begin(), cuboids.end());

    // step 3: use logic of longest Increasing Sub_Sequence
    return solve_SO(n, cuboids);
}


int main(){
    // vector<vector<int>> cuboids = {{7,9,5}, {8,6,3}, {9,10,11}};
    // step 1 : cuboids = {{5,7,9}, {3,6,8}, {9,10,11}};
    // step 2 : cuboids = {{3,6,8}, {5,7,9}, {9,10,11}};
    // maxHeight = 28

    vector<vector<int>> cuboids = {{7,9,5}, {8,10,3}, {9,10,11}};
    // step 1 : cuboids = {{5,7,9}, {3,6,8}, {9,10,11}};
    // step 2 : cuboids = {{3,8,10}, {5,7,9}, {9,10,11}};  // in this case we cant place cuboid {3,8,10} & {5,7,9} on each other, 
                                                           // then for max height we take only two cubes {3,8,10} & {9,10,11}      
    // maxHeight = 21

    cout<<maxHeight(cuboids);
    return 0;
}