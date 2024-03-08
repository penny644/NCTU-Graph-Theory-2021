#include<iostream>
#include<algorithm>
#include<vector>
#include <climits>
#include<queue>
using namespace std;
long long int flag,*value,cnt;
struct edge{
	long long int end;
	long long int weight;
	long long int used1;
	long long int used2;
};
struct use_edge{
	long long int start;
	long long int end;
};
use_edge *use1,*use2;
bool cmp(use_edge a, use_edge b){
	if(a.start!=b.start) return a.start<b.start;
	else return a.end<b.end;
}
typedef pair<long long int,long long int> mst_pair;
long long int prim(vector< vector<edge> > &graph,int n,bool first){
	long long int parent[n],mst[n],i,j,tmp,min_tmp,ans=0,tmp1;
	priority_queue< mst_pair, vector <mst_pair> , greater<mst_pair> > pq;
	long long int s=0;
	for(i=0;i<n;i++){
		value[i]=INT_MAX;	
		mst[i]=0;
	}
	pq.push(make_pair(0,s));
	value[0]=0;
	parent[0]=-1;
	flag=0;
	while(!pq.empty()){		
		tmp=pq.top().second;
		pq.pop();
		if(mst[tmp]==1) continue;
		mst[tmp]=1;
		for(j=0;j<graph[tmp].size();j++){
			if(mst[graph[tmp][j].end]==0&&graph[tmp][j].weight<value[graph[tmp][j].end]){
				parent[graph[tmp][j].end]=tmp;
				value[graph[tmp][j].end]=graph[tmp][j].weight;
				pq.push(make_pair(value[graph[tmp][j].end], graph[tmp][j].end));
				graph[tmp][j].used1=1;
				tmp1=graph[tmp][j].end;
			}
			else if(mst[graph[tmp][j].end]==0&&graph[tmp][j].weight==value[graph[tmp][j].end]&&first==false){
				if(graph[tmp][j].used1==0){
					parent[graph[tmp][j].end]=tmp;
					value[graph[tmp][j].end]=graph[tmp][j].weight;
					pq.pop();
					pq.push(make_pair(value[graph[tmp][j].end], graph[tmp][j].end));
					graph[tmp][j].used2=1;
					flag=1;
					tmp1=graph[tmp][j].end;
				}
			}
		}
		if(tmp<tmp1){
			if(first){
				use_edge c;
				c.start=tmp;
				c.end=tmp1;
				use1[cnt]=c;
				cnt++;
			}
			else{
				use_edge c;
				c.start=tmp;
				c.end=tmp1;
				use2[cnt]=c;
				cnt++;
			}
		}
		else{
			if(first){
				use_edge c;
				c.start=tmp1;
				c.end=tmp;
				use1[cnt]=c;
				cnt++;
			}
			else{
				use_edge c;
				c.start=tmp1;
				c.end=tmp;
				use2[cnt]=c;
				cnt++;
			}
		}
	}
	
	for(i=0;i<n;i++){
		ans+=value[i];
	}
	return ans;
}

int main(){
	long long int n,m,i,tmp1,tmp2,tmp3,ans,old;
	cin>>n>>m;
	edge tmp;
	vector< vector<edge> > graph(n);
	value = new long long int[n];
	use1=new use_edge[n];
	use2=new use_edge[n];
	for(i=0;i<m;i++){
		cin>>tmp1>>tmp2>>tmp3;
		tmp.end=tmp2-1;
		tmp.weight=tmp3;
		tmp.used1=0;
		tmp.used2=0;
		graph[tmp1-1].push_back(tmp);
		tmp.end=tmp1-1;
		tmp.weight=tmp3;
		tmp.used1=0;
		tmp.used2=0;
		graph[tmp2-1].push_back(tmp);
	}
	for(i=0;i<n;i++){
		value[i]=INT_MAX;
	}
	cnt=0;
	ans=prim(graph,n,true);
	cnt=0;
	prim(graph,n,false);
	if(flag==1){
		sort(use1,use1+n,cmp);
		sort(use2,use2+n,cmp);
		flag=0;
		for(i=0;i<n;i++){
			if(use1[i].start!=use2[i].start||use1[i].end!=use2[i].end){
				flag=1;
				break;
			}
		}
	}
	cout<<ans<<endl;
	if(flag==0) cout<<"YES";
	else cout<<"NO";
}
