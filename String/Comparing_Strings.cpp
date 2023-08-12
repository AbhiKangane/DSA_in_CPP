#include <iostream>
using namespace std;

int main(){
    char str1[] = "Abhishek";
    char str2[] = "Abhinav";
    int i,j;
    for(i=0, j=0; str1[i] != '\0' && str2[j] !='\0'; i++,j++){
        if(str1[i] != str2[j])
            break;
    }
 
    if(str1[i] == str2[j])
        cout<<"Equal strings";

    else if(str1[i] <str2[j])
        cout<<"second string is larger";
        
    else    
        cout<<"first string is larger";
    
    return 0;
}