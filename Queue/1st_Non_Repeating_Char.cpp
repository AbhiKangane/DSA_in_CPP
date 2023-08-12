#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

string first_Non_Repeating(string s){
    unordered_map<char,int> count;
    queue<int> q;
    string ans = "";

    for(int i=0; i<s.length(); i++){
        char ch = s[i];

        // increase count
        count[ch] ++;

        q.push(ch);

        while(!q.empty()){
            if(count[q.front()] > 1)
                q.pop(); // repeating char
            
            else{
                ans.push_back(q.front());  // non repeating char
                break;
            }
        }

        if(q.empty()){
            ans.push_back('#');
        }
    }
    return ans;
}

int main(){
    string st = "aabc";
    cout<<"1st non repeating char till each char: \n"<<first_Non_Repeating(st);
    
    return 0;
}