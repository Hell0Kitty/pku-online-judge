#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<iterator>
#include<utility>
#include<sstream>
#include<iostream>
#include<cmath>
#include<stack>
using namespace std;
const int INF=1000000007;
const double eps=0.00000001;
int dx[]={0,-1,0,1},dy[]={-1,0,1,0};
int vis[10][10],hold[10][10][10][10];
int pre[10][10];
char dir[]={'N','W','S','E'};
struct node
{
    int x,y;
};
bool in(int x,int y){ return x>=1&&x<=6&&y>=1&&y<=6; }
int main()
{
    int bex,bey,endx,endy;
    while(cin>>bex>>bey&&(bex||bey))
    {
        cin>>endx>>endy;
        int x1,y1,x2,y2;
        memset(hold,0,sizeof(hold));
        for(int i=0;i<3;i++)
        {
            cin>>x1>>y1>>x2>>y2;
            if(x1==x2)  for(int st=min(y1,y2)+1;st<=max(y1,y2);st++)  hold[x1][st][x1+1][st]=hold[x1+1][st][x1][st]=1;
            else  for(int st=min(x1,x2)+1;st<=max(x1,x2);st++)  hold[st][y1][st][y1+1]=hold[st][y1+1][st][y1]=1;
        }
        queue<node> que;
        node start;
        start.x=bex,start.y=bey;
        que.push(start);
        memset(vis,0,sizeof(vis));
        vis[bex][bey]=1;
        pre[bex][bey]=-1;
        while(!que.empty())
        {
            node now=que.front();
            que.pop();
            if(now.x==endx&&now.y==endy)  break;
            for(int i=0;i<4;i++)
            {
                node t;
                t.x=now.x+dx[i];
                t.y=now.y+dy[i];
                if(in(t.x,t.y)&&!vis[t.x][t.y]&&!hold[now.x][now.y][t.x][t.y])
                {
                    vis[t.x][t.y]=1;
                    pre[t.x][t.y]=i;
                    que.push(t);
                }
            }
        }
        int lastx=endx,lasty=endy;
        string ans;
        while(pre[lastx][lasty]!=-1)
        {
            int t=pre[lastx][lasty];
            ans=dir[t]+ans;
            lastx=lastx-dx[t],lasty=lasty-dy[t];
        }
        cout<<ans<<endl;
    }
    return 0;
}



