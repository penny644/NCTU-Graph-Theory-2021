#include <iostream>
using namespace std;

int main(){
	int n,a,b,c,**p,*r,i,j;
	cin>>n>>a>>b>>c;
	p = new int*[n];
	r = new int[n];
	for(i=0;i<n;i++){
		p[i] = new int[n];
		r[i] = 0;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>p[i][j];
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j){
				if(p[i][j]==0){
					r[i] += b;
				}
				else if(p[i][j]==1){
					r[i] += a;
				}
				else{
					r[i] += c;
				}	
			}
		}
	} 
	for(i=0;i<n;i++){
		if(i==n-1) cout<<r[i];
		else cout<<r[i]<<" ";
	}
}
