#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<set>
using namespace std;

void prepareAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int,int>> &edges){
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void solve_bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int vertex){
    queue<int> q;
    q.push(vertex);
    visited[vertex] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        // store frontNode into ans
        ans.push_back(frontNode);

        // traverse all neighbours of frontNode
        for (auto i : adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        } 
    }
}

vector<int> BFS(int vertex, vector<pair<int,int>> edges){
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;

    prepareAdjList(adjList, edges);
    // traverse all components of graph
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            solve_bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}


int main(){
    vector<pair<int, int>> Edges = {{0,1}, {1,2}, {1,3}, {3,4}, {2,4}, {4,5}};

    vector<int> bfs = BFS(6, Edges);
    for(int i=0; i<bfs.size(); i++){
        cout<<bfs[i]<<" ";
    }

    return 0;
}