#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,**e,*d,*visit,ans=0,tmp,count=0;
	int i,j;
	vector<int> connect;
	
	cin>>n;
	vector< vector<int> > v(n);
	e = new int*[n-1];
	for(i=0;i<n-1;i++) e[i]=new int[2];
	d = new int[n];
	visit = new int[n];
	for(i=0;i<n-1;i++) cin>>e[i][0]>>e[i][1];
	for(i=0;i<n;i++){
		d[i]=0;
		visit[i]=0;
	}
	for(i=0;i<n-1;i++){
		v[e[i][0]-1].push_back(e[i][1]-1);
		v[e[i][1]-1].push_back(e[i][0]-1);
	}
	d[0] = 0;
	visit[0] = 1;
	connect.push_back(0);
	while((connect.empty()==0)){
		tmp = connect.back();
		connect.pop_back();	
		for(i=0;i<v[tmp].size();i++){
			if(visit[v[tmp][i]]==0){
				visit[v[tmp][i]] = 1;
				d[v[tmp][i]] = d[v[tmp][i]] + d[tmp] + 1;
				connect.push_back(v[tmp][i]);
			}			
		}
	}
	ans = d[0];
	for(i=1;i<n;i++){
		if(ans<d[i]){
			ans = d[i];
			tmp = i;
		}
	}
	for(i=0;i<n;i++){
		d[i]=0;
		visit[i]=0;
	}
	d[tmp] = 0;
	visit[tmp] = 1;
	connect.push_back(tmp);
	while((connect.empty()==0)){
		tmp = connect.back();
		connect.pop_back();	
		for(i=0;i<v[tmp].size();i++){
			if(visit[v[tmp][i]]==0){
				visit[v[tmp][i]] = 1;
				d[v[tmp][i]] = d[v[tmp][i]] + d[tmp] + 1;
				connect.push_back(v[tmp][i]);
			}			
		}
	}
	ans = d[0];
	for(i=1;i<n;i++){
		if(ans<d[i]){
			ans = d[i];
		}
	}
	cout<<ans;
}
