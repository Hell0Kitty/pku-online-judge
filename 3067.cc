#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int N=1005;
int d[N],n,m,k;
struct Node{
	int a,b;
}node[N*N];
int cmp(Node a,Node b){
	if(a.a==b.a)return a.b<b.b;
	else return a.a<b.a;
}
int lowbit(int x){
	return x&(-x);
}
void update(int i){
	while(i<=m){
		d[i]++;
		i+=lowbit(i);
	}
}
long long query(int i){
	long long sum=0;
	while(i){
		sum+=d[i];
		i-=lowbit(i);
	}
	return sum;
}
int main(){
	int T,i,j;
	scanf("%d",&T);
	for(j=1;j<=T;j++){
		memset(d,0,sizeof(d));
		scanf("%d%d%d",&n,&m,&k);
		for(i=1;i<=k;i++)scanf("%d%d",&node[i].a,&node[i].b);
		sort(node+1,node+k+1,cmp);
		long long sum=0;
		for(i=1;i<=k;i++){
			update(node[i].b);
			sum+=i-query(node[i].b);
		}
		printf("Test case %d: %lld\n",j,sum);
	}
	return 0;
}



