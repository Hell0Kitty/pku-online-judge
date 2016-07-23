#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=10010;

int M,N,len,test;
int f[MAXN],s[MAXN];

void Init()
{
    scanf("%d",&M);
    scanf("%d",&N);
    memset(s,0,sizeof(s));
    for (int i=1;i<=N;i++)
    {
        scanf("%d",&len);
        s[i]=s[i-1]+len;
    }
}

void Solve()
{
    memset(f,100,sizeof(f));
    for (int i=1;i<=N;i++)
        if (s[i]+i-1<=M)  f[i]=(M-s[i]-i+1)*(M-s[i]-i+1);
    for (int i=1;i<=N;i++)
        for (int j=1;j<=i-1;j++)
            if (s[i]-s[j]+i-j-1<=M)
                f[i]=min(f[i],f[j]+(M-(s[i]-s[j]+i-j-1))*(M-(s[i]-s[j]+i-j-1)));
    printf("%d\n",f[N]);
}

int  main()
{
    scanf("%d",&test);
    while (test--)
    {
        Init();
        Solve();
    }
    return 0;
}


