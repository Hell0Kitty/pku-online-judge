#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <bitset>
#include <vector>
using namespace std;

const int BORDER = (1<<26)-1;
const int MAXSIZE = 37;
const int MAXN = 150;
const int INF = 0x6ffffff;
#define CLR(x,y) memset(x,y,sizeof(x))
#define ADD(x) x=((x+1)&BORDER)
#define IN(x) scanf("%d",&x)
#define OUT(x) printf("%d\n",x)
#define MIN(m,v) (m)<(v)?(m):(v)
#define MAX(m,v) (m)>(v)?(m):(v)
#define ABS(x) (x>0?x:-x)

#define SET_NODE(no,a,b)  {no.x=a;no.y=b;}
typedef struct {
    int x,y;
}Node;
Node que[BORDER+5],hole[MAXN*MAXN],t_node;
int direct[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int st,en;
int n,m,n_hole,ans_wall,ans_hole,cur_wall,cur_hole;
int arr[MAXN][MAXN],v_wall[MAXN][MAXN],v_hole[MAXN][MAXN];
int visit[MAXN][MAXN];
int _is(const int& x,const int& y)
{
    if(x<0 || x>=n)
        return false;
    if(y<0 || y>=m)
        return false;
    return true;
}
int init()
{
    ans_hole = 0;
    ans_wall = INF;
    CLR(arr,0);
    CLR(v_wall,0);
    CLR(v_hole,0);
    CLR(visit,0);
    return 0;
}
bool _in(const int& x,const int& y)
{
    int i,j,a,b;
    for(i = 0; i < 4; ++i)
    {
        a = x;
        b = y;
        while(true)
        {
            a += direct[i][0];
            b += direct[i][1];
            if(!_is(a,b))
                return false;
            if(arr[a][b] && v_wall[a][b])
                break;
        }
    }
    return true;
}
int bfs_wall(const int& sx,const int& sy)
{
    int i,j,a,b,x,y;
    CLR(v_wall,0);
    CLR(v_hole,0);
    st = 0;
    en = 1;
    cur_wall = 0;
    n_hole = 0;
    SET_NODE(que[0],sx,sy);
    v_wall[sx][sy] = 1;
    visit[sx][sy] = 1;
    while(st < en)
    {
        a = que[st].x;
        b = que[st].y;
        ++cur_wall;
        ADD(st);
        for( i = 0; i < 4; ++i)
        {
            x = a + direct[i][0];
            y = b + direct[i][1];
            if(_is(x,y))
            {
                if(arr[x][y])
                {
                    if(!v_wall[x][y])
                    {
                        SET_NODE(que[en],x,y);
                        ADD(en);
                        v_wall[x][y] = 1;
                        visit[x][y] = 1;
                    }
                }else
                {
                    if(!v_hole[x][y])
                    {
                        SET_NODE(hole[n_hole],x,y);
                        v_hole[x][y] = 1;
                        ++n_hole;
                    }
                }
            }
        }
    }
    return 0;
}
int bfs_hole(const int& sx,const int& sy)
{
    int a,b,x,y,i,j,flag;
    st = 0;
    en = 1;
    flag = 0;
    SET_NODE(que[0],sx,sy);
    while(st < en)
    {
        a = que[st].x;
        b = que[st].y;
        ADD(st);
        if(!flag)
            if(!_in(a,b))
            {
                flag = -1;
            }
        for(i = 0; i < 4; ++i)
        {
            x = a + direct[i][0];
            y = b + direct[i][1];
            if(_is(x,y))
            {
                if(arr[x][y])
                {
                    ;
                }else
                {
                    if(!v_hole[x][y])
                    {
                        SET_NODE(que[en],x,y);
                        ADD(en);
                        v_hole[x][y] = 1;
                    }
                }
            }else
            {
                return -1;
            }
        }
    }
    return flag;
}
int work()
{
    int i,j,tmp,k;
    for(i = 0; i < n; ++i)
        for(j = 0; j < m; ++j)
        {
            if(arr[i][j] && !visit[i][j])
            {
                bfs_wall(i,j);
                CLR(v_hole,0);
                cur_hole = 0;
                for(k = 0; k < n_hole; ++k)
                {
                    if(!v_hole[hole[k].x][hole[k].y])
                    {
                        tmp = bfs_hole(hole[k].x,hole[k].y);
                        if(tmp == -1)
                            continue;
                        else
                            ++cur_hole;
                    }
                }
                if(cur_hole == ans_hole && cur_hole!=0)
                    ans_wall = MIN(ans_wall,cur_wall);
                else if(cur_hole > ans_hole)
                {
                    ans_hole = cur_hole;
                    ans_wall = cur_wall;
                }
            }
        }
    if(ans_wall < INF)
        OUT(ans_wall);
    else
    {
        ans_wall = 0;
        OUT(ans_wall);
    }
    return 0;
}
int input()
{
    int i,j;
    char str[MAXN];
    for(i = 0; i < n; ++i)
    {
        scanf("%s",str);
        for(j = 0; j < m; ++j)
            if(str[j] == '*')
                arr[i][j] = 1;
    }
    return 0;
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        init();
        input();
        work();
    }
    return 0;
}



