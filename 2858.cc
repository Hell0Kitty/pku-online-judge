#include <stdio.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <math.h>
#include <algorithm>
#include <map>
#include <string.h>

using namespace std;

typedef long long LL;
typedef pair<int, int>PII;
typedef pair<PII, int>PII2;

string s;
set<string>S;
int n;

char c[20];
int v[20];

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++ )
    {
        cin >> s;
        sort(s.begin(), s.end());
        S.insert(s);
    }

    int m;
    scanf("%d", &m);
    for(int mm = 0; mm < m; mm ++ )
    {
        int num;
        scanf("%d", &num);
        for(int i = 0; i < num; i++ )
        {
            scanf(" %c %d", &c[i], &v[i]);
        }

        int maxv = 0;
        for(int i = 0; i < (1<<num); i++ )
        {
            string s = "";
            int cval = 0;
            for(int j = 0; j < num; j++ )
            {
                if(i & (1<<j))
                {
                    cval += v[j];
                    s += c[j];
                }
            }
            sort(s.begin(), s.end());
            if(S.count(s) && cval > maxv)
            {
                maxv = cval;
            }
        }

        printf("%d\n", maxv);
    }

return 0;
}



