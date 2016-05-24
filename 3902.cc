#include<cstdio>  
#include<cmath>  
using namespace std;  
int main()  
{  
    int T,i;  
    scanf("%d",&T);  
    while(T--)  
    {  
        int n,m,k;  
        int res=0;  
        scanf("%d%d%d",&n,&m,&k);  

        if(k%n==0)  
           k--;  
        if(n==1)  
        {  
            puts("-1");       
        }  
          else if(k==1)             
{  
               if(m%n==0)  
                    puts("-1");  
                 else  
                    printf("%d\n",m);  
          }  
           else if(n==2)  
          {  
             if(!(m&1))        
             {  
                 puts("-1");      
             }  
              else  
              {  
                  res=m/k;  
                  m=m%k;  
                  if(m>0)  
                    res++;  
                  if(res%2==0)  
                    res++;  
                  printf("%d\n",res);  
              }  
          }  
           else   //n>2,k>1  
           {  
               res=m/k;  
               m=m%k;   
            if(m>0)  
            {  
                res++;  
                if(res%n==0)  
                   res++;   
                  else if(m%n==0)  
                 {  
                    if(res==1)    
                       res=2;      
                    else if((k-1)%n==0)  
                    {  
                        int flag=0;  
                        for(i=1;i<n&&i<k-m;i++)  
                            if((m+i)%n!=0&&(k-i)%n!=0)  
                            {  
                                   flag=1;  
                                   break;  
                            }   
                        if(flag==0)  
                        {  
                            res++;  
                            if(res%n==0)  
                            {  
                                   res++;                              }  
                        }  
                    }  
                  }  

             }  

             printf("%d\n",res);  
          }  
     }  
    return 0;  
}



