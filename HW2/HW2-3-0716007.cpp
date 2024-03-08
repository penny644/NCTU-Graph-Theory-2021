#include<iostream>
#include<vector>
using namespace std;
#define max_int 20000001
int main(){
	int n,m,k,tmp[3],min=max_int,min_tmp,color_check;
	int i,j,l;
	cin>>n>>m>>k;
	int **graph,**dp,*flag;
	vector<int> tmp1;
	vector<int> color[k];
	graph = new int*[n];
	flag = new int[k];
	dp = new int*[1<<n];
	for(i=0;i<n;i++){
		graph[i] = new int [n];
	}
	for(i=0;i<(1<<n);i++){
		dp[i] = new int [n];
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j) graph[i][j]=max_int;
			else graph[i][j]=0;
		}
	}
	for(i=0;i<(1<<n);i++){
		for(j=0;j<n;j++){
			dp[i][j]=max_int;
		}
	}
	for(i=0;i<n;i++){
		cin>>tmp[0];
		color[tmp[0]-1].push_back(i);
	}
	for(i=0;i<m;i++){
		cin>>tmp[0]>>tmp[1]>>tmp[2];
		graph[tmp[0]-1][tmp[1]-1]=tmp[2];
		graph[tmp[1]-1][tmp[0]-1]=tmp[2];
	}
	
	for(l=0;l<n;l++){	
	    for(i=0;i<n;i++){
	    	for(j=0;j<n;j++){    		
    			if(graph[i][j]>graph[i][l]+graph[l][j]){
    				graph[i][j]=graph[i][l]+graph[l][j];
				}
			}
		}
	}
	for(i=0;i<n;i++){
		dp[1<<i][i]=0;
	}

	for(i=0;i<(1<<n);i++){
		color_check=1;
		for(j=0;j<k;j++){
			flag[j]=0;
		}
		for(j=0;j<k;j++){
			for(l=0;l<color[j].size();l++){
				if(i&(1<<color[j][l])){
					flag[j]=1;
					break;
				}
			}
		}
		for(j=0;j<k;j++){
			if(flag[j]==0){
				color_check=0;
				break;
			}
		}
		tmp1.clear();
		for(j=0;j<n;j++){
			if(i & (1<<j)){
				tmp1.push_back(j);
			}
		}
		for(j=0;j<tmp1.size();j++){			
			for(l=0;l<tmp1.size();l++){			
				if(dp[i][tmp1[j]]>dp[i^(1<<tmp1[j])][tmp1[l]]+graph[tmp1[l]][tmp1[j]]){						
					dp[i][tmp1[j]]=dp[i^(1<<tmp1[j])][tmp1[l]]+graph[tmp1[l]][tmp1[j]];
				} 	
			}
		}
		if(color_check==1){
			min_tmp=max_int;
			for(j=0;j<n;j++){
				if(min_tmp>dp[i][j]&&dp[i][j]!=0) min_tmp = dp[i][j];
			}
			if(min>min_tmp) min = min_tmp;
		}
	}
	cout<<min;
}
