#include<iostream>
#include<vector>
#include<queue>
using namespace std;
long long int ans=0;
void dfs(vector< vector<long long int> > &graph, long long int root, long long int *visit, long long int *dp){
	long long int i;
	visit[root]=1;
	for(i=0;i<graph[root].size();i++){
		if(visit[graph[root][i]]==0){
			dfs(graph,graph[root][i],visit,dp);
			dp[root] = dp[root]*(dp[graph[root][i]]+1);
			dp[root] = dp[root]%1000000007;
		}
	}
	ans += dp[root];
	ans = ans % 1000000007;
}

int main(){
	long long int n,tmp[2],i,root=0,*dp,*visit;
	cin>>n;
	vector< vector<long long int> > graph(n);
	dp = new long long int[n];
	visit = new long long int[n];
	for(i=0;i<n-1;i++){
		cin>>tmp[0]>>tmp[1];
		graph[tmp[0]-1].push_back(tmp[1]-1);
		graph[tmp[1]-1].push_back(tmp[0]-1);
	}
	for(i=0;i<n;i++){
		dp[i]=1;
		visit[i]=0;
	}
	dfs(graph,0,visit,dp);
	ans = ans % 1000000007;
	cout<<ans;
}
