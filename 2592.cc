#include <stdio.h>
#include <math.h>
#include <string.h>
#define M 1000000
#define PI 3.141592653589793
int num[151];

double cal(double p)
{
	double dx=0.0002,c=1.0/sqrt(2*PI),x0=0,s=0.5,t,m;
	if (p>=0.5){
		while(x0<=5&&s<=p){
			m=x0+dx/2.0;
			t=exp(-(m*m)/2.0)*dx*c;
			s=s+t;
			x0+=dx;
		}
	}	
	else{
		while(x0>=-5&&s>=p){
			m=x0-dx/2.0;
			t=exp(-(m*m)/2.0)*dx*c;
			s=s-t;
			x0-=dx;
		}

	}
	return x0;
}
int main()
{
	int i,n,m,sc,j,k,first=1,sp;
	double p,sp1,x;

	while(scanf("%d",&n)!=EOF&&n){
		if (!first) printf("\n");
		first=0;
		memset(num,0,sizeof(num));
		for(i=0;i<n;i++){scanf("%d",&sc);num[sc]++;}
		scanf("%d",&m);
		for(i=0;i<m;i++){
			scanf("%d",&sc);
			k=0;
			for(j=0;j<sc;j++) k+=num[j];
			p=k/double(n);
			x=cal(p);
			sp1=500.0+100.0*x;
			if (sp1<=100) sp=100;
			else if (sp1>100&&sp1<=501) sp=sp1;
			else if (sp1>501&&sp1<=900){ 
				if (sp1>int(sp1)) sp=sp1+1;
				else sp=sp1;
			}
			else sp=900;
			printf("%d\n",sp);
		}
	}
	return 0;
}



