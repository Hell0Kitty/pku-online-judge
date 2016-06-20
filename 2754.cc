#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define CL(a,b) (memset((a),(b),sizeof((a))))
#define inf 0x7fffffff
#define LL unsigned __int64
#define eps 1e-8
#define PI acos(-1.0)
using namespace std;
const int N(200100);
int f[N];
int M[300],P[300],low[300],up[300];
int main()
{
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        int i;
        int sum=0,maxr=0,sum1=0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&P[i],&M[i],&low[i],&up[i]);
            up[i]=up[i]-low[i]; 
            maxr+=M[i]*up[i];
            sum+=M[i]*(-low[i]);
            sum1+=P[i]*(-low[i]); 
        }
        int j,k,num,num1;
        for(i=0;i<=maxr;i++)
            f[i]=-inf;
        f[0]=0;
        for(i=0;i<m;i++)
        {
            j=1;
            while(j<up[i])
            {
                num=j*P[i];
                num1=j*M[i];
                for(k=maxr;k>=num1;k--)
                    if(f[k-num1]!=-inf)
                        f[k]=MAX(f[k],f[k-num1]+num);
                up[i]-=j;     
                j<<=1;
            }
            num=up[i]*P[i];
            num1=up[i]*M[i];
            for(k=maxr;k>=num1;k--)
                    if(f[k-num1]!=inf)
                        f[k]=MAX(f[k],f[k-num1]+num);
        }
        printf("%d\n",f[sum]-sum1);
    }
}


