#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int, int> > a[50];
inline void input(int n)
{
    int x, y, flag, po_x, po_y;
    char ctmp;
    for (int i = 0; i <= n; ++i)
    {
        po_x = po_y = flag = x = y = 0;
        while ((ctmp = getchar()) != EOF)
        {
            if (flag == 0 && ctmp == '-')
                po_x = 1;
            else if (flag == 0 && ctmp >= '0' && ctmp <= '9')
                x = x * 10 + ctmp - '0';
            else if (flag == 0 && ctmp == ',')
                flag = 1;
            else if (flag == 1 && ctmp == '-')
                po_y = 1;
            else if (flag == 1 && ctmp >= '0' && ctmp <= '9')
                y = y * 10 + ctmp - '0';
            else if (flag == 1 && ctmp == ';')
                flag = 2;
            if (flag == 2)
            {
                if (po_x)
                    x = -x;
                if (po_y)
                    y = -y;
                a[i].push_back(make_pair(x, y));
                po_x = po_y = flag = x = y = 0;
            }
            if (ctmp == '#')
                break;
        }
    }
}
int main(int argc, char* argv[])
{
    int n, ii0, ii1, jj0, jj1, x1, y1, x2, y2, arr[3];
    int max_ans = 0, kx, ky, s0j, x, y, flag, mark_s0, ans;
    int i, j;
    scanf("%d", &n);
    input(n);
    for (ii0 = 0; ii0 <= n; ++ii0) for (jj0 = 0; jj0 < int(a[ii0].size()); ++jj0)
    {
        x1 = a[ii0][jj0].first;
        y1 = a[ii0][jj0].second;
        for (ii1 = 0; ii1 <= n; ++ii1) for (jj1 = 0; jj1 < int(a[ii1].size()); ++jj1)
        {
            x2 = a[ii1][jj1].first;
            y2 = a[ii1][jj1].second;
            if (x1 == x2 && y1 == y2)
                continue;
            kx = y2 - y1;
            ky = x2 - x1;
            x = a[0][0].first;
            y = a[0][0].second;
            if (kx * (x - x1) > (y - y1) * ky)
                flag = 1;
            else if (kx * (x - x1) < (y - y1) * ky)
                flag = -1;
            else
                flag = 0;
            for (s0j = 1; s0j < int(a[0].size()); ++s0j)
            {
                x = a[0][s0j].first;
                y = a[0][s0j].second;
                if (flag == 0)
                {
                    if (kx * (x - x1) > (y - y1) * ky)
                        flag = 1;
                    else if (kx * (x - x1) < (y - y1) * ky)
                        flag = -1;
                }
                else if (flag == 1 && kx * (x - x1) < (y - y1) * ky)
                    break;
                else if (flag == -1 && kx * (x - x1) > (y - y1) * ky)
                    break;
            }
            if (s0j != int(a[0].size())) 
                continue;
            arr[0] = arr[1] = arr[2] = 0; 
            mark_s0 = flag;
            for (i = 1; i <= n; ++i)
            {
                x = a[i][0].first;
                y = a[i][0].second;
                if (kx * (x - x1) > (y - y1) * ky)
                    flag = 1;
                else if (kx * (x - x1) < (y - y1) * ky)
                    flag = -1;
                else
                    flag = 0;
                for (j = 1; j < int(a[i].size()); ++j)
                {
                    x = a[i][j].first;
                    y = a[i][j].second;
                    if (flag == 0)
                    {
                        if (kx * (x - x1) > (y - y1) * ky)
                            flag = 1;
                        else if (kx * (x - x1) < (y - y1) * ky)
                            flag = -1;
                    }
                    else if (flag == 1 && kx * (x - x1) < (y - y1) * ky)
                        break;
                    else if (flag == -1 && kx * (x - x1) > (y - y1) * ky)
                        break;
                }
                if (j == int(a[i].size())) 
                    ++arr[flag + 1];
            }
            if (mark_s0 == 1)
                ans = arr[0] + arr[1];
            else if (mark_s0 == -1)
                ans = arr[1] + arr[2];
            else
            {
                if (arr[0] + arr[1] > arr[1] + arr[2])
                    ans = arr[0] + arr[1];
                else
                    ans = arr[1] + arr[2];
            }
            max_ans = ans > max_ans ? ans : max_ans;
        }
    }
    printf("%d\n", max_ans);
    return 0;
}



