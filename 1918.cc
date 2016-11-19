#include<map>
#include<string>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct node
{
	char name[20];
	bool solve[10];
	int wrong[10],sumtime,solved;
};
node team[20];
int cmp(const void *m1,const void *m2)
{
	node *team1=(node*)m1;
	node *team2=(node*)m2;
	if(team1->solved==team2->solved)
	{
		if(team1->sumtime-team2->sumtime)
			return (team1->sumtime>team2->sumtime)?1:-1;
		return strcmp(team1->name,team2->name)>0?1:-1;
	}
	return (team1->solved<team2->solved)?1:-1;
}
int main()
{
	char n[20],yes[5];
	int cas,teams,problem,submit,pro,t,rank,i,j;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d",&teams);
		map<string,int>mp;
		for(i=0;i<teams;i++)
		{
			scanf("%s",team[i].name);
			mp[team[i].name]=i;///
			memset(team[i].wrong,0,sizeof(team[i].wrong));
			memset(team[i].solve,false,sizeof(team[i].solve));
			team[i].sumtime=team[i].solved=0;
		}
		scanf("%d %d",&problem,&submit);
		for(i=0;i<submit;i++)
		{
			scanf("%d%d%s%s",&pro,&t,yes,n);
			pro--;
			j=mp[n];
			if(team[j].solve[pro])
				continue;
			if(!strcmp(yes,"Yes"))
			{
				team[j].sumtime+=t+20*team[j].wrong[pro];
				team[j].solve[pro]=true;
				team[j].solved++;
				continue;
			}
			team[j].wrong[pro]++;
		}
		qsort(team,teams,sizeof(team[0]),cmp);
		rank=1;
		for(i=0;i<teams;i++)
		{
			printf("%2d. %-8s% 2d% 5d\n", rank,
				team[i].name,team[i].solved,team[i].sumtime);
			if( (team[i+1].solved-team[i].solved) || 
						(team[i+1].sumtime-team[i].sumtime) )
					rank=i+2;
		}
		puts("");
	}
	return 0;
}



