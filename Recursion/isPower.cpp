// for given n & x, we have to check that whether n = x^m , where 0 <= m

#include<iostream>
using namespace std;

bool solveRec(int n, int x){
    if(n==1)
        return true;
    if(n<=0 || n%x !=0)
        return false;

    solveRec(n/x, x);
}

bool solveIter(int n, int x){
    if(n<=0)
        return false;
    
    while(n){
        if(n==1)
            return true;
        if(n%x != 0)
            return false;
        n /= x;
    }
    
    return false;
}



int main(){
    cout<<solveRec(100, 10)<<endl;
    cout<<solveIter(100, 10);
}