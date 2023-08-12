// topological sort: It can't  apply on cyclic group
//          linear ordering of vertices such that for every edge(u,v),  u is always appears before the v
// this is find by using Kahn's algorithm
#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<queue>
#include<stack>
using namespace std;

// method 1. topological sort using dfs
void topoSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj){
    visited[node] = 1;

    for (auto neighbour: adj[node]){
         if(!visited[neighbour]){
            topoSort(neighbour, visited, s, adj);
         }
    }
    // insert nodes while returning into stack
    s.push(node); 
}

vector<int> topological_Sort(vector<vector<int>> &edges, int v, int e){
    // create adj list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v); // here graph is directed
    }

    // call dfs topoSort util function for all components
    vector<bool> visited(v);
    stack<int> s;
    for(int i=0; i<v; i++){
        if(!visited[i]) 
            topoSort(i, visited, s, adj);
    }
    
    vector<int> ans;
    while (!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}


// method 2: using indegree & parent vector
vector<int> Topological(vector<vector<int>> &edges, int v, int e){
    // create adj list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v); // here graph is directed
    }

    // find indegrees of all nodes
    vector<int> indegree(v);
    for(auto i : adj)
        for(auto j : i.second)
            indegree[j] ++;
    
    // push nodes having indegree 0 into queue
    queue<int> q;
    for (int i = 0; i < v; i++)
        if(indegree[i] == 0)
            q.push(i);
        
    // for other nodes do BFS
    vector<int> ans;
    while (!q.empty()){
        int front = q.front();
        q.pop();

        // ṣtore answer
        ans.push_back(front);

        // neighbour indegree update
        for(auto neighbour : adj[front]){
            indegree[neighbour] --;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }
    
    return ans;
}


int main(){
/*  2 -> 3 -> 4
    ^        ^
    |        |
    0 ----> 1

    topological sort: 
    1)  0, 1, 2, 3, 4
    2)  0, 2, 3, 1, 4
*/
    vector<vector<int>> edges = {{0,1}, {0,2}, {1,4}, {2,3}, {3,4}};

    int e=5, v=5;
    vector<int> ans = topological_Sort(edges, v, e);
    // vector<int> ans = Topological(edges, v, e); // not work properly

    for(int i=0; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}