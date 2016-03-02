#include <stdio.h>
#include <string.h>

long long n;
const int N=50;
long long fac[N][2],tot;

void decompose(){
	tot=0;
	for(long long i=2;i*i<=n;i++){
		if(n%i==0){
			fac[tot][0]=i;
			fac[tot][1]=0;
			do{
				n/=i;
				fac[tot][1]++;
			}while(n%i==0);
			tot++;
		}
	}
	if(n>1){
		fac[tot][0]=n;
		fac[tot++][1]=1;
	}
}

long long pow(long long a,int p){
	long long ret=1LL;
	while(p){
		if(p&1)ret*=a;
		p>>=1;
		a*=a;
	}
	return ret;
}

long long SigemaGcd(){
	decompose();
	long long ret=1LL;
	for(int i=0;i<tot;i++){
		long long p=fac[i][0];
		long long r=fac[i][1];
		ret*=pow(p,r-1)*(p+p*r-r);
	}
	return ret;
}

int main(){
	while(~scanf("%I64d",&n)){
		printf("%I64d\n",SigemaGcd());
	}
	return 0;
}



