// this program converts uppercase string into lowercase string using char array(ascii codes 0-127)
// ASCII Codes: 1) for numbers 0,1,2,..,9 => 48,..,57
//              2) for Uppercase alphabets A,B,C,...,Z  => 65,...,90
//              3) for Lowercase alphabets a,b,c,...,z  => 97,...,122

#include <iostream>
using namespace std;

int main(){
    char str[] = "WELCOME ";
    int i;
    for(i=0; str[i] != '\0'; i++){
        str[i] += 32; 
    }
    cout<<str;
    return 0;
}