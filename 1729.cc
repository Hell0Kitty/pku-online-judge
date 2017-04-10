#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#define min(a,b) a<b?a:b
#include<algorithm>
#include<vector>
#include<stack>
#include<iostream>
#include<queue>
using namespace std;
struct status
{
public:
  int hx,hy;
  int Hx,Hy;
  int mindist;
  char moveh,moveH;
  int pre;
  int id;
  bool operator < (const status& r) const
  {
    return this->mindist<r.mindist;
  }
};
int fx[]={0,-1,0,1};
int fy[]={1,0,-1,0};
char move[]="ENWS";
int g[50][50][50][50];
int n;
int p;
char mp[100][100];
status way[1000000];//记录路径
int dist(int x1,int y1,int x2,int y2)
{
  return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
void BFS(int hx,int hy,int Hx,int Hy)
{
  int i,j;
  memset(g,-1,sizeof(g));
  status x,y;
  p=0;
  x.hx=hx,x.hy=hy,x.Hx=Hx,x.Hy=Hy;
  x.id=p;
  x.pre=-1;
  int dis=dist(hx,hy,Hx,Hy);
  x.mindist=dis;
  way[p++]=x;
  priority_queue<status> que;
  que.push(x);
  while(!que.empty())
  { 
    y=que.top();
    que.pop();
    if(mp[y.hx][y.hy]=='s'&&mp[y.Hx][y.Hy]=='S')
    {
      printf("%.2f\n",sqrt(1.0*y.mindist));
      stack<char> st1,st2;
      while(y.pre!=-1)
      {
        if(y.moveH!='*')
        st1.push(y.moveH);
        if(y.moveh!='*')
        st2.push(y.moveh);
        y=way[y.pre];
      }
      while(!st1.empty())
      {
        printf("%c",st1.top());
        st1.pop();
      }
      puts("");
      while(!st2.empty())
      {
        printf("%c",st2.top());
        st2.pop();
      }
      puts("");
      break;
    }
    for(i=0;i<4;i++)
    {
      int a=y.hx+fx[i];
      int b=y.hy+fy[i];
      char moveh=move[i];
      if(mp[y.hx][y.hy]=='s')
        a=y.hx,b=y.hy,moveh='*';
      if(a>=0&&a<n&&b>=0&&b<n&&mp[a][b]!='*'&&mp[a][b]!='S'&&mp[a][b]!='H')
      {
        for(j=0;j<4;j++)
        {
          int c=y.Hx+fx[j];
          int d=y.Hy+fy[j];
          char moveH=move[j];
          if(mp[y.Hx][y.Hy]=='S')
          c=y.Hx,d=y.Hy,moveH='*';
          if(c>=0&&c<n&&d>=0&&d<n&&mp[c][d]!='*'&&mp[c][d]!='s'&&mp[c][d]!='h')
          {
            dis=dist(a,b,c,d);
            dis=min(dis,y.mindist);
            if(dis>g[a][b][c][d]||g[a][b][c][d]==-1)
            {
              x.hx=a,x.hy=b,x.Hx=c,x.Hy=d;
              x.id=p;
              x.mindist=dis;
              x.pre=y.id;
              x.moveh=moveh;
              x.moveH=moveH;
              way[p++]=x;
              que.push(x);
              g[a][b][c][d]=dis;
            }
          }
          if(mp[y.Hx][y.Hy]=='S')
            break;
        }
      }
      if(mp[y.hx][y.hy]=='s')
        break;
    }
  }
}
int main()
{
  int i,j,hx,hy,Hx,Hy;
  while(cin>>n,n)
  {
    for(i=0;i<n;i++)
    {
      cin>>mp[i];
      for(j=0;j<n;j++)
      if(mp[i][j]=='h')
        hx=i,hy=j;
      else
        if(mp[i][j]=='H')
      Hx=i,Hy=j;
      mp[i][j]='\0';
    }
    BFS(hx,hy,Hx,Hy);
  }
  return 0;
}