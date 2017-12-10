#include<cstdio>
#include<cstring>
#include<map>
#include<string>
using namespace std;
const int inf=1000000;
int ma[300],lm[50020];
map<string,int> md;
char word[50020][70];
int dp[120],pre[120];
int main()
{
    ma['i']=ma['j']='1';
    ma['a']=ma['b']=ma['c']='2';
    ma['d']=ma['e']=ma['f']='3';
    ma['g']=ma['h']='4';
    ma['k']=ma['l']='5';
    ma['m']=ma['n']='6';
    ma['p']=ma['r']=ma['s']='7';
    ma['t']=ma['u']=ma['v']='8';
    ma['w']=ma['x']=ma['y']='9';
    ma['o']=ma['q']=ma['z']='0';
    char s[120];
    int n;
    while(scanf("%s",s+1)!=EOF)
    {
        md.clear();
        scanf("%d",&n);
        int i,j,k;
        for(i=1; i<=n; i++)
        {
            scanf("%s",word[i]);
            char tp[70];
            for(j=0;word[i][j];j++)
                tp[j]=ma[word[i][j]];
            tp[lm[i]=j]='\0';
            md[tp]=i;
        }
        memset(pre,-1,sizeof(pre));
        for(i=110;i>0;i--)
            dp[i]=inf;
        dp[0]=0;
        for(i=1;s[i]!='\0';i++)
        {
            if(dp[i-1]==inf)
                continue;
            if(md.find(s+i)!=md.end())
                {
                    k=md[s+i];
                    if(dp[i-1+lm[k]]>dp[i-1]+1)
                    {
                        dp[i-1+lm[k]]=dp[i-1]+1;
                        pre[i-1+lm[k]]=k;
                    }
                }
            for(j=i+1;s[j]!='\0';j++)
            {
                char ch=s[j];
                s[j]='\0';
                if(md.find(s+i)!=md.end())
                {
                    k=md[s+i];
                    if(dp[i-1+lm[k]]>dp[i-1]+1)
                    {
                        dp[i-1+lm[k]]=dp[i-1]+1;
                        pre[i-1+lm[k]]=k;
                    }
                }
                s[j]=ch;
            }
        }
        if(dp[--i]==inf)
            printf("No solution.\n");
        else
        {
            int wos[200],top=0;
            for(; i!=0; i-=lm[pre[i]])
                wos[top++]=pre[i];
            for(int i=top-1; i>0; i--)
                printf("%s ",word[wos[i]]);
            printf("%s\n",word[wos[0]]);
        }
    }
    return 0;
}