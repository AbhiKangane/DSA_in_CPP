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
        // method 1 : O(N*M)
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

    // Method 2 : Rabin-Karp Algorithm 
    const int PRIME = 101;
    std::vector<int> findPatternOccurrences(const std::string &text, const std::string &pattern) {
        std::vector<int> result;
        int textLength = text.size();
        int patternLength = pattern.size();
    
        if (patternLength > textLength) return result;
    
        long long patternHash = 0, textHash = 0, h = 1;
    
        // Calculate the value of h as pow(PRIME, patternLength-1)
        for (int i = 0; i < patternLength - 1; ++i) {
            h = (h * PRIME);
        }
    
        // Calculate initial hash values for pattern and first window of text
        for (int i = 0; i < patternLength; ++i) {
            patternHash = (patternHash * PRIME + pattern[i]);
            textHash = (textHash * PRIME + text[i]);
        }
    
        // Slide the pattern over the text one by one
        for (int i = 0; i <= textLength - patternLength; ++i) {
            // If the hash values match, check for characters one by one
            if (patternHash == textHash) {
                if (text.substr(i, patternLength) == pattern) {
                    result.push_back(i + 1); // Convert to 1-based index
                }
            }
    
            // Calculate hash value for next window of text
            if (i < textLength - patternLength) {
                textHash = (textHash - text[i] * h) * PRIME + text[i + patternLength];
            }
        }
        return result;
    }
};
