#include"cstdlib"
#include"cstdio"
#include"cstring"
#include"cmath"
#include"queue"
#include"algorithm"
#include"iostream"
#include"map"
#include"string"
#define mod 1000000009
#define ll long long
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        int max=0;
        char v[123][77];
        char x[77],ans[87];
        scanf("%d",&n);
        int i,k,j;
        for(i=0;i<n;i++) scanf("%s",v[i]);
        for(i=0;v[0][i+2];i++)
        {
            for(j=2;v[0][i+j];j++)
            {
                for(k=0,m=0;k<=j;k++)    x[m++]=v[0][i+k];
                x[m]='\0';
                for(k=1;k<n;k++) if(strstr(v[k],x)==NULL) break;
                if(k==n&&j>=max)
                {
                    if(j==max)
                    {
                        if(strcmp(x,ans)<0)
                            strcpy(ans,x);
                    }
                    else
                        strcpy(ans,x);
                    max=j;
                }
            }
        }
        if(!max)
            printf("no significant commonalities\n");
        else
            printf("%s\n",ans);
    }
}




