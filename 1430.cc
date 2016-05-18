#include<cstdio>
#define lint __int64

lint getTwo ( lint x )
{
    lint cnt = 0, bit = 2;
    while ( x / bit )
    {
        cnt += x / bit;
        bit <<= 1;
    }
    return cnt;
}

int main()
{
    int d, n, k;
    scanf("%d",&d);
    while ( d-- )
    {
        scanf("%d%d",&n, &k);
        lint z = n - (k+2) / 2;
        lint w = (k-1) / 2;
        if ( getTwo(z) - getTwo(w) - getTwo(z-w) > 0 )
            printf("0\n");
        else printf("1\n");
    }
    return 0;

}


