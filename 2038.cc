#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<stdio.h>
using namespace std;

map<char,bool>my;
int main()
{
	int n,best,tot,t,i,j,p,pp;
	char str[105][5],ANS[5];
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
		   break;
	    best=999999999;
	    for(i=0;i<n;i++)
		{
			scanf("%s",str[i]);
		}
		char ans[]={'A','B','C','D','E'};
		do
		{
		    tot=0;
			for(t=0;t<n;t++)
			{
				my.clear();
				for(i=0;i<5;i++)
				{
					my[str[t][i]]=1;
					for(j=0;j<5;j++)
					{
						if(!my[ans[j]])
						   tot++;
					    if(ans[j]==str[t][i])
					       break;
					}
				}
			}
			if(tot<best)
			{
				best=tot;
				for(i=0;i<5;i++)
				{
					ANS[i]=ans[i];
				}
			}
		}while(next_permutation(ans,ans+5));
		printf("%s is the median ranking with value %d.\n",ANS,best);
	}
}



