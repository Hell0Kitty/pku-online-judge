#include <iostream>
#include <cstring>
#include <algorithm>


#define H   51
#define W   51

using namespace std;

char f[H][W];
char vis[H][W];
char d[8][2] = {{-1,0},{0,-1},{0,1},{1,0},{1,-1},{-1,1},{-1,-1},{1,1}};

int w, h, ans[W], n, num;

int cmp(const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void prints()
{
    for(int i=1; i <= h; ++i)
    {
        for(int j=1; j <= w; ++j)
            cout << (int)vis[i][j];
        cout << endl;
    }
    cout << "-------------------------------------------------------" << endl;
}

void findNum(int x, int y)
{
    if(f[x][y]!='X' || vis[x][y] != 0)
        return;
    vis[x][y] = 2;
    for(int i=0; i < 4; ++i)
    {
        int dx = x + d[i][0];
        int dy = y + d[i][1];
        findNum(dx, dy);
    }
    return;
}

int dfs(int x, int y)
{
    if(f[x][y] == '*' || f[x][y] == 'X')
    {
        if(vis[x][y] == 1)
            return 1;
        if(f[x][y] == 'X' && vis[x][y] == 0)
        {
            num++;
            findNum(x, y);
        }
        vis[x][y] = 1;

        for(int i=0; i < 4; ++i)
        {
            int dx = x + d[i][0];
            int dy = y + d[i][1];
            if(vis[x][y] == 2 && f[dx][dy] == 'X')
                continue;
            dfs(dx, dy);
        }
    }
    return num;
}

int main()
{
    int i=1;
    //freopen("in.txt", "rb+", stdin);
    //freopen("out.txt", "wb+", stdout);
    while(cin >> w >> h, h!=0)
    {
        n = 0;
        memset(ans, 0, sizeof(char)*W);
        memset(f  , 0, sizeof(char)*H*W);
        memset(vis, 0, sizeof(char)*H*W);

        for(int i=1; i <= h; ++i)
            for(int j=1; j <= w; ++j)
                cin >> f[i][j];

        for(int i=1; i <= h; ++i)
            for(int j=1; j <= w; ++j)
                if((f[i][j] == '*' || f[i][j] == 'X') && vis[i][j] == 0)
                {
                    num = 0;
                    ans[n++] = dfs(i, j);
                    //prints();
                }

        cout << "Throw " << i++ << endl;
        qsort(ans, n, sizeof(int), cmp);
        for(int i=0; i < n; ++i)
        {
            if(i!=0)
                cout << " ";
            cout << ans[i];
        }
        cout << "\n" << endl;
    }
    return 0;
}



