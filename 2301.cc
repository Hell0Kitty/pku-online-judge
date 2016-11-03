#include <cstdio>
#include <cstdlib>

int main()
{
    long long n,s,d,a,b;
    scanf("%I64d",&n);
    for (long long t=0; t<n; t++)
    {
        scanf("%I64d%I64d",&s,&d);
        if ((s+d)&1)
        {
            printf("impossible\n");
            continue;
        }
        a=(s+d)/2;
        b=s-a;
        if (a<0||b<0)
        {
            printf("impossible\n");
            continue;
        }
        a<b?printf("%I64d %I64d\n",b,a):printf("%I64d %I64d\n",a,b);
    }
    return 0;
}




