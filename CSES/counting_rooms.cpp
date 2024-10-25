#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<char>> &v, vector<vector<int>> &vis){

	int n=v.size();
	int m=v[0].size();
	vis[row][col]=1;

	int dx[]={0,-1,0,1};
	int dy[]={-1,0,1,0};

	for(int i=0;i<4;i++){
		int nrow=row+dx[i];
		int ncol=col+dy[i];

		bool cond=(nrow>=0 && nrow<n && ncol>=0 && ncol<m && v[nrow][ncol]=='.' && vis[nrow][ncol]==0);
		if(cond){
			dfs(nrow,ncol,v,vis);
		}
	}
}

int main(){
	int n,m;
	cin>>n;
	cin>>m;

	vector<vector<char>> v(n,vector<char>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>v[i][j];
		}
	}

	int cnt=0;
	vector<vector<int>> vis(n,vector<int>(m,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i][j]=='.' && vis[i][j]==0){
				dfs(i,j,v,vis);
				cnt++;
			}
		}
	}

	cout<<cnt<<endl;
}