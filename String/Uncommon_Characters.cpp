#include <bits/stdc++.h>
using namespace std;


// this function not work properly for if any string contains repeated characters
string UncommonChars(string A, string B)
{
    // code here
    int count[26] = {0};
    for (int i = 0; i < A.length(); i++)
    {
        count[A[i] - 'a'] = 1;
    }

    for (int i = 0; i < B.length(); i++)
    {
        if(count[B[i]-'a'] == 1 || count[B[i]-'a'] == -1)
            count[B[i] - 'a'] = -1;
        
        else
            count[B[i] - 'a'] = 2;
    }

    bool flag = false;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] == 1 || count[i] == 2)
        {   
            flag = true;
            cout <<char(i +'a')<<" ";
        }
    }

    if(flag == true)
        return "";
    else
        return "-1";
}

int main() {
    
    // string str1 = "aabccdefgefg" , str2 = "efefgxyyz";
    string str1 = "geeksforgeeks" , str2 = "geeksquiz";
    
    cout << UncommonChars(str1, str2);
    return 0;
}