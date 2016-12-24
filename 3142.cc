#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<stdio.h>
#include<map>
using namespace std;
long long ans;
int n,m,k,t;
int adj[3][111][501],num[111],MOD;
int radj[3][111][501],rnum[111];
int queue[1000000][2],dp[101][3001];
bool visit[111][3001];
struct pp
{
	int x,y,g,num;
	long long d;
	bool operator <(const pp &temp) const
	{
		if(d+(long long)g==temp.d+(long long)temp.g)
		   return num<temp.num;
		return d+(long long)g<temp.d+(long long)temp.g;
	}
};
map <pp,bool> hash;
map <pp,bool>:: iterator it;
pp u,nw,now;
int cnt;
int lcm(int x,int y)
{
	int res=x*y,temp;
	while(x%y)
	{
		temp=x%y;
		x=y;
		y=temp;
	}
	res/=y;
	return res;
}
void SPFA()
{
	int i,j,s,tv,cc,v,id,temp1,temp2,temp,gc,value;
	for(i=0;i<n;i++)
	  for(j=0;j<MOD;j++)
	  {
	     dp[i][j]=1000000000;
         visit[i][j]=false;
      }
   temp=0;
   for(i=0;i<MOD;i++)
   {	     
       if(visit[n-1][i]==false)
       {
       	   visit[n-1][i]=true;
       	   queue[temp][0]=n-1;
    	   queue[temp++][1]=i;
    	   dp[n-1][i]=0;
       }
   }
   temp1=0;
   temp2=temp-1;
	while(temp1<=temp2)
	{
		for(i=temp1;i<=temp2;i++)
		{
           	visit[queue[i][0]][queue[i][1]]=false;
			for(j=0;j<rnum[queue[i][0]];j++)
			{
				id=radj[0][queue[i][0]][j];
				 v=radj[1][queue[i][0]][j];
			    cc=radj[2][queue[i][0]][j];
			    if((queue[i][1]-v)%cc!=0)
			       continue;
                value=((queue[i][1]-v)%MOD+MOD)%MOD;
                int smin,smax;
				for(s=max(max(value-t,0),value-cc+1);s<=value;s++)
				{
					if(((queue[i][1]-v-s)%MOD+MOD)%MOD<=t&&dp[id][s]>dp[queue[i][0]][queue[i][1]]+v+((queue[i][1]-v-s)%MOD+MOD)%MOD)
					{
					   dp[id][s]=dp[queue[i][0]][queue[i][1]]+v+((queue[i][1]-v-s)%MOD+MOD)%MOD;
                       if(visit[id][s]==false)
					   {
					   	   visit[id][s]=true;
					   	   queue[temp][0]=id;
					   	   queue[temp++][1]=s;
					   }
					}
				} 
			    for(s=max(max(value+1,MOD+value-t),MOD+value-cc+1);s<MOD;s++)
			    {
                    if(((queue[i][1]-v-s)%MOD+MOD)%MOD<=t&&dp[id][s]>dp[queue[i][0]][queue[i][1]]+v+((queue[i][1]-v-s)%MOD+MOD)%MOD)
					{
					   dp[id][s]=dp[queue[i][0]][queue[i][1]]+v+((queue[i][1]-v-s)%MOD+MOD)%MOD;
					   if(visit[id][s]==false)
					   {
					   	   visit[id][s]=true;
					   	   queue[temp][0]=id;
					   	   queue[temp++][1]=s;
					   }
					}
                }
			}
		}
		temp1=temp2+1;
		temp2=temp-1;
	}
}
long long kth()
{
	int id,i,j,cc;
    u.x=0;
	u.y=0;
	u.d=0;
	u.g=dp[0][0];
	hash[u]; 
	while(true)
	{
        if(hash.size()==0)
           return -1;
		u=hash.begin()->first;   
		hash.erase(u);
		if(u.g>=1000000000)
		   return -1;
		if(u.x==n-1)
        {
        	k--;
        	if(k==0)
        	   return u.d;
        }  
		for(i=0;i<num[u.x];i++)
		{
		   cc=adj[2][u.x][i];
		   now.d=(long long)1000000000*(long long)1000000000;
		   now.g=1000000000;
		   int jmin=(u.y-1)/cc+1;
		   if(u.y==0)
		       jmin=0;
           int cont=0;
		   for(j=jmin;j<=jmin+MOD/cc-1;j++)
 	       {
		     if(((j*cc-u.y)%MOD+MOD)%MOD<=t)
		     {
                 cont++;
		  	     id=adj[0][u.x][i];
			     nw.x=id;
	    	     nw.d=u.d+(long long)adj[1][u.x][i]+(long long)((j*cc-u.y)%MOD+MOD)%MOD;
		   	     nw.y=nw.d%MOD;
		   	     nw.g=dp[id][nw.y];
                 if(nw.g<1000000000)
                 {
                    nw.num=1000000000;
		   	        if(hash.size()==0)
		   	        {
                       nw.num=1;
                       hash[nw];
                    }
                    else
                    {
                       it=hash.upper_bound(nw);
                       if(it==hash.begin())
                       {
                          nw.num=1;
                          hash[nw];
                       }
                       else
                       {
                         it--;
                         if(nw.d+nw.g==it->first.d+it->first.g)
                            nw.num=it->first.num+1;
                         else
                            nw.num=1;
                         hash[nw];
                       }
                    }
                    if(hash.size()>k)
                    {
                       it=hash.end();
                       it--;
                       hash.erase(it);
                    }
                    if(hash.size()==k)
                    {
                       it=hash.end();
                       it--;
                       if(it->first.d+it->first.g<=nw.d+nw.g)
                            break;
                    }
                  }     		 
		   	 }
		   	 else
		   	 {
                 int kp;
                 if(j*cc<u.y)
                    kp=(j*cc-u.y)/MOD-((j*cc-u.y)%MOD!=0);
                 else
                    kp=(j*cc-u.y)/MOD;
                 j=((kp+1)*MOD+u.y-1)/cc+1;
             }
		  }
		} 
	} 
}
int main()
{
	int id1,id2,w,c,i,j,tst=0,ax;
	while(scanf("%d%d%d%d",&n,&m,&k,&t)&&n>0)
	{
		 tst++;
	     memset(num,0,sizeof(num));
		 memset(rnum,0,sizeof(rnum));
		 hash.clear();
		 k++;
		 MOD=1;
		 ax=0;
		 for(i=0;i<m;i++)
		 { 
 		    scanf("%d%d%d%d",&id1,&id2,&c,&w);
		    MOD=lcm(MOD,c);
		    adj[0][id1][num[id1]]=id2;
		    adj[1][id1][num[id1]]=w;
		    adj[2][id1][num[id1]++]=c;
		    if(ax<c)
		       ax=c;
            radj[0][id2][rnum[id2]]=id1;
		    radj[1][id2][rnum[id2]]=w;
		    radj[2][id2][rnum[id2]++]=c;
		 } 
		 SPFA();
		 ans=kth();
		 while(ans<-1)
		    puts("orz");
		 printf("Case %d: %I64d\n",tst,ans);
	}
	return 0;
}


