#include <iostream>
#include <vector>
using namespace std;
struct vertex{
	long long int num;
	long long int value;
	long long int choose;
	long long int total;
	vector< vertex* > child;
};

vertex *new_vertex(long long int num,long long int value){
	vertex *node = new vertex;
	node->num = num;
	node->value = value;
	node->choose = 0;
	node->total = 0;
	return node;
}

long long int cover(vertex *root){
	long long int size,i,sizeo,j,value;
	if(root==NULL) return 0;
	if(root->child.empty()==1) return 0;
	if(root->choose!=0) return root->choose;
	size=1;
	for(i=0;i<root->child.size();i++){
		size+=cover(root->child[i]);
	}
	sizeo=0;
	for(i=0;i<root->child.size();i++){
		sizeo+=1;
		for(j=0;j<root->child[i]->child.size();j++){
			sizeo += cover(root->child[i]->child[j]);
		}
	}
	if(size<sizeo) root->choose=size;
	else root->choose=sizeo;
	return root->choose;
}
long long int costcover(vertex *root){
	long long int cost,i,costo,j,value;
	if(root==NULL) return 0;
	if(root->child.empty()==1) return 0;
	if(root->total!=0) return root->total;
	cost=root->value;
	for(i=0;i<root->child.size();i++){
		cost+=costcover(root->child[i]);
	}
	costo=0;
	for(i=0;i<root->child.size();i++){
		costo+=root->child[i]->value;
		for(j=0;j<root->child[i]->child.size();j++){
			costo += costcover(root->child[i]->child[j]);
		}
	}
	if(cost>costo) root->total = costo;
	else root->total = cost;
	return root->total;
}
int main(){
	long long int n,*value,i,tmp[2],*visit,max_i,max_c;
	cin>>n;
	vector<long long int> edge[n];
	vector< vertex* > tmp1;
	value = new long long int[n];
	visit = new long long int[n];
	for(i=0;i<n;i++){
		cin>>value[i];
		visit[i]=0;
	}
	for(i=0;i<n-1;i++){
		cin>>tmp[0]>>tmp[1];
		edge[tmp[0]-1].push_back(tmp[1]-1);
		edge[tmp[1]-1].push_back(tmp[0]-1);
	}
	max_i=0;
	vertex *root = new_vertex(max_i,value[max_i]);
	visit[max_i]=1;
	for(i=0;i<edge[max_i].size();i++){
		if(visit[edge[max_i][i]]==0){
			vertex *tmp2 = new_vertex(edge[max_i][i],value[edge[max_i][i]]);
			root->child.push_back(tmp2);
			visit[edge[max_i][i]]=1;
			tmp1.push_back(tmp2);
		}
	}
	while(tmp1.empty()==0){
		vertex *tmp3=tmp1.back();
		tmp1.pop_back();
		for(i=0;i<edge[tmp3->num].size();i++){
			if(visit[edge[tmp3->num][i]]==0){
				vertex *tmp2 = new_vertex(edge[tmp3->num][i],value[edge[tmp3->num][i]]);
				tmp3->child.push_back(tmp2);
				visit[edge[tmp3->num][i]]=1;
				tmp1.push_back(tmp2);
			}
		}
	}
	cout <<costcover(root)<<" "<< cover(root);
}
