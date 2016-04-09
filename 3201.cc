#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int SIZE = 50;
const int MAX = 200;
const int LEN = 5000;

struct QUILT
{
    char effect[2][5];
}quilt[6];

struct NODE
{
    int map[SIZE][SIZE];
    int ht, wt;
}node[MAX];

char exp[LEN];
int gLen, gPos, temp[SIZE][SIZE], start;
bool mark;

void Init()
{
    strcpy(quilt[0].effect[0],"//");
    strcpy(quilt[0].effect[1],"/+");
    strcpy(quilt[1].effect[0],"\\\\");
    strcpy(quilt[1].effect[1],"+\\");
    strcpy(quilt[2].effect[0],"+/");
    strcpy(quilt[2].effect[1],"//");
    strcpy(quilt[3].effect[0],"\\+");
    strcpy(quilt[3].effect[1],"\\\\");
    strcpy(quilt[4].effect[0],"--");
    strcpy(quilt[4].effect[1],"--");
    strcpy(quilt[5].effect[0],"||");
    strcpy(quilt[5].effect[1],"||");

    gLen = gPos = 0;
}

bool Is(char ch)
{
    if ( ch == ';' || ch == ',' || ch == '(' || ch == ')' 
        || isalpha(ch) )
        return true;
    return false;
}

inline int GetValue(const int& s)
{
    switch(s)
    {
    case 0:
        return 1;
    case 1:
        return 2;
    case 2:
        return 3;
    case 3:
       return 0;
    case 4:
        return 5;
    case 5:
        return 4;
    }

    return -1;
}

void Turn(const int& p)
{
    int i, j, k, l, t;

    for ( i = 0, k = node[p].ht - 1; i < node[p].ht; ++i, --k )
        for ( j = 0, l = 0; j < node[p].wt; ++j, ++l )
        {
            temp[j][i] = GetValue( node[p].map[k][l] );
        }

    t = node[p].ht; node[p].ht = node[p].wt; node[p].wt = t;

    for ( i = 0; i < node[p].ht; ++i )
        for ( j = 0; j < node[p].wt; ++j )
            node[p].map[i][j] = temp[i][j];
}

bool Sew(const int& a, const int& b)
{
    if ( node[a].ht != node[b].ht )
    {
        mark = true;
        return false;
    }

    int i, j, k;

    for ( i = 0; i < node[a].ht; ++i )
        for ( j = node[a].wt, k = 0; k < node[b].wt; ++j, ++k )
            node[a].map[i][j] = node[b].map[i][k];

    node[a].wt += node[b].wt;

    return true;
}

int Solve()
{
    if ( mark )
        return -1;
    int a = 0, b;

    if ( exp[start] == 's' )
    {
        start += 4;
        a = Solve();
        start++;

        if ( a == -1 )
            return -1;

        b = Solve();

        if ( b == -1 )
            return -1;

        if ( !Sew( a, b ) )
            a = -1;
        start++;
    }
    else if ( exp[start] == 't' )
    {
        start += 5;
        a = Solve();
        start++;
        if ( a == -1 )
            return -1;
        Turn( a );
    }
    else if ( exp[start] == 'A' || exp[start] == 'B' )
    {
        a = gPos;
        node[gPos].wt = node[gPos].ht = 1;

        if ( exp[start] == 'B' )
            node[gPos].map[0][0] = 4;
        else 
            node[gPos].map[0][0] = 0;
        gPos++;
        start++;
    }

    return a;
}

void Output( const int& p )
{
    int i, j, k;

    for ( i = 0; i < node[p].ht; ++i )
    {
        for ( k = 0; k < 2; ++k )
        {
            for ( j = 0; j < node[p].wt; ++j )
            {
                for ( int l = 0; l < 2; ++l )
                    printf("%c", quilt[node[p].map[i][j]].effect[k][l]);
            }
            printf("\n");
        }
    }
}

int main()
{

    Init();

    char ch;
    int p, t = 1;
    gLen = gPos = 0;
    mark = false;

    while ( cin >> ch )
    {        
        if ( Is(ch) )
       {
            if ( ch == ';' )
            {
                exp[gLen++] = ch;

                printf("Quilt %d:\n", t);

                start = 0;
                p = Solve();

                if ( p == -1 || mark ) {
                    printf("error\n");
                }
                else {
                    Output(p);
                }
                t++;
                gLen = gPos = 0;
                mark = false;
            }
            else
                exp[gLen++] = ch;
        }
    }

    return 0;
}



