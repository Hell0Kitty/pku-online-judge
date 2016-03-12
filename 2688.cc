#include <stdio.h>
#include <memory.h>
#define MAXN 20
typedef struct Node
{
  int step;
  int x,y;
}Node;
Node stack[10000],u;

typedef struct Point
{
  int x,y;
}Point;

Point point[15];

int min,sum;
int dist[15][15];
char map[MAXN][MAXN];
char grid[MAXN][MAXN];
int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};
int m,n;
int BFS(Point start, Point end)
{
  int sx = start.x;
  int sy = start.y;
  int ex = end.x;
  int ey = end.y;
  int head,tail,i,j,k;
  int flag = 0;

  for (k = 0; k < n; k ++)
  {
    for (j = 0; j < m; j ++)
    {
      map[k][j] = grid[k][j];
    }
  }

  map[sx][sy] = 'x';
  stack[0].x = sx;
  stack[0].y = sy;
  stack[0].step = 0;
  head = 0;
  tail = 1;

  while (head < tail)
  {
    u = stack[head ++];
    if (u.x == ex && u.y == ey)
    {
      flag = 1;
      break;
    }
    for (i = 0; i < 4; i ++)
    {
      if (u.x + dx[i] < n && u.x + dx[i] >= 0 && u.y + dy[i] < m && u.y + dy[i] >= 0 && map[u.x + dx[i]][u.y + dy[i]] != 'x')
      {
        stack[tail].x = u.x + dx[i];
        stack[tail].y = u.y + dy[i];
        stack[tail].step = u.step + 1;
        map[u.x + dx[i]][u.y + dy[i]] = 'x';
        tail ++;
      }
    }
  }
  if (flag)
    return u.step;
  else
    return -1;
}

int visited[15];
void DFS(int num,int add,int cur)
{
  int i;
  if (num == sum - 1)
  {
    if (add < min || min < 0)
    {
      min = add;
    }
  }
  else
  {
    for (i = 1; i < sum; i ++)
    {
      if ((add < min || min < 0) && !visited[i])
      {
        visited[i] = 1;
        DFS(num + 1,add + dist[cur][i],i);
      }
    }
  }
  visited[cur] = 0;
}
int main()
{
  int i,j,k;
  int head,tail;
  int flag;
  while (scanf("%d%d",&m,&n),m,n)
  {
    getchar();
    sum = 1;
    for (i = 0; i < n; i ++)
    {
      for (j = 0; j < m; j ++)
      {
        scanf("%c",&grid[i][j]);
        if (grid[i][j] == 'o')
        {
          point[0].x = i;
          point[0].y = j;
        }
        if (grid[i][j] == '*')
        {
          point[sum].x = i;
          point[sum].y = j;
          sum ++;
        }
      }
      getchar();
    }
    flag = 1;
    memset(dist,-1,sizeof(dist));
    for (i = 0; i < sum; i ++)
    {
      for (j = i; j < sum; j ++)
      {
        dist[i][j] = dist[j][i] = BFS(point[i],point[j]);
        if (dist[i][j] == -1)
        {
          flag = 0;
          break;
        }
      }
    }
    if (flag)
    {
      min = -1;
      memset(visited,0,sizeof(visited));
      visited[0] = 1;
      DFS(0,0,0);
      printf("%d\n",min);
    }
    else
      puts("-1");
  }
  return 0;
}
