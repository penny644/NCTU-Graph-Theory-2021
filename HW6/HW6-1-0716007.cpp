#include <iostream>
using namespace std;

int K5(int **graph,int n){
	int a,b,c,d,e;
	for(a=0;a<n;a++){
		for(b=0;b<n;b++){
			if(a==b) continue;
			for(c=0;c<n;c++){
				if(a==c||b==c) continue;
				for(d=0;d<n;d++){
					if(a==d||b==d||c==d) continue;
					for(e=0;e<n;e++){
						if(a==e||b==e||c==e||d==e) continue;
						if(graph[a][b]==0||graph[a][c]==0||graph[a][d]==0||graph[a][e]==0) continue;
						if(graph[b][c]==0||graph[b][d]==0||graph[b][e]==0) continue;
						if(graph[c][d]==0||graph[c][e]==0) continue;
						if(graph[d][e]==0) continue;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int K3(int **graph,int n){
	int a,b,c,d,e,f;
	for(a=0;a<n;a++){
		for(b=0;b<n;b++){
			if(a==b) continue;
			for(c=0;c<n;c++){
				if(a==c||b==c) continue;
				for(d=0;d<n;d++){
					if(a==d||b==d||c==d) continue;
					for(e=0;e<n;e++){
						if(a==e||b==e||c==e||d==e) continue;
						for(f=0;f<n;f++){
							if(a==f||b==f||c==f||d==f||e==f) continue;
							if(graph[a][d]==0||graph[a][e]==0||graph[a][f]==0) continue;
							if(graph[b][d]==0||graph[b][e]==0||graph[b][f]==0) continue;
							if(graph[c][d]==0||graph[c][e]==0||graph[c][f]==0) continue;
							return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}

int main(){
	int *deg,**graph,n,m,tmp[2],i,j,k;
	cin>>n>>m;
	deg = new int[n];
	graph = new int*[n];
	for(i=0;i<n;i++){
		graph[i] = new int[n];
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			graph[i][j] = 0;
		}
	}
	for(i=0;i<m;i++){
		cin>>tmp[0]>>tmp[1];
		graph[tmp[0]-1][tmp[1]-1] = 1;
		graph[tmp[1]-1][tmp[0]-1] = 1;
	}
	if(K5(graph,n)&&K3(graph,n)) cout<<3;
	else if(K5(graph,n)) cout<<2;
	else if(K3(graph,n)) cout<<1;
	else cout<<0;
} 
