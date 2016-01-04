#include <stdio.h>

long long k,n,m;

void mod(long long &x){
	x%=m;
}

long long pow(long long a,int p){
	long long ret=1LL;
	while(p){
		if(p&1)ret*=a; mod(ret);
		p>>=1; a*=a; mod(a);
	}
	return ret;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%I64d%I64d%I64d",&n,&k,&m);
		printf("%I64d\n",pow(pow(10,k)+1,n));
	}
	return 0;
}



