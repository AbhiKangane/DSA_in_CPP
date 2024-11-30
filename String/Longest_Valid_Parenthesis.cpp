// https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1
/*
Given a string str consisting of opening and closing parenthesis '(' and ')'. Find the length of the longest valid parenthesis substring.
A parenthesis string is valid if:
For every opening parenthesis, there is a closing parenthesis.
The closing parenthesis must be after its opening parenthesis.

Examples :
Input: str = ((()
Output: 2
Explaination: The longest valid parenthesis substring is "()".
*/

class Solution {
  public:
    int maxLength(string& str) {
        int mx=0,op=0,cl=0,mx2=0;
        // Left -> Right checking
        for(int i=0; i<str.length(); i++){
            if(str[i]=='(')
                op++;
            else 
                cl++;
            
            // if no. of ) is greater than no. of ( 
            if(cl>op)
                cl = op = 0;
            if(cl==op)
                mx=max(mx,op*2);
        }
        
        op=cl=0;
        // /Right -> Left checking 
        for(int i=str.length()-1; i>=0; i--){
            if(str[i]=='(')
                op++;
            else 
                cl++;
            
            // if no. of ( is greater than no. of ) 
            if(op>cl)
                op = cl = 0;
            if(op==cl)
                mx2=max(mx2,op*2);
        }
        return max(mx,mx2);
    }
};
