#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct digrams
{
	char name[2];
	int time;
	bool operator < (const digrams &a) const
	{
		if(time==a.time)
		{
			if(name[0]==a.name[0])
			{
				return name[1]>a.name[1];
			}
			return name[0]>a.name[0];
		}
		return time<a.time;
	}
};
int main()
{
	int n;
    while(scanf("%d",&n),n)
    {
		int a[150][150]={0};
		getchar();
		char t=10;
        while(n--)
        {
			char s[100];
            gets(s);
			int len=strlen(s);
			if(t!=10)a[t][s[0]]++;
			for(int i=0;i<len-1;i++)
				a[s[i]][s[i+1]]++;
			t=s[len-1];
        }
		priority_queue<digrams> q;
		int sum=0;
		for(int i=0;i<150;i++)
		{
			for(int j=0;j<150;j++)
			{
				if(a[i][j]!=0)
				{
					digrams d;
					d.name[0]=i;
					d.name[1]=j;
					d.time=a[i][j];
					q.push(d);
					sum+=d.time;
				}
			}
		}
		int k=5;
		while(k--)
		{
			digrams d=q.top();
			printf("%c%c %d %.6f\n",d.name[0],d.name[1],d.time,1.0*d.time/sum);
			q.pop();
		}
		printf("\n");
    }
    return 0;
}


