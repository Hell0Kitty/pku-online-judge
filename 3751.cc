#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(void)
{
	int t;
	int year,mon,day,hour,mini,sec;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&year);
		getchar();
		scanf("%d",&mon);
		getchar();
		scanf("%d",&day);
		getchar();
		scanf("%d",&hour);
		getchar();
		scanf("%d",&mini);
		getchar();
		scanf("%d",&sec);
		char sign[] = "am";
		if(hour == 0)
			hour = 12;
		else if(hour >= 12)
		{
			if(hour > 12)
				hour -= 12;
			strcpy(sign,"pm");
		}
		printf("%d%d/%d%d/%d-%d%d:%d%d:%d%d%s\n",mon/10,mon%10,day/10,day%10,year,hour/10,hour%10,mini/10,mini%10,sec/10,sec%10,sign);
	}
	return 0;
}



