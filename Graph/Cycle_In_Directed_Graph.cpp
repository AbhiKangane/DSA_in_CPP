#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

// method 1: using DFS
bool check_Cycle_DFS(int vertex, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsVisited, 
                     unordered_map<int,list<int>> &adj){
    visited[vertex] = true;
    dfsVisited[vertex] = true;

    for(auto neighbour: adj[vertex]){
        if(!visited[neighbour]){
            bool cycle_Detected = check_Cycle_DFS(neighbour, visited, dfsVisited, adj);
            if(cycle_Detected)
                return true;
        }
        else if(dfsVisited[neighbour]){
            return true;
        }
    }

    dfsVisited[vertex] = false;
    return false;
}

bool cycle_In_Directed_Graph(int n, vector<pair<int,int>> &edges){
    // create adj list
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
    }

    // call for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for(int i=1; i<=n; i++){
        if(!visited[i]){
            bool cycle_Found = check_Cycle_DFS(i, visited, dfsVisited, adjList);
            if(cycle_Found)
                return true;
        }
    }
    return false;
}


// method 2: using indegree
int Detect_Cycle_In_Directed_Graph(int v, vector<pair<int,int>> &edges){
    // create adj list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first - 1;     // here nodes starts from 1
        int v = edges[i].second - 1;

        adj[u].push_back(v);
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
    int cnt = 0;
    while (!q.empty()){
        int front = q.front();
        q.pop();

        // increment count
        cnt++;

        // neighbour indegree update
        for(auto neighbour : adj[front]){
            indegree[neighbour] --;
            if(indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    if(cnt == v)
        return false;
    
    else    
        return true;
}



int main(){
    // vector<pair<int, int>> Edges = {{0,1}, {1,2}, {2,3}, {3,4}, {4,6}, {4,5}};
    // if(cycle_In_Directed_Graph(6, Edges))
    //     cout<<"Cycle is present"<<endl;

    // else
    //     cout<<"Cycle is not present"<<endl;


    vector<pair<int, int>> Edges2 = {{1,2}, {2,3}, {3,4}, {4,1}, {4,5}};

    if(Detect_Cycle_In_Directed_Graph(5, Edges2)) // nodes starts from 1
        cout<<"Cycle is present"<<endl;

    else
        cout<<"Cycle is not present"<<endl;
    
    return 0;
}