#include<stdio.h>
#include<math.h>
#define eps 1e-8

double a[11]={1,1e-1,1e-2,1e-3,1e-4,1e-5,1e-6,1e-7,1e-8,1e-9,1e-10};

int main(){
	int n;
	int m;
	double p,q,x,y;
	while(scanf("%d",&n)!=EOF){
		scanf("%d",&m);
		p=m*a[n];  q=(m+1)*a[n];
		x=y=0;
		while(x==y){
			p+=1; q+=1;
			x=floor(p*p);  y=floor(q*q-eps);
		}
		printf("%.f\n",floor(y));
	}
	return 0;
}




