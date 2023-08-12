#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

// method 1
class graph{
    public:
    unordered_map<int, list<int>> adj_list;

    void add_Edge(int u, int v, bool direction){
        // create edge bet u & v
        adj_list[u].push_front(v);

        if(direction == 0)  // if undireceted 
            adj_list[v].push_back(u);
    }

    void Print_AdjList(){
        cout<<"\nPrinting adjacency list of graph: \n";
        for(auto i : adj_list){
            cout<<i.first<<"->";
            for(auto j : i.second){
                cout<<j<<", ";
            }

            cout<<endl;
        }
    }
};

// method 2
vector<vector<int>> printAdjacency(int v, int e, vector<vector<int>> &edges){
    vector<int> ans[v];
    // ans stores all adjacency nodes of corresponding vertices
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>> adj(v);
    for(int i=0; i<v; i++){
        adj[i].push_back(i);

        for(int j=0; j<ans[i].size(); j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}



int main(){
    // int v, e;
    // cout<<"Enter the no. of vertices & edges: ";
    // cin>>v>>e;

    // graph g;
    // cout<<"Enter end vertices of edges: "<<endl;
    // for(int i=0; i<e; i++){
    //     int u, v;
    //     cin >> u >> v;
    //     // creating an undirected graph
    //     g.add_Edge(u, v, 0);
    // }

    // // printing graph
    // g.Print_AdjList();


// for method 2
    vector<vector<int>> Edges {{1,2}, {0,3}, {2,3}, {3,1}};
    vector<vector<int>> Adj_Matrix = printAdjacency(4, 4, Edges);
    for(int i=0; i<Adj_Matrix.size(); i++){
        for(int j=0; j<Adj_Matrix[i].size(); j++)
            cout<<Adj_Matrix[i][j]<<" ";
        
        cout<<endl;
    }

    return 0;
}