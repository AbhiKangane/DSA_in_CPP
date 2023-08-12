#include<iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];
}

void make_set(vector<int> &parent, vector<int> &rank, int n){
    for (int i = 0; i < n; i++){
        parent[i] = i;  // here consider every vertex is a parent itself
        rank[i] = 0;
    }
}

int find_Parent(vector<int> &parent, int node){
    if(parent[node] == node){
        return node;
    }

    return parent[node] = find_Parent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank){
    u = find_Parent(parent, u);
    v = find_Parent(parent, v);

    if(rank[u] < rank[v])
        parent[u] = v;
    
    else if(rank[u] > rank[v])  
        parent[v] = u;

    else{
        parent[v] = u;
        rank[u] ++;
    }
}

int Kruskals_MST(vector<vector<int>> &edges, int V){
    // sorting edges ascending order of weights
    sort(edges.begin(), edges.end(), cmp);

    vector<int> parent(V);
    vector<int> rank(V);
    make_set(parent, rank, V);

    int min_Weight = 0;

    for (int i = 0; i < edges.size(); i++){
        int u = find_Parent(parent, edges[i][0]);
        int v = find_Parent(parent, edges[i][1]);
        int wt = edges[i][2];

        if(u != v){
            min_Weight += wt;
            unionSet(u,v,parent, rank);
        }
    }
    return min_Weight;
}



int main(){
/*       2           3          4   
    1--------3----------- 4--------- 5
    |      /              |          |
  1 |  1 /             2 |           |  1
    |  /     6          |      7     |
     0 ---------------- 2 ----------- 6

    cost of MST : 12
*/

    vector<vector<int>> edges = {{0, 1,1}, {0, 2,6}, {0, 3,1}, {1, 3,2}, {2, 4,2}, {2, 6,7}, {3, 4,3}, {4, 5,4},
                                 {5, 6, 1}};
    
    cout<<"Cost of MST is: "<< Kruskals_MST(edges, 7);

    return 0;
}