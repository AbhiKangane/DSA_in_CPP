#include <iostream>
using namespace std;

// for small alphabets ascii code range: 97-122
int main(){
    char str[] = "abhishek";
    int Hash[26]={0};
    int i,j;


    for(i=0; str[i] != '\0'; i++){
        Hash[str[i] - 97] += 1;
    }

    // for checking Hash array
    // for(i=0; i<26; i++){
        // cout<<Hash[i];
    // }

    for(i=0; i<26; i++){
        if(Hash[i] > 1){
            // cout<<"letter "<<i+97<<" repeated "<<Hash[i]<<" times"<<endl;
            printf("Letter '%c' is repeated %d times\n", i+97, Hash[i]);
        }
    }

    return 0;
}