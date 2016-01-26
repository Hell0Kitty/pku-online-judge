#include<stdio.h>
#include<string.h>
#include<iostream>
#define MAX 30
using namespace std;
int n,pos[MAX],stack[MAX][MAX],len[MAX];
void DealMove(int index)
{
    int w=pos[index];
    for(int i=len[w]-1;stack[w][i]!=index;i--)
    {
	int ita=stack[w][i];
	pos[ita]=ita;
	stack[ita][len[ita]++]=ita;
	len[w]--;
    }
}
void Show()
{
    for(int i=0;i<n;i++)
    {
	printf("%d:",i);
	for(int j=0;j<len[i];j++)
	    printf(" %d",stack[i][j]);
	printf("\n");
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
	for(int i=0;i<n;i++)
	{
	    len[i]=1;
	    pos[i]=i;
	    stack[i][0]=i;
	}
	char op[10];
	while(scanf("%s",op)&&op[0]!='q')
	{
	    int a,b;
	    char s[10];
	    scanf("%d%s%d",&a,&s,&b);
	    if(a==b&&pos[a]==pos[b])
		continue;
	    if(op[0]=='m')
	    {
		if(s[1]=='n')
		{
		    DealMove(a);
		    DealMove(b);
		    stack[pos[b]][len[pos[b]]++]=a;
		    len[pos[a]]--;
		    pos[a]=pos[b];
		}
		else
		{
		    DealMove(a);
		    stack[pos[b]][len[pos[b]]++]=a;
		    len[pos[a]]--;
		    pos[a]=pos[b];
		}
	    }
	    else
	    {
		if(s[1]=='n')
		{
		    DealMove(b);
		    int t=-1;
		    for(int i=0;i<len[pos[a]];i++)
			if(stack[pos[a]][i]==a)
			{
			    t=i;
			    break;
			}
		    int lena=len[pos[a]],last=pos[a];
		    for(int i=t;i<lena;i++)
		    {
			stack[pos[b]][len[pos[b]]++]=stack[last][i];
			pos[stack[last][i]]=pos[b];
			len[last]--;
		    }
		}
		else
		{
		    int t=-1,lena;
		    for(int i=0;i<len[pos[a]];i++)
			if(stack[pos[a]][i]==a)
			{
			    t=i;
			    break;
			}
		    lena=len[pos[a]];
		    int last=pos[a];
		    for(int i=t;i<lena;i++)
		    {
			stack[pos[b]][len[pos[b]]++]=stack[last][i];
			pos[stack[last][i]]=pos[b];
			len[last]--;
		    }
		}
	    }
	}
	Show();
    }
    return 0;
}


