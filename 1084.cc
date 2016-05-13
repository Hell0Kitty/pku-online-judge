#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int inf=1<<30;
const int NUM=100*60;
int cnt,L[NUM],R[NUM],S[NUM],D[NUM],U[NUM],C[NUM],O[NUM],H[NUM],X[NUM];
/*
    NUM:最大结点数
    U,D,L,R：上下左右结点
    C：列的头指针位置
    O：储存答案
    X：与O配合代表第几行（X[O[i]]]）
    通过link（r,c）加点，dfs（0）运算
*/
void remove(int c)
{
    for(int i=D[c];i!=c;i=D[i])
    {
        L[R[i]]=L[i];
        R[L[i]]=R[i];
    }
}
void resume(int c)
{
    for(int i=D[c];i!=c;i=D[i])
    {
        L[R[i]]=i;
        R[L[i]]=i;
    }
}
int geth()
{
    bool has[80];
    memset(has, false, sizeof(has));
    int res=0;
    for(int i=R[0]; i!=0; i=R[i])
        if(!has[i])
        {
            res++;
            for(int j=D[i]; j!=i; j=D[j])
                for(int k=R[j]; k!=j; k=R[k])
                    has[C[k]]=true;
        }
    return res;
}
int ans;
void dfs(int k)
{
    if(!R[0])
    {
        ans=min(k,ans);
        return;
    }
    else if(k+geth()>=ans)
        return;
    int c=R[0];
    for(int t=R[0],ms=inf; t!=0; t=R[t])
        if(S[t]<ms)
            ms=S[t],c=t;
    for(int i=D[c];i!=c;i=D[i])
    {
        remove(i);
        for(int j=R[i]; j!=i; j=R[j])
        {
            remove(j);
            S[C[j]]--;
        }
        dfs(k+1);
        for(int j=L[i]; j!=i; j=L[j])
        {
            resume(j);
            S[C[j]]++;
        }
        resume(i);
    }
}
void build(int r,int c)
{
    for(int i=0;i<=c;i++)
    {
        U[i]=D[i]=i;
        L[i+1]=i;
        R[i]=i+1;
        C[i]=i;
        S[i]=0;
    }
    R[cnt=c]=0;
    while(r)
        H[r--]=-1;
}
void link(int r,int c)
{
    ++S[C[++cnt]=c];
    X[cnt]=r;
    D[cnt]=D[c];
    U[D[c]]=cnt;
    U[cnt]=c;
    D[c]=cnt;
    if(H[r]<0)
        H[r]=L[cnt]=R[cnt]=cnt;
    else
    {
        R[cnt]=R[H[r]];
        L[R[H[r]]]=cnt;
        L[cnt]=H[r];
        R[H[r]]=cnt;
    }
}
bool mark[80][80];
void init(int n)
{
    memset(mark,false,sizeof(mark));
    int i,j,k,si,num=0,c=1;
    for(si=1;si<=n;si++)
    {
        for(i=1;i<=n-si+1;i++)
        {
            for(j=1;j<=n-si+1;j++)
            {
                for(k=0;k<si;k++)
                {
                    mark[(i-1)*(2*n+1)+j+k][c]=true;
                    mark[(i-1+si)*(2*n+1)+j+k][c]=true;
                    mark[i*n+(i-1)*(n+1)+j+k*(2*n+1)][c]=true;
                    mark[i*n+(i-1)*(n+1)+j+k*(2*n+1)+si][c]=true;
                }
                c++;
            }
        }
    }
}
int main()
{
    int T,n;
    for(scanf("%d",&T);T;T--)
    {
        scanf("%d",&n);
        int num,row=2*n*(n+1),col=0;
        for(int i=1;i<=n;i++)
            col+=i*i;
        build(row,col);
        init(n);
        scanf("%d",&num);
        bool vis[80];
        memset(vis,false,sizeof(vis));
        for(int i=0;i<num;i++)
        {
            int r;
            scanf("%d",&r);
            for(int j=1;j<=col;j++)
            {
                if(mark[r][j])
                {
                    if(!vis[j])
                    {
                        vis[j]=true;
                        R[L[j]]=R[j];
                        L[R[j]]=L[j];
                        R[j]=L[j]=0;
                    }
                }
            }
        }
        for(int i=1;i<=row;i++)
            for(int j=1;j<=col;j++)
                if(mark[i][j]&&!vis[j])
                    link(i,j);
        ans=100000;
        dfs(0);
        printf("%d\n",ans);
    }
    return 0;
}


