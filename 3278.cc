#include <stdio.h>
#include <string.h>
struct data
{
  int x,min;
}queue[100000],now;

int flag[100000];
int in,out;
int N,K;

int bfs()
{
    in=out=0;
    queue[in].x=N;
    queue[in].min=0;
    memset(flag,0,sizeof(flag));
    flag[N]=1;
    in++;

    while(1)
    {
        now=queue[out++];

        if(now.x==K)
            return now.min;
        if(now.x+1<=100000 && !flag[now.x+1])
        {
            queue[in].x=now.x+1;
            queue[in++].min=now.min+1;
            flag[now.x+1]=1;
        }
        if(now.x-1>=0 && !flag[now.x-1])
        {
            queue[in].x=now.x-1;
            queue[in++].min=now.min+1;
            flag[now.x-1]=1;
        }
        if(now.x*2<=100000 && !flag[now.x*2])
        {
            queue[in].x=now.x*2;
            queue[in++].min=now.min+1;
            flag[now.x*2]=1;
        }
    }
    return 213;
}

int main()
{
    while((scanf("%d%d",&N,&K))!=EOF)
    {
        printf("%d\n",bfs());
    }
    return 0;
}
