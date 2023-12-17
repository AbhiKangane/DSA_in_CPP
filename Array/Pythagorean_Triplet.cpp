// we have to check whether given array contains pythagorean triplet or not

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool checkTriplet(vector<int> arr){
    int maxi=0;       
    for(auto i: arr){
        maxi = max(maxi, i);
    }
    maxi = maxi*maxi;      // for storing sq. of maximum element

    unordered_map<int, int> freq;    // stores key-val pairs such as => (arr[i]*arr[i], freq)
    for(auto i: arr){
        freq[i*i]++;
    }

    // for all possible a's
    for(auto i: freq){
        // for all possible b's
        for(auto j: freq){
            if(i.first == j.first && i.second==1){
                // this means that i & j are equal
                continue;
            }
            // now we have possibility of a & b
            // evaluate c & check if it is present
            int c = i.first + j.first;
            if(c > maxi)
                continue;
            
            if(freq[c] > 0)
                return true;

        }
    }

    return false;
}


int main(){
    vector<int> arr = {100,2,3,4,6,8};

    cout<<"Is there any Pythagorean Triplet present : "<<checkTriplet(arr);
}