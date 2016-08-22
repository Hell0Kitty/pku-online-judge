#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
#define MAXV 310
#define INF 1<<27
#define min(a,b) (a>b?b:a)

int s,t,n,m,map[MAXV][MAXV];
int ric[MAXV],tb[MAXV],tp[MAXV];
char c[MAXV];

//这里状态0为B，1为P
//查看经过now_time时间后node结点的颜色，以及经过r的时间后会再次变色
int status(int now_time,int node,int &r){
	if(c[node]=='B'){
		if(now_time-ric[node]<0) {r=ric[node]-now_time;return 0;}

		now_time=(now_time-ric[node])%(tp[node]+tb[node]);
		if(now_time<tp[node]) {r=tp[node]-now_time;return 1;}
		r=tb[node]-now_time+tp[node];
		return 0;
	}else{
		if(now_time-ric[node]<0) {r=ric[node]-now_time;return 1;}

		now_time=(now_time-ric[node])%(tp[node]+tb[node]);
		if(now_time<tb[node]) {r=tb[node]-now_time;return 0;}
		r=tp[node]-now_time+tb[node];
		return 1;
	}
}

//求出已经过了ini_time时间，从start点到end点的最小等待时间
int ti(int ini_time,int start,int end){
	int c1,c2,r1,r2;
	c1=status(ini_time,start,r1);		//等待时间，第一步求两个节点经过ini_time后的状态是否一致
	c2=status(ini_time,end,r2);
	if(c1==c2) return 0;			//状态一致则不用等待
						//如果状态不一致，看两个节点经过ini_time后变到下一个状态的时间是否相同
	if(r1!=r2) return min(r1,r2);		//时间不同，则返回需要变到下一个时间短的时间即可，因为那样他们状态就相同了

	if(c1==0){                             //如果时间也相同，那么就看到下下次的状态时间
                   if(tp[start]<tb[end]) return r1+tp[start];
		if(tp[start]>tb[end]) return r2+tb[end];
		return -1;
	}else{
		if(tb[start]<tp[end]) return r1+tb[start];
		if(tb[start]>tp[end]) return r2+tp[end];
		return -1;
	}
}

void spfa(){
	queue <int>q;
	int v,i,d[MAXV],tmp;
	bool vis[MAXV];
	memset(vis,false,sizeof(vis));
	for(i=0;i<=n;i++) d[i]=INF;
	d[s]=0;
	vis[s]=true;
	q.push(s);

	while(!q.empty()){
		v=q.front();q.pop();
		vis[v]=false;

		for(i=1;i<=n;i++){
			tmp=ti(d[v],v,i);	//求此路的等待时间，为-1就永远不能经过
			if(map[v][i] && tmp!=-1 && d[i]>d[v]+map[v][i]+tmp){
				d[i]=d[v]+map[v][i]+tmp;
				if(!vis[i]){
					q.push(i);
					vis[i]=true;
				}
			}
		}
	}

	if(d[t]>=INF) printf("0\n");
	else printf("%d\n",d[t]);
}

int main(){
	int i;
	int a,b,tmp;
	while(~scanf("%d%d",&s,&t)){
		scanf("%d%d",&n,&m);
		getchar();
		for(i=1;i<=n;i++) scanf("%c %d %d %d\n",&c[i],&ric[i],&tb[i],&tp[i]);
		//记录下结点初始状态，还有多少时间变色，颜色为'B'的存在时间,颜色为'P'的存在时间

		for(i=1;i<=m;i++){		//输入m条无向边
			scanf("%d%d%d",&a,&b,&tmp);
			map[b][a]=map[a][b]=tmp;
		}

		spfa();			//求最短路径
	}
	return 0;
}


