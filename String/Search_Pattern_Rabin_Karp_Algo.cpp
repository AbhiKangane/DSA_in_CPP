// https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1
/*
Given two strings, one is a text string and the other is a pattern string. The task is to print the starting indexes of all the occurrences of the pattern string 
in the text string. For printing, the Starting Index of a string should be taken as 1. The strings will only contain lowercase English alphabets ('a' to 'z').

Input:
text = "geeksforgeeks"
pattern = "geek"
Output: 
[1, 9]
Explanation: 
The string "geek" occurs twice in text, one starts are index 1 and the other at index 9.
*/

class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            vector<int> ans;
            int pSize = pattern.size();
            int n = text.size();
            for(int i=0; i<n-pSize+1; i++){
                int j=i, k=0;
                while(j < i+pSize){
                    if(text[j] != pattern[k])
                        break;
                    j++;
                    k++;
                }
                // if pattern == text
                if(j==i+pSize)
                    ans.push_back(i+1);
            }
            return ans;
        }
};
