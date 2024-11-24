#include<bits/stdc++.h>
using namespace std;

int MOD=1e9+7;

long long solve(int n, vector<int> &dp){
	
	if(n==0) return 1;
	if(n<0) return 0;

	if(dp[n]!=-1) return dp[n];

	long long ans=0;
	for(int i=1;i<=6;i++){
		ans=(ans+solve(n-i,dp))%MOD;
	}

	return dp[n]=ans%MOD;
}

int main(){
	int n;
	cin>>n;

	vector<int> dp(n+1,-1);

	cout<<solve(n,dp)%MOD<<endl;

}