#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=25e3+9;
int n;
bool use[maxn];
struct
{
    int a,b,c,d;
}data[maxn];
struct A
{
    int key,down,up,id;
    bool operator <(const A & xx) const
    {
        if(key==xx.key) return down<xx.down;
        return key<xx.key;
    }
}a[maxn<<1];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&data[i].a,&data[i].b);
            scanf("%d %d",&data[i].c,&data[i].d);
        }
        memset(use,0,sizeof(use));
        for(int i=1;i<=n;i++)
        {
            a[i*2-1].key=data[i].a;
            a[i*2-1].down=data[i].b;
            a[i*2-1].up=data[i].d;
            a[i*2].key=data[i].c;
            a[i*2].down=data[i].b;
            a[i*2].up=data[i].d;
            a[i*2].id=a[i*2-1].id=i;
        }
        sort(a+1,a+n+n+1);
        for(int i=1,j;i<=n+n;i=j)
        {
            for(j=i;j<=n+n;j++)
            if(a[i].key!=a[j].key) break;

            int up=a[i].up;
            for(int k=i+1;k<j;k++)
            {
                if(a[k].down<=up)
                use[a[k].id]=use[a[k-1].id]=1;
                up=max(up,a[k].up);
            }
        }

        for(int i=1;i<=n;i++)
        {
            a[i*2-1].key=data[i].b;
            a[i*2-1].down=data[i].a;
            a[i*2-1].up=data[i].c;
            a[i*2].key=data[i].d;
            a[i*2].down=data[i].a;
            a[i*2].up=data[i].c;
            a[i*2].id=a[i*2-1].id=i;
        }
        sort(a+1,a+n+n+1);
        for(int i=1,j;i<=n+n;i=j)
        {
            for(j=i;j<=n+n;j++)
            if(a[i].key!=a[j].key) break;

            int up=a[i].up;
            for(int k=i+1;k<j;k++)
            {
                if(a[k].down<=up)
                use[a[k].id]=use[a[k-1].id]=1;
                up=max(up,a[k].up);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++) ans+=!use[i];
        cout<<ans<<endl;
    }
    return 0;
}



