#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;
int len,cnt,num[17],ans,cont,num1[17];
struct pai
{
    int rank;
    char suit;
    bool operator <(const pai &temp)const
    {
        return rank<temp.rank;
    }
};
struct pp
{
    pai a[10];
};
pp nw,now;
char str[100];
int level(pp nw,int num[])
{
    int i,j,s,p,q,res;
    if(num[nw.a[4].rank]==4) 
      return 7;
    if(num[nw.a[4].rank]==3&&num[nw.a[1].rank]==2)
      return 6;
    for(i=1;i<5;i++)
    {
        if(nw.a[i].suit!=nw.a[i-1].suit)
           break;
    }
    if(i>=5)
    {
       for(i=1;i<5;i++)
       {
           if(nw.a[i].rank!=nw.a[i-1].rank+1)
              break;
       }
       if(i>=5)
          return 8;
       return 5;
    }
    for(i=1;i<5;i++)
    {
        if(nw.a[i].rank!=nw.a[i-1].rank+1)
              break;
    }
    if(i>=5)
       return 4;
    if(num[nw.a[4].rank]==3)
       return 3;
    if(num[nw.a[4].rank]==2&&num[nw.a[2].rank]==2)
       return 2;
    if(num[nw.a[4].rank]==2)
       return 1;
    return 0;
}
int compare(pp nw1,pp nw2)
{
    int i,v1=level(nw1,num1),v2=level(nw2,num);
    if(v1<v2)
       return -1;
    if(v1>v2)
       return 1;
    for(i=4;i>=0;i--)
    {
       if(nw1.a[i].rank<nw2.a[i].rank)
          return -1;
       else if(nw1.a[i].rank>nw2.a[i].rank)
          return 1;
    }
    return 0;
}
void xu(pp &nw,int num[])
{
     int i,j;
     if(nw.a[0].rank==2&&nw.a[1].rank==3&&nw.a[2].rank==4&&nw.a[3].rank==5&&nw.a[4].rank==14)
     {
         swap(nw.a[0],nw.a[4]);
         swap(nw.a[3],nw.a[4]);
         swap(nw.a[2],nw.a[3]);
         swap(nw.a[1],nw.a[2]);
         nw.a[0].rank=1;
     }
     for(i=0;i<5;i++)
     {
         num[nw.a[i].rank]=0;
         for(j=0;j<5;j++)
         {
               if(nw.a[i].rank==nw.a[j].rank)
                  num[nw.a[i].rank]++;
         }
     }
     for(i=0;i<5;i++)
        for(j=i+1;j<5;j++)
        {
            if((num[nw.a[i].rank]>num[nw.a[j].rank])||(num[nw.a[i].rank]==num[nw.a[j].rank]&&nw.a[i].rank>nw.a[j].rank))
               swap(nw.a[i],nw.a[j]);
        }
}
int main()
{
    int i,j,lv1,lv2,lv3;
    int a[5];
    while(gets(str))
    {
        len=strlen(str);
        cnt=0;
        for(i=0;i<len;i++)
        {
            if(str[i]<='9'&&str[i]>='0')
                nw.a[cnt].rank=str[i]-'0';
            else if(str[i]=='C'||str[i]=='D'||str[i]=='H'||str[i]=='S')
                nw.a[cnt++].suit=str[i];
            else if(str[i]=='A')
                nw.a[cnt].rank=14;
            else if(str[i]=='K')
                nw.a[cnt].rank=13;
            else if(str[i]=='Q')
                nw.a[cnt].rank=12;
            else if(str[i]=='J')
                nw.a[cnt].rank=11;
            else if(str[i]=='T') 
                nw.a[cnt].rank=10;
        }
        sort(nw.a,nw.a+5);
        xu(nw,num); 
        ans=0;
        cont=0;
        for(a[0]=2;a[0]<=14;a[0]++)
          for(a[1]=a[0];a[1]<=14;a[1]++)
             for(a[2]=a[1];a[2]<=14;a[2]++)
                for(a[3]=a[2];a[3]<=14;a[3]++)
                  for(a[4]=a[3];a[4]<=14;a[4]++)
                  {
                      for(i=0;i<5;i++)
                      {
                         now.a[i].rank=a[i];
                         now.a[i].suit='C';
                      }
                      xu(now,num1);
                      if(num1[now.a[4].rank]==5)
                         continue;
                      if(num1[now.a[4].rank]==1)
                      {
                         lv2=level(now,num1);
                         if(compare(now,nw)<0)
                            ans++;
                      }
                      else
                         lv2=-1; 
                      now.a[4].suit='S';
                      lv3=level(now,num1);
                      if(lv2!=lv3)
                      {
                         if(compare(now,nw)<0)
                            ans++;
                      }
                  }
        ans++;
        printf("%d\n",ans);
    }
    return 0;   
}


