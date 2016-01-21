#include<cstdio>
#include<cstring>
using namespace std;
int link[30],rlink[30],n;
bool g[30][30],chk[30];
bool findpath(int x)
{
    for(int y=0;y<n;y++)
    {
        if(g[x][y]&&!chk[y])
        {
            chk[y]=true;
            if(rlink[y]==-1||findpath(rlink[y]))
            {
                rlink[y]=x;
                link[x]=y;
                return true;
            }
        }
    }
    return false;
}
int maxmatch()
{
    memset(link,-1,sizeof(link));
    memset(rlink,-1,sizeof(rlink));
    int ret=0;
    for(int x=0;x<n;x++)
    {
        memset(chk,false,sizeof(chk));
        if(findpath(x))
            ret++;
    }
    return ret;
}
struct Rec
{
    int minx,maxx,miny,maxy;
}rec[30];
int main()
{
    int ca=0;
    while(scanf("%d",&n)&&n)
    {
        if(ca)
            printf("\n");
        memset(g,false,sizeof(g));
        for(int i=0;i<n;i++)
            scanf("%d%d%d%d",&rec[i].minx,&rec[i].maxx,&rec[i].miny,&rec[i].maxy);
        for(int i=0;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            for(int j=0;j<n;j++)
            {
                if(x>=rec[j].minx&&x<=rec[j].maxx&&y>=rec[j].miny&&y<=rec[j].maxy)
                {
                    g[j][i]=true;
                }
            }
        }
        maxmatch();
        printf("Heap %d\n",++ca);
        bool flag=true,ths;
        for(int i=0;i<n;i++)
        {
            int t=link[i],rl;
            ths=true;
            for(int j=0;j<n;j++)
            {
                if(t!=j&&g[i][j])
                {
                    rl=rlink[j];
                    link[rl]=-1;
                    rlink[j]=i;
                    link[i]=j;
                    rlink[t]=-1;
                    memset(chk,false,sizeof(chk));
                    chk[j]=true;
                    if(findpath(rl))
                    {
                        ths=false;
                        break;
                    }
                    rlink[j]=rl;
                    link[rl]=j;
                    link[i]=t;
                    rlink[t]=i;
                }
            }
            if(ths)
            {
                if(!flag)
                    printf(" ");
                flag=false;
                printf("(%c,%d)",'A'+i,link[i]+1);
            }
        }
        if(flag)
            printf("none");
        printf("\n");
    }
    return 0;
}


