#include<queue>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 1005
#define inf 0x3f3f3f3f
int w,h;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char mp[maxn][maxn];
int sum;
bool judge(int x,int y){
    if(x>=0&&y>=0&&x<h&&y<w&&mp[x][y]=='*')return true;
    return false;
}
void dfs(int x,int y){
   mp[x][y]='.';
   sum++;
   for(int i=0;i<4;i++){
    int nx=x+dir[i][0];
    int ny=y+dir[i][1];
    if(judge(nx,ny)){
        dfs(nx,ny);
    }
   }
}
int main()
{
    //freopen("in.txt","r",stdin);
    while(scanf("%d%d",&w,&h)!=EOF){
        for(int i=0;i<h;i++)
            scanf("%s",mp[i]);
            int mas=0;
        for(int i=0;i<h;i++)
            for(int j=0;j<w;j++){
                if(mp[i][j]=='*'){
                        sum=0;
                        dfs(i,j);
                        mas=max(mas,sum);
                }
            }
            printf("%d\n",mas);
    }
}



