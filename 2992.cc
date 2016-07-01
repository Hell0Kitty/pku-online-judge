#include<stdio.h>
#include<string.h>
int prime[500],num;
int dev[500];
bool isprime[500];
int main()
    {
        memset(isprime,true,sizeof(isprime));
        for(int i=2;i<500;i++)
        {
            if(!isprime[i])
            continue;
            prime[num++]=i;
            for(int j=i*2;j<500;j+=i)
            {
                isprime[j]=0;
            }
        }
        int n,k;
        while(scanf("%d%d",&n,&k)!=EOF)
        {
            memset(dev,0,sizeof(dev));
            for(int i=0;prime[i]<=n;i++)
            {
                int t=prime[i];
                while(t<=n)
                {
                    dev[prime[i]]+=(n/t);
                    t*=prime[i];
                }
            }
            for(int i=0;prime[i]<=n-k;i++)
            {
                int t=prime[i];
                while(t<=n-k)
                {
                    dev[prime[i]]-=((n-k)/t);
                    t*=prime[i];
                }
            }
            for(int i=0;prime[i]<=k;i++)
            {
                int t=prime[i];
                while(t<=k)
                {
                    dev[prime[i]]-=(k/t);
                    t*=prime[i];
                }
            }
            long long sum=1;
            for(int i=0;i<500;i++)
            {
                sum=sum*(dev[i]+1);
            }
            printf("%I64d\n",sum);
        }
        return 0;
    }



