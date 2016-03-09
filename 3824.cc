#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

struct node
{
    int face,num;
}card[105][105];

int ip[105],work[105];

void turn(int x,int y)
{
    int i;
    for(i=ip[x];i>=1;i--)
    {
        if(card[x][i].face)
        card[x][i].face = 0;
        else
        card[x][i].face = 1;
        card[y][++ip[y]] = card[x][i];
    }
}

int main()
{
    int cas = 1;
    int n,m,i,j;
    char str[105],done[105];
    while(~scanf("%d",&n),n)
    {
        scanf("%s%s",str,done);
        memset(ip,0,sizeof(ip));
        for(i = 0;i<n;i++)
        {
            card[i+1][1].num = i+1;
            if(str[i] == 'U')
            card[i+1][1].face = 1;
            else
            card[i+1][1].face = 0;
            ip[i+1] = 1;
        }
        int l = 1,r = n;
        for(i = 0;i<n-1;i++)
        {
            if(done[i] == 'R')
            {
                turn(r,r-1);
                r--;
            }
            else
            {
                turn(l,l+1);
                l++;
            }
        }
        scanf("%d",&m);
        for(i = 1;i<=m;i++)
        {
            scanf("%d",&work[i]);
        }
        printf("Pile %d\n",cas++);
        for(i = 1;i<=m;i++)
        {
            if(card[r][n-work[i]+1].face==1)
            printf("Card %d is a face up %d.\n",work[i],card[r][n-work[i]+1].num);
            else
            printf("Card %d is a face down %d.\n",work[i],card[r][n-work[i]+1].num);
        }
    }

    return 0;
}



