#include<iostream>
#include<algorithm>
using namespace std;

struct point
{
    char ss;
    int x, y;
};

struct direction
{
    char ul, ur, lr, ll;
};

direction dir[100];
point p[30];
int sum;

int cmp(point a, point b)
{
    if (a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}

int cmp_re(direction a, direction b)
{
    if (a.ul != b.ul)
        return a.ul < b.ul;
    else
    {
        if (a.ur != b.ur)
            return a.ur < b.ur;
        else
        {
            if (a.lr != b.lr)
                return a.lr < b.lr;
            else
                return a.ll < b.ll;
        }
    }
}

bool work(int n)
{
    int i, j, k, l;
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (p[i].x == p[j].x)
            {
                for (k = j + 1; k < n; ++k)
                {
                    if (p[i].y == p[k].y)
                    {
                        for (l = k + 1; l < n; ++l)
                        {
                            if (p[j].y - p[i].y == p[l].y - p[k].y

                            && p[k].x - p[i].x == p[l].x - p[j].x)
                            {
                                dir[sum].ul = p[j].ss, dir

                                [sum].ur = p[l].ss;
                                dir[sum].lr = p[k].ss, dir

                                [sum].ll = p[i].ss;
                                sum++;
                            }
                        }
                    }
                }
            }
        }
    }
    if (!sum)
        return false;
    else
        return true;
}

int main()
{
    int i, n, cas = 1;
    while (cin >> n && n)
    {
        for (i = 0; i < n; ++i)
            cin >> p[i].ss >> p[i].x >> p[i].y;
        sort(p, p + n, cmp);
        sum = 0;
        cout << "Point set " << cas++ << ":";
        if (!work(n))
            cout << " No rectangles" << endl;
        else
        {

            cout << endl;
            sort(dir, dir + sum, cmp_re);
            for (i = 0; i < sum; ++i)
            {
                cout << " " << dir[i].ul << dir[i].ur << dir[i].lr << dir[i].ll;
                if ((i + 1) % 10 == 0 && i + 1 < sum)
                    cout << endl;
            }
            cout << endl;
        }
    }
    return 0;
}


