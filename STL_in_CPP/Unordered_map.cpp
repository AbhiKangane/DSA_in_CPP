#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

// for insertion, deletion, searching
// TC in map is: O(log n)
// TC in unordered_map is: O(1)  

int main(){
    unordered_map<string, int> m;
    // map<string, int> m;

    // insertions
    // 1
    pair<string, int> p1 = make_pair("a", 1);
    m.insert(p1);

    // 2
    pair<string, int> p2("b", 2);
    m.insert(p2);

    // 3
    m["c"] = 3;
    // m["d"];

    // search
    // cout<<m["a"]<<endl;
    // cout<<m.at("a")<<endl;

    // cout<<m.at("unknown_key")<<endl;  // it'll give error at 1st time
    cout<<m["unknown_key"]<<endl;   // it makes new key with 0 value

    // iterator
    unordered_map<string, int> :: iterator it = m.begin();  // in this iterator will print pairs in reverse order of insertion of pairs
    // map<string, int> :: iterator it = m.begin();  // in this iterator will print pairs in alphabetical order of keys
    while(it != m.end()){
        cout << it->first << " : " << it->second << endl;
        it++;
    }
     
    return 0;
}
