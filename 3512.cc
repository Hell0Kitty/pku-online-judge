#include <iostream>   
#include <algorithm>   
#include <cmath>   
using namespace std;   
const double eps=1e-10;   
const double INF=0xffffffff;   
struct point    
{ long x,y; };   

bool same (double x,double y)   
{  return fabs(x-y)<eps ;   }   
double pp[1005];   
int main()   
{   
    point p[1005];   
    long i,j,tt,k,flag,cnt=1,max;   
    char s[20],t[20]={'0'};   
    while(1)   
    {   
        flag=0; i=0;   
        gets(s);   
        if(t[0]=='-'&&t[1]=='-'&&s[0]=='-'&&s[1]=='-')flag=1;   
        if(flag)break;   
        sscanf(s,"%ld %ld",&p[i].x,&p[i].y);i++;   
        while(gets(t))   
        {      
            if(t[0]=='-'&&t[1]=='-')break;             
            sscanf(t,"%ld %ld",&p[i].x,&p[i].y);   
            strcpy(s,t);i++;   
        }   
        max=0;   
        for(j=0;j<i;j++)   
        {     
            tt=0;   
            for(k=j+1;k<i;k++)   
            {   
               if(p[k].x!=p[j].x)pp[tt++]=1.0*(p[k].y-p[j].y)/(p[k].x-p[j].x);     
               else  pp[tt++]=INF;   
            }   
            sort(pp,pp+tt);   
            int temp=1;   
            for(k=1;k<tt;k++)   
               if(same(pp[k],pp[k-1]))temp++;   
               else { if(max<temp)max=temp; temp=1;  }   
            if(max<temp)max=temp;   
       }   
        printf("%ld. %ld\n",cnt,max+1);cnt++;   
    }   
    return 0;   
}



