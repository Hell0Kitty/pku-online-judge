#include <cstdio>
#include <algorithm>
using namespace std;
int mp[1017][1017];
int main()
{
    int c, y;
    while(scanf("%d",&c)!=EOF)
    {
        scanf("%d",&y);
        for(int i = 1; i <= y; i++)
        {
            for(int j = i; j <= y; j++)
            {
                scanf("%d",&mp[i][j]);
            }
        }

        for(int i = 1; i <= y; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                mp[1][i] = min(mp[1][j-1]+mp[j][i]+c,mp[1][i]);
            }
        }
        printf("%d\n",mp[1][y]+c);
    }
    return 0;
}



