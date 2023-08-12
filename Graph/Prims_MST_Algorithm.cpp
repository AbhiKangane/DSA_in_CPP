#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>

using namespace std;

vector<pair<pair<int, int>, int>> Calculate_Prims_isMST(int V, vector<pair<pair<int, int>, int>> &edges){

    // creating adj list
    unordered_map<int, list<pair<int,int>>> adj;
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int w = edges[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
    // here nodes starts from 1
    vector<int> cost(V+1);
    vector<bool> isMST(V+1);
    vector<int> parent(V+1);

    for (int i = 0; i <= V; i++){
        cost[i] = INT32_MAX;
        parent[i] = -1;
        isMST[i] = false;
    }
    
    // starting of algorithm
    cost[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < V; i++){
        int mini = INT32_MAX;
        int u;

        // find min valued node
        for (int v = 1; v <= V; v++){
            if(isMST[v] == false && cost[v] < mini){
                u=v;
                mini = cost[v];
            }
        }
        // mark min node as true
        isMST[u] = true;

        // check its adjacent nodes
        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;

            if(isMST[v] == false && w<cost[v]){
                parent[v] = u;
                cost[v] = w;
            }
        }
    }
    
    vector<pair<pair<int,int>,int>> result;
    for(int i=2; i<=V; i++){
        result.push_back({{parent[i], i}, cost[i]});
    }

    return result;
}

int main(){
/*       2           3          5   
    2-----------4--------- 5--------- 6
    |                     |           |
  1 |                  2 |           |  1
    |        6          |      7     |
    1 ---------------- 3 ----------- 7
 
*/
// {{src, dest}, cost}     here, src < dest
    vector<pair<pair<int, int>, int>> edges = {{{1, 2},1}, {{1, 3},6}, {{2, 4},2}, {{4, 5},3}, {{5, 3},2}, 
                                                {{5, 6},5}, {{6, 7},1}, {{7, 3},7}};

    vector<pair<pair<int, int>, int>> ans = Calculate_Prims_isMST(7, edges);

    cout<<"Printing Edges included in isMST :"<<endl;
    for(int i=0; i<ans.size(); i++){
        int u = ans[i].first.first;
        int v = ans[i].first.second;
        int w = ans[i].second;

        cout<<"{ ("<<u<<","<<v<<"), "<<w<<" }"<<endl;
    }

    return 0;
}