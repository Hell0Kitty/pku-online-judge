#include <stdio.h>
#include <math.h>
#include <string.h>
const int maxn=20000+5;
bool vis[maxn];
int Prime[maxn],cnt;

void init(){
	int i,k;
	cnt=0;
	memset(vis,true,sizeof vis);
	vis[0]=vis[1]=false;
	for(i=2;i<=maxn;i++){
		if(!vis[i]) continue;
		Prime[cnt++]=i;
		for(k=i+i;k<=maxn;k+=i){
			vis[k]=false;
		}
	}
}

int Maxfactor(int x){
	int i,j,u,max=-1;
	for(i=2,j=0;x!=1;i++,j++){
		u=Prime[j];
		while(!(x%u)){
			x/=u;
			if(max<u) max=u;
		}
	}
	return max;
}



