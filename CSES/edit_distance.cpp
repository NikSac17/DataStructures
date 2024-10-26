#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(string &s1, string &s2, int ind1, int ind2){
	if(ind1<0) return ind2+1; // will add all rem of s2 in s1
	if(ind2<0) return ind1+1; // will delete all in s1

	if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

	if(s1[ind1]==s2[ind2]) return dp[ind1][ind2]=solve(s1,s2,ind1-1,ind2-1);

	// else{
		int add=1+solve(s1,s2,ind1,ind2-1);
		int remove=1+solve(s1,s2,ind1-1,ind2);
		int replace=1+solve(s1,s2,ind1-1,ind2-1);

		return dp[ind1][ind2]=min({add,remove,replace});	
	// }
	
}

int main(){
	string s1,s2;
	cin>>s1;
	cin>>s2;

	int m=s1.length();
	int n=s2.length();

	dp.resize(m+1,vector<int>(n+1,-1));

	cout<<solve(s1,s2,m-1,n-1);

}