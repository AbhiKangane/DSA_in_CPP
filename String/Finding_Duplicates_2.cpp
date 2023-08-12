#include <iostream>
using namespace std;

// for small alphabets ascii code range: 97-122
int main(){
    char str[] = "abhishek";
    long int H=0, x=0;
    int i,j;

    for(i=0; str[i] != '\0'; i++){ 
        x=1;
        x = x << (str[i] - 97);
        if((x & H) > 0){
            cout<<"letter '"<<str[i]<<"'"<<" is duplicated\n";
        }
        else
            H = x|H ;
    }

    return 0;
}