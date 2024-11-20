// GFG Question : https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1
// An Eulerian Path is a path in graph that visits every edge exactly once. An Eulerian Circuit is an Eulerian Path which starts and ends on the same vertex. 
// Given an undirected connected graph with V nodes, and E edges, with adjacency list adj, return 2 if the graph contains an eulerian circuit, 
// else if the graph contains an eulerian path, return 1, otherwise, return 0.

class Solution {
public:
    void DFS(vector<int>adj[], int u, vector<bool>&visited){
        visited[u] = true;
        
        for(auto neighbour : adj[u]){
            if(visited[neighbour] == false){
                DFS(adj,neighbour,visited);
            }
        }
    }
    
    bool isConnected(int V, vector<int>adj[]){
        int non0DegVertex = -1;
        for(int i=0; i<V; i++){
            if(adj[i].size() != 0){
                non0DegVertex = i;
                break;
            }
        }
        vector<bool> visited(V,0); 
        // start DFS from non0DegVertex
        DFS(adj, non0DegVertex, visited);
        
        // check if all non-0 degree wale vertices are visited
        for(int i=0; i<V; i++){
            if(visited[i] == false && adj[i].size() > 0)
                return false;
        }
        
        return true;
    } 
    
	int isEulerCircuit(int V, vector<int>adj[]){
	   // check if all non-zero degree wale vertices are connected
	   if(isConnected(V,adj) == false)
	       return 0;    // neither EC nor EP
	   
	   // count odd degree wale vertices
	   int oddDegVertices = 0;
	   for(int i=0; i<V; i++){
	       if(adj[i].size() % 2)
	            oddDegVertices++;
	   }
	   
	   if(oddDegVertices > 2)
	        return 0;   // neither EC nor EP
	   else if(oddDegVertices == 2)
	        return 1;   // EP
	  
	   return 2;   // EC
	}
};
