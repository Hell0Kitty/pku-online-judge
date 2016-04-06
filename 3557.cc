#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string.h>

using namespace std;

#define eps 1e-8
#define zero(_) (abs(_)<=eps)
const double pi=acos(-1.0);
typedef long long LL;
const int Max=22;
const LL INF=0x3FFFFFFF;
double ans[23];
int n;
double p;
LL C[30][30];
void init()
{
    for(int i=0; i<Max; i++)
        for(int j=0; j<=i; j++)
            C[i][j]= j==0? 1 : C[i-1][j-1]+C[i-1][j];

}
int main()
{
    init();
    while(scanf("%d%lf",&n,&p)==2)
    {
       memset(ans,0,sizeof ans);
       ans[1]=1.0;
       for(int i=2;i<=n;i++)
       {
           double help=0;
           for(int j=1;j<i;j++)
           help+=C[i-1][j-1]*ans[j]*pow(1.0-p,double(j*(i-j)));
           ans[i]=1.0-help;
       }
       printf("%.3lf\n",ans[n]);
    }
    return 0;
}



