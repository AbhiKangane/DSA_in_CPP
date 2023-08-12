#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

void solve_dfs(int vertex, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component){
    // ans store
    component.push_back(vertex);
    visited[vertex]  = true;

    // recursive call for every vertex
    for(auto i: adj[vertex]){
        if(!visited[i])
            solve_dfs(i, visited, adj, component);
    }
}

vector<vector<int>> DFS(int v, int e, vector<vector<int>> &edges){
    // prepare adjList
    unordered_map<int, list<int>> adj;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    // for all vertices call DFS is not visited
    for(int i=0; i<v; i++){
        if(!visited[i]){
            vector<int> component;
            solve_dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    
    return ans;
}



int main(){
    vector<vector<int>> Edges {{0,1}, {1,2}, {1,3}, {1,4}, {3,4}, {2,4}, {4,5}};

    vector<vector<int>> dfs = DFS(6, 7, Edges);

    for(int i=0; i<dfs.size(); i++){
        for(int j=0; j<dfs[i].size(); j++){
            cout<<dfs[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}