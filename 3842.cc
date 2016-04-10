#include <cstdio>  
#include <cstdlib>  
#include <string>  
#include <cstring>  
#include <map>  
#include <vector>  
#include <cmath>  
using namespace std;  
int f[10000],su[1000],nn=0;  
bool used[10000000];  
int ans,len,a[8];  
char str[10];  
void init()  
{  
    int i,j;  
    memset(f,0,sizeof(f));  
    for(i=2;i<3400;i++)  
        if(!f[i])  
            for(j=2*i;j<3400;j+=i)  
                f[j]=1;  
    for(i=2;i<3400;i++)  
        if(!f[i])  
            su[nn++]=i;  
}  
int antry(int x)  
{  
    if(x==0||x==1) return 0;  
    for(int i=0;i<nn&&su[i]<x;i++)  
        if(x%su[i]==0)  
            return 0;  
    return 1;  
}  
void dfs(int cur,int num,int ck)  
{  
    if(used[num]) return;  
    if(antry(num)&&!used[num]){  
        used[num]=1;  
        ans++;  
    }  
    used[num]=1;  
    if(cur==len) return;  
    dfs(cur+1,num,ck);  
    for(int i=0;i<len;i++){  
        if(num==0&&a[i]==0) continue;  
        if(ck&(1<<i)) continue;  
        dfs(cur+1,num*10+a[i],ck|(1<<i));  
    }  
}  
int main()  
{  
    int t;init();  
    scanf("%d",&t);  
    while(t--){  
        scanf("%s",str);  
        ans=0; len=strlen(str);  
        memset(used,0,sizeof(used));  
        for(int i=0;i<len;i++)  
            a[i]=(str[i]-'0');  
        dfs(0,0,0);  
        printf("%d\n",ans);  
    }  
    return 0;  
}



