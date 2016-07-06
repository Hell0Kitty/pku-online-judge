#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <stack>
#include <set>
#include <cstdlib>
#include <vector>
#include <time.h>

using namespace std;
const int maxn = 100;
int dp[maxn][maxn];
int last1[maxn][27], last2[maxn][27];
set <string> ans;
char tmp[maxn];
void dfs(int s1, int s2, int len)
{
    if (len <= 0)
    {
        ans.insert(tmp);
        return ;
    }
    if (s1 > 0 && s2 > 0)
    {
        for (int i = 0; i < 26; ++i)
        {
            int t1 = last1[s1][i];
            int t2 = last2[s2][i];
            if (dp[t1][t2] == len)
            {
                tmp[len - 1] = 'a' + i;
                dfs(t1 - 1, t2 - 1, len - 1);
            }
        }
    }
    return ;
}
void LCS(string s1, string s2)
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= s1.size(); ++i)
    {
        for (int j = 1; j <= s2.size(); ++j)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
}
void solve(string s1, string s2)
{
    memset(last1, 0, sizeof(last1));
    memset(last2, 0, sizeof(last2));
    for (int i = 1; i <= s1.size(); ++i)
    {
        for (int j = 0; j < 26; ++j)
            last1[i][j] = last1[i - 1][j];
        last1[i][s1[i - 1] - 'a'] = i;
    }
    for (int i = 1; i <= s2.size(); ++i)
    {
        for (int j = 0; j < 26; ++j)
            last2[i][j] = last2[i - 1][j];
        last2[i][s2[i - 1] - 'a'] = i;
    }
    tmp[dp[s1.size()][s2.size()]] = '\0';
    dfs(s1.size(), s2.size(), dp[s1.size()][s2.size()]);
    for (set <string> :: iterator it = ans.begin(); it != ans.end(); ++it)
        cout <<*it<<endl;
}
int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        LCS(s1, s2);
        solve(s1, s2);
    }
    return 0;
}



