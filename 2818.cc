#include<iostream>
#include<cstdio>
using namespace std;

int cnt,w[5],ans[5],num[5],tot,m;
int c[]={25,10,5,1};

void dfs(int x){
	int i,sum,n;
	if(x>3){
		sum=0,n=0;
		for(i=0;i<4;i++){
			sum+=c[i]*num[i];
			n+=num[i];
		}
		if(sum==tot){
			if(n<m){
				for(i=0;i<4;i++)
					ans[i]=num[i];
				m=n;
			}
			cnt++;
		}
	}
	else{
		for(i=0;i<=w[x];i++){
			num[x]=i;
			dfs(x+1);
		}
	}
}

int main(){
	while(~scanf("%d%d%d%d%d",&w[0],&w[1],&w[2],&w[3],&tot)&&(w[0]+w[1]+w[2]+w[3]+tot)){
		m=w[0]+w[1]+w[2]+w[3]+1;
		cnt=0;
		dfs(0);
		if(cnt==0)
			printf("Cannot dispense the desired amount.\n");
		else
			printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies.\n",ans[0],ans[1],ans[2],ans[3]);
	}
	return 0;
}


