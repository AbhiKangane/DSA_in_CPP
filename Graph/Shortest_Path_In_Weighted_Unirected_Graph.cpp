// diff bet Dijkstra Algo & Bellmon Ford Algo:
// Dijkstra Algo : Not work for negative weighted edges 
// Bellmon Ford Algo: work properly with negative edges in weighted undirected graph

#include<bits/stdc++.h>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges){
    vector<int> distance(n+1, 1e9);
    distance[src] = 0;

    
    for (int i = 1; i <= n; i++){
        for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if(distance[u] != 1e9 && (distance[u] + w < distance[v])){
                distance[v] = distance[u] + w;
            }
        }
    }

    // check for negative weighted edges
    bool flag = 0;
    for(int j=0; j<m; j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];

        if(distance[u] != 1e9 && (distance[u] + w < distance[v]))
            flag = 1;
    }    

    if(flag == 0)
        return distance[dest];

    return -1; 
}

int main(){
/*       2           3          5   
    1-----------3--------- 4--------- 5
    |                                |
  1 |                                |  -1
    |        6                 7     |
    0 ---------------- 2 ----------- 6

    Shortest path between 0 & 6 : 10
*/

    vector<vector<int>> edges = {{0, 1,1}, {0, 2,6}, {1, 3,2}, {2, 6,7}, {3, 4,3}, {4, 5,5}, {5, 6, -1}};

    int src = 0, dest = 6;
    int v = 7, e = 7;

    cout<<"Shortest path between "<<src<<" & "<<dest<<" : "<<bellmonFord(v, e, src, dest, edges);
}
