#include<bits/stdc++.h>
using namespace std;

vector<int> components; 

int get_Comp(int v, vector<vector<int>>&adj, vector<bool> &vis){
    if(vis[v])      // if vertex visited
        return 0;
    
    vis[v] = true;
    int ans = 1;

    for(auto i: adj[v]){
        if(!vis[i]){
            ans += get_Comp(i, adj, vis);
            vis[i] = true;
        }
    }
    return ans;
}

int main(){
    int n,m;
    cout<<"Enter no. of Vertices & Edges : ";
    cin>>n>>m;

    vector<vector<int>>adj(n);
    vector<bool> vis(n,false); 

    cout<<"Enter Edges :"<<endl;
    for (int i = 0; i < m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);     // graph is directed
    }

    for(int i=0; i<n; i++){
        if(!vis[i]){
            components.push_back(get_Comp(i,adj,vis));
        }
    }
    cout<<"No. of components "<<components.size()<<endl;
    cout<<"Printing components of graph with size"<<endl;
    for(auto i: components)
        cout<<i<<" ";

    long long NoOfWays = 0;
    for(auto i: components){
        NoOfWays = NoOfWays + i*(n-i);
    }
    NoOfWays /= 2;
    cout<<"\nNo. of ways of selecting components from different components : "<<NoOfWays;

    return 0;


    // 3 components : 0 1 2,  3 4, 5 6 7  == NoOfWays : 21
} 