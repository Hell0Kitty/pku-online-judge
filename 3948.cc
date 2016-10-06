#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<cstring>
using namespace std;
char str1[100],str2[100];
int len1,len2,ans[11],mul;
struct pp
{
     int fenzi,fenmu;
};
pp mod[11],shang[11],x[11],y[11],temp[11];
void dfs(int id1,int id2,char str[],int coef[11])
{
     int i,j,s,p,q,ip1,ip2,ax=-100,cou=0,coef1[11],coef2[11],temp[11]={0};
     for(i=0;i<10;i++)
        coef[i]=0;
     for(i=id1;i<=id2;i++)
     {
        if(!(str[i]<='9'&&str[i]>='0'))
           break;
     }
     if(i>id2)
     {
         for(i=id1;i<=id2;i++)
            coef[0]=10*coef[0]+str[i]-'0';
         return;
     }
     if(id1==id2)
     {
         coef[1]=1;
         return;
     }
     for(i=id2;i>=id1;i--)
     {
         if(str[i]==')')
            cou++;
         else if(str[i]=='(')
            cou--;
         if(cou==0&&(str[i]=='+'||str[i]=='-'))
         {
             if(ax<2)
             {
                 ax=2;
                 ip1=i-1;
                 ip2=i+1;
             }
         }
         else if(cou==0)
         {
              if(i>id1&&((str[i-1]==')'&&str[i]=='(')||(str[i-1]<='9'&&str[i-1]>='0'&&(str[i]=='x'||str[i]=='('))||(str[i-1]=='x'&&str[i]=='(')))
              {
                  if(ax<1)
                  {
                     ax=1;
                     ip1=i-1;
                     ip2=i;
                  }
              }
              else if(str[i]=='^')
              {
                  if(ax<0)
                  {
                     ax=0;
                     ip1=i-1;
                     ip2=i+1;
                  }
              }
         }
     }
     if(ax==-100&&str[id1]=='-')
     {
          dfs(id1+1,id2,str,coef);
          for(i=0;i<10;i++)
             coef[i]=-coef[i];
          return;
     }
     if(ax==-100)
        dfs(id1+1,id2-1,str,coef);
     else
     {
         dfs(id1,ip1,str,coef1);
         dfs(ip2,id2,str,coef2);
         if(ax==2)
         {  
             for(i=0;i<10;i++)
             {
                if(str[ip1+1]=='+')
                  coef[i]=coef1[i]+coef2[i];
                else
                  coef[i]=coef1[i]-coef2[i];
             }
         }
         else if(ax==1)
         {
             for(i=0;i<10;i++)
               for(j=0;j<=i;j++)
                   coef[i]+=coef1[j]*coef2[i-j];
         }
         else if(ax==0)
         {
              coef[0]=1;
              for(i=0;i<coef2[0];i++)
              {
                  for(j=0;j<10;j++)
                     temp[j]=0;
                  for(j=0;j<10;j++)
                    for(s=0;s<=j;s++)
                        temp[j]+=coef[s]*coef1[j-s];
                  for(j=0;j<10;j++)
                    coef[j]=temp[j];
              }
         }
     }
}
int gcd(int x,int y)
{
    int temp;
    while(x%y)
    {
       temp=x%y;
       x=y;
       y=temp;
    }
    return y;
}
int lcm(int x,int y)
{
    return x*y/gcd(x,y);
}
int main()
{
    int i,j,s,p,q,coef[2][11],id1,id2,d;
    while(scanf("%s",str1)&&str1[0]!='.')
    {
         scanf("%s",str2);
         len1=strlen(str1);
         len2=strlen(str2);
         dfs(0,len1-1,str1,coef[0]);
         dfs(0,len2-1,str2,coef[1]);
         for(i=0;i<10;i++)
         {
           x[i].fenzi=coef[0][i];
           x[i].fenmu=1;
           y[i].fenzi=coef[1][i];
           y[i].fenmu=1;
         }
         id1=id2=9;
         while(coef[0][id1]==0)
            id1--;
         while(coef[1][id2]==0)
            id2--;
         while(true)
         {
            if(id1<id2)
            {
               for(i=0;i<10;i++)
                   swap(x[i],y[i]);
               swap(id1,id2);
               continue;
            }
            int nid1=id1,nid2=id2;
            while(id1>=id2)
            {
                shang[id1-id2].fenzi=x[id1].fenzi*y[id2].fenmu;
                shang[id1-id2].fenmu=x[id1].fenmu*y[id2].fenzi;
                d=gcd(shang[id1-id2].fenzi,shang[id1-id2].fenmu);
                shang[id1-id2].fenzi/=d;
                shang[id1-id2].fenmu/=d;
                for(i=id2;i>=0;i--)
                {
                    temp[i+id1-id2].fenzi=shang[id1-id2].fenzi*y[i].fenzi;
                    temp[i+id1-id2].fenmu=shang[id1-id2].fenmu*y[i].fenmu;
                    d=gcd(temp[i+id1-id2].fenzi,temp[i+id1-id2].fenmu);
                    temp[i+id1-id2].fenzi/=d;
                    temp[i+id1-id2].fenmu/=d;
                }
                for(i=id1-id2-1;i>=0;i--)
                {
                    temp[i].fenzi=0;
                    temp[i].fenmu=1;
                }
                for(i=id1;i>=0;i--)
                {
                    mod[i].fenzi=x[i].fenzi*temp[i].fenmu-x[i].fenmu*temp[i].fenzi;
                    mod[i].fenmu=x[i].fenmu*temp[i].fenmu;
                    d=gcd(mod[i].fenzi,mod[i].fenmu);
                    mod[i].fenzi/=d;
                    mod[i].fenmu/=d;
                }
                while(id1>=0&&mod[id1].fenzi==0)
                    id1--;     
                for(i=id1;i>=0;i--)
                    x[i]=mod[i];
            } 
            if(id1<0) 
              break;
         } 
         mul=1;
         for(i=0;i<=id2;i++)
         {
             if(y[i].fenmu==0) 
                continue;
             mul=lcm(y[i].fenmu,mul);
         }
         for(i=0;i<=id2;i++)
             ans[i]=(mul/y[i].fenmu)*y[i].fenzi;
         d=ans[0];
         for(i=0;i<=id2;i++)
         {
            if(ans[i]==0)
               continue;
            d=gcd(d,ans[i]);
         }
         for(i=0;i<=id2;i++)
            ans[i]/=d;

         if(ans[id2]<0)
         {
             for(i=id2;i>=0;i--)
               ans[i]=-ans[i];
         }
         for(i=id2;i>=0;i--)
         {
             if(ans[i]>0)
             {
                if(i!=id2)
                   putchar('+');
                if(abs(ans[i])!=1||i==0)
                   printf("%d",ans[i]);
             }
             else if(ans[i]<0)
             {
                 putchar('-');
                 if(abs(ans[i])!=1||i==0)
                    printf("%d",abs(ans[i]));
             }
             if(i!=0&&ans[i]!=0)
             {
                putchar('x');
                if(i>1)
                   printf("^%d",i);
             }
         }
         printf("\n");
    }
    return 0;
}


