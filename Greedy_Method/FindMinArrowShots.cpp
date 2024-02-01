/*
There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.
Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
Given the array points, return the minimum number of arrows that must be shot to burst all balloons
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int findMinArrowShots(vector<vector<int>>& points) {
    // sorting points in ascending order w.r.t. 1st coordinate followed by 2nd
    sort(points.begin(), points.end());
    int n = points.size(), i=1, ans=1;
    int maxRange = points[0][1];
    
    while(i<n){
        // if maxRange of previous overlapped balloons < next balloon
        if(points[i][0] > maxRange){
            ans++;                      // use new arrow for burst this balloon
            maxRange = points[i][1];    // setting maxRange = range of this new ballon
            i++;
            continue;
        } 

        maxRange = min(maxRange, points[i][1]);//for setting maxRange if newballoon range<maxRange 
    
        i++;
    } 
        
    return ans;
}

int main(){
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};

    cout<<findMinArrowShots(points);
    return 0;
}
