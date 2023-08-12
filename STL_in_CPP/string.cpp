#include<iostream>
#include<string> // diffrent from string.h header file
#include<string.h>
#include<algorithm>

using namespace std;

int main(){
    char s[] = "Hello";
    // s = "Abhishek"; // this will gives error. Also wee can't apply assignment operators & various string opertions on char array 
    // strcpy(s, "Abhishek"); // for using this string functions on char array #include<string.h> header file

    string S1;
    string S2 = s;
    string S3 = S2;

    string num="3574214";
    int n = stoi(num); //string to integer
    // cout<<n;

    sort(num.begin(), num.end(), greater<int>()); //gives largest number form by digits
    // cout<<num<<endl;

    S1 = " Abhishek ";
    transform(S1.begin(), S1.end(), S1.begin(), :: toupper); //converting a string to uppercase
    transform(S1.begin(), S1.end(), S1.begin(), :: tolower); //converting a string to lowercase
    // cout<<S1;
    S3 = S1 + S2;
    S2 += S1;
    // cout<<S1<<endl<<S2<<endl<<S3<<endl;

// mixed opoeration
    string mix = s + S1; //char array concatenated with string
    // cout<<mix;

    string s1;
    s1.assign("hi");
    cout<<s1<<endl;
    
    S1.append(" xyz");
    cout<<S1<<endl;
    
    s1.insert(0, "123 "); //insert(inndex, replaced_string)
    cout<<s1<<endl;
    
    s1.replace(0, 3, "Abhishek"); // replace(start_index, length, replaced_string)
    cout<<s1<<endl;

    s1.erase();
    cout<<s1<<endl;

    string state = "hello, guys";
    int i = state.find("l"); //gives 1st occurrence of required string
    int j = state.rfind("l"); //gives last occurrence of required string
    cout<<i<<endl;
    cout<<j<<endl;

    char str[100];
    strcpy(str, state.c_str());
    cout<<str<<endl;

    int size = state.size();
    cout<<size<<endl;
}