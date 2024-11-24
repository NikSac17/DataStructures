#include<bits/stdc++.h>
using namespace std;

int MOD=1e9+7;

void bfs(int src, vector<int> adj[], vector<int> &vis, vector<int> &path){
	int n=vis.size()-1;
	queue<int> q;
	q.push(src);
	vector<int> dist(n+1,-1);
	vector<int> parent(n+1,-1);

	dist[src]=1;
	vis[src]=1;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(auto x:adj[node]){
			if(!vis[x]){
				vis[x]=1;
				dist[x]=1+dist[node];
				q.push(x);
				parent[x]=node;
			}
		}
	}

	if(vis[n]==0){
		cout<<"IMPOSSIBLE"<<endl;
		return;
	}

	
	int node=n;
	while(node!=-1){
		path.push_back(node);
		node=parent[node];
	}

	reverse(path.begin(),path.end());
	cout<<path.size()<<endl;
	for(auto x:path){
		cout<<x<<" ";
	}
	cout<<endl;
}

void solve(int n, vector<vector<int>> &connection){
	vector<int> adj[n+1];
	for(auto c:connection){
		int u=c[0];
		int v=c[1];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> vis(n+1,0);
	vector<int> path;
	bfs(1,adj,vis,path);
	// cout<<vis[n-1];
}

int main(){
	int n,m;
	cin>>n>>m;

	vector<vector<int>> connection;

	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		vector<int> tmp;
		tmp.push_back(x);
		tmp.push_back(y);
		connection.push_back(tmp);
	}

	solve(n,connection);

}