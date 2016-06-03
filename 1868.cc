#include<cstdio>
#include<algorithm>
using namespace std;
const int N=10005;
int pos[N];
int main()
{
    int n,f;
    while(scanf("%d",&n),n)
    {
        getchar();
        for(int i=0,tp;i<n;i++)
        {
            scanf("%d",&tp);
            pos[tp]=i;
        }
        f=0;
        for(int i=1;!f&&i<n-1;i++)
            for(int j=1,lim=min(n-1-i,i);!f&&j<=lim;j++)
                if((pos[i+j]-pos[i])*(pos[i-j]-pos[i])<0)
                    f=1;
        printf("%s\n",f?"no":"yes");
    }
    return 0;
}



