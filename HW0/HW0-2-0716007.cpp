#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,*list,max_int,max_count,i,j,current_count=1,current_int=0;
	cin >> n;
	max_count = 1;	
	list = new int[n];
	for(i=0;i<n;i++){
		cin>>list[i];
	}
	sort(list,list+n);
	for(i=0;i<n;i++){
		if(current_int!=list[i]){
			if(current_count>=max_count){
				max_count = current_count;
				max_int = current_int;	
			} 
			current_int = list[i];
			current_count = 1;
		}
		else{
			current_count++;
		}	
	}
	if(current_count>=max_count){
		max_count = current_count;
		max_int = current_int;	
	} 
	cout<<max_int<<" "<<max_count;
} 
