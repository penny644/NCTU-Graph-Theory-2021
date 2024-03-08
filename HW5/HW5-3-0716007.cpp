#include<iostream>
#include<vector>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ipair;

int main(){
	int n,m,k,i,input[3],count=0,max=0;
	vector<ipair> edge;
	cin>>n>>m>>k;
	for(i=0;i<m;i++){
		ipair tmp;
		cin>>input[0]>>input[1];
		tmp.first = input[0]-1;
		tmp.second = input[1]-1;
		edge.push_back(tmp);
	}
	for(i=0;i<k;i++){
		cin>>input[0];
		if(input[0]==1){
			cin>>input[1]>>input[2];
		}
		else{
			cin>>input[1];	
		}
	}
}
