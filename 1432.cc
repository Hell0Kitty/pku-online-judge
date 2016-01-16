#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<list>
#include<iostream>
#include<map>
using namespace std;
#define inf 0x3f3f3f3f
#define Max 110
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
string rec;
char s[10100],str[10100];
int dp[10100];
int len;
char cod[26][5]={
            ".-","-...","-.-.","-..",
            ".","..-.","--.","....",
            "..",".---","-.-",".-..",
            "--","-.","---",".--.",
            "--.-",".-.","...","-",
            "..-","...-",".--","-..-",
            "-.--","--.."
            };
map<string ,int>mp;
int main()
{
    int t,n,i,j,k;
    scanf("%d",&t);

    while(t--)
    {
        mp.clear();
        memset(dp,0,sizeof(dp));
       scanf("%s",s+1);
       len=strlen(s+1);

       scanf("%d",&n);
       for(i=0;i<n;i++)
       {
            scanf("%s",str);

            string tmp;
            for(j=0;str[j];j++)
                tmp+=cod[str[j]-'A'];

            mp[tmp]++;
       }
       dp[0]=1;
       for(i=1;i<=len;i++)
            for(j=i-1;j>=i-81&&j>=0;j--)
            {
                if(dp[j]==0)
                    continue;
                char a[100];
                for(k=j+1;k<=i;k++)
                {
                    a[k-j-1]=s[k];
                }
                a[k-j-1]=0;

                    dp[i]+=dp[j]*mp[a];

            }
        printf("%d\n",dp[len]);
    }
}


