//Intution - if visited but not via parent node means cycle
class Solution {
  public:
    bool dfs(int node, int parent, vector<int> adj[], vector<int> vis){
        vis[node]=1;
        
        for(auto it:adj[node]){
            //unvisited adjacent node
            if(!vis[it]){
                if(dfs(it,node,adj,vis)) return true;
            }
            // visited node but not a parent node
            else if(it!=parent){
                return true;
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(dfs(i,-1,adj,vis)) return true;
        }
        
        return false;
    }
}