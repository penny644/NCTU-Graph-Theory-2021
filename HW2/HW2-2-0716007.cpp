#include <iostream>
#include<cmath>
#include <vector>
#include <queue>
using namespace std;
int *index;
typedef struct node{
	int dst;
	int weight;
}adjnode;

void swap(adjnode &a1, adjnode &a2){
    adjnode tmp = a1;
    a1 = a2;
    a2 = tmp;
}

class min_heap{
public:
    std::vector<adjnode> adjnode_list;

    min_heap(){               
        adjnode_list.resize(1);         
    }

    void heapify(int dst, int length){
	    int left,right,min,tmp;
	    left=2*dst;
		right=2*dst+1;
	    if (left<=length && adjnode_list[left].weight<adjnode_list[dst].weight){
	    	if (right<=length && adjnode_list[right].weight<adjnode_list[left].weight) min = right;
	    	else min = left;
		}
	    else{
	    	if (right<=length && adjnode_list[right].weight<adjnode_list[dst].weight) min = right;
	    	else min = dst;
		}	
	    if (min!=dst) {
	        swap(adjnode_list[min], adjnode_list[dst]);
	        tmp = index[adjnode_list[min].dst];
	        index[adjnode_list[min].dst] = index[adjnode_list[dst].dst];
	        index[adjnode_list[dst].dst] = tmp;	        
	        heapify(min, length); 
	    }
	};
	
    void decrease(int dst, int weight){
		int index_tmp,tmp;
		index_tmp = index[dst];
	    adjnode_list[index_tmp].weight = weight;
	    while (index_tmp>1 && adjnode_list[floor(index_tmp/2)].weight>adjnode_list[index_tmp].weight) {
	        tmp = index[adjnode_list[index_tmp].dst];
	        index[adjnode_list[index_tmp].dst] = index[adjnode_list[floor(index_tmp/2)].dst];
	        index[adjnode_list[floor(index_tmp/2)].dst] = tmp;
			swap(adjnode_list[index_tmp], adjnode_list[floor(index_tmp/2)]);
	        index_tmp = floor(index_tmp/2);	        
	    }
	};
	
    void insert(int dst, int weight){
	    adjnode tmp;
	    tmp.dst = dst;
	    tmp.weight = weight;
		adjnode_list.push_back(tmp);
		index[dst] = adjnode_list.size()-1;
	    decrease(dst,weight);
	};         
	        
    int extract(){
	    int min = adjnode_list[1].dst;
	    adjnode_list[1] = adjnode_list[adjnode_list.size()-1];
	    index[adjnode_list[adjnode_list.size()-1].dst]=1;
	    adjnode_list.pop_back();
	    heapify(1, adjnode_list.size());
	    return min;
	};           
};

void newedge(vector<adjnode> graph[] ,int s, int dst, int weight) {
    adjnode tmp;
    tmp.dst = dst-1;
    tmp.weight = weight;
    graph[s-1].push_back(tmp);
}

int main(){
	int n,m,inputedge[3],*ans,*c,s_tmp;
	int i,j,k;
	
	cin>>n>>m;
	min_heap ticket;
	c = new int[n]; 
	ans = new int[n];
	index = new int[n];
	for(i=0;i<n;i++){
		cin>>c[i];
		ans[i] = c[i];
		ticket.insert(i,ans[i]);
	}
	vector<adjnode> graph[n];
	for(i=0;i<m;i++){
		cin>>inputedge[0]>>inputedge[1]>>inputedge[2];
		newedge(graph,inputedge[0],inputedge[1],inputedge[2]);
		newedge(graph,inputedge[1],inputedge[0],inputedge[2]);
	}
	while(ticket.adjnode_list.size()>=1){
		s_tmp = ticket.extract();
		for(i=0;i<graph[s_tmp].size();i++){
			if(graph[s_tmp][i].weight+ans[s_tmp]<ans[graph[s_tmp][i].dst]){
				ans[graph[s_tmp][i].dst] = graph[s_tmp][i].weight+ans[s_tmp];
				ticket.decrease(graph[s_tmp][i].dst,ans[graph[s_tmp][i].dst]);
			}
		}
		
	}
	for(i=0;i<n;i++){
		if(i<n-1) cout<<ans[i]<<" ";
		else cout<<ans[i];
	}
}
