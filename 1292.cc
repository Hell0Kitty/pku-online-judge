#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<queue>
using namespace std;
#define MAX 99999999999999
struct point
{
    double x;
    double y;
};
struct line
{
    point first;//西南
    point last;//东北
    double length;
    double len;
}l[1010];//l[0],l[1],,,l[n-1]
int n;
double linjie[1010][1010];
double distpp(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
double distpl(point a,line b)//求a到b所在直线的距离
{
    if(b.first.x==b.last.x)
    {
        return (a.x*1.0-1.0*b.first.x)*(a.x*1.0-1.0*b.first.x);
    }
    if(b.first.y==b.last.y)
    {
        return (a.y-b.first.y)*(a.y-b.first.y);
    }
}
double cal2(int x,int y)//l[x],l[y]
{
    if(l[x].first.x==l[x].last.x&&l[y].first.x==l[y].last.x)//l[x]为南北方向,l[y]为南北方向
    {
        if(l[x].last.y<l[y].first.y)//l[x]整个在l[y]下面
        {
            return distpp(l[x].last,l[y].first);
        }
        else if(l[y].last.y<l[x].first.y)//l[y]整个在l[x]下面
        {
            return distpp(l[y].last,l[x].first);
        }
        else 
        {
            return distpl(l[x].first,l[y]);
        }
    }
    else if(l[x].first.y==l[x].last.y&&l[y].first.y==l[y].last.y)//l[x]为西东方向，l[y]为西东方向
    {
        if(l[x].last.x<l[y].first.x)//l[x]整个在l[y]左边
        {
            return distpp(l[x].last,l[y].first);
        }
        else if(l[y].last.x<l[x].first.x)//l[y]整个在l[x]左边
        {
            return distpp(l[y].last,l[x].first);
        }
        else 
        {
            return distpl(l[y].first,l[x]);
        }
    }
    else if(l[x].first.x==l[x].last.x&&l[y].first.y==l[y].last.y)//l[x]为南北方向，l[y]为西东方向
    {
        if(l[y].first.y<l[x].first.y)
        {
            if(l[x].first.x<l[y].first.x)
            {

                return distpp(l[y].first,l[x].first);
            }
            else if(l[y].last.x<l[x].first.x)
            {

                return distpp(l[y].last,l[x].first);
            }
            else
            {

                return distpl(l[x].first,l[y]);
            }
        }
        else if(l[y].first.y>=l[x].first.y&&l[y].first.y<=l[x].last.y)
        {
            if(l[x].first.x>=l[y].first.x&&l[x].first.x<=l[y].last.x)
            {

                return 0;
            }
            else if(l[y].first.x>l[x].first.x)
            {

                return (l[y].first.x-l[x].first.x)*(l[y].first.x-l[x].first.x);
            }
            else
            {

                return (l[x].first.x-l[y].last.x)*(l[x].first.x-l[y].last.x);
            }
        }
        else
        {
            if(l[x].first.x<l[y].first.x)
            {

                return distpp(l[y].first,l[x].last);
            }
            else if(l[x].last.x>l[y].last.x)
            {

                return distpp(l[y].last,l[x].last);
            }
            else
            {

                return distpl(l[x].last,l[y]);
            }
        }
    }
    else//l[x]为西东方向，l[y]为南北方向
    {
        line temp=l[x];
        l[x]=l[y];
        l[y]=temp;
        double tt;
        if(l[y].first.y<l[x].first.y)
        {
            if(l[x].first.x<l[y].first.x)
            {
                tt=distpp(l[y].first,l[x].first);
                temp=l[x];
                l[x]=l[y];
                l[y]=temp;
                return tt;
            }
            else if(l[y].last.x<l[x].first.x)
            {
                tt=distpp(l[y].last,l[x].first);
                temp=l[x];
                l[x]=l[y];
                l[y]=temp;
                return tt;
            }
            else
            {
                tt=distpl(l[x].first,l[y]);
                temp=l[x];
                l[x]=l[y];
                l[y]=temp;
                return tt;
            }
        }
        else if(l[y].first.y>=l[x].first.y&&l[y].first.y<=l[x].last.y)
        {
            if(l[x].first.x>=l[y].first.x&&l[x].first.x<=l[y].last.x)
            {
                temp=l[x];
                l[x]=l[y];
                l[y]=temp;
                return 0;
            }
            else if(l[y].first.x>l[x].first.x)
            {
                tt=(l[y].first.x-l[x].first.x)*(l[y].first.x-l[x].first.x);
                temp=l[x];
                l[x]=l[y];
                l[y]=temp;
                return tt;
            }
            else
            {
                tt=(l[x].first.x-l[y].last.x)*(l[x].first.x-l[y].last.x);
                temp=l[x];
                l[x]=l[y];
                l[y]=temp;
                return tt;
            }
        }
        else
        {
            if(l[x].first.x<l[y].first.x)
            {

                tt=distpp(l[y].first,l[x].last);
                temp=l[x];
                l[x]=l[y];
                l[y]=temp;
                return tt;
            }
            else if(l[x].last.x>l[y].last.x)
            {
                tt=distpp(l[y].last,l[x].last);
                temp=l[x];
                l[x]=l[y];
                l[y]=temp;
                return tt;
            }
            else
            {
                tt=distpl(l[x].last,l[y]);
                temp=l[x];
                l[x]=l[y];
                l[y]=temp;
                return tt;
            }
        }
        temp=l[x];
        l[x]=l[y];
        l[y]=temp;
    }
}
void cal()
{
    int i,j;
    double temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            temp=cal2(i,j);
            linjie[i][j]=temp;
            linjie[j][i]=temp;
        }
    }
}
struct T
{
    int u;//直线编号
    double len;
};
bool operator<(T a,T b)
{
    return b.len<a.len;
}

bool flag[1010];
priority_queue<T>Q;
void dijkstra()
{
    while(!Q.empty())
    {
        Q.pop();
    }
    T qi;
    int i;
    qi.len=0;
    qi.u=0;
    Q.push(qi);
    l[0].len=0;
    T re;
    for(i=1;i<n;i++)
    {
        l[i].len=MAX;
    }
    double mmax;

    while(!Q.empty())
    {
        T temp=Q.top();Q.pop();
        for(i=0;i<n;i++)
        {
            if(temp.u==i)
            {
                continue;
            }
            mmax=temp.len>linjie[temp.u][i]?temp.len:linjie[temp.u][i];
            if(mmax<l[i].len)
            {
                //printf("%d节点把%d节点扩展为%.2f\n",temp.u,i,mmax);
                l[i].len=mmax;
                re.len=l[i].len;
                re.u=i;
                Q.push(re);
            }
        }
    }
    printf("%.2f\n",sqrt(l[1].len));
}
int main()
{
    int a,b,c;
    int i;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(c>=0)
            {
                l[i].first.x=a;
                l[i].first.y=b;
                l[i].last.x=a+c;
                l[i].last.y=b;
                l[i].length=c;
            }
            else
            {
                l[i].first.x=a;
                l[i].first.y=b;
                l[i].last.x=a;
                l[i].last.y=b-c;
                l[i].length=-1*c;
            }
        }
        //线段的输入完毕,l[0],l[1],,,,l[n-1]
        cal();//计算线段的两两距离，存进linjie、、计算线段距离由于必定是横的或者竖的，所以分情况考虑，情况比较多，这个比较容易实现

        int j;
        /*
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%.2f ",linjie[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        //*/
        dijkstra();
    }
    return 0;
}


