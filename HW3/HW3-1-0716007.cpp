#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n,m,tmp1,tmp2,i,j,k,*visit,ans=1,odd=0;
	cin>>n>>m;
	vector< vector<int> > graph(n);
	vector<int> connected;
	visit = new int[n];
	for(i=0;i<m;i++){
		cin>>tmp1>>tmp2;
		graph[tmp1-1].push_back(tmp2-1);
		graph[tmp2-1].push_back(tmp1-1);
	}
	for(i=0;i<n;i++) visit[i]=0;
	for(i=0;i<n;i++){
		if(graph[i].size()!=0){
			tmp1=i;
			connected.push_back(i);
			break;
		}
	}
	while(!connected.empty()){
		tmp1=connected.back();
		visit[tmp1]=1;
		connected.pop_back();
		for(i=0;i<graph[tmp1].size();i++){
			if(visit[graph[tmp1][i]]==0){
				connected.push_back(graph[tmp1][i]);
			}
		}
	}
	for(i=0;i<n;i++){
		if(visit[i]==0&&graph[i].size()!=0){
			ans=0;
			break;
		}
	}
	if(ans==1){
		for(i=0;i<n;i++){
			if(graph[i].size()%2==1){
				odd++;
				if(odd>=3){
					ans=0;
					break;
				}
			}
		}
	}
	if(odd==1) ans=0;
	if(ans==1) cout<<"YES";
	else cout<<"NO";
} 
