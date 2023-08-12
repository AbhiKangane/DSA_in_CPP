#include <iostream>
using namespace std;

int main(){
    char str[] = "WELCOME,  in  Aurangabad";
    int i, vc=0, cc=0, word=0;
    for(i=0; str[i] != '\0'; i++){
        
        if(str[i] == 'a' ||str[i] == 'A' ||str[i] == 'e' ||str[i] == 'E' ||str[i] == 'i' ||str[i] == 'I' ||str[i] == 'o' ||str[i] == 'O' ||str[i] == 'u' ||str[i] == 'U'){
            vc++;
        }
        else if((str[i]>65 && str[i]<90) || (str[i]>97 && str[i]<122)){
            cc++;
        }
        else if(str[i] == ' ' && str[i-1] != ' '){
            word++;
        }
    }
    cout<<"Vowel count: "<<vc<<"\nConsonant count: "<<cc<<"\nWords: "<<word+1;
    return 0;
}