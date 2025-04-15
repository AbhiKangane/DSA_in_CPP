// https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>dist(V, 1e8);
        dist[src]=0;
        
        for(int i=0; i<V; i++){
            for(auto &it:edges){
                int u=it[0];
                int v=it[1];
                int w=it[2];
                if(dist[u]!=1e8 && dist[v]>dist[u]+w){
                    dist[v]=w+dist[u];
                }
            }
        }
        
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            if(dist[u]!=1e8 && dist[v]>w+dist[u]){
                return {-1};
            }
        }
        return dist;
    }
};

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int> > edges;

        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(V, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
