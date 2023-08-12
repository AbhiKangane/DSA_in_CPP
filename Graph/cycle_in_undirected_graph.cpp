#include<iostream>
#include<queue>
#include<unordered_map>
#include<list>
using namespace std;

// method 1: using BFS
bool is_Cyclic_BFS(int src, unordered_map<int,bool> &visited, unordered_map<int,list<int>> &adj){
    unordered_map<int,int> parent;

    parent[src] = -1;  // starting vertex parent -1
    visited[src] = 1;
    queue<int> q;
    q.push(src);

    while( !q.empty() ){
        int front = q.front();
        q.pop();

        for(auto neighbour: adj[front]){
            if(visited[neighbour] == true && neighbour != parent[front])
                return true;
            
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}

// method 2: using DFS
bool is_Cyclic_DFS(int vertex, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj){
    visited[vertex] = true;
    for(auto neighbour: adj[vertex]){
        if(visited[neighbour] == true && neighbour != parent)
                return true;
        
        else if(!visited[neighbour]){
            bool cycleDetected = is_Cyclic_DFS(neighbour, vertex, visited, adj);
            if(cycleDetected)
                return true;
        }
    }
    return false;
}


string cycle_Detection(vector<vector<int>> &edges, int V, int E){
    // crete adj list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<E; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to handle disconnected components
    unordered_map<int, bool> visited;
    for(int i=0; i<V; i++){
        if(!visited[i]){
            // bool ans = is_Cyclic_BFS(i, visited, adj);
            bool ans = is_Cyclic_DFS(i, -1, visited, adj);
            if(ans == 1)
                return "Yes";
        }
    }
    return "No";
}


int main(){
    vector<vector<int>> Edges {{0,1}, {1,2}, {2,3}, {3,4}, {0,4}, {4,5}};

    cout<<"Is given graph contains cycle: "<<cycle_Detection(Edges, 5, 6);

    return 0;
}