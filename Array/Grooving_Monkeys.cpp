/* N monkeys are invited to a party where they start dancing. They dance in a circular formation, 
very similar to a Gujarati Garba or a Drum Circle. The dance requires the monkeys to constantly change positions after every 1 second.
The change of position is not random & you, in the audience, observe a pattern. Monkeys are very disciplined & follow a specific pattern while dancing.

Consider N = 6, and an array monkeys = {3,6,5,4,1,2}.
        OUTPUT = 6
This array (1-indexed) is the dancing pattern. The value at monkeys[i], indicates the new of position of the monkey who is standing at the ith position.

Given N & the array monkeys[ ], find the time after which all monkeys are in the initial positions for the 1st time.

Constraints:
    1<=t<=10 (test cases)
    1<=N<=10000 (Number of monkeys)
*/

#include<iostream>
#include<vector>
using namespace std;

// Naive solution
int Grooving_Monkeys(vector<int> X){
    int n = X.size();

    // creating vector of indices
    vector<int> Y;
    for(int i=0; i<n; i++)
        Y.push_back(i+1);  // initially Y contains sequential indices (1 based)
    
    if(X == Y)
        return 0;

    // creating another vector for storing new arrangement after each second
    vector<int> Z(n);
    int ans = 1;
    while(X != Y){
        for(int i=0; i<n; i++)
            Z[X[i]-1] = Y[i];
        Y=Z;
        ans++;
    }

    return ans;
}


// 2 Optimized Solution
long long int monkeys(long long int a,long long int b)
{
  if(b==0)
    return a;
  else
    return monkeys(b,a%b);
}

long long int Grooving_Monkeys_2(vector<int> arr){
    long long int n = arr.size(), i=0;
    long long int res=1, c=0, te,te1;
    
    while(i<=n-1)
    {
        te1=i;
        c=0;
        while(arr[i]!=0)
        {
            te=i;
            i=arr[i]-1;
            arr[te]=0;
            c+=1;
        }
        i=te1+1;
        if(c!=0)
            res=res*c/monkeys(res,c);
    }
    return res;
}

int main(){
    vector<int> X = {1,2,3,4,5,6};
    
    cout<<"Min seconds required to arrange monkeys in initial position : "<<Grooving_Monkeys_2(X);

    return 0;
}