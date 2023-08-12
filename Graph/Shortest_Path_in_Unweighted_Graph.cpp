#include<unordered_map>
#include<queue>
#include<list>
#include<iostream>
#include<algorithm>
using namespace std;

vector<int> Shortest_Path(vector<pair<int, int>> edges, int src, int dest){
    // create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        // here graph undirected
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // do BFS 
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(src);
    parent[src] = -1;
    visited[src] = 1;

    while (!q.empty()){
        int front = q.front();
        q.pop();

        for(auto i:adj[front]){
            if(!visited[i]){
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
        }
    }

    // prepare shortest path
    vector<int> ans;
    int currNode = dest;
    ans.push_back(dest);

    while (currNode != src){
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    
    reverse(ans.begin(), ans.end());

    return ans;
}



int main(){
/*   ______ 4 ___ 5 ___ 6
    |                   |
    1 ---- 2 -----------3
    |                   |
    !_____7__ 8 __9____10
*/

    vector<pair<int,int>> edges = {{1,2}, {1,4}, {1,7}, {2,3}, {3,6}, {3,10}, {4,5}, {5,6}, {7,8}, {8,9}, {9,10}};

    vector<int> sp = Shortest_Path(edges, 1, 3);

    for(int i=0; i<sp.size(); i++){
        cout<<sp[i]<<" ";
    }    

    return 0;
}