#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAXN 110
#define MAXM 110
#define inf 9999999999.0
#define eps 1e-5
#define Abs(t) (t>0?t:-t)
double w[MAXN][MAXM];
double lx[MAXN],ly[MAXM];
int linky[MAXM];
bool visx[MAXN],visy[MAXM];
double slack[MAXM];
int nx,ny;

struct point
{
    double x,y;//double..
}ant[MAXN],apple[MAXM];

bool find(int x)
{
    visx[x]=1;
    for(int y=1;y<=ny;y++)
    {
        if(visy[y]) continue;
        double t=lx[x]+ly[y]-w[x][y];
        if(Abs(t)<eps)
        {
            visy[y]=1;
            if(linky[y] == -1 || find(linky[y]))
            {
                linky[y]=x;
                return true;
            }
        }
        else if(slack[y] >t)
            slack[y]=t;
    }
    return false;
}
void KM()
{
    int i,j;
    memset(linky,-1,sizeof(linky));
    memset(ly,0,sizeof(ly));
    for(i=1;i<=nx;i++)
    {
        lx[i]=-inf;
        for(j=1;j<=ny;j++)
            if(w[i][j] >lx[i])
                lx[i]=w[i][j];
    }
    for(int x=1;x<=nx;x++)
    {
        for(i=1;i<=ny;i++)
            slack[i]=inf;
        while(true)
        {
            memset(visx,0,sizeof(visx));
            memset(visy,0,sizeof(visy));
            if(find(x)) break;
            double d=inf;
            for(i=1;i<=ny;i++)
                if(!visy[i] && d>slack[i])
                    d=slack[i];
            for(i=1;i<=nx;i++)
                if(visx[i])
                    lx[i]-=d;
            for(i=1;i<=ny;i++)
                if(visy[i])
                    ly[i]+=d;
                else
                    slack[i]-=d;
        }
    }
}

double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

void init()
{
    for(int i=1;i<=nx;i++)
        scanf("%lf%lf",&ant[i].x,&ant[i].y);
    for(int i=1;i<=ny;i++)
        scanf("%lf%lf",&apple[i].x,&apple[i].y);
    for(int i=1;i<=ny;i++)
        for(int j=1;j<=nx;j++)
        {
            w[i][j]=-dist(apple[i],ant[j]);
        }
}

void solve()
{
    KM();
    for(int i=1;i<=ny;i++)
        printf("%d\n",linky[i]);

}

int main()
{
    while(scanf("%d",&nx) != EOF)
    {
        ny=nx;
        init();
        solve();
    }
    return 0;
}




