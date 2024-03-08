#include<iostream>
#include<algorithm>
#include<vector>
using namespace std; 

int main(){
	int n,*s,i,j,k,ans=1,tmp=0,*count;
	cin>>n;
	s = new int[n];
	count = new int[n];

	for(i=0;i<n;i++){
		count[i] = 0;
	}
	for(i=0;i<n;i++){
		cin>>s[i];
		if(s[i]%2==1) tmp++;
		if(s[i]<0||s[i]>=n) ans=0;
		else{
			count[s[i]]++;
		}
	}
	if(tmp%2==1) ans=0;
	
	for(i=n-1;i>0;i--){
		if(ans==0||count[0]==n) break;		
		while(count[i]!=0){
			int index=i,counter=0,tmp_i;
			
			count[i]--;
			for(j=i;j>=1;j--){
				counter+=count[j];
				if(counter>=index){
					tmp_i = j;
					break;
				}
			}
			if(counter<index){
				ans=0;
				break;
			}
			for(j=tmp_i;j<=i;j++){
				if(j==tmp_i){
					count[j-1]+=count[j]-(counter-index);
					count[j]=(counter-index);
				}
				else{
					count[j-1]+=count[j];
					count[j]=0;
				}
				
			}
			count[0]++;
		}
	}
	if(count[0]!=n) ans=0;
	
	if(ans==0) cout<<"No";
	else cout<<"Yes";
}
