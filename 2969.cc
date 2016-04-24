#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
char a[1010],c;

int sm(){
	int i,sum=0;for(i=0;a[i];i++)sum+=a[i]-'0';return sum;}
int pt(){
	int j,t;
	t=sm();
	if(t%3==0){
		if(t){for(j=strlen(a)-1;~j;j--)printf("%c",a[j]);puts("");}
		else puts("0");
		return 1;
	}else return 0;
}
void pe(){puts("impossible");}
int main(){
	int i,j,k,m,sum,len;
	scanf("%s",a);len=strlen(a);sort(a,a+len);
	if(a[0]=='0'){
		if(pt())return 0;
		for(i=1,sum=sm()%3;a[i]&&(a[i]-'0')%3!=sum;i++);
		if(!a[i]){
			for(;;){
				for(m=1;(a[m]-'0')%3==0;m++);
				for(j=m;a[j];j++)a[j]=a[j+1];
				if(pt())return 0;
			}
		}
		for(j=i;j<len;j++)a[j]=a[j+1];
		pt();return 1;
	}else{
		for(i=0;a[i]&&a[i]!='5';i++);
		if(!a[i]){pe();return 0;}
		c=a[i];a[i]=a[0];a[0]=c;
		sort(a+1,a+len);
		if(pt())return 0;
		for(i=1,sum=sm()%3;a[i]&&(a[i]-'0')%3!=sum;i++);
		if(!a[i]){
			for(m=1,k=0;a[m]&&((a[m]-'0')%3==0||(a[m]-'0')%3==5%3);m++)if((a[m]-'0')%3==5%3)k++;
			if(k==1){pe();return 1;}
			while(1){
				for(m=1;a[m]&&(a[m]-'0')%3==0;m++);
				if(!a[m]){pe();return 0;}
				for(j=m;a[j];j++)a[j]=a[j+1];
				if(pt())return 1;
			}
		}
		for(j=i;j<strlen(a);j++)a[j]=a[j+1];
		pt();return 1;
	}
}


