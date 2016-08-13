# include <stdio.h>
int main()
{
    int n,i,bit=33,A=-1,B=-1;
    long long res=0xfffffffffffffffll,sp,sq;
    scanf("%d%lld%lld",&n,&sp,&sq);
    if(n==1) 
    {
       printf("%d 0 0\n",sq);
       return 0;
    }
    for(i=0;i<=bit;i++)
    {
         if(sp+(sp<<i)<sq) continue;
         int b=0;
         while(((sp+(sp<<i))>>b)>=sq) b++;
         b--;
         if(((sp*(n-1)+((sp*(n-1))<<i))>>b)+sq<res) 
             res=((sp*(n-1)+((sp*(n-1))<<i))>>b)+sq,A=i,B=b;
    }
    printf("%lld %d %d\n",res,A,B);
    return 0;
}



