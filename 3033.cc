#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LENTH 10271
#define MAXN 6008
typedef struct talP{
	int x,y,z;
	talP(){}
	talP(int _x,int _y,int _z):x(_x),y(_y),z(_z){}
	void Set(int _x,int _y,int _z){talP(_x,_y,_z);}
	bool operator == (const talP &a)
	{return a.x==x&&a.y==y&&a.z==z;}
}Point3D;
typedef struct talH{
	int ix;
	Point3D p;
	talH *next;
}HashNode;
typedef struct talE{
	int v;
	talE *next;
}Edge;
HashNode MEM[MAXN*24];
HashNode *hashtable[LENTH];
int city[MAXN][24];
Edge edg[MAXN*24];
Edge *head[MAXN];
int cs[2][MAXN][8];
int s[MAXN];
int q[MAXN];
int dis[MAXN];
bool vis[MAXN];
int n[MAXN];
int front,tail;
int c,totalp,e,hm;

int Key(Point3D p)
{
	int ret=p.x;
	ret<<=3;ret^=p.y;
	ret<<=3;ret^=p.z;
	if(ret<0)ret=-ret;
	return ret%LENTH;
}

int HashFind(Point3D p,int c,int ith)
{
	int key=Key(p);
	HashNode *cur;
	for(cur=hashtable[key];cur&&!(cur->p==p);cur=cur->next);
	if(cur){ 
		cs[0][cur->ix][s[cur->ix]]=c;
		cs[1][cur->ix][s[cur->ix]++]=ith;
		return cur->ix;
	}
	return 0;
}

void HashInsert(Point3D p,int c,int ith,int ix)
{
	int key=Key(p);
	HashNode *cur=&MEM[hm++];
	cur->ix=ix;cur->p=p;
	cs[0][ix][s[ix]]=c;
	cs[1][ix][s[ix]++]=ith;
	cur->next=hashtable[key];
	hashtable[key]=cur;
}

void AddEdge(int u,int v)
{
	edg[e].v=v;edg[e].next=head[u];head[u]=&edg[e++];
	edg[e].v=u;edg[e].next=head[v];head[v]=&edg[e++];
}

int Bfs(int f,int t)
{
	int u,v;
	Edge *tmp;
	memset(vis,false,sizeof(vis));
	front=tail=0;
	q[tail++]=f;
	dis[f]=0;
	vis[f]=true;
	while(front<tail){
		u=q[front++];
		if(u==t) return dis[t];
		for(tmp=head[u];tmp;tmp=tmp->next){
			v=tmp->v;
			if(vis[v])continue;
			if(v==t)return dis[u]+1;
			vis[v]=true;
			dis[v]=dis[u]+1;
			q[tail++]=v;
		}
	}
	return -1;
}

int main()
{
	int i,j,k,l,x,y,z,r,m;
	int pa,pb;
	while(scanf("%d",&c),c){
		totalp=1;e=0;hm=0;
		memset(head,NULL,sizeof(head));
		memset(hashtable,NULL,sizeof(hashtable));
		memset(s,0,sizeof(s));

		for(i=1;i<=c;i++){
			scanf("%d",n+i);
			for(j=0;j<n[i];j++){
				scanf("%d%d%d",&x,&y,&z);
				r=HashFind(Point3D(x,y,z),i,j);
				if(r) city[i][j]=r;
				else{
					city[i][j]=totalp;
					HashInsert(Point3D(x,y,z),i,j,totalp++);
				}
			}
		}
		for(i=1;i<=c;i++){
			city[i][n[i]]=city[i][0];
			for(j=0;j<n[i];j++){
				pa=city[i][j];pb=city[i][j+1];
				for(k=0;k<s[pa];k++){
					if(cs[0][pa][k]<=i)
						continue;
					for(l=0;l<s[pb];l++){
						if(cs[0][pb][l]<=i)
							continue;
						if(cs[0][pb][l]==cs[0][pa][k]){
							if(abs(cs[1][pa][k]-cs[1][pb][l])==1
								||abs(cs[1][pa][k]-cs[1][pb][l])+1==n[cs[0][pb][l]])
								AddEdge(i,cs[0][pb][l]);
						}
					}
				}
			}
		}
		scanf("%d",&m);
		while(m--){
			scanf("%d%d",&i,&j);
			printf("%d\n",Bfs(i,j));
		}
	}
	return 0;
}



