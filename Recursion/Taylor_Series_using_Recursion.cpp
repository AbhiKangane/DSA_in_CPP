// TAYLOR SERIES: 
// f((x-a)+a) = f(a) + f'(a)*(x-a)/1! + f''(a)*(x-a)^2/2! + ...
// e^x = 1 + x/1 + x^2/2! + x^3/3! +....
//     = 1+x/1 {1+x/2 [1+x/3 (1+x/4 (...))]}

#include<iostream>
using namespace std;

// Method 1
double e(int x, int nterms){
    static double power=1, factorial=1;
    double r;
    if (nterms==0)
        return 1;

    r = e(x,nterms-1);
    power = power*x;
    factorial *= nterms;
    return r+power/factorial;
}

// Method 2
double e2(int x, int nterms){
    static double s;

    if (nterms==0)
        return s;

    s = 1+s*x/nterms;
    return e2(x,nterms-1);
}

// Method 3
double eIterative(int x, int nterms){
    double s=1, power=1, factorial=1;

    if (nterms==0)
        return 1;

    for(int i=1; i<=nterms; i++){
        power *= x;
        factorial *= i;
        s += power/factorial;
    }
    
    return s;
}


int main(){
    cout<<"e = "<<e(1,20)<<endl;
    cout<<"e^2 = "<<e2(2,20)<<endl;
    cout<<"e^3 = "<<eIterative(3,20)<<endl;

    return 0;
}