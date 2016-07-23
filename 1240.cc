#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll c[30][30];
int n;
ll dfs(char s1[],char s2[])
{
    ll ans=1;
    if(s1[0]==s2[0])
        return 1ll;
    int i,j,k,cnt=0,len=strlen(s1);
    for(i=1,j=0;i<len;)
    {
        k=1;
        while(s1[i]!=s2[j])
            j++,k++;
        cnt++;
        char t1[30],t2[30];
        strncpy(t1,s1+i,k);
        strncpy(t2,s2+j-k+1,k);
        t1[k]=t2[k]='\0';
        ans*=dfs(t1,t2);
        i+=k;
        j++;
    }
    return ans*c[n][cnt];
}
int main()
{
    c[0][0]=1;
    for(int i=1;i<=20;i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
        {
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
    while(scanf("%d",&n),n)
    {
        char s1[30],s2[30];
        scanf("%s%s",s1,s2);
        printf("%lld\n",dfs(s1,s2));
    }
    return 0;
}


