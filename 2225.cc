#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
struct data
{
    int x,y,z;
    bool operator==(const data &ne)const
    {
        return x==ne.x&&y==ne.y&&z==ne.z;
    }
    data(){}
    data(int _x,int _y,int _z){x=_x;y=_y;z=_z;}
};
int mark[15][15][15];
char map[15][15][15];
int dr[][3]={0,0,1,0,0,-1,0,1,0,0,-1,0,1,0,0,-1,0,0};
int main()
{
    char s[10];
    while(scanf("%s",s)!=EOF)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%s",map[i][j]);
        data a,t;
        scanf("%d%d%d",&a.z,&a.y,&a.x);
        scanf("%d%d%d",&t.z,&t.y,&t.x);
        queue<data> Q;
        memset(mark,-1,sizeof(mark));
        mark[a.x][a.y][a.z]=0;
        Q.push(a);
        scanf("%s",s);
        bool flag=false;
        while(!Q.empty())
        {
            a=Q.front();
            Q.pop();
            if(a==t)
            {
                flag=true;
                break;
            }
            int tp=mark[a.x][a.y][a.z];
            for(int i=0;i<6;i++)
            {
                data b(a.x+dr[i][0],a.y+dr[i][1],a.z+dr[i][2]);
                if(b.x<0||b.x>=n||b.y<0||b.y>=n||b.z<0||b.z>=n||mark[b.x][b.y][b.z]!=-1||map[b.x][b.y][b.z]=='X')
                    continue;
                mark[b.x][b.y][b.z]=tp+1;
                Q.push(b);
            }
        }
        if(flag)
            printf("%d %d\n",n,mark[t.x][t.y][t.z]);
        else
            printf("NO ROUTE\n");
    }
    return 0;
}



