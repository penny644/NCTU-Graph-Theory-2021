#include <iostream>
#include <vector>
using namespace std;
int discover_time,count;
void bridge(int u, int v, vector<int> &visit, vector< vector<int> >&graph,vector<int> &d_time,vector<int> &minimum){
	int i;
	visit[u]=1;
	d_time[u]=discover_time;
	minimum[u]=discover_time;
	discover_time++;
	for(i=0;i<graph[u].size();i++){
		if(graph[u][i]!=v){
			if(visit[graph[u][i]]==0){
				bridge(graph[u][i],u,visit,graph,d_time,minimum);
				if(minimum[u]>minimum[graph[u][i]]) minimum[u]=minimum[graph[u][i]];
				if(minimum[graph[u][i]]>d_time[u]) count++;
			}
			else{
				if(minimum[u]>d_time[graph[u][i]]) minimum[u]=d_time[graph[u][i]];
			}
		}
	}
}

int main(){
	int n,m,i,j,tmp1,tmp2;
	vector<int> visit,d_time,minimum;
	discover_time=0;
	count=0;
	cin>>n>>m;
	vector< vector<int> > graph(n);
	vector<int> tmp;
	d_time.resize(n);
	minimum.resize(n);
	visit.resize(n);
	for(i=0;i<n;i++){
		visit[i]=0;
	}
	for(i=0;i<m;i++){
		cin>>tmp1>>tmp2;
		graph[tmp1-1].push_back(tmp2-1);
		graph[tmp2-1].push_back(tmp1-1);
	}
	for(i=0;i<n;i++){
		if(visit[i]==0){
			bridge(i,-1,visit,graph,d_time,minimum);
		}
	}
	cout<<count;
}
