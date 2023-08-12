#include <iostream>
using namespace std;

// for sol : ballon  everywhere problem on gfg for finding number of times "balloon" letter form given string
int maxInstance(string s)
{

    int i, hash[26] = {0};
    // b-> hash[1], a->hash[0], l->hash['l'-97], o->hash['o'-97], n->hash['n'-97]
    for (i = 0; s[i] != '\0'; i++)
    {
        hash[s[i] - 97] += 1;
    }

    int N[100000];
    for (int i = 0; i < 100000; i++)
        N[i] = i + 1;

    int j = 0;
    int max = 0;
    while (j < 100000)
    {
        if (hash[0] >= (N[j] * 1) && hash[1] >= (N[j] * 1) && hash['n' - 97] >= (N[j] * 1) && hash['l' - 97] >= (N[j] * 2) && hash['o' - 97] >= (N[j] * 2))
            max = j + 1;
        j++;
    }

    return max;
}

string firstRepChar(string s)
{

    int i, H[26] = {0};
    for (i = 0; s[i] != '\0'; i++)
    {
        H[s[i] - 97] += 1;

        if (H[s[i] - 97] > 1)
        {
            cout << s[i];
            break;
        }
    }
    return '\0';
}

// strings are said anagram of each other if they contains same characters
int main()
{
    // string s="bnlbllanmbaamnmobbanablboolonlollllllll";
    // cout<<maxInstance(s);

    string str = "geeks";
    firstRepChar(str);
/*    
    char A[] = "dbbb", B[] = "bdbb";
    int i, H[26] = {0};
    for (i = 0; A[i] != '\0'; i++)
    {
        H[A[i] - 97] += 1;
    }

    for (i = 0; B[i] != '\0'; i++)
    {
        H[B[i] - 97] -= 1;
    }

    int flag = 1;
    for (i = 0; i < 26; i++)
    {
        if (H[i] != 0)
        {
            flag = 0;
            break;
        }
    }

    // for checking if string traverse till last(null character)
    if (flag == 1)
    {
        cout << "Its Anagram" << endl;
    }

    else
    {
        cout << "Not Anagram" << endl;
    }
*/
    return 0;
}