#include <iostream>
using namespace std;

// recursive reverse string
void reverse(string str, int s, int e){
    // base case
    if(s > e) 
        return ;
    
    swap(str[s], str[e]);

    // reverse string call 
    reverse(str, s+1, e-1);
}


bool checkPalindrome(string str, int s, int e){
    // base case
    if(s > e) 
        return true;
    
    if(str[s] != str[e])
        return false;

    else
        checkPalindrome(str, s+1, e-1);
}



int main(){
    char str[] = "EMOCOME";
    int i, j;
    
    for(i=0; str[i] != '\0'; i++){ }

    /*Method 1*/
    
    // char B[i]; // i=7
    // i=i-1;
    // for(j=0; i>=0; i--, j++){
    //     B[j] = str[i];
    // }
    // B[j] = '\0';
    // cout<<B;

    /*Method 2*/
    // j=i-1;
    // for(i=0; i<j; i++, j--){
    //     char temp = str[i];
    //     str[i] = str[j];
    //     str[j] = temp;
    // }
    // cout<<str;

    // reverse(str, 0, 6);
    cout<<"Is string Palindrome: "<<checkPalindrome(str, 0, 6);

    return 0;
}