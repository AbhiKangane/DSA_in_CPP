// Articulation Point in graph: it is a vertex in graph which, when removed graph becomes disconnected

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, 
    unordered_map<int, list<int>> &adj, vector<int> &ap, int &timer){
    
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for(auto nbr: adj[node]){
        if(nbr == parent)
            continue;
        
        if(!vis[nbr]){
            dfs(nbr, node, disc, low, vis, adj, ap, timer);
            low[node] = min(low[node], low[nbr]);

            // check vertex is ap or not
            if(low[nbr] >= disc[node] && parent != -1)
                ap[node] = 1;
        }

        else{
            low[node] = min(low[node], disc[nbr]);
        }
    }
    if(parent == -1 && child>1)
        ap[node] = 1;
}


int main(){
/*
    0-----1------3-----4
     \   /        \   
      \ /          \ 
       2            5

    ap : 1, 3
*/
    vector<pair<int, int>> edges = {{0,1}, {0,2}, {1,2}, {1,3}, {3,4}, {3,5}};
    int v = 6;

    // creating adj list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> vis;
    vector<int> ap(v, 0);
    int parent = -1;

    // dfs()
    for (int i = 0; i < v; i++)
        if(!vis[i])
            dfs(i, parent, disc, low, vis, adj, ap, timer);
    
    // print ap
    cout<<"Articulation points in the graph as follows: "<<endl;
    for (int i = 0; i < ap.size(); i++){
        if(ap[i] != 0)
            cout<<i<<" ";
    }
     
    return 0;
}