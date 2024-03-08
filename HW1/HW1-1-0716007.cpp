#include <iostream>
using namespace std;

int main(){
	int n,k,a,b,c,**p,*r,**change,i,j;
	cin>>n>>k>>a>>b>>c;
	p = new int*[n];
	change = new int*[k];
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
	for(i=0;i<k;i++) change[i] = new int[3];
	for(i=0;i<k;i++){
		for(j=0;j<3;j++){
			cin>>change[i][j];
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
	for(i=0;i<k;i++){
		if(change[i][2]==0){
			if(p[change[i][0]-1][change[i][1]-1]==1){
				r[change[i][0]-1] = r[change[i][0]-1]-a+b;
				r[change[i][1]-1] = r[change[i][1]-1]-b+a;
			}
			else{
				r[change[i][0]-1] = r[change[i][0]-1]-c+b;
				r[change[i][1]-1] = r[change[i][1]-1]-c+a;
			}
			p[change[i][0]-1][change[i][1]-1] = 0;
			p[change[i][1]-1][change[i][0]-1] = 1;

		}
		else if(change[i][2]==1){
			if(p[change[i][0]-1][change[i][1]-1]==0){
				r[change[i][0]-1] = r[change[i][0]-1]-b+a;
				r[change[i][1]-1] = r[change[i][1]-1]-a+b;

			}
			else{
				r[change[i][0]-1] = r[change[i][0]-1]-c+a;
				r[change[i][1]-1] = r[change[i][1]-1]-c+b;
			}
			p[change[i][0]-1][change[i][1]-1] = 1;
			p[change[i][1]-1][change[i][0]-1] = 0;
		}
		else{
			if(p[change[i][0]-1][change[i][1]-1]==0){
				r[change[i][0]-1] = r[change[i][0]-1]-b+c;
				r[change[i][1]-1] = r[change[i][1]-1]-a+c;
			}
			else{
				r[change[i][0]-1] = r[change[i][0]-1]-a+c;
				r[change[i][1]-1] = r[change[i][1]-1]-b+c;
			}
			p[change[i][0]-1][change[i][1]-1] = 2;
			p[change[i][1]-1][change[i][0]-1] = 2;	
		} 
		int max = r[0], min=r[0];
		for(j=1;j<n;j++){
			if(max<r[j]) max = r[j];
			if(min>r[j]) min = r[j];
		}
		if(i==k-1) cout<<max-min;
		else cout<<max-min<<" ";
	} 
	
}
