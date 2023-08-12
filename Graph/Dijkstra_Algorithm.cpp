// codeStudio Question

#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &edges, int V, int E, int src){
    // creating adj list
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i=0; i<E; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        // here graph is undirected
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    // creating distance array with infinite values initially
    vector<int> dist(V);
    for(int i=0; i<V; i++){
        dist[i] = INT_MAX;
    }

    // creation of set of the pairs(distance, node)
    set<pair<int, int>> st;
    
    dist[src] = 0;
    st.insert(make_pair(0,src));  // inserting 1st pair into set

    while (!st.empty()){
        // fetch the top record
        auto top = *(st.begin());

        int node_Dist = top.first;
        int top_Node = top.second;

        // remove top record
        st.erase(st.begin());

        // traverse all neighbours (BFS)
        for(auto neighbour : adj[top_Node]){
            if((node_Dist + neighbour.second) < dist[neighbour.first]){
                
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                // if record found then erase it
                if(record != st.end())
                    st.erase(record);
                
                // update the distance
                dist[neighbour.first] = node_Dist + neighbour.second;

                // push record in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}

int main(){
/*       2           3          5   
    1-----------3--------- 4--------- 5
    |                                |
  1 |                                |  1
    |        6                 7     |
    0 ---------------- 2 ----------- 6
 
*/

    vector<vector<int>> edges = {{0, 1,1}, {0, 2,6}, {1, 3,2}, {2, 6,7}, {3, 4,3}, {4, 5,5}, {5, 6, 1}};

    vector<int> dist = dijkstra(edges, 7, 7, 0); // if negative weight of edge present then algo not working 

    cout<<"Printing distance array from 0 as src node: "<<endl;

    for (int i = 0; i < dist.size(); i++){
        cout<<dist[i]<<" ";
    }
    
    return 0;
}