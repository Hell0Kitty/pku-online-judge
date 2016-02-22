#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool graph[250][250];

int main()
{
    int n,t,casecnt=0;
    while(scanf("%d%d",&n,&t)!=EOF,!(n==0&&t==0))
    {
        int res=0;
        memset(graph,0,sizeof(graph));

        for(int i=1;i<=n;i++) graph[i][i]=true;
        for(int i=0;i<t;i++)
        {
            int a,b; scanf("%d%d",&a,&b);
            if(graph[b][a]) { res++; }
            else if(!graph[a][b])
            {
                graph[a][b]=true;
                for(int j=1;j<=n;j++)
                {
                    if(graph[j][a])
                    {
                        graph[j][b]=true;
                        for(int k=1;k<=n;k++)
                        {
                            if(graph[b][k]) graph[j][k]=true;
                        }
                    }
                }
            }
        }
        casecnt++;
        printf("%d. %d\n",casecnt,res);
    }
    return 0;
}


