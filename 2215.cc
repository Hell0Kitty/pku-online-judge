nclude<iostream>
#include<cstdio>
using namespace std;

int maze[1010][1010];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,m,n;
        scanf("%d%d",&m,&n);
        for(i=0;i<m;i++)
            for(j=0;j<n;j++)
                scanf("%d",&maze[i][j]);
        int t;
        scanf("%d",&t);
        while(t--)
        {
            int ans=0;
            int r1,r2,s1,s2;
            scanf("%d%d%d%d",&r1,&r2,&s1,&s2);
            for(i=r1-1;i<s1;i++)
                for(j=r2-1;j<s2;j++)
                    ans+=maze[i][j];
            printf("Absolutni hodnota pohodlnosti je %d bodu.\n",ans);
        }
        if(T)
            cout<<endl;
    }
    return 0;
}



