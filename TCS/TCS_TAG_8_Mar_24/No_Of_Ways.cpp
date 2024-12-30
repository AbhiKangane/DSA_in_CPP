/*
There are 3 different types of balls (Green, Yellow, Red) having frequency x, y, z.
Then return the no. of ways of arranging this balls into straight line such that adjacent balls always have diffrent colors.

Ex. 1 : 
Input : G=1, Y=1, R=0
OutPut : 2   
Explaination : GY & YG

Ex. 2 : 
Input : G=1, Y=1, R=1
OutPut : 6   
Explaination : GYR, GRY, RGY, RYG, YGR, YRG
*/
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
 
// sol 1: using recusrion
int solveRec(int R, int Y, int G, bool r, bool y, bool g){
    if(R==0 && Y==0 && G==0)
        return 1;
    
    else if(R==-1 || Y==-1 || G==-1)
        return 0;

    int count = 0;
    if(r)       count += solveRec(R-1,Y,G,0,1,1);
    if(y)       count += solveRec(R,Y-1,G,1,0,1);
    if(g)       count += solveRec(R,Y,G-1,1,1,0);

    return count;
}

// sol 2: Storing  unique permutations 
void FindUniquePerm(int left, int right, string &s, set<string> &ans){
    if (left == right){// reach the end of s
        ans.insert(s);
        return ;
    } 

    for (int j=left; j<=right; j++){       
        swap(s[left], s[j]);
        FindUniquePerm(left+1, right, s, ans);
        swap(s[left], s[j]);     // backtrack
    }
}    

vector<string> permuteUnique(string &s) {
    set<string> ans;
    int n = s.size();
    sort(s.begin(), s.end());
    FindUniquePerm(0,n-1, s, ans);

    return vector<string>(ans.begin(), ans.end());     // if set<string> ans is used insted of vector
}


int main(){
    int g, y, r;
    cout<<"Enter no of green, yellow, red balls: ";
    cin>>g>>y>>r;

    cout<<"\nNo of ways to arrange balls by recursion only: "<<solveRec(g,y,r,1,1,1)<<endl;

    string str ="";
    for(int i=0; i<g; i++)
        str+="G";
    for(int i=0; i<y; i++)
        str+="Y";
    for(int i=0; i<r; i++)
        str+="R";
    
    vector<string> uniquePerm = permuteUnique(str);
    
    // cout<<"\n\nPrinting unique Permutations of string by using 2nd method: \n";
    // for (int i = 0; i < uniquePerm.size(); i++){
    //     cout<<uniquePerm[i]<<" ";
    // }
    
    int ans = uniquePerm.size();
    for(int i=0; i<uniquePerm.size(); i++){
        for(int j=0; j<uniquePerm[i].size()-1; j++){
            if(uniquePerm[i][j]==uniquePerm[i][j+1]){
                ans--;
                break;
            }
        }
    }
    // this solution gives TLE
    cout<<"\nNo of ways to arrange balls: "<<ans<<endl;

    return 0;

}
