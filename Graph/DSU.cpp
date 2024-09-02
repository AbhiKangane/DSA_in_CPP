// To solve this problem we have to find different components of graph.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> parent, Rank, Size;

int find(int x){
    return (x == parent[x]) ? x : (parent[x] = find(parent[x]));
}

// Method 1: by using rank
void Union(int x, int y){
    int x_parent = find(x);
    int y_parent = find(y);

    if(x_parent == y_parent)
        return;

    if(Rank[x_parent] > Rank[y_parent])
        parent[y_parent] = x_parent;
    
    else if(Rank[x_parent] < Rank[y_parent])
        parent[x_parent] = y_parent;
    
    else{
        parent[x_parent] = y_parent;
        Rank[y_parent]++;
    }
}

// Method 2: using Size
void Union2(int x, int y){
    int x_parent = find(x);
    int y_parent = find(y);

    if(x_parent == y_parent)
        return;

    if(Size[x_parent] > Size[y_parent]){
        parent[y_parent] = x_parent;
        Size[x_parent] += Size[y_parent];
    }
    else if(Size[x_parent] < Size[y_parent]){
        parent[x_parent] = y_parent;
        Size[y_parent] += Size[x_parent];
    }
    else{
        parent[x_parent] = y_parent;
        Size[y_parent] += Size[x_parent];
    }
}

vector<vector<int>> all_Components(int n, vector<vector<int>> &edges){
    parent.resize(n);
    Rank.resize(n,0);
    Size.resize(n,1);

    for(int i=0; i<n; i++){
        parent[i] = i;
    }

    // making components
    for(auto &vec: edges){
        Union(vec[0], vec[1]);
        // Union2(vec[0], vec[1]);
    }

    // creating map: parent -> nodes of components
    unordered_map<int,vector<int>> mp;
    for(int i=0; i<n; i++){
        int father = find(i); // parent
        mp[father].push_back(i);
    }

    vector<vector<int>> ans;
    for(auto &it : mp)
        ans.push_back(it.second);

    return ans;
}

int main(){
/*
    0    2 --- 3 
    |    |             = ANS => 11
    1    4      5
*/
    vector<vector<int>> edges = {{0,1}, {2,3}, {2,4}};

    vector<vector<int>> ans = all_Components(6, edges);
    cout<<"Printing all Components:\n";
    for(auto &vec : ans){
        for(auto v: vec){
            cout<<v<<" ";
        }
        cout<<endl;
    }

    return 0;
}