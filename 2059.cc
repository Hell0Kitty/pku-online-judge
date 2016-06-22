#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int po[60][2];
int s,n;
bool solve(int x,int y)
{
    int len=min(min(x,y),min(s-x,s-y));
    len=len*len;
    for(int i=0;i<n;i++)
    {
        int xx=po[i][0],yy=po[i][1];
        if((xx==x&&yy==y)||((xx-x)*(xx-x)+(yy-y)*(yy-y))>len)
            return false;
    }
    return true;
}
int main()
{
    int T;
    for(scanf("%d",&T);T;T--)
    {
        scanf("%d%d",&s,&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&po[i][0],&po[i][1]);
        bool flag=false;
        for(int x=1;x<s;x++)
        {
            for(int y=1;y<s;y++)
            {
                if(solve(x,y))
                {
                    flag=true;
                    printf("%d %d\n",x,y);
                    x=y=s;
                }
            }
        }
        if(!flag)
            printf("poodle\n");
    }
    return 0;
}



