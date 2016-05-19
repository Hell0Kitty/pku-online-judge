#include <iostream>
#include <stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<ctype.h>
using namespace std;
#define MAXN     100000
char m[110];
char k[110];
long long p[110];
long long q[110];
long long start[1000];
long long ans[1000];
long long res[1000];
long long mm[1000];
long long kk[1000];
long long a[1000];
long long b[1000];
long long d;
long long vi[110];
long long getnum(char c)
{
    return c-'0';
}
void trans(char* str,long long base0,long long base1)
{
    memset(res,0,sizeof(res));
    long long y,i,j;
    start[0]=strlen(str);
    for(i=1;i<=start[0];i++)
    {
        start[i]=getnum(str[i-1]);
    }
    while(start[0]>=1)
    {
        y=0; //余数
        ans[0]=start[0];
        for(i=1;i<=start[0];i++)
        {
            y=y*base0+start[i];
            ans[i]=y/base1;
            y%=base1;
        }
        res[++res[0]]=y;  //这一轮的余数
        i=1;
        while(i<=ans[0]&&ans[i]==0)
            i++;
        memset(start,0,sizeof(start));
        for(j=i;j<=ans[0];j++)
            start[++start[0]]=ans[j];
        memset(ans,0,sizeof(ans));
    }
    return;
}
long long save(long long *dis)
{
    for(long long i=res[0];i;i--)
    {
        dis[res[0]-i]=res[i];
    }
    return res[0];
}
long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(!b)
    {
        x=1;
        y=0;
        return a;
    }
    long long tt=exgcd(b,a%b,x,y);
    long long t;
    t=x;
    x=y;
    y=(t-a/b*y);
    return tt;
}
long long solve(long long r)
{
    long long a1,a2,b1,b2,x,y,A,B,C,d,t;
    a1=a[0];
    b1=b[0];
    for(long long i=1;i<r;i++)
    {
        a2=a[i];
        b2=b[i];
        A=a1;
        B=a2;
        C=b2-b1;
        d=exgcd(A,B,x,y);
        if(C%d)
        {
            return -1;
        }
        t=B/d;
        x=(x*(C/d)%t+t)%t;
        b1=a1*x+b1;
        a1=a1/d*a2;
    }
    return b1;
}
int main()
{
    while(scanf("%lld",&d),d!=-1)
    {
        for(long long i=1;i<d;i++)
            scanf("%lld",p+i);
        for(long long i=0;i<d;i++)
            scanf("%lld",q+i);
        scanf("%s%s",m,k);
        trans(m,10,d);
        long long nm=save(mm);
        trans(k,10,d);
        long long nk=save(kk);
        if(nm!=nk)
        {
            puts("NO");
            continue;
        }
        memset(a,-1,sizeof(a));
        memset(b,-1,sizeof(b));
        bool have=1;
        for(long long i=0;i<nm;i++)
        {
            bool ok=0;
            long long tmp=0;
            memset(vi,0,sizeof(vi));
            for(long long j=mm[i];;)
            {
                if(j==kk[i])
                {
                    if(ok==0)
                    {
                        b[i]=tmp;
                        ok=1;
                    }
                    else
                    {
                        a[i]=tmp-b[i];
                        break;
                    }
                }
                tmp++;
                if(i==0)
                    j=p[j];
                else
                    j=q[j];
                if(tmp>=5000)
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)
            {
                have=0;
                break;
            }
        }
        if(!have)
        {
            puts("NO");
            continue;
        }
        long long ans=solve(nm);
        if(ans==-1)
        {
            puts("NO");
            continue;
        }
        printf("%lld\n",ans);
    }
    return 0;
}



