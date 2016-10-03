#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#define N 100005
using namespace std;

vector<long long> gra[N];
map<string, long long> hash;
string nam;
char str[1000 * 2000 + 5];
long long s, f, vis[N], id;
struct Dp {
  long long ns, nf;
} dp[N][2];

void dfs(long long r) {
  vis[r] = 1;
  Dp temp;
  dp[r][1].nf = 1;
  for (long long i = 0; i < gra[r].size(); i++) {
    long long t = gra[r][i];
    dfs(t);
    long long a = s * dp[t][0].ns + f * dp[t][0].nf;
    long long b = s * dp[t][1].ns + f * dp[t][1].nf;
    if (a > b || (a == b && dp[t][1].nf > dp[t][0].nf)) {
      dp[r][1].ns += dp[t][1].ns;
      dp[r][1].nf += dp[t][1].nf;
    } else {
      dp[r][1].ns += dp[t][0].ns;
      dp[r][1].nf += dp[t][0].nf;
    }
    dp[r][0].ns += dp[t][1].ns;
    dp[r][0].nf += dp[t][1].nf;
  }
  long long a = s * dp[r][0].ns + s + f * dp[r][0].nf;
  long long b = s * dp[r][1].ns + f * dp[r][1].nf;
  if (a < b || (a == b && dp[r][0].nf > dp[r][1].nf)) {
    dp[r][1].ns = dp[r][0].ns + 1;
    dp[r][1].nf = dp[r][0].nf;
  }
}

void run(long long h) {
  Dp ans;
  ans.nf = ans.ns = 0;
  for (long long i = 1; i < id; i++)
    if (vis[i] == 0) {
      dfs(i);
      ans.nf += dp[i][1].nf;
      ans.ns += dp[i][1].ns;
    }
  printf("%lld. %lld %lld %lld\n", h, ans.ns, ans.nf, s * ans.ns + f * ans.nf);
}

int main() {
  gets(str);
  for (long long h = 1;; h++) {
    sscanf(str, "%lld%lld", &s, &f);
    if (s == 0 & f == 0) break;
    id = 1;
    for (long long i = 0; i < N; i++) gra[i].clear();
    hash.clear();
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    while (1) {
      gets(str);
      if (str[0] >= '0' && str[0] <= '9') break;
      if (!(str[0] >= 'a' && str[0] <= 'z')) continue;
      long long flag = 0, k = 0, len = strlen(str), fa;
      char temp[1005];
      for (long long i = 0; i <= len; i++) {
        if (i == len || str[i] == ' ') {
          temp[k] = 0;
          k = 0;
          nam = temp;
          if (hash.count(nam) == 0) hash[nam] = id++;
          if (flag == 0)
            flag = 1, fa = hash[nam];
          else
            gra[fa].push_back(hash[nam]), vis[hash[nam]] = 1;
          continue;
        }
        temp[k++] = str[i];
      }
    }
    run(h);
  }
}
