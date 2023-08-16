// Bipartite Graphs: 
// 1. Its vertices can be divided into 2 disjoint & independent sets U & V such that every edge connects a vertex in U to  one in V
// 2. Graph doesn't contain any odd length cycles
// 3. The graph is 2 colorable

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<int> col;
bool biPart = true;

void color(int u, int curr){
    if(col[u] != -1 and col[u] != curr){   // if vertex u is same colored with neighbour vertex or connected vertex
        biPart = false;
        return;
    }
    col[u] = curr;                        // giving color to vertex 
    if(vis[u])                            // if vertex u already visited
        return;
    vis[u] = true;
    for(auto i: adj[u]){
        color(i, curr ^ 1);               // checking for all vertex
    }
}

int main(){
    int n,m;
    cout<<"Enter no. of Edges & Vertices : ";
    cin>>n>>m;

    adj = vector<vector<int>>(n);
    vis = vector<bool>(n,false); 
    col = vector<int>(n,-1); 

    for (int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);     // graph is directed
    }

    for(int i=0; i<n; i++){
        if(!vis[i]){
            color(i,0);
        }
    }
    if(biPart)
        cout<<"Graph is bipartite"<<endl;
    else
        cout<<"Graph is not bipartite"<<endl;
}