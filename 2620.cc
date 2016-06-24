#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct dian
{
    int s;
    int e;
    int l;
}d[100015],d1[100015];
bool cmp(struct dian a,struct dian b)
{
    if(a.s==b.s)
        return a.e<b.e;
    return a.s<b.s;
}
int main()
{

    int t,i,j;
    int st,en;
    int m,flag;
    int max1;
    int x,y;
    int sum,flag1;
    int k;
    while(scanf("%d",&m)!=EOF)
    {
        flag=0;
        sum=0;
        k=0;
        while(1)
        {
            scanf("%d%d",&x,&y);
            if(x==0&&y==0)
                break;
            d[k].s=x;
            d[k].e=y;
            d[k].l=y-x;
            k++;
        }
        sort(d,d+k,cmp);
        st=0;
        int kk=0;
        int pos=100005;
        int jl=0;
        while(st<m&&flag==0)
        {
            max1=-100005;
            pos=100005;
            for(i=kk;i<k;i++)
            {
                if(d[i].s<=st&&d[i].e>=st)
                {

                    if(d[i].e>max1) max1=d[i].e,pos=i;
                    kk++;
                }
                else if(d[i].s>st)
                    break;
            }

            if(pos==100005)
            {
                flag=1;
                break;
            }
            st=max1;
            sum++;
            d1[jl].s=d[pos].s;
            d1[jl++].e=d[pos].e;
        }
        if(flag==0)
        {
        printf("%d\n",sum);
          for(i=0;i<jl;i++)
          {
            printf("%d %d\n",d1[i].s,d1[i].e);
          }
        }
        if(flag==1)
            printf("No solution\n");
    }
}



