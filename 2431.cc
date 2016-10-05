#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;
struct stop
{
    int x;
    int v;
}s[10010];
bool comp(stop s1, stop s2)
{
    return s1.x < s2.x;
}
int main()
{
    int n, i, L, P;
    while(~scanf("%d",&n))
    {
        for(i = 0; i < n; i++)
            scanf("%d%d",&s[i].x, &s[i].v);
        scanf("%d%d",&L,&P);
        for(i = 0; i < n; i++)
            s[i].x = L - s[i].x; 
        s[n].x = L;
        s[n++].v = 0; 
        sort(s, s+n, comp);
        priority_queue<int, vector<int>, less<int> > Q; 
        int rest = P; 
        int ans = 0; 
        int pos = 0; 
        for(i = 0; i < n; i++)
        {
            int dis = s[i].x - pos; 
            while(rest - dis < 0) 
            {
                if(Q.empty()) 
                {
                    ans = -1;
                    break;
                }
                rest += Q.top();
                Q.pop();
                ans++;
            }
            if(ans == -1)
                break;
            rest = rest - dis;
            pos = s[i].x;
            Q.push(s[i].v);
        }
        printf("%d\n",ans);
    }
    return 0;
}



