#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const    int        maxv = 110;

struct edge
{
    int        w, v1, v2;
    edge(int ww, int vv1, int vv2):w(ww), v1(vv1), v2(vv2){}
    edge(){}
}edges[maxv * maxv], bestedge[maxv];

int        n, namecount, father[maxv], areacount, best[maxv], limit, answer, fans;
string    names[maxv];
bool    used[maxv][maxv];
vector<vector<edge>>map(maxv);

int getid(string name)
{
    int        i;

    for (i = 0; i < namecount; i++)
        if (name == names[i])
            return i;
    names[namecount++] = name;
    return namecount - 1;
}

void init()
{
    int        i, length, n1, n2;
    string    name1, name2;

    memset(used, 0, sizeof(used));
    scanf("%d", &n);
    namecount = 1;
    answer = 0;
    areacount = 0;
    names[0] = "Park";
    for (i = 0; i < n; i++)
    {
        getchar();
        cin >> name1;
        cin >> name2;
        cin >> length;
        n1 = getid(name1);
        n2 = getid(name2);
        map[n1].push_back(edge(length, n2, -1));
        map[n2].push_back(edge(length, n1, -1));
        edges[i].v1 = n1;
        edges[i].v2 = n2;
        edges[i].w = length;
    }
    scanf("%d", &limit);
}

bool operator< (edge a, edge b)
{
    return a.w < b.w;
}

int getanc(int a)
{
    if (father[a] != a)
        return father[a] = getanc(father[a]);
    return a;
}

void makeareas()
{
    int        i, n1, n2;

    for (i = 0; i < namecount; i++)
        father[i] = i;
    sort(edges, edges + n);
    for (i = 0; i < n; i++)
    {
        if (edges[i].v1 == 0 || edges[i].v2 == 0)
            continue;
        n1 = getanc(edges[i].v1);
        n2 = getanc(edges[i].v2);
        if (n1 == n2)
            continue;
        father[n1] = n2;
        used[edges[i].v1][edges[i].v2] = true;
        used[edges[i].v2][edges[i].v1] = true;
    }
    for (i = 1; i < namecount; i++)
        if (father[i] == i)
            areacount++;
}

void maketree()
{
    int        vdist[maxv], n1, i, vconect[maxv];

    memset(vconect, -1, sizeof(vconect));
    for (i = 0; i < map[0].size(); i++)
    {
        n1 = getanc(map[0][i].v1);
        if (vconect[n1] == -1 || vdist[n1] > map[0][i].w)
        {
            vconect[n1] = map[0][i].v1;
            vdist[n1] = map[0][i].w;
        }
    }
    for (i = 1; i < namecount; i++)
    {
        if (father[i] != i)
            continue;
        used[vconect[i]][0] = true;
        used[0][vconect[i]] = true;
    }
}

void calculate()
{
    int        i;

    for (i = 0; i < n; i++)
        if (used[edges[i].v1][edges[i].v2])
            answer += edges[i].w;
    fans = answer;
}

void dp()
{
    int        i, l, vused[maxv];

    queue<int> q;
    memset(father, -1, sizeof(father));
    memset(vused, 0, sizeof(vused));
    memset(best, 0, sizeof(best));
    memset(bestedge, 0, sizeof(bestedge));
    vused[0] = true;
    for (i = 0; i < map[0].size(); i++)
        if (used[0][map[0][i].v1])
        {
            q.push(map[0][i].v1);
            father[map[0][i].v1] = 0;
            vused[map[0][i].v1] = true;
        }
    while (!q.empty())
    {
        l = q.front();
        for (i = 0; i < map[l].size(); i++)
            if (!vused[map[l][i].v1] && used[l][map[l][i].v1])
            {
                vused[map[l][i].v1] = true;
                q.push(map[l][i].v1);
                if (best[l] > map[l][i].w)
                {
                    best[map[l][i].v1] = best[l];
                    bestedge[map[l][i].v1] = bestedge[l];
                }
                else
                {
                    best[map[l][i].v1] = map[l][i].w;
                    bestedge[map[l][i].v1] = map[l][i];
                    bestedge[map[l][i].v1].v2 = l;
                }
            }
        q.pop();
    }
}

void up1()
{
    int        dis = 1000000000, besti, i;

    for (i = 0; i < map[0].size(); i++)
        if (!used[0][map[0][i].v1] && dis > map[0][i].w - best[map[0][i].v1])
        {
            dis = map[0][i].w - best[map[0][i].v1];
            besti = map[0][i].v1;
        }
    used[0][besti] = true;
    used[besti][0] = true;
    answer += dis;
    if (answer < fans)
        fans = answer;
    used[bestedge[besti].v1][bestedge[besti].v2] = false;
    used[bestedge[besti].v2][bestedge[besti].v1] = false;
}

int main()
{
    int  i;

    init();
    makeareas();
    maketree();
    calculate();
    for (i = areacount; i < limit; i++)
    {
        dp();
        up1();
    }
    printf("Total miles driven: %d\n", fans);
    return 0;
}



