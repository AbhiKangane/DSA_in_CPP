/*
Que 1) Weapon Boxes
Problem Description
In the border of India, there is a military camp where soldiers stay. The soldiers need weapons during the wars and some weapons are made in India while the others are imported from other countries. One day many boxes of weapons arrived from different countries. These boxes have different numbers assigned to it. These numbers denotes the weight of the boxes. Larger the number on the box, the more will be the weapons inside it. All these boxes are arranged in a line starting from the camp. One day the commander wanted to test the weapons in all the boxes one by one. But he wanted to prioritize the boxes with more weight because when he open that box, the number of weapons will be more. So he will followed the below steps.

=> He will carry this process in cycles. In each cycle, he will select the first N boxes. From those, every time he will pick the first two boxes and compare them and send the box with lower weight to the end of the line.
=> At last one box will remain from those N boxes, then the cycle is said to be complete.
=> He halts this process when the same box remains un-shifted to the end of the line in K consecutive cycles.
=> For shifting these boxes, he hired labors and they will charge an amount which is equal to the sum of weights of all those boxes except those which are having triangular number weights.

Given an array consisting of weights of all the boxes, two integers N and K, print the amount of money that the commander have to give to workers.

Constraints
1 <= weight of each box <= 10^5
1 <= number of boxes <= 10^4
1 <= N,K <= 10^3
All the elements in the array are distinct.

Input
First line consists of an array denoting the weight of all the boxes.
Second line consists of two space separated integers N and K, denoting the number of boxes he selects in each cycle and number of times a box should remain un-shifted to halt the process.

Output
Print the amount of money that the commander have to give to workers.

Time Limit (secs)
1

Examples
Example 1
Input
7 3 6 9 10 2 4 11 5 12 17 1
3 2

Output
22

Explanation
In each cycle, we select 3 boxes and follow the below steps.
Cycle number   Comparing numbers    Shifting box    Resulting Sequence
1              7,3                   3              7 6 9 10 2 4 11 5 12 17 1 3
               7,6                   6              7 9 10 2 4 11 5 12 17 1 3 6

2              7,9                   7              9 10 2 4 11 5 12 17 1 3 6 7
               9,10                  9              10 2 4 11 5 12 17 1 3 6 7 9

3              10,2                  2              10 4 11 5 12 17 1 3 6 7 9
               10,4                  4              10 11 5 12 17 1 3 6 7 9 2 4

After cycle 3, 10 remained un-shifted in 2 cycles. Hence he halts the process.
Total amount need to be paid for the labor = sum of non triangular weights of all the shifted boxes = 7 + 9 + 2 + 4 = 22

Example 2
Input
6 2 8 14 5 1 3
2 2

Output
15

Explanation
In each cycle, we select 2 boxes and follow the below steps.
Cycle number    Comparing boxes       Shifting box      Resulting sequence
1               6,2                   2                 6 8 14 5 1 3 2

2               6,8                   6                 8 14 5 1 3 2 6

3               8,14                  8                 14 5 1 3 2 6 8

4               14,5                  5                 14 1 3 2 6 8 5

After cycle 4, 14 remained un-shifted for 2 cycles. Hence he halts the process.
Total amount need to be paid for the labor = sum of non triangular weights of all the shifted boxes = 2 + 8 + 5 = 15.
*/
#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// Function to check if a number is a triangular number
bool isTriangular(int n) {
    int x = 1;
    int sum = 0;

    while (sum < n) {
        sum += x;
        x++;
    }

    return sum == n;
}

int weaponBoxes(vector<int> arr, int N, int K){
    int comparisions=0, cycles=0;
  	vector<int> shifted;

    int unshifted_in_Cycles = 0;
	  unordered_map<int,int> mp;

  	int i=0, j=1;
 	while(unshifted_in_Cycles < K){
    	if(arr[0] < arr[1]){
          	shifted.push_back(arr[0]);
            // i++;
            arr.push_back(arr[0]);
            arr.erase(arr.begin());
          	comparisions++;
        }
      	else{
            shifted.push_back(arr[1]);
            // j++;
          	arr.push_back(arr[1]);
            arr.erase(arr.begin()+1);
          	comparisions++;

        }
      	if(comparisions % (N-1) == 0){
            cycles++;
            mp[arr[0]]++;
            unshifted_in_Cycles = max(unshifted_in_Cycles, mp[arr[0]]);
        }
    }

    // for debugging
    // cout<<"Printing map:";
    // for(auto i: mp){
    //     cout<<i.first<<" "<<i.second<<"\n";
    // }
    
    // unordered_set<int> triangularNumbers;
  	// int sum = 0;
  	// for(int i=1; sum<=1e5; i++){
    // 	sum += i;
    //     triangularNumbers.insert(sum);
    // }
  
  	int ans = 0;
  	for(long unsigned int i=0; i<shifted.size(); i++){
        // if(triangularNumbers.find(shifted[i]) == triangularNumbers.end()){
        if(!isTriangular(shifted[i])){
            // cout<<shifted[i]<<" ";
            ans += shifted[i];
        }
    }
    return ans;
}

int main(){
    int testcases;
    cout<<"Enter no of testcases: ";
    cin>>testcases;
    while (testcases--)
    {
        int size;
        cout<<"Enter size: ";
        cin>>size;
        vector<int>arr(size);
        cout<<"Enter numbers in vector: ";
        for(int i=0; i<size; i++)
            cin>>arr[i];
        cout<<"Enter N & K: ";
        int N, K;
        cin>>N>>K;
        
        cout<<"\nAns: "<<weaponBoxes(arr,N,K)<<"\n\n";
    }
    
  	    
	return 0;
}