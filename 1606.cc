#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
typedef struct Node
{
    int xx;
    int yy;
} Node;
typedef struct Path
{
    int x,y;
    int step;
} Path;
int vis[1010][1010];
Path path[1010][1010];
Node pos;
int  ca,cb,n;
bool flag;
char map[7][12]=
{
    {"fill A"},
    {"fill B"},
    {"empty A"},
    {"empty B"},
    {"pour A B"},
    {"pour B A"},
};
Node judge(int i,Node p)
{
    Node a;
    int t;
    switch(i)
    {
    case 0:
        a.xx=ca;
        a.yy=p.yy;
        break;
    case 1:
        a.xx=p.xx;
        a.yy=cb;
        break;
    case 2:
        a.xx=0;
        a.yy=p.yy;
        break;
    case 3:
        a.xx=p.xx;
        a.yy=0;
        break;
    case 4:
        t=cb-p.yy;
        if(t>=p.xx)
        {
            a.xx=0;
            a.yy=p.yy+p.xx;
            break;
        }
        else
        {
            a.yy=cb;
            a.xx=p.xx-t;
            break;
        }
    case 5:
        t=ca-p.xx;
        if(t>=p.yy)
        {
            a.xx=p.xx+p.yy;
            a.yy=0;
            break;
        }
        else
        {
            a.xx=ca;
            a.yy=p.yy-t;
            break;
        }
    }
    return a;
}
void BFS()
{
    queue<Node> q;
    Node tem;
    tem.xx=0;//(0,0)为起始点。
    tem.yy=0;
    vis[tem.xx][tem.yy]=true;
    q.push(tem);
    while(!q.empty())
    {
        Node t=q.front();
        q.pop();
        for(int i=0; i<6; i++)
        {
            Node np=judge(i,t);
            if(!vis[np.xx][np.yy])
            {
                vis[np.xx][np.yy]=1;
                path[np.xx][np.yy].step=i;  //放的是它前驱结点的值。
                path[np.xx][np.yy].x=t.xx;
                path[np.xx][np.yy].y=t.yy;
                q.push(np);
                if(np.yy==n)
                {
                    pos=np;
                    flag=true;
                    break;
                }
            }
        }
        if(flag)
            return ;
    }
}
void pr(int tx,int ty)//递归打印路径：
{
    if(tx==0&&ty==0)
    {
        return ;
    }
    pr(path[tx][ty].x, path[tx][ty].y);
    printf("%s\n",map[path[tx][ty].step]);
}
int main()
{
    while(scanf("%d%d%d",&ca,&cb,&n)!=EOF)
    {
        flag=false;
        memset(vis,0,sizeof(vis));
        memset(path,0,sizeof(path));
        BFS();
        pr(pos.xx,pos.yy);
        printf("success\n");
    }
    return 0;
}



