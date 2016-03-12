/* 
Memory 176K 
Time   0MS 
*/  
#include <iostream>  
#include <memory.h>
#include <stdio.h>
#include <limits.h>
using namespace std;  
#define MAXV 20  
#define INF INT_MAX  
  
int map[MAXV][MAXV],d[MAXV],parent[MAXV];  
int n,fire,stasum,station[MAXV];  
  
void dijkstra(){  
    int i,j,v,tmp;  
    bool vis[MAXV];  
    memset(parent,-1,sizeof(parent));  
    memset(vis,false,sizeof(vis));  
    for(i=1;i<=n;i++) d[i]=INF;  
    d[fire]=0;  
  
    for(i=1;i<=n;i++){  
        tmp=INF;  
        for(j=1;j<=n;j++)  
            if(d[j]<tmp && !vis[j]){  
                tmp=d[j];  
                v=j;  
            }  
        vis[v]=true;  
        for(j=1;j<=n;j++){  
            if(!vis[j] && map[v][j]!=-1 && d[j]>d[v]+map[v][j]){     //-1不能走  
                d[j]=d[v]+map[v][j];  
                parent[j]=v;        //记录路径  
            }  
        }  
    }  
}  
  
void output(){  
    int j,i,tmp,v;  
    printf("Org Dest    Time    Path\n");  
      
    j=0;  
    while(j!=stasum){  
        tmp=INF;  
        for(i=1;i<=n;i++){                   //每次找最小的时间输出  
            if(station[i] && d[i]<tmp){  
                tmp=d[i];  
                v=i;  
            }  
        }  
        station[v]=0;                       //将这个站点设为非消防站  
        printf("%d  %d  %d",v,fire,d[v]);  
        while(v!=-1){  
            printf("    %d",v);  
            v=parent[v];  
        }  
        printf("\n");  
        j++;  
    }  
}  
  
int main(){  
    int i,j,x;  
    scanf("%d",&n);  
    for(i=1;i<=n;i++){  
        for(j=1;j<=n;j++){  
            scanf("%d",&map[j][i]);     //边反向存储  
        }  
    }  
    scanf("%d",&fire);  
    stasum=0;  
    memset(station,0,sizeof(station));  
    while(~scanf("%d",&x)) {  
        station[x]=1;                   //标记消防站  
        stasum++;                       //计算消防站总数  
    }  
  
    dijkstra();  
    output();  
    return 0;  
}  
