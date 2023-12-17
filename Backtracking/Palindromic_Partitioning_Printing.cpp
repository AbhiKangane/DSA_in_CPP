// Problem : Given a String str, Find all possible Palindromic partitions of the given String.

#include<iostream>
#include<vector>
using namespace std;

class Palindromic_Partition_Printing{
    public:
    bool checkPalindrome(string& s)
    {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    // Recursive function which takes starting index idx & generates all substrings starting at idx.
    // If substring generated is palindrome it adds to current list and makes a recursive call for remaining  string.
    void Partition(vector<vector<string> >& res, string& s, int idx, vector<string>& curr)
    {
        // If we reach the end of string at the current list to the result.
        if (idx == s.size()) {
            res.push_back(curr);
            return;
        }
        // Stores the current substring.
        string str;
        for (int i = idx; i < s.size(); i++) {
            str.push_back(s[i]);

            // Check whether the string is palindrome or not.
            if (checkPalindrome(str)) {
                // Adds the string to current list
                curr.push_back(str);

                // Recursive call for the remaining string
                Partition(res, s, i + 1, curr);    // backtracking

                // Remove the string from the current string.
                curr.pop_back();  
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string S) {
        vector<vector<string>> ans;
        vector<string> curr;
        Partition(ans, S, 0, curr);
        
        return ans;
    }
};

int main(){
    string s1 = "ababbbabbababa";   
    string s2 = "abcdcba";   // a b c d c b a, a b cdc b a, a bcdcb a, abcdcba
    string s3 = "geeks";     // g e e k s, g ee k s

    vector<vector<string> > res;
    Palindromic_Partition_Printing obj;
 
    // Starting index of string
    int idx = 0;
 
    // Current list
    vector<string> curr;
    obj.Partition(res, s1, idx, curr);
    for (auto& v : res) {
        for (auto& it : v) {
            cout << it << " ";
        }
        cout << "\n";
    }

    cout<<"\n\n";
    vector<vector<string>> ans = obj.allPalindromicPerms(s1);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }


    // for optimal partition
    vector<string> minPartition_Palindromic_Substrings;
    int minSize = INT32_MAX;
    for(int i=0; i<ans.size(); i++){
        if(ans[i].size() < minSize){
            minSize = ans[i].size();
            minPartition_Palindromic_Substrings = ans[i];
        }
    }

    cout<<"\n\nPrinting 1st minimum Partition_Palindromic_Substrings : ";
    for(int i=0; i<minPartition_Palindromic_Substrings.size(); i++){
        cout<<minPartition_Palindromic_Substrings[i]<<" ";
    }

    cout<<"\n\nMinimum no. of cuts required to Partition a string into Palindromic_Substrings : "<<minPartition_Palindromic_Substrings.size()-1;
    cout<<"\n\nTotal no. of all possible Palindromic Partitions of string are: "<<ans.size()<<endl;

    return 0;
}