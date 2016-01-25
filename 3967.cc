#include <iostream>             
#include <stdio.h>             
#include <cmath>             
#include <algorithm>             
#include <iomanip>             
#include <cstdlib>             
#include <string>             
#include <string.h>             
#include <vector>             
#include <queue>             
#include <stack>             
#include <map>           
#include <set>           
#include <ctype.h>             
#define INF 1<<30         
#define ll long long         
#define max3(a,b,c) max(a,max(b,c))         
#define MAXN 1000    

using namespace std;    

struct edge{    
    int v;    
    int c;    
};    

edge eg[410000];
int head[410000];  
int next[410000];
int level[110000];
int tmp[410000];
bool vis[110000];    
int minc[110000]; 
int Q[410000];

int main(){
    int n,m;    
    while(~scanf("%d%d",&n,&m)){        
        int front=0;  
        int rear=0;  
        memset(level,0,sizeof(level));    
        memset(head,-1,sizeof(head));  
        memset(next,-1,sizeof(next));  
        memset(vis,0,sizeof(vis));    
        for(int i=0;i<=n;i++)minc[i]=INF;  

        for(int i=1;i<=m;i++){    
            int u,v,c;    
            scanf("%d%d%d",&u,&v,&c);    
            int h;  

            eg[i*2-1].v=v; eg[i*2-1].c=c;   
            next[i*2-1]=head[u];  
            head[u]=i*2-1;  

            eg[i*2].v=u; eg[i*2].c=c;    
            next[i*2]=head[v];  
            head[v]=i*2;  

        }  

        Q[rear++]=n;  
        level[n]=1;    
        vis[n]=1;  
        while(front!=rear){      
            int cur=Q[front]; front++;    
            int t=head[cur];  
            while(t!=-1){    
                int v=eg[t].v;    
                if( !vis[v]){    
                    level[v]=level[cur]+1;     
                    Q[rear++]=v;  
                    vis[v]=1;    
                }    
                t=next[t];  
            }    
        }

		memset(vis,0,sizeof(vis)); 
        int test=rear;  
        front=rear=0;  
        Q[rear++]=1;  
        int k=level[1];  
        for(int i=k;i>1;i--){  
            int end=0;  
            while(front!=rear){    
                int cur=Q[front]; front++;  
                tmp[end++]=cur;  
            }  
            for(int j=0;j<end;j++){  
                int cur=tmp[j];  
                int t=head[cur];   
                while(t!=-1){  
                    int v=eg[t].v;  
                    if( !vis[v]&&level[v]==i-1 && eg[t].c<minc[i-1]  ){    
                        minc[i-1]= eg[t].c;    
                    }    
                    t=next[t];  
                }  
            }  

            for(int j=0;j<end;j++){  
                int cur=tmp[j];  
                int t=head[cur];   
                while(t!=-1){  
                    int v=eg[t].v;  
                    if( !vis[v]&&level[v]==i-1 && eg[t].c==minc[i-1]  ){    
                        vis[v]=1;
                        Q[rear++]=v;  
                    }   
                    t=next[t];  
                }  
            }  
        }  

        printf("%d\n",level[1]-1);    
        for(int i=k-1;i>=1;i--){  
            printf("%d",minc[i]);  
            if(i!=1)printf(" ");  
        }  
        printf("\n");  
    }    
    return 0;    
}


