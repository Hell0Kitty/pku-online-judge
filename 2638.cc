#include<iostream>
#include<string.h> 
#include<stdio.h>
#define INF 1000000000
#define lINF 400000
const int pN=200,eN=20000;
int f_min(int x,int y){
	return x<y?x:y;
}
int f_max(int x,int y){
	return x>y?x:y;
}
int f_min(int a,int b,int c,int d){
	return f_min(f_min(a,b),f_min(c,d));
}
struct Edge{
	int u,v,next;
	int w,l;
};
Edge edge[eN];
int en,head[pN],cur[pN],ps[pN],dep[pN];
void insert(int u,int v,int l){
	edge[en].u=u;
	edge[en].v=v;
	edge[en].l=l;
	edge[en].next=head[u];
	head[u]=en++;
	edge[en].u=v;
	edge[en].v=u;
	edge[en].l=l;
	edge[en].next=head[v];
	head[v]=en++;
}
int max_flow(int n,int s,int t){
	int tr,res=0;
	int i,j,k,f,r,top;
	while(1){
		memset(dep,-1,n*sizeof(int));
		for(f=dep[ps[0]=s]=0,r=1;f!=r;)
			for(i=ps[f++],j=head[i];j!=-1;j=edge[j].next){
				if(edge[j].w&&-1==dep[k=edge[j].v]){
					dep[k]=dep[i]+1;
					ps[r++]=k;
					if(k==t){
						f=r;
						break;
					}
				}
			}
			if(-1==dep[t])break;
			memcpy(cur,head,n*sizeof(int));
			for(i=s,top=0;;){
				if(i==t){
					for(k=0,tr=INF;k<top;++k)
						if(edge[ps[k]].w<tr)
							tr=edge[ps[f=k]].w;
						for(k=0;k<top;++k)
							edge[ps[k]].w-=tr,edge[ps[k]^1].w+=tr;
						res+=tr;
						i=edge[ps[top=f]].u;
				}
				for(j=cur[i];cur[i]!=-1;j=cur[i]=edge[cur[i]].next)
					if(edge[j].w&&dep[i]+1==dep[edge[j].v])break;
					if(cur[i]!=-1){
						ps[top++]=cur[i];
						i=edge[cur[i]].v;
					}else{
						if(0==top)break;
						dep[i]=-1;
						i=edge[ps[--top]].u;
					}
			}
	}
	return res;
}
int N,K,M;
int tran(int x){
	if(x==95050)return N-2;
	if(x==104729)return N-1;
	return x;
}
int diss[200],dise[200];
void get_data(){
	scanf("%d%d",&K,&M);
	int u,v,l;
	memset(head,-1,sizeof(head));en=0;
	N+=2;
	while(M--){
		scanf("%d%d%d",&u,&v,&l);
		u=tran(u);
		v=tran(v);
		insert(u,v,l);
	}
}
int que[100000],qhead,qtail;
bool inque[200];
void spfa(int x[200],int s){
	int u,v,i;
	for(i=0;i<N;i++)x[i]=INF;
	qhead=qtail=0;
	memset(inque,0,sizeof(inque));
	inque[s]=1;x[s]=0;
	que[qtail++]=s;
	while(qtail>qhead){
		u=que[qhead++];inque[u]=0;
		for(i=head[u];i!=-1;i=edge[i].next){
			v=edge[i].v;
			if(x[v]>x[u]+edge[i].l){
				x[v]=x[u]+edge[i].l;
				if(!inque[v]){
					inque[v]=1;
					que[qtail++]=v;
				}
			}
		}
	}
}
void f_swap(int &a,int &b){
	int t=a;
	a=b;
	b=t;
}
int cal(int l1,int l2,int v){
	if(l1>l2)f_swap(l1,l2);
	if(l1+v<=l2)return l2*2;
	return l1+v+l2;
}
int get_w(int i){
	int s1,s2,e1,e2,temp;
	s1=diss[edge[i].u];s2=diss[edge[i].v];
	e1=dise[edge[i].u];e2=dise[edge[i].v];
	temp=f_min(2*f_max(s1,e1),2*f_max(s2,e2));
	temp=f_min(temp,cal(s1,e2,edge[i].l));
	temp=f_min(temp,cal(s2,e1,edge[i].l));
	return temp;
}
void get_dis_w(){
	spfa(diss,N-2);
	spfa(dise,N-1);
	int i;
	for(i=0;i<en;i+=2){
		edge[i].l=get_w(i);
		edge[i^1].l=edge[i].l;
	}
}
bool ok(int lim){
	int i;
	for(i=0;i<en;i+=2){
		if(edge[i].l<=lim){
			edge[i].w=edge[i^1].w=1;
		}else{
			edge[i].w=edge[i^1].w=lINF;
		}
	}
	int temp=max_flow(N,N-2,N-1);
	if(temp>K)return 0;
	return 1;
}
void run(){
	get_dis_w();
	int h,l,mid;
	h=200000;l=0;
	while(h>l){
		mid=(h+l)>>1;
		if(ok(mid))h=mid;
		else l=mid+1;
	}
	if(h==200000)printf("Impossible\n");
	else printf("%.1lf\n",h*0.5);
}
int main(){
	while(scanf("%d",&N),N){
		get_data();
		run();
	}
	return 0;
}



