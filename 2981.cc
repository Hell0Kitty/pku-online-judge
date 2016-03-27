#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <functional>
#include <iterator>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <complex>
#include <string>
#include <ctime>
#include <stdlib.h>
using namespace std;
struct subclause
{
    char str[1000];
    bool flag;
    int id,num_po,num_ne,num;
    bool operator <(const subclause &temp)const
    {
         return strcmp(str,temp.str)<0;
    }
};
bool cmp(subclause a,subclause b)
{
     return max(a.num_po,a.num_ne)*b.num>max(b.num_po,b.num_ne)*a.num;
}
struct clause
{
    subclause sc[7];
    int id,num_sub;
};
clause cl[1001];
subclause list[6001],kind[133],now;
int num_cl,num_kind,num_sub,len,nlen,adj[7][1111],num[7],imin;
int ans[1001],pos[2][1001][1001],num_p[2][1001],tot;
bool saf[1111];
char str[11111],nstr[11111];
char no[100];
int find_sub(int left,int right,subclause now)
{
    int mid;
    while(left<=right)
    {
        mid=(left+right)>>1;
        if(kind[mid]<now)
            left=mid+1;
        else if(now<kind[mid])
            right=mid-1;
        else
            return mid;
    }
}
bool check(int id)
{
     int i;
     if(id==imin||str[id]==' ')
     {
        if(id!=imin)
               id++;
        if(id+3==len||str[id+3]==' ')
        {
            for(i=id;i<id+3;i++)
            {
                if(str[i]!=no[i-id])
                    return false;
            }
            return true;
        }
     }
     return false;
}
bool dfs()
{
     int now_id,i,j,s,p,q,id_cnt,id,flag,ip,iden,num_in=10000;
     vector<int>hp;
     double ax=-1,now_v;
     for(i=0;i<num_cl;i++)
     {
        if(saf[i])
            continue;
        int now_num=0,now_v=0;
        for(j=0;j<cl[i].num_sub;j++)
        {
            now_id=cl[i].sc[j].id;
            if(ans[now_id]<0)
                now_num++;
        }
        if(now_num==0)
            return false;
        if(num_in>now_num)
        {
            num_in=now_num;
            id=i;
            ax=-1;
            for(j=0;j<cl[i].num_sub;j++)
            {
                now_id=cl[i].sc[j].id;
                if(ans[now_id]>=0)
                    continue;
                int po=kind[now_id].num_po,ne=kind[now_id].num_ne;
                if(ax<(double)max(po,ne)/(double)(po+ne))
                {
                    ax=(double)max(po,ne)/(double)(po+ne);
                    ip=j;
                    iden=now_id;
                    flag=cl[i].sc[j].flag;
                }
            }
        }
        else if(num_in==now_num)
        {
            for(j=0;j<cl[i].num_sub;j++)
            {
                now_id=cl[i].sc[j].id;
                if(ans[now_id]>=0)
                    continue;
                int po=kind[now_id].num_po,ne=kind[now_id].num_ne;
                if(ax<(double)max(po,ne)/(double)(po+ne))
                {
                    ax=(double)max(po,ne)/(double)(po+ne);
                    id=i;
                    ip=j;
                    iden=now_id;
                    flag=cl[i].sc[j].flag;
                }
            }
        }
     }
   //  printf("num_in=%d\n",num_in);
     if(num_in==10000)
         return true;
    // printf("id=%d,ip=%d,num_in=%d,iden=%d,flag=%d\n",id,ip,num_in,iden,flag);
     for(int fp=0;fp<2;fp++)
     {
        if(fp==1)
           flag=1-flag;
        ans[iden]=flag;
        hp.clear();
        for(i=0;i<num_p[flag][iden];i++)
        {
           id=pos[flag][iden][i];
           if(!saf[id])
           {
              saf[id]=true;
              hp.push_back(id);
           }
           for(j=0;j<cl[id].num_sub;j++)
           {
              ip=cl[id].sc[j].id;
              int ff=cl[id].sc[j].flag;
              if(ff>0)
                 kind[ip].num_po--;
              else
                 kind[ip].num_ne--;
           }
        }
        if(dfs())
           return true;
        ans[iden]=-1;
        for(i=0;i<hp.size();i++)
            saf[hp[i]]=false;
        for(i=0;i<num_p[flag][iden];i++)
        {
            id=pos[flag][iden][i];
            for(j=0;j<cl[id].num_sub;j++)
            {
               ip=cl[id].sc[j].id;
               int ff=cl[id].sc[j].flag;
               if(ff>0)
                  kind[ip].num_po++;
               else
                  kind[ip].num_ne++;
            }
        }
     }
     return false;     
}
int main()
{
    int i,j,s,p,q;
    strcpy(no,"not");
    num_cl=num_sub=0;
    cl[0].num_sub=0;
    while(gets(str))
    {
        len=strlen(str);
        while(len>=1000)
            puts("orz");
      //  puts(str);

        if(strcmp(str,"and")==0)
        {
           num_cl++;
           cl[num_cl].num_sub=0;
        }
        else
        {
            nlen=0;
            now.flag=true;
            if(len>=3&&str[0]=='o'&&str[1]=='r'&&str[2]==' ')
                imin=3;
            else
                imin=0;
            for(i=imin;i<len;i++)
            {
                if(check(i))
                {
                    i+=3;
                    now.flag=false;
                }
                else
                    now.str[nlen++]=str[i];
            }
            now.str[nlen]=0;
            list[num_sub++]=now;
            cl[num_cl].sc[cl[num_cl].num_sub++]=now;
        }
    }
    num_cl++;
    sort(list,list+num_sub);
    num_kind=0;
    for(i=0;i<num_sub;i++)
    {
       if(num_kind==0||kind[num_kind-1]<list[i])
          kind[num_kind++]=list[i];
    }
    memset(num_p,0,sizeof(num_p));
    for(i=0;i<num_kind;i++)
    {
           kind[i].num_po=kind[i].num_ne=0;
           for(j=0;j<num_cl;j++)
           {
               int tc=0;
               for(s=0;s<cl[j].num_sub;s++)
               {
                   if(strcmp(kind[i].str,cl[j].sc[s].str)==0)
                   {
                       tc+=2*cl[j].sc[s].flag-1;
                       cl[j].sc[s].id=i;
                       int flag=cl[j].sc[s].flag;
                       pos[flag][i][num_p[flag][i]++]=j;
                   }
               }
               if(tc<0)
                  kind[i].num_ne-=tc;
               else
                  kind[i].num_po+=tc;
               kind[i].num+=abs(tc);
           }
    }
    memset(ans,-1,sizeof(ans));
    memset(saf,false,sizeof(saf));
    if(!dfs())
        puts("mission impossible");
    for(i=0;i<num_kind;i++)
    {
        if(ans[i]>0)
           puts(kind[i].str);
        else
        {
            printf("not ");
            puts(kind[i].str);
        }
        int len=strlen(kind[i].str);
    }
    return 0;
}



