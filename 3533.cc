#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf=(1<<30);
const int N=1005;
const int pw[]={2,4,16,256,65536}; 

int n,m;
int nim_multi_power(int x,int y) { 
	if(x<2) return (x==1)&&(y==1);
	int a=0; 
	while(pw[a+1]<=x) a++;
	int M=pw[a];
	int p=x/M; 
	int s=y/M,t=y-s*M; 
	int d1=nim_multi_power(p,s);
	int d2=nim_multi_power(p,t);
	return (d1^d2)*M^nim_multi_power(M/2,d1);
}
int nim_multi(int x,int y) {
	if(x<y) return nim_multi(y,x);
	if(x<2) return (x==1)&&(y==1);
	int a=0; 
	while(pw[a+1]<=x) a++;
	int M=pw[a];
	int p=x/M,q=x-p*M; 
	int s=y/M,t=y-s*M; 
	int c1=nim_multi(p,s);
	int c2=nim_multi(p,t)^nim_multi(q,s);
	int c3=nim_multi(q,t);
	return (c1^c2)*M^c3^nim_multi_power(M/2,c1);
}
int nim_multi2(int x,int y,int z) {
	int g=nim_multi(x,y);
	return nim_multi(g,z);
}
int main()
{
	int i,j,t,cas=0;
	int x,y,z;
	while(scanf("%d",&n)!=EOF) {
		int nim=0;
		for(i=1;i<=n;i++) {
			scanf("%d%d%d",&x,&y,&z);
			nim^=nim_multi2(x,y,z);
		}

		if(nim) puts("No");
		else puts("Yes");
	}
	return 0;
}


