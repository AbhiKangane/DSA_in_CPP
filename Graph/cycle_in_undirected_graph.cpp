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
            // if neighbour is already visited but not parent of src then cycle is present
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

// method 3: using DSU
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

bool is_Cyclic_DSU(int V, unordered_map<int, list<int>> &adj){
    parent.resize(V);
    Rank.resize(V,1);

    for(int i=0; i<V; i++)
        parent[i] = i;

    for(auto &pairs : adj){
        int u = pairs.first;
        for(int &v : pairs.second){
            if(u < v){
                int u_parent = find(u);
                int v_parent = find(v);

                if(u_parent == v_parent)
                    return 1;
                
                Union(u,v);
            }
        }
    }
    return 0;
}

string cycle_Detection(vector<vector<int>> &edges, int V, int E){
    // create adj list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<E; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // by using DSU
    return (is_Cyclic_DSU(V, adj) == 1) ? "YES" : "NO";


    // to handle disconnected components
    // unordered_map<int, bool> visited;
    // for(int i=0; i<V; i++){
    //     if(!visited[i]){
    //         // bool ans = is_Cyclic_BFS(i, visited, adj);
    //         bool ans = is_Cyclic_DFS(i, -1, visited, adj);
    //         if(ans == 1)
    //             return "Yes";
    //     }
    // }
    // return "No";
}


int main(){
    vector<vector<int>> Edges {{0,1}, {1,2}, {2,3}, {3,4}, {0,4}, {4,5}};

    cout<<"Is given graph contains cycle: "<<cycle_Detection(Edges, 6, 6);

    return 0;
}
