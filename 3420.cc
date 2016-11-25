#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct MT
{
    int x,y;
    int mt[7][7];
}ans,def;

int n,m;

inline MT operator *(MT a,MT b)
{
    MT c;
    memset(c.mt,0,sizeof c.mt);
    c.x=a.x; c.y=b.y;
    for(int i=1;i<=a.x;i++)
        for(int j=1;j<=b.y;j++)
            for(int k=1;k<=a.y;k++)
                c.mt[i][j]=(c.mt[i][j]+(a.mt[i][k]%m)*(b.mt[k][j]%m))%m;
    return c;
}

void go()
{
    while(n)
    {
        if(n&1) ans=def*ans;
        def=def*def;
        n>>=1;
    }
    printf("%d\n",ans.mt[4][1]);
}

bool prev()
{
    if(n==1) {printf("%d\n",1%m);return false;}
    else if(n==2) {printf("%d\n",5%m);return false;}
    else if(n==3) {printf("%d\n",11%m);return false;}
    n-=4;

    memset(def.mt,0,sizeof def.mt);
    def.mt[1][2]=def.mt[2][3]=def.mt[3][4]=1;
    def.mt[4][1]=-1; def.mt[4][2]=1; def.mt[4][3]=5; def.mt[4][4]=1;
    def.x=def.y=4;

    ans.x=4; ans.y=1;
    ans.mt[1][1]=1; ans.mt[2][1]=5; ans.mt[3][1]=11; ans.mt[4][1]=36;
    return true;
}

int main()
{
    while(scanf("%d%d",&n,&m),n)
    {
        if(!prev()) continue;
        else go();
    }
    return 0;
}



