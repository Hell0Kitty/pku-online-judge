#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=4001;
char str[maxn][201];
int f[maxn];
void GetFail(char *s)
{
    int len=strlen(s);
    f[0]=f[1]=0;
    for(int i=1;i<len;i++)
    {
	int j=f[i];
	while(j&&s[i]!=s[j])
	    j=f[j];
	f[i+1]=s[i]==s[j]?j+1:0;
    }
}
bool find(char *T,char *s)
{
    int len=strlen(T),m=strlen(s);
    int j=0;
    for(int i=0;i<len;i++)
    {
	while(j&&T[i]!=s[j])
	    j=f[j];
	if(s[j]==T[i])
	    j++;
	if(j==m)
	    return true;
    }
    return false;
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
	for(int i=0;i<n;i++)
	    scanf("%s",str[i]);
	int len=strlen(str[0]);
	char ita[201],ans[201]="";
	for(int i=0;i<len;i++)
	{
	    int cou=0;
	    for(int j=i;j<len;j++)
	    {
		ita[cou++]=str[0][j];
		ita[cou]='\0';
		GetFail(ita);
		int flag=0;
		for(int k=1;k<n;k++)
		    if(!find(str[k],ita))
		    {
			flag=1;
			break;
		    }
		if(!flag)
		{
		    if(strlen(ita)>strlen(ans)||(strlen(ita)==strlen(ans)&&strcmp(ita,ans)<0))
			memcpy(ans,ita,sizeof(ita));
		}
	    }
	}
	if(strlen(ans)==0)
	    printf("IDENTITY LOST\n");
	else
	    printf("%s\n",ans);
    }
    return 0;
}


