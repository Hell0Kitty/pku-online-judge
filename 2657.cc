#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
inline int extgcd(int a,int b,int &x,int &y)
{
    if (b==0)
    {
        x=1,y=0;
        return a;
    }
    int d, tp;
    d=extgcd (b, a%b, x, y);
    tp=x;
    x=y;
    y=tp - a/b*y;
    return d;
}
inline int getx(int a, int b, int n) // ! n > 0
{
    int e, i, d, x, y;
    d = extgcd(a, n, x, y);
    if (b%d>0) return -1;
    else
    {
        e=(x*(b/d))%n;
        int ans=e,t=n/d,num=(n-e)/t;
        for(i=-1;i<=1;i++)
            e=(e+(num+i)*t+n)%n,ans=min(ans,e);
        return ans;
    }
}
int s1[1005],s2[1005],top1,top2;
int main()
{
    int n,z,m;
    while(scanf("%d%d%d",&n,&z,&m)!=EOF)
    {
        int i,k,v;
        top1=top2=0;
        for(int i=0; i<m; i++)
        {
            scanf("%d",&v);
            if(v<z)
                s1[top1++]=v;
            else
                s2[top2++]=v;
        }
        if(top1==0)
        {
            printf("1\n");
            continue;
        }
        for(k=2; k<z; k++)
        {
            int b,d=gcd(k,z-1);
            if(d==k)
            {
                for(i=0; i<top1; i++)
                    if((s1[i]-1)%k==0)
                        break;
                if(i<top1)
                    continue;
                printf("%d\n",k);
                break;
            }
            m=getx(n,k-(z-1)%k,k);
            if(m==-1)
                continue;
            for(i=0; i<top1; i++)
                if((s1[i]-1)%k==0||((v=getx(n,k-(s1[i]-1)%k,k))!=-1&&v<=m))
                    break;
            if(i<top1)
                continue;
            for(i=0; i<top2; i++)
                if((s2[i]-1)%k==0||((v=getx(n,k-(s2[i]-1)%k,k))!=-1&&v<m))
                    break;
            if(i<top2)
                continue;
            printf("%d\n",k);
            break;
        }
    }
    return 0;
}


