#include <stdio.h>  
#include <string.h>  
  
int main()  
{  
    int devCon[25];  
    int opt;  
    int flag[25];  
    int n,m,c;  
    int i;  
    int max,sum;  
    int count=0;  
    while(scanf("%d%d%d",&n,&m,&c))  
    {  
        if(n==0 && m==0 && c==0)  
            return 0;  
          
        //init  
        memset(flag,0,sizeof(flag));  
        sum=0;  
        max=-1;  
        //sum=0,max=-1;  
          
        for(i=1;i<=n;i++)  
            scanf("%d",&devCon[i]);  
          
        for(i=1;i<=m;i++)  
        {  
            scanf("%d",&opt);  
  
            if(flag[opt]==0)  
            {  
                sum+=devCon[opt];  
                flag[opt]=1;  
            }  
              
            else  
            {  
                sum-=devCon[opt];  
                flag[opt]=0;  
            }  
              
            if(sum>max)  
                max=sum;  
        }  
        printf("Sequence %d\n",++count);  
        if(max<=c)   //没被烧  
        {  
            printf("Fuse was not blown.\n");  
            printf("Maximal power consumption was %d amperes.\n",max);  
        }  
          
        else        //保险丝烧掉了  
            printf("Fuse was blown.\n");  
        printf("\n");  
    }  
      
    return 0;  
}  

