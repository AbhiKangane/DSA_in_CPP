//  shortest path in DAG(Directed Acyclic Graph)
#include<stack>
#include<unordered_map>
#include<iostream>
#include<list>
#include<vector>

using namespace std;

class Graph{
    public:
    unordered_map<int, list<pair<int,int>>> adj;

    void addEdge(int u, int v, int weight){
        pair<int,int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printAdj(){
        cout<<"Printing adj list: \n";
        for(auto i: adj){
            cout<<i.first<<"->";  // printing initial vertex
            for(auto j: i.second){
                cout<<"("<<j.first<<","<<j.second<<"),";  // printing 2nd vertex & weight
            }
            cout<<endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo){
        visited[node] = 1;

        for(auto neighbour : adj[node]){
            if(!visited[neighbour.first])
                dfs(neighbour.first, visited, topo);
        }
        topo.push(node);   // pushing node into stack while returning, the stack stores topological sort of graph
    }

    void getShortest_Path(int src, vector<int> &dist, stack<int> &topo){
        dist[src] = 0;

        while (!topo.empty()){
            int top = topo.top();
            topo.pop();

            if(dist[top] != INT32_MAX)
                for(auto i: adj[top])
                    if((dist[top] + i.second) < dist[i.first])
                        dist[i.first] = dist[top] + i.second;
        }
    }
};



int main(){
/*       2           3          5   
    1----------> 3-------> 4--------> 5
    ^                                ^
  1 |                                |  -1
    |        6                 7     |
    0 ----------------> 2 ---------> 6
 
*/
    Graph g;
    g.addEdge(0, 1,1);
    g.addEdge(0, 2,6);
    g.addEdge(1, 3,2);
    g.addEdge(2, 6,7);
    g.addEdge(3, 4,3);
    g.addEdge(4, 5,5);
    g.addEdge(6, 5,-1);
    
    g.printAdj();

    int V = 7;

    // topological sort
    unordered_map<int, bool> visited;
    stack<int> s;
    for(int i=0; i<V; i++){
        if(!visited[i])
            g.dfs(i, visited, s);
    }

    int src = 1;
    vector<int> dist(V);

    // initialize distance between src node & other nodes equals to infinity or INT_MAX
    for(int i=0; i<V; i++)
        dist[i] = INT32_MAX;

    g.getShortest_Path(src, dist, s);

    cout<<"Shortest distance between src node & other nodes: "<<endl;
    for(int i=0; i<dist.size(); i++){
        if(dist[i]!=INT32_MAX)
            cout<<dist[i]<<" ";
        else
            cout<<"INF"<<" ";
    }

    return 0;
}
