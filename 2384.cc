#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
#include<string>  
#include<queue>  
#include<algorithm>  
#include<vector>  
#include<stack>  
#include<list>  
#include<iostream>  
#include<map>  
using namespace std;  
#define inf 0x3f3f3f3f  
#define Max 110  
inline int max(int a,int b)  
{  
    return a>b?a:b;  
}  
int min(int a,int b)  
{  
    return a<b?a:b;  
}  
int vst[27][27][27][27],ans;  
char mp[27][27];  
int sx,sy,n;  
struct node  
{  
    int rx,ry,bx,by,d;  
};  
int dx[4][2]={0,1,1,0,-1,0,0,-1};  
void bfs()  
{  
    int i,x,y,tx,ty;  
    node ct,st;  
    queue<node>q;  
    st.bx=sx,st.by=sy;  
    for(i=0;i<4;i++)  
    {  
        x=sx+dx[i][0];  
        y=sy+dx[i][1];  
        if(x>=0&&x<n&&y>=0&&y<n&&mp[x][y]!='#')  
        {  
            ct=st;ct.rx=x;ct.ry=y;  
            ct.d=0;  
            vst[ct.rx][ct.ry][ct.bx][ct.by]=1;  
            q.push(ct);  
        }  
    }  
    while(!q.empty())  
    {  
        st=q.front();    
        q.pop();  
        for(i=0;i<4;i++)  
        {  
            x=st.rx+dx[i][0];  
            y=st.ry+dx[i][1];  
            tx=st.rx+dx[3-i][0];  
            ty=st.ry+dx[3-i][1];  
            if(x>=0&&x<n&&y>=0&&y<n&&mp[x][y]!='#'&&(x!=st.bx||y!=st.by))  
            {  
                if(tx==st.bx&&ty==st.by)  
                {  
                    if(!vst[x][y][st.rx][st.ry])  
                    {  
                        vst[x][y][st.rx][st.ry]=1;  
                        ct.rx=x;ct.ry=y;  
                        ct.bx=st.rx;ct.by=st.ry;  
                        ct.d=st.d+1;  
                        ans=max(ans,ct.d);  
                        q.push(ct);  
                    }  
                }  
                if(!vst[x][y][st.bx][st.by])  
                {  
                    vst[x][y][st.bx][st.by]=1;  
                    ct=st;  
                    ct.rx=x;ct.ry=y;  
                    ct.d=st.d+1;  
                    if(ct.bx!=sx||ct.by!=sy)  
                    {  
                        ans=max(ans,ct.d);  
                        q.push(ct);  
                    }  
                }  
            }  
        }  
    }  
}  
int main()  
{  
    int i,j;  
    scanf("%d",&n);  
    ans=0;  
    for(i=0;i<n;i++)  
        scanf("%s",mp[i]);  
    for(i=0;i<n;i++)  
        for(j=0;j<n;j++)  
        {  
            if(mp[i][j]=='*')  
            {  
                sx=i;  
                sy=j;  
                bfs();  
                printf("%d\n",ans);  
                return 0;  
            }  
        }  
}



