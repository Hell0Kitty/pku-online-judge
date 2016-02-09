#include<cstdio>
#include<iostream>
using namespace std;
#include<cstring>
#define MAXN 1000
bool map[MAXN][MAXN];
int next[MAXN];
int head;
int n;
char line[2500];
int main()
{
    int i,j,k;
    while(scanf("%d",&n) != EOF)
    {
        getchar();
        for(i = 0;i < n; i++)
        {
            gets(line);
            int ct;
            for(j = 0,ct = 0;j < 2*n-1;j += 2)
            {
                map[i][ct++] = line[j] -'0';
            }
            next[i] = -1;
        }
        head = 0;
        for(i = 1;i <n; i++)
        {
            if(map[i][head])
            {
                next[i] = head;
                head = i;
                continue;
            }
            j = head;
            k = next[j];
            while(k != -1)
            {
                if(map[j][i] && map[i][k])
                break;
                j = k;
                k = next[j];
            }
            next[i] = k;
            next[j] = i;
        }
        printf("1\n%d\n",n);
        for(i = 0; i < n;i++)
        {
            if(i > 0)printf(" ");
            printf("%d",head+1);
            head = next[head];
        }
        printf("\n");
    }
    return 0;
}




