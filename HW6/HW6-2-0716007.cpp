#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
long long int count=0;

void coloring(vector< vector<long long int> > &graph, long long int *color, long long int src, long long int n){
	long long int i,j;
	bool flag;
	if(src==n){
		count++;
		return;
	}
	for(i=1;i<=3;i++){
		flag=true;
		for(j=0;j<graph[src].size();j++){
			if(color[graph[src][j]]==i){
				flag=false;
				break;
			}
		}
		if(flag){
			color[src]=i;
			coloring(graph,color,src+1,n);
			color[src]=0;
		}
	}
}

int main(){
	long long int n,m,tmp[2],i,j,*color;
	cin>>n>>m;
	color = new long long int[n];
	vector< vector<long long int> > graph(n);
	for(i=0;i<n;i++){
		color[i]=0;
	}
	for(i=0;i<m;i++){
		cin>>tmp[0]>>tmp[1];
		graph[tmp[0]-1].push_back(tmp[1]-1);
		graph[tmp[1]-1].push_back(tmp[0]-1);
	}
	if(m==0) count=pow(3,n);
	else coloring(graph,color,0,n);
	cout<<count;
}
