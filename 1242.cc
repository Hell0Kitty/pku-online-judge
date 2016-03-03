#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

struct M
{
    int x,y;
};

M S[20000],O[20000];
int n,m,res,MIN;
int map[110][110],tmpmap[110][110],a[20000],b[20000];

void InitPlug_front()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            S[(i-1)*n+j].x=i;
            S[(i-1)*n+j].y=j;
            map[i][j]=(i-1)*n+j;
            O[(i-1)*n+j].x=i;
            O[(i-1)*n+j].y=j;
        }
    }
    return ;
}

void InitPlug_back()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            S[(i-1)*n+(n-j+1)].x=i;
            S[(i-1)*n+(n-j+1)].y=j;
            map[i][j]=(i-1)*n+n-j+1;
        }
    }
    return ;
}

void Rotate()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            tmpmap[j][n-i+1]=map[i][j];
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            map[i][j]=tmpmap[i][j];
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            S[map[i][j]].x=i;
            S[map[i][j]].y=j;
        }
    }
}

int main()
{
    int cse=1;
    int i,j;
    while(scanf("%d",&n),n)
    {
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a[i],&b[i]);
        }
        InitPlug_front();//-------------Init Map-front
        res=0;
        MIN=0x7fffffff;
        for(i=0;i<m;i++)
        {
            res+=abs(S[b[i]].x-O[a[i]].x)+abs(S[b[i]].y-O[a[i]].y);
        }
        if(res<MIN)MIN=res;
        Rotate();//---------------90 degree clockwise
        res=0;
        for(i=0;i<m;i++)
        {
            res+=abs(S[b[i]].x-O[a[i]].x)+abs(S[b[i]].y-O[a[i]].y);
        }
        if(res<MIN)MIN=res;
        Rotate();//---------------180 degree clockwise
        res=0;
        for(i=0;i<m;i++)
        {
            res+=abs(S[b[i]].x-O[a[i]].x)+abs(S[b[i]].y-O[a[i]].y);
        }
        if(res<MIN)MIN=res;
        Rotate();//---------------270 degree clockwise
        res=0;
        for(i=0;i<m;i++)
        {
            res+=abs(S[b[i]].x-O[a[i]].x)+abs(S[b[i]].y-O[a[i]].y);
        }
        if(res<MIN)MIN=res;
        InitPlug_back();//-------------Init Map-back
        res=0;
        for(i=0;i<m;i++)
        {
            res+=abs(S[b[i]].x-O[a[i]].x)+abs(S[b[i]].y-O[a[i]].y);
        }
        if(res<MIN)MIN=res;
        Rotate();//---------------90 degree clockwise
        res=0;
        for(i=0;i<m;i++)
        {
            res+=abs(S[b[i]].x-O[a[i]].x)+abs(S[b[i]].y-O[a[i]].y);
        }
        if(res<MIN)MIN=res;
        Rotate();//---------------180 degree clockwise
        res=0;
        for(i=0;i<m;i++)
        {
            res+=abs(S[b[i]].x-O[a[i]].x)+abs(S[b[i]].y-O[a[i]].y);
        }
        if(res<MIN)MIN=res;
        Rotate();//---------------270 degree clockwise
        res=0;
        for(i=0;i<m;i++)
        {
            res+=abs(S[b[i]].x-O[a[i]].x)+abs(S[b[i]].y-O[a[i]].y);
        }
        if(res<MIN)MIN=res;
        printf("Scenario %d: smallest average = %.4f\n\n",cse++,1.0*(MIN+m)/(1.0*m));
    }

    return 0;
}


