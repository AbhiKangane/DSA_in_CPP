#include<bits/stdc++.h>
using namespace std;

// codeStudio Question: using set
vector<int> dijkstra1(unordered_map<int, list<pair<int,int>>> &adj, int V, int src){
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

// LeetCode question : using Priority Queue
vector<int> dijkstra2(unordered_map<int, list<pair<int,int>>> &adj, int V, int S){
    // creating min_heap of pair(distance, node)
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> result(V, INT_MAX);
    
    result[S] = 0;
    pq.push({0,S});

    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto &v : adj[node]){
            int adjNode = v.first;
            int dist = v.second;

            if(d + dist < result[adjNode]){
                result[adjNode] = d+dist;
                pq.push({d+dist, adjNode});
            }
        }
    }
    return result;
}


int main(){
/*       2           3          5   
    1-----------3--------- 4--------- 5
    |                                |
  1 |                                |  1
    |        6                 7     |
    0 ---------------- 2 ----------- 6
 
*/
    int V=7, E=7;
    vector<vector<int>> edges = {{0, 1,1}, {0, 2,6}, {1, 3,2}, {2, 6,7}, {3, 4,3}, {4, 5,5}, {5, 6, 1}};

    // creating adj list : u->(v,w)
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i=0; i<E; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        // here graph is undirected
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int> dist1 = dijkstra1(adj,V,0); // if negative weight of edge present then algo not working 
    cout<<"Printing distance array from 0 as src node: "<<endl;

    for (int i = 0; i < dist1.size(); i++){
        cout<<dist1[i]<<" ";
    }
    
    vector<int> dist2 = dijkstra2(adj,V,0); // if negative weight of edge present then algo not working 
    cout<<"\nPrinting distance array from 0 as src node: "<<endl;

    for (int i = 0; i < dist2.size(); i++){
        cout<<dist2[i]<<" ";
    }
    
    return 0;
}
