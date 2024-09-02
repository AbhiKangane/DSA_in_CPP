// To solve this problem we have to find size of each component of graph.
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// DSU ka code : find() & Union() functions
vector<int> parent;
vector<int> Rank;

int find(int x){
    return (x == parent[x]) ? x : (parent[x] = find(parent[x]));
}

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

long long countPairs(int n, vector<vector<int>> &edges){
    parent.resize(n);
    Rank.resize(n,0);

    for(int i=0; i<n; i++){
        parent[i] = i;
    }

    // making components
    for(auto &vec: edges){
        Union(vec[0], vec[1]);
    }

    // creating map: parent(component) -> size of components
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        int father = find(i); // parent
        mp[father]++;
    }

    // finding result
    long long result = 0, remainingNodes = n;
    for(auto &it: mp){
        long long size = it.second;

        result += (size) * (remainingNodes - size);
        remainingNodes -= size;
    }

    return result;
}

int main(){
/*
    0    2 --- 3 
    |    |             = ANS => 11
    1    4      5
*/
    vector<vector<int>> edges = {{0,1}, {2,3}, {2,4}};

    cout<<"Ans: "<<countPairs(6, edges);

    return 0;
}