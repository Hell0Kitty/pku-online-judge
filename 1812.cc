#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
char table[50],hand[10];
bool use[10];
int minres;

void DFS(int totuse,char *nowtable,int use)
{
    if (strlen(nowtable) == 0)
    {
        if (totuse < minres)    minres = totuse;
        return;
    }
    if (totuse >= minres)   return;
    char newtable[50];
    int nowlen = strlen(nowtable);
    for (int i = 0;i < m;i++)
    if (((use>>i)&1) == 0)
    {
        for (int j = 1;j < nowlen;j++)
        if (nowtable[j-1] == hand[i] && nowtable[j] == hand[i])
        {
            int len = 0;
            for (int k = 0;k < j;k++)
            {
                newtable[len] = nowtable[k];
                len++;
            }
            newtable[len] = hand[i];
            len++;
            for (int k = j;k < nowlen;k++)
            {
                newtable[len] = nowtable[k];
                len++;
            }
            newtable[len] = 0;
            while (true)
            {
                bool cando = false;

                for (int k = 0;k <= len-3;k++)
                    if (newtable[k] != '*')
                        for (int q = 1;k+q-1 <= len;q++)
                            if (newtable[k+q-1] != newtable[k])
                            {
                                if (q > 3)
                                {

                                    for (int p = 1;p < q;p++)
                                        newtable[k+p-1] = '*';
                                    cando = true;
                                }
                                break;
                            }
                if (cando == false) break;
                int tlen = len;
                len = 0;

                for (int k = 0;k < tlen;k++)
                    if (newtable[k] != '*')
                    {
                        newtable[len] = newtable[k];
                        len++;
                    }
                newtable[len] = 0;
            }

            DFS(totuse+1,newtable,use|(1<<i));
        }
        int nexti = m;
        for (int j = 0;j < m;j++)
        if (((use>>j)&1) == 0 && hand[j] == hand[i] && i != j)
            nexti = j;
        if (nexti < m)
        {
            for (int j = 0;j < nowlen;j++)
            if (nowtable[j] == hand[i])
            {
                int len = 0;
                for (int k = 0;k < j;k++)
                {
                    newtable[len] = nowtable[k];
                    len++;
                }
                newtable[len] = hand[i];
                len++;
                newtable[len] = hand[nexti];
                len++;
                for (int k = j;k < nowlen;k++)
                {
                    newtable[len] = nowtable[k];
                    len++;
                }
                newtable[len] = 0;
                while (true)
                {
                    bool cando = false;

                    for (int k = 0;k <= len-3;k++)
                        if (newtable[k] != '*')
                            for (int q = 1;k+q-1 <= len;q++)
                                if (newtable[k+q-1] != newtable[k])
                                {
                                    if (q > 3)
                                    {

                                        for (int p = 1;p < q;p++)
                                            newtable[k+p-1] = '*';
                                        cando = true;
                                    }
                                    break;
                                }
                    if (cando == false) break;
                    int tlen = len;
                    len = 0;

                    for (int k = 0;k < tlen;k++)
                        if (newtable[k] != '*')
                        {
                            newtable[len] = newtable[k];
                            len++;
                        }
                    newtable[len] = 0;
                }

                DFS(totuse+2,newtable,use|(1<<i)|(1<<nexti));
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    for (int ft = 1;ft <= t;ft++)
    {
        scanf("%d%d",&n,&m);
        scanf("%s",table);
        int len = strlen(table);
                while (true)
                {
                    bool cando = false;
                    for (int k = 0;k <= len-3;k++)
                        if (table[k] != '*')
                            for (int q = 1;k+q-1 <= len;q++)
                                if (table[k+q-1] != table[k])
                                {
                                    if (q > 3)
                                    {
                                            for (int p = 1;p < q;p++)
                                            table[k+p-1] = '*';
                                        cando = true;
                                    }
                                    break;
                                }
                    if (cando == false) break;
                    int tlen = len;
                    len = 0;

                    for (int k = 0;k < tlen;k++)
                        if (table[k] != '*')
                        {
                            table[len] = table[k];
                            len++;
                        }
                    table[len] = 0;
                }
        scanf("%s",hand);
        memset(use,false,sizeof(use));
        minres = m+1;
        DFS(0,table,0);
        if (minres == m+1)
            printf("lose\n");
        else printf("%d\n",minres);
    }
}



