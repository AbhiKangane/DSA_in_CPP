#include<iostream>
using namespace std;

// in this problem replace the 0 with 1 & vise versa of given number

int BitwiseComplement(int num){
    int m = num;
    int mask = 0;  // 00000000

    if(num == 0)
        return 1;


// following loop is for finding mask of numberplacing no. of 1s(equal to no. of main bits) at right side  
// ex. 5(00000101) => mask(00000111) 
    while(m != 0){
        mask = (mask << 1) | 1;  // left shift & placing 1 (by performing or)
        m = m >> 1;  // right shift 
    }
    int ans = (~num) & mask;  // not then and
    return ans;
}

int main(){
    cout<<BitwiseComplement(7)<<endl;  // 00000111 => 00000000 = 0
    cout<<BitwiseComplement(10)<<endl;  // 00001010 => 00000101 = 5
    
    return 0;
}