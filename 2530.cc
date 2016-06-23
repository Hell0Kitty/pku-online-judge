#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char str[55][25],tmp[55][25],ans[27];
int n,flag;

int judge(int x,int y,char ch)
{
    int j;
    for (j=x;j<n;j++)
    {
        if (str[j][y]>='A'&&str[j][y]<='Z'&&str[j][y]!=ch)
        {
            flag=1;return 1;
        }
    }
    return 0;
}

void dfs(int x,int y,char ch)
{
    int i,j,row,col,dir[4][2]={-1,0,1,0,0,-1,0,1};
    for (i=0;i<4;i++)
    {
        row=dir[i][0]+x;
        col=dir[i][1]+y;
        if (row<n&&col<20&&row>=0&&col>=0&&tmp[row][col]==ch)
        {
            if(judge(row,col,ch))return;
            tmp[row][col]='.';
            dfs(row,col,ch);
            if(flag)tmp[row][col]=ch;
        }
    }
}

void slove1()
{
    int i,j,k=0;
    for (j=0;j<20;j++)
    {
        for (i=n-1;i>=0;i--)
        {
            flag=0;
            if (tmp[i][j]!='.')
            {
                tmp[i][j]='.';
                if(!judge(i,j,str[i][j]))
                    dfs(i,j,str[i][j]);
                if(flag)tmp[i][j]=str[i][j];
                else ans[k++]=str[i][j];
                break;
            }
        }
    }
    sort(ans,ans+k);
    printf("%c",ans[0]);
}

void slove2()
{
    int i,j;
    for (j=0;j<20;j++)
    {
        for (i=n-1;i>=0;i--)
        {
            if (tmp[i][j]==ans[0])
            {
                tmp[i][j]='.';
                dfs(i,j,ans[0]);
                return;
            }
        }
    }
}

void Copy1()
{
    int i;
    for (i=0;i<n;i++)strcpy(tmp[i],str[i]);
}

void Copy2()
{
    int i;
    for (i=0;i<n;i++)strcpy(str[i],tmp[i]);
}

int main()
{
    int i,j,num=0,vis[27]={0};
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%s",str[i]);
        strcpy(tmp[i],str[i]);
        for(j=0;j<20;j++)
        {
            if(str[i][j]!='.'&&!vis[str[i][j]-'A'])
            {
                vis[str[i][j]-'A']=1;
                num++;
            }
        }
    }
    for (i=0;i<num;i++)
    {
        slove1();
        Copy1();
        slove2();
        Copy2();
    }
    printf("\n");
    return 0;
}



