#include<iostream>
#include<algorithm>
using namespace std;

struct Edge{
 __int64 x,y,next,dis;
 __int64 has;
 __int64 id;
 __int64 left;
};
bool com1(Edge &a,Edge &b){
 return a.has>b.has;
}
bool com2(Edge &a,Edge &b){
 return a.has<b.has;
}
Edge edges[100010];
__int64 head[100010];
__int64 eloc;
void addEdge(__int64 x,__int64 y,__int64 dis,__int64 id){
 edges[eloc].x=x,edges[eloc].y=y,edges[eloc].next=head[x],edges[eloc].id=id,edges[eloc].dis=dis;
 edges[eloc].left=0,edges[eloc].has=0,head[x]=eloc++;
}
bool visit[100000];
__int64 number,nu,a,b;

__int64 dfs(__int64 now){
 visit[now]=true;
 __int64 i;
 __int64 out=1;
 for(i=head[now];i!=-1;i=edges[i].next){
  if(!visit[edges[i].y]){
   __int64 temp=dfs(edges[i].y);
   edges[i].left=temp;
   out+=temp;
  }
 }
 return out;
}
int main(){
 while(scanf("%I64d%I64d%I64d%I64d",&number,&nu,&a,&b)!=EOF){
  eloc=0;
  memset(head,-1,sizeof(head)),memset(visit,false,sizeof(visit));
  __int64 i;
  for(i=1;i<number;i++){
   __int64 t1,t2,t3;
   scanf("%I64d%I64d%I64d",&t1,&t2,&t3);
   addEdge(t1,t2,t3,i);
   addEdge(t2,t1,t3,i);
  }
  __int64 now=0;
  for(i=1;i<=number;i++){
   if(!visit[i]){
    dfs(i);
   }
  }
  for(i=0;i<eloc;i++){
   edges[i].has=(number-edges[i].left)*(edges[i].left)*edges[i].dis;
  }

  if(a<=b){
   sort(&edges[0],&edges[eloc],com1);
   for(i=0;i<nu;i++){
    printf("%I64d ",edges[i].id);
   }
   printf("\n");
  }else{
   sort(&edges[0],&edges[eloc],com2);
   __int64 need=0;
   __int64 i=0;
   while(edges[i].has==0){
    i++;
   }
   __int64 j;
   for(j=0;j<nu;j++,i++){
    printf("%I64d ",edges[i].id);
   }
   printf("\n");

  }

 }
 return 0;
}


