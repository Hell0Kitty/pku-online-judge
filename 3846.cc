#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;

#define MAXN 300
#define INF 0x3f3f3f3f

int ls[MAXN],le[MAXN],rs[MAXN],re[MAXN];
int f[MAXN][MAXN][2];
int n,nl,nr;

int main()
{
    int cs;
    scanf("%d",&cs);
    while(cs--)
    {
        scanf("%d",&n);
        nl=nr=0;
        for(int i=0;i<n;i++)
        {
            char s[3];
            int st,ed;
            scanf("%s%d%d",s,&st,&ed);
            if(s[0]=='A')
                ls[++nl]=st,le[nl]=ed;
            else
                rs[++nr]=st,re[nr]=ed;
        }
        for(int i=0;i<=nl;i++)
            for(int j=0;j<=nr;j++)
                f[i][j][1]=f[i][j][0]=INF;
        f[0][0][0]=f[0][0][1]=0;
        for(int i=0;i<=nl;i++)
            for(int j=0;j<=nr;j++)
                for(int k=0;k<2;k++)
                {
                    int cur,pre;
                    cur=pre=f[i][j][k]-10;
                    if(k==0)
                    {
                        for(int m=j+1;m<=nr;m++)
                        {
                            pre=max(pre+10,rs[m]);
                            cur=max(cur+10,pre+re[m]);
                            f[i][m][1]=min(f[i][m][1],cur);
                        }
                    }
                    else
                    {
                        for(int m=i+1;m<=nl;m++)
                        {
                            pre=max(pre+10,ls[m]);
                            cur=max(cur+10,pre+le[m]);
                            f[m][j][0]=min(f[m][j][0],cur);
                        }
                    }
                }
        printf("%d\n",min(f[nl][nr][0],f[nl][nr][1]));
    }
    return 0;
}



