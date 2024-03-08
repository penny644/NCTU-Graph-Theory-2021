#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct vertex{
	long long int s,t;
};
void update(map< long long int,vector<vertex> > &edge, map< long long int,long long int > &dp, map< long long int,long long int > &result, map< long long int, vector<vertex> >::iterator j){
	long long int k;
	vertex tmp1;
	map< long long int,long long int >::iterator m;
	dp.clear();
	for(k=0;k<(*j).second.size();k++){
		tmp1=(*j).second[k];
		if(dp.find(tmp1.s)!=dp.end()) dp[tmp1.s]++;
		else dp[tmp1.s]=result[tmp1.s]+1;
		
		if(dp.find(tmp1.t)!=dp.end()) dp[tmp1.t]++;
		else dp[tmp1.t]=result[tmp1.t]+1;
		
		dp[tmp1.s]+=result[tmp1.t];
		dp[tmp1.t]+=result[tmp1.s];
	}
	for(m=dp.begin();m!=dp.end();m++) result[(*m).first]=(*m).second;
	if(j==edge.end()) return;
	else{
		j++;
		update(edge, dp, result, j);
	}
	
}
int main(){
	long long int n,tmp[3],i,ans=0;
	cin>>n;
	vertex tmp1;
	map< long long int,vector<vertex> > edge;
	map< long long int,long long int >result,dp;
	map< long long int,vector<vertex> >::iterator j;
	map< long long int,long long int >::iterator m;
	
	for(i=0;i<n-1;i++){
		cin>>tmp[0]>>tmp[1]>>tmp[2];
		tmp1.s=tmp[0]-1;
		tmp1.t=tmp[1]-1;
		edge[tmp[2]].push_back(tmp1);
	}
	j=edge.begin();
	update(edge, dp, result, j);
	for(m=result.begin();m!=result.end();m++) ans+=(*m).second;
	cout<<ans;
}
