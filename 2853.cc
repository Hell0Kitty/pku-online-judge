#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int no;
        long long num;
        scanf("%d%I64d",&no,&num);
        num*=2;
        long long i;
        long long ans=0;
        for(i=2;i*i<=num;i++)
        {
            if(num%i==0)
            {
                long long b=i-1;
                long long t=num/i;
                if(t>=b&&(t-b)%2==0)
                {
                    ans++;
                }
            }
        }
        printf("%d %I64d\n",no,ans);
    }
    return 0;
}



