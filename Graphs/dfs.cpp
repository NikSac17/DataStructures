class Solution {
    
    private:
        void dfs(int vis[], vector<int> adj[], vector<int> &v, int node){
            vis[node]=1;
            v.push_back(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                    dfs(vis,adj,v,it);
                }
            }
        
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        vis[0]=1;
        vector<int> v;
        dfs(vis,adj,v,0);
        return v;
    }
};