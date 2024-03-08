#include <iostream>
#include <climits>
using namespace std;

int main(){
	long long int n,m,type,i,j,k,tmp[3],output=INT_MAX;
	cin>>n>>m>>type;
	long long int **graph,**ans;
	graph = new long long int*[n];
	ans = new long long int*[n];
	for(i=0;i<n;i++){
		graph[i]=new long long int[n];
		ans[i]=new long long int[n];
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			graph[i][j]=INT_MAX;
			ans[i][j]=INT_MAX;
		}
	}
	for(j=0;j<m;j++){
		cin>>tmp[0]>>tmp[1]>>tmp[2];
		if(type==1){
			graph[tmp[0]-1][tmp[1]-1] = tmp[2];
		}
		else{
			graph[tmp[0]-1][tmp[1]-1] = tmp[2];
			graph[tmp[1]-1][tmp[0]-1] = tmp[2];
		}
	} 
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			ans[i][j]=graph[i][j];
		}
	}
	for(k=0;k<n;k++){
		for(i=0;i<k;i++){
			for(j=0;j<k;j++){
				if(type==0){
					if(i!=j&&j!=k&&i!=k){
						if(graph[k][i]+ans[i][j]+graph[j][k]<output){
							output=graph[k][i]+ans[i][j]+graph[j][k];
						}
					}
				}
			}
		}	
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(ans[i][k]+ans[k][j]<ans[i][j]){
					ans[i][j] = ans[i][k]+ans[k][j];
				}
			}
		}	
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(type==1){
				if(ans[i][j] + ans[j][i]<output) output = ans[i][j] + ans[j][i];
			}
		}
	}
	if(output==INT_MAX) output=-1;
	cout<<output;
}
