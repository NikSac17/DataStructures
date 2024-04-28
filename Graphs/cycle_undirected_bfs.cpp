class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool bfs(int src, vector<int> adj[], vector<int> vis){
        vis[src]=1;
        queue<pair<int,int>> q;
        q.push({src,-1});
        
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto it:adj[node]){
                //if node is unvisited
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,node});
                }
                // if node is visited and is not it's own parent node
                else if(it!=parent){
                    return true; //cycle detected
                }
            }
        }
        
        return false; //no cycle
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(bfs(i,adj,vis)) return true;
        }
        
        return false;
    }
};
