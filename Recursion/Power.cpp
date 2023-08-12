#include<iostream>
using namespace std;

int power(int x, int pow){
    if(pow == 0)
        return 1;
    
    else if(pow == 1)
        return x;
    
    else{
        if(pow % 2 == 0)
            return power(x, pow/2) * power(x, pow/2);
        
        else
            return x*power(x, pow/2) * power(x, pow/2);
    }
}

int main(){
    cout<<power(3,5);
    return 0;
}