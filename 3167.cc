#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=100005,M=30005;
int ar[N],br[M],next[M];
int as[N][30],bs[M][30],n,m,s;
vector<int> ans;
void init()
{
    ans.clear();
    memset(as,0,sizeof(as));
    memset(bs,0,sizeof(bs));
    as[1][ar[1]]=bs[1][br[1]]=1;
    for(int i=2;i<=n;i++)
    {
        memcpy(as[i],as[i-1],sizeof(as[0]));
        as[i][ar[i]]++;
    }
    for(int i=2;i<=m;i++)
    {
        memcpy(bs[i],bs[i-1],sizeof(bs[0]));
        bs[i][br[i]]++;
    }
}
void getnext()
{
    memset(next,0,sizeof(next));
    int i=1,j=0,k,si,sj,ei,ej;
    next[1]=0;
    while(i<=m)
    {
        si=sj=ei=ej=0;
        for(k=1;k<br[i];k++)
            si+=bs[i][k]-bs[i-j][k];
        ei=bs[i][k]-bs[i-j][k];
        for(k=1;k<br[j];k++)
            sj+=bs[j][k];
        ej=bs[j][k];
        if(j==0||(si==sj&&ei==ej))
            i++,j++,next[i]=j;
        else j=next[j];
    }
}
void kmp()
{
    int i,j,k,si,sj,ei,ej;
    for(i=j=1;i<=n;)
    {
        si=sj=ei=ej=0;
        for(k=1;k<ar[i];k++)
            si+=as[i][k]-as[i-j][k];
        ei=as[i][k]-as[i-j][k];
        for(k=1;k<br[j];k++)
            sj+=bs[j][k];
        ej=bs[j][k];
        if(j==0||(si==sj&&ei==ej))
            i++,j++;
        else j=next[j];
        if(j==m+1)
        {
            ans.push_back(i-m);
            j=next[j];
        }
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&s)!=EOF)
    {
        for(int i=1;i<=n;i++)scanf("%d",ar+i);
        for(int i=1;i<=m;i++)scanf("%d",br+i);
        init();
        getnext();
        kmp();
        printf("%d\n",s=ans.size());
        for(int i=0;i<s;i++)printf("%d\n",ans[i]);
    }
    return 0;
}



