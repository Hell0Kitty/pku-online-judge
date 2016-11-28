#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
#define MAXN 10005 
struct Node
{
    int to,next;
}edge1[MAXN*5],edge2[MAXN*5];

int head1[MAXN];
int head2[MAXN];
int mark1[MAXN],mark2[MAXN];
int tot1,tot2;
int cnt1,cnt2,st[MAXN],belong[MAXN];
int num,setNum[MAXN];
struct Edge
{
    int l,r;
}e[MAXN*5];

void add(int a,int b)
{
    edge1[tot1].to=b;edge1[tot1].next=head1[a];head1[a]=tot1++;
    edge2[tot2].to=a;edge2[tot2].next=head2[b];head2[b]=tot2++; 
}   
void DFS1(int x)
{
    mark1[x]=1;
    for(int i=head1[x];i!=-1;i=edge1[i].next)
          if(!mark1[edge1[i].to])  DFS1(edge1[i].to);
    st[cnt1++]=x; 
}      
void DFS2(int x)
{
    mark2[x]=1;
    num++;
    belong[x]=cnt2;
    for(int i=head2[x];i!=-1;i=edge2[i].next)
       if(!mark2[edge2[i].to]) DFS2(edge2[i].to);
}     
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        tot1=tot2=1;
        for(int i=1;i<=n;i++)
        {
            head1[i]=head2[i]=-1;
            mark1[i]=mark2[i]=0;
        }
        for(int i=1;i<=m;i++)
        {
            int w,v;
            scanf("%d%d",&w,&v);
            e[i].l=w;e[i].r=v;
            add(w,v);
        }        
        cnt1=cnt2=1;
        for(int i=1;i<=n;i++)
        {
            if(!mark1[i])DFS1(i);
        }    
        for(int i=cnt1-1;i>=1;i--)
        {
            if(!mark2[st[i]])
            {
                num=0;
                DFS2(st[i]);
                setNum[cnt2++]=num;
            }    
        }

        int cnt=0;
        for(int i=1;i<cnt2;i++)
            if(setNum[i]>=2)cnt++;
        printf("%d\n",cnt);     
    }    
    return 0;
}



