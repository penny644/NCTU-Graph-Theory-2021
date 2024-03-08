#include<iostream>
#include<vector>
#include<queue>
#include <limits.h>
using namespace std;
struct node{
	int t;
	int c;
};
int dfs(vector< vector<node> > &graph,int s,int t,int *parent,int v,int *visit){
	int i;
	if(s==t){
		return 1;
	}
	visit[s]=1;
	for(i=0;i<graph[s].size();i++){
		if(visit[graph[s][i].t]==0&&graph[s][i].c>0){
			parent[graph[s][i].t]=s;
			if(dfs(graph,graph[s][i].t,t,parent,v,visit)) return 1;
		}
	}
	return 0;
}

int ford(vector< vector<node> > &graph,int s,int t,int v){
	int i,j,tmp,*parent,max=0,index,*visit;
	parent=new int[v];
	visit=new int[v];
	for(i=0;i<v;i++) visit[i]=0;
	while(dfs(graph,s,t,parent,v,visit)){
		int path=INT_MAX;
		for(i=0;i<v;i++) visit[i]=0;
		for(i=t;i!=s;i=parent[i]){
			tmp=parent[i];
			index=-1;
			for(j=0;j<graph[tmp].size();j++){
				if(graph[tmp][j].t==i){
					index=j;
					break;
				}
			}
			if(index!=-1){
				if(path>graph[tmp][index].c){
					path=graph[tmp][index].c;
				}
			}

		}
		for(i=t;i!=s;i=parent[i]){
			tmp=parent[i];
			index=-1;
			for(j=0;j<graph[tmp].size();j++){
				if(graph[tmp][j].t==i){
					index=j;
					break;
				}
			}
			if(index!=-1){
				graph[tmp][index].c-=path;
			}
			index=-1;
			for(j=0;j<graph[i].size();j++){
				if(graph[i][j].t==tmp){
					index=j;
					break;
				}
			}
			if(index!=-1){
				graph[i][index].c+=path;
			}
		}
		max+=path;
	}
	return max;
}

int main(){
	int n,m,k,v,i,tmp[2],*a,*b;
	cin>>n>>m>>k;
	v=n+m+2;
	vector< vector<node> > graph(v);
	a=new int[n];
	b=new int[m];
	for(i=0;i<n;i++){
		cin>>a[i];
		node tmp1;
		tmp1.t=i+1;
		tmp1.c=a[i];
		graph[0].push_back(tmp1);
		tmp1.t=0;
		tmp1.c=0;
		graph[i+1].push_back(tmp1);
	}
	for(i=0;i<m;i++){
		cin>>b[i];
		node tmp1;
		tmp1.t=v-1;
		tmp1.c=b[i];
		graph[n+i+1].push_back(tmp1);
		tmp1.t=n+i+1;
		tmp1.c=0;
		graph[v-1].push_back(tmp1);
	}
	for(i=0;i<k;i++){
		cin>>tmp[0]>>tmp[1];
		node tmp1;
		tmp1.t=n+tmp[1];
		tmp1.c=1;
		graph[tmp[0]].push_back(tmp1);
		tmp1.t=tmp[0];
		tmp1.c=0;
		graph[n+tmp[1]].push_back(tmp1);
	}
	cout<<ford(graph,0,v-1,v);
}
