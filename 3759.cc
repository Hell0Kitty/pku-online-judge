#include<iostream>
using namespace std;
#define size 500
#define Max 0x7fffffff
int cap[size][size],s,t,n;
int queue[size],head,tail, Flow,prev[size];
bool findload()      //bfs找增广路径
{
 int i, tmp;
 memset(prev,-1,sizeof(prev));
 head = tail = 0;;
 queue[tail++] = s;
 prev[s] = s;
 while(head < tail)
 {
  tmp = queue[head++];
  for(i = 1; i <= n; i++)
   if(prev[i] == -1 && cap[tmp][i] > 0)
   {
    prev[i] = tmp;
    if (i == t) return true;
    queue[tail++] = i;
   }
 }
 return false;
}
int maxflow()
{
    Flow = 0;
 while(findload())
 {
  int min = Max;
  for(int i = t; i != s; i = prev[i])  //增广路径中的最小可通过流
   if(min > cap[prev[i]][i])
    min = cap[prev[i]][i];
  for(int i = t; i != s; i = prev[i])//调整路径上的流
  {
   cap[prev[i]][i] -= min;
   cap[i][prev[i]] += min;
  }
  Flow += min;   //最大流累加
 }
 return Flow;
}
int nn, mm, x, y[210][210];
int main()
{
    scanf("%d%d", &nn, &mm);
    s = nn + mm + 1; n = t = nn + mm + 2;
    memset(cap, 0, sizeof(cap));
    for(int i = 1; i <= nn; i++)
    {
        scanf("%d", &x);
        cap[s][i] = x;
    }
    for(int i = 1; i <= mm; i++)
    {
        scanf("%d", &x);
        cap[i + nn][t] = x;
        y[i][0] = 1;
        int k; scanf("%d", &k);
        for(int j = 0; j < k; j++)
        {
            scanf("%d", &x);
            y[i][y[i][0]++] = x + 1;
            cap[x + 1][i + nn] = cap[s][x + 1];
        }
    }
    printf("%d\n", maxflow());
    for(int i = 1; i <= mm; i++)
    {
        for(int j = 1; j < y[i][0]; j++)
        {
            printf("%d", cap[i + nn][y[i][j]]);
            if (j < y[i][0] - 1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}



