#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,m,**e,*c,ans=1,tmp,count=0,flag;
	int i,j;
	vector<int> connect;
	
	cin>>n>>m;
	vector< vector<int> > v(n);
	e = new int*[m];
	for(i=0;i<m;i++) e[i]=new int[2];
	c = new int[n];
	for(i=0;i<m;i++) cin>>e[i][0]>>e[i][1];
	for(i=0;i<n;i++){
		c[i]=-1;
	}
	for(i=0;i<m;i++){
		v[e[i][0]-1].push_back(e[i][1]-1);
		v[e[i][1]-1].push_back(e[i][0]-1);
	}
	c[0] = 0;
	connect.push_back(0);
	while((connect.empty()==0)&&(ans!=0)){
		tmp = connect.back();
		connect.pop_back();	
		for(i=0;i<v[tmp].size();i++){
			if(c[v[tmp][i]]==-1){
				if(c[tmp]==0) c[v[tmp][i]] = 1;
				else if(c[tmp]==1) c[v[tmp][i]] = 0;
				connect.push_back(v[tmp][i]);
			}
			else if(c[v[tmp][i]]==c[tmp] || tmp==v[tmp][i]){
				ans = 0;
				break;
			}

			
		}
	}
	if(ans==0) cout<<-1;
	else{
		for(i=0;i<n;i++){
			if(c[i]==0) count++;	
		}
		cout<<count<<" "<<(n-count);
	}
}
