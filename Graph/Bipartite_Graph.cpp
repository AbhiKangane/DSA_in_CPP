// Bipartite Graphs: https://leetcode.com/problems/is-graph-bipartite/
// 1. Its vertices can be divided into 2 disjoint & independent sets U & V such that every edge connects a vertex in U to  one in V
// 2. Graph doesn't contain any odd length cycles
// 3. The graph is 2 colorable

#include<bits/stdc++.h>
using namespace std;

bool checkBFS(vector<vector<int>> &adj, int node, vector<int>&color, int currColor){
    queue<int> q;
    q.push(node);
    color[node] = currColor;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int &v : adj[u]){
            if(color[v] == color[u])
                return false;
            else if(color[v] == -1){ // never colored or visited
                color[v] = 1 - color[u]; // if color[u]=1,0 => color[v]=0,1
                q.push(v);
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<int> color(V,-1);  // all vertices are uncolored / unvisited

    // red:1, green:0
    for(int i=0; i<V; i++){
        if(color[i] == -1){
            if(!checkBFS(adj,i,color,1))
                return false;
        }
    }
    return true;
}

int main(){
    // not bipartite
    vector<vector<int>> adj1 = {{1,2,3},{0,2},{0,1,3},{0,2}};
    // bipartite
    vector<vector<int>> adj2 = {{1,3},{0,2},{1,3},{0,2}};

    if(isBipartite(adj2))
        cout<<"Graph is bipartite"<<endl;
    else
        cout<<"Graph is not bipartite"<<endl;
}
