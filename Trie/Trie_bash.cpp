// From given arr[N], we have to find out maximum value of (arr[a]^arr[a+1]...^arr[b]) + (arr[c]^arr[c+1]...^arr[d]),
// where 1 <= a <= b < c <= d <= N & '^' denotes XOR operation (in this same bits produce 0 while diff. bits produces 1)

// ex : arr[] = {1,2,6,8};
// 1^2 = (01) ^ (10) = (11) = 3
// 6^8 = (0110) ^ (1000) = (1110) = 14
// ans = 3 + 14 = 17
 
#include<bits/stdc++.h>
using namespace std;

int int_size = 32;

class Node{
    public:
    Node *next[2];

    Node(){
        next[0] = NULL;  // if cur_bit is 0 act as left
        next[1] = NULL;  // if cur_bit is 1 act as right
    }
};

Node *trie;

// function for inserting word into trie
void insert(int num){
    Node* it = trie;

    for (int i = int_size-1; i>=0; i--){
        int cur_bit = (num>>i) & 1;
        if(!it->next[cur_bit]){
            it->next[cur_bit] = new Node();
        }
        it = it->next[cur_bit];
    }
}

// fuction for query
int query(int num){
    Node *it = trie;
    int ans = 0;
    for (int i = int_size-1; i >= 0; i--){
        int cur_bit = (num>>i) & 1;

        int opposite = cur_bit xor 1;
        if(it->next[opposite]){
            it = it->next[opposite];
            ans |= 1<<i; // opposite bits gives maximum XOR Hence adding contribution to ans while going in oppposite direction
        }
        else{
            it = it->next[opposite ^ 1];  // if going same direction
        }
    }
    return ans;
}

int32_t main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    cout<<"Enter numbers in array: ";
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin>>v[i];
    }

    trie = new Node();    // creating trie
    insert(0);
    vector<int> rmax(n+1, 0);
    int R = 0;
    for (int i = n-1; i >= 0; i--){
        R = R xor v[i];     // calculates XOR from rightmost number
        if(i != n-1){
            rmax[i] = max(rmax[i+1], query(R));  // query(R) gives max. XOR subarray from i to N
            insert(R);
        }
        else{
            rmax[i] = query(R);
            insert(R);
        }
    }
    
    free (trie);
    trie = new Node();    // creating trie
    insert(0);
    int ans = 0;
    int L = 0;
    for (int i = 0; i < n; i++){
        L = L xor v[i];     // calculates XOR from leftmost number
        ans = max(ans, (rmax[i+1] + query(L)));  // query(L) gives max. XOR subarray from 0 to i 
        insert(L);
    }

    cout<<ans;

    return 0;

}