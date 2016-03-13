#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=505,M=1000000;
char map[N][N];
bool mark[N][N][3];
int r,c;
struct Data
{
    int x,y,w,step;
}S[M];
bool in(int x,int y)
{
    return x>=1&&x<=r&&y>=1&&y<=c;
}
bool place(int x,int y,int w)
{
    if(!in(x,y)||map[x][y]=='#')
        return false;
    switch(w)
    {
        case 0:
            return map[x][y]!='E';break;
        case 1:
            return in(x,y+1)&&map[x][y+1]!='#';break;
        case 2:
            return in(x+1,y)&&map[x+1][y]!='#';break;
    }
}
int dr[][2]={0,1,1,0,0,-1,-1,0};
int main()
{
    while(scanf("%d%d",&r,&c),(r||c))
    {
        bool flag=false;
        Data a,b;
        for(int i=1; i<=r; i++)
        {
            scanf("%s",map[i]+1);
            for(int j=1; j<=c; j++)
            {
                if(map[i][j]=='X')
                {
                    if(flag)
                    {
                        if(in(i-1,j)&&map[i-1][j]=='X')
                            a.w=2;
                        else
                            a.w=1;
                    }
                    else
                    {
                        flag=true;
                        a.x=i;
                        a.y=j;
                        a.w=a.step=0;
                    }
                }
            }
        }
        int st=0,ed=1;
        S[0]=a;
        memset(mark,false,sizeof(mark));
        mark[a.x][a.y][a.w]=true;
        while(st!=ed)
        {
            a=S[st++];
            if(st==M)
                st=0;
            if(a.w==0&&map[a.x][a.y]=='O')
            {
                flag=false;
                printf("%d\n",a.step);
                break;
            }
            for(int i=0;i<4;i++)
            {
                b.x=a.x+dr[i][0];
                b.y=a.y+dr[i][1];
                b.step=a.step+1;
                switch(a.w)
                {
                    case 0:
                    {
                        switch(i)
                        {
                            case 0:
                                b.w=1;break;
                            case 1:
                                b.w=2;break;
                            case 2:
                                b.w=1;b.y--;break;
                            case 3:
                                b.w=2;b.x--;break;
                        }
                        break;
                    }
                    case 1:
                    {
                        switch(i)
                        {
                            case 0:
                                b.w=0;b.y++;break;
                            case 1:
                                b.w=1;break;
                            case 2:
                                b.w=0;break;
                            case 3:
                                b.w=1;break;
                        }
                        break;
                    }
                    case 2:
                    {
                        switch(i)
                        {
                            case 0:
                                b.w=2;break;
                            case 1:
                                b.x++;b.w=0;break;
                            case 2:
                                b.w=2;break;
                            case 3:
                                b.w=0;break;
                        }
                        break;
                    }
                }
                if(place(b.x,b.y,b.w)&&!mark[b.x][b.y][b.w])
                {
                    mark[b.x][b.y][b.w]=true;
                    S[ed++]=b;
                    if(ed==M)
                        ed=0;
                }
            }
        }
        if(flag)
            printf("Impossible\n");
    }
    return 0;
}



