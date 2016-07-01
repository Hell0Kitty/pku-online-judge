#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
#include<ctime>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define PI acos(-1)
#define LL long long
#define inf (1<<30)
#define modn 1000000007
#define maxn 700+10
#define Mod 2
#define type 1
#define rep(a,b) for(i=a;i<=b;i++)
#define eps 1e-7
#define zero(x) fabs(x)<eps
#define equal(x,y) zero(x-y)
#define shift(x) (1<<x)
#define lowbit(x) (x&(-x))
#define jihe_del(S,i,j) (S^(1<<i)^(1<<j))
#define jihe_jiao(S,i) (S&(1<<i))
#define jihe_bing(S,i) (S|(1<<i))
#define jihe_bu(S,i) (S^(1<<i))
#define ALL_BITS (1<<n)-1
#define BuJi(A) ALL_BITS^A
#define wei_del(A,bit) (A|=(1<<bit))
#define rep_all for(s=1;s<=ALL_BITS;s++)
#define rep_zi for(s0=s;s0;s0=(s0-1)&s)
using namespace std;
int main()
{
    LL n,p,Str,i;
    while(scanf("%lld",&n)!=EOF)
    {
        p=1;
        Str=2;
        for(i=1;;i++)
        {
            if(i&1)p*=9;
            else p*=2;
            if(n>=Str&&n<=p)
            {
                if(i&1)
                cout<<"Stan wins."<<endl;
                else cout<<"Ollie wins."<<endl;
                break;
            }
            Str=p+1;
        }
    }
}



