#include<stdio.h>
#include<string.h>
#define inf 0x7fffffff
struct edge//边  
{  
    int u,v,f,next,b,c;  
}e[1500];  
int head[70],in[70],s,t,ss,tt,yong,sum;
int n,m;
void ini()
{
	memset(head,-1,sizeof(head));
	yong=0;
	memset(in,0,sizeof(in));
	s=0,t=n+1,ss=t+1,tt=ss+1;
	sum=0;
}
void adde(int from,int to,int xia,int shang) 
{	  
    e[yong].u=from,e[yong].v=to,e[yong].f=shang-xia,e[yong].b=xia,e[yong].c=shang;  
    e[yong].next=head[from],head[from]=yong++;    
    e[yong].u=to,e[yong].v=from,e[yong].f=0,e[yong].b=xia,e[yong].c=shang;  
    e[yong].next=head[to],head[to]=yong++;  
} 
void build()
{
	int i;  
    for(i=0;i<=t;++i)  
    {  
        if(in[i]>0)  
            adde(ss,i,0,in[i]);  
        else  
        {  
            adde(i,tt,0,-in[i]);  
            sum+=(-in[i]);  
        }  
    } 
}
int d[1000],num[1000];
int min(int a,int b){return a<b?a:b;}  
int sap_gap(int u,int f,int s,int t)
{  
    if(u==t)  
        return f;  
    int i,v,mind=t,last=f,cost;  
    for(i=head[u];i!=-1;i=e[i].next)  
    {  
        v=e[i].v;  
        int flow=e[i].f;  
        if(flow>0)
        {  
            if(d[u]==d[v]+1)  
            {  
                cost=sap_gap(v,min(last,flow),s,t);  
                e[i].f-=cost;  
                e[i^1].f+=cost;  
                last-=cost;  

                if(d[s]>=t+1)  
                    return f-last;  

                if(last==0)  
                    break;  
            }  
            if(d[v]<mind)  
                mind=d[v];  
        }  
    }  

    if(last==f)  
    {  
        --num[d[u]];  
        if(num[d[u]]==0)  
            d[s]=t+1;  
        d[u]=mind+1;  
        ++num[d[u]];  
    }  
    return f-last;  
}  
int max_f(int s,int t)
{
    int f=0;  
    memset(d,0,sizeof(d));  
    memset(num,0,sizeof(num));  
    for(num[s]=t+1;d[s]<t+1;)  
        f+=sap_gap(s,inf,s,t);  
    return f; 
}
int main()
{
	int i,dat,u,v,f1,f2,p;
	char from[10],to[10];
	while(scanf("%d%d",&n,&m),n+m)
	{
		ini();
		for(i=1;i<=m;++i)
		{
			scanf("%s%s%d",from,to,&dat);
			if(from[0]=='+') u=s;
			else sscanf(from,"%d",&u);
			if(to[0]=='-') v=t;
			else sscanf(to,"%d",&v);
			adde(u,v,dat,inf);
			in[u]-=dat,in[v]+=dat;
		}
		build();

		f1=max_f(ss,tt);
		p=yong;
		adde(t,s,0,inf);
		f2=max_f(ss,tt);
		if(f1+f2!=sum) printf("impossible\n");
		else printf("%d\n",e[p^1].f);
	}
	return 0;
}



