#include <stdio.h>
# include <string.h>

# define N 33

int n;
int tar[N];

int ans;
int stop;
int station[N],result[N];

int MIN(int a,int b)
{
    return a>b?b:a;
}

void init()
{
    for (int i = 1;i <= n; i ++)
    {
        scanf("%d",&tar[i]);
    }
}

bool isOK(int time)
{
    int t_st=1,t_ti=0;
    int tmp;
    stop=0;
    for (int i=1;i<=n;i++)
    {
        if (tar[i] <= t_st) continue;
        tmp = t_ti+(tar[i]-t_st)*20;
        if (tmp <= time) continue ;
        if (t_st == 1)
        {
            tmp = time - t_ti + (4*t_st+20*tar[i]);
        }
        else
        {
            tmp = time - (t_ti+10) + (4*t_st+20*tar[i]);
        }
        tmp /= 24;
        if (tmp<tar[i]) return false;
        if (t_st==1)
        {
            t_ti+= (tmp-t_st)*4;
        }
        else
        {
            t_ti += 10+(tmp-t_st)*4;
        }
        t_st = tmp;
        stop++; station[stop]=t_st;
    }

    return true;
}

void solve()
{
    ans = tar[n]*4+20*(tar[n]-tar[1]);
    result[0]=1; result[1]=tar[n];

    int low=0,up=ans-1,mid;
    while (low<up)
    {
        mid = (low+up)/2;
        if (isOK(mid))
        {
            {
                result[0]=stop;
                for (int i=1;i<=stop;i++)
                {
                    result[i] = station[i];
                }
                ans = mid;
            }
            up = mid;
        }
        else
        {
            low = mid+1;
        }
    }
}

void output()
{
    printf("%d\n%d",ans,result[0]);
    for (int i=1;i<=result[0];i++)
    {
        printf(" %d",result[i]);
    }
    printf("\n");
}

int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n == 0) break;
        init();
        solve();
        output();
    }
    return 0;
}


