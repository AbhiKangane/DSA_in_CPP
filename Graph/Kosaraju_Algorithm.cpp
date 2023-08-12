// Kosaraju's algorithm: It is used for counting strongly connected components

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj){
    vis[node] = true;
    for(auto nbr: adj[node]){
        if(!vis[nbr])
            dfs(nbr, vis, st, adj);
    }

    // topo logic
    st.push(node);
}

void revDFS(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj){
    vis[node] = true;

    for(auto nbr: adj[node]){
        if(!vis[nbr])
            revDFS(nbr, vis, adj);
    }
}

int strongly_connected_components(int v, vector<vector<int>> &edges){
    // creating adj list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        // here graph is directed
        adj[u].push_back(v);
    }
    
    // topo sort
    stack<int> st;
    unordered_map<int, bool> vis;
    for(int i=0; i<v; i++){
        if(!vis[i]) 
            dfs(i, vis, st, adj);
    }
    
    // create transpose graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++){
        vis[i] = 0;
        for (auto nbr: adj[i]){
            transpose[nbr].push_back(i);
        }   
    }
    
    // dfs call using above ordering
    int count = 0;
    while (!st.empty()){
        int top = st.top();
        st.pop();
        if(!vis[top]){
            count++;
            revDFS(top, vis, transpose);
        }
    }
    
    return count;
}

int main(){
/*
    0 <---> 1 ----> 3 ----> 4
     \\   //      
      \\ //        
        2            

    strongly_connected_components = {0,1,2}, {3}, {4}
*/
    vector<vector<int>> edges = {{0,1}, {0,2}, {1,0}, {1,2}, {2,0}, {2,1}, {1,3}, {3,4}};
    int vertices = 5;

    cout<<strongly_connected_components(vertices, edges);
    return 0;
}