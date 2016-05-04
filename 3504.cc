#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int N = 10055;
const int S = 1024;
const int SD = 129;
const int M = 1046527;
const int K = 27;

int hk1[K], hk2[K], hk3[K];
void hash_init() {
  srand(K);
  for (int i = 0; i < K; i++)
    hk1[i] = rand() % M, hk2[i] = rand() % M, hk3[i] = rand() % M;
}

int hasha(char *s) {
  int ret = 0;
  for (int i = 0; s[i]; i++) {
    int no = s[i] - 'a' + 1;
    ret += no * hk1[no] % M;
    if (ret > M) ret %= M;
    if (ret < 0) ret += M;
  }
  return ret;
}

int hashb(char *s) {
  int ret = 0;
  for (int i = 0; s[i]; i++) {
    int no = s[i] - 'a' + 1;
    ret += no * hk2[no] % M;
    if (ret > M) ret %= M;
    if (ret < 0) ret += M;
  }
  return ret;
}

int hashc(char *s) {
  int ret = 0;
  for (int i = 0; s[i]; i++) {
    int no = s[i] - 'a' + 1;
    ret += no * hk3[no] % M;
    if (ret > M) ret %= M;
    if (ret < 0) ret += M;
  }
  return ret;
}

struct HashTable {
  struct HashNode {
    int hb, hc;
    char st, ed;
    int cnt;
    int id;
    HashNode *nxt;
  } node[M], *cur, *pos[M];

  void init() {
    memset(pos, 0, sizeof(pos));
    cur = node;
  }

  void insert(char *s, int idx) {
    int ha = hasha(s), hb = hashb(s), hc = hashc(s);
    char st = s[0], ed = s[strlen(s) - 1];
    for (HashNode *i = pos[ha]; i; i = i->nxt) {
      if (i->hb == hb && i->hc == hc && i->st == st && i->ed == ed) {
        i->cnt++;
        return;
      }
    }
    cur->hb = hb;
    cur->hc = hc;
    cur->nxt = pos[ha];
    cur->cnt = 1;
    cur->id = idx;
    cur->st = st, cur->ed = ed;
    pos[ha] = cur++;
  }

  int search(int ha, int hb, int hc, char st, char ed) {
    for (HashNode *i = pos[ha]; i; i = i->nxt)
      if (i->hb == hb && i->hc == hc && i->st == st && i->ed == ed)
        return i->cnt;
    return 0;
  }

  int get(int ha, int hb, int hc, char st, char ed) {
    for (HashNode *i = pos[ha]; i; i = i->nxt)
      if (i->hb == hb && i->hc == hc && i->st == st && i->ed == ed)
        return i->id;
    return -1;
  }
} hash_table;

char str[S];
char word[N][SD];
int dp[N];
int pre[N];

int main() {
  int n, dic;
  hash_init();
  for (scanf("%d", &n); n; n--) {
    scanf("%s", str + 1);
    scanf("%d", &dic);
    hash_table.init();
    memset(dp, 0, sizeof(dp));
    pre[1] = 0;
    for (int i = 0; i < dic; i++) {
      scanf("%s", word[i]);
      hash_table.insert(word[i], i);
    }

    dp[0] = 1;
    int i, j;
    for (i = 1; str[i]; i++) {
      j = i;
      int ta = 0, tb = 0, tc = 0;
      while (j) {
        int no = (int)(str[j] - 'a' + 1);
        ta += no * hk1[no] % M, tb += no * hk2[no] % M, tc += no * hk3[no] % M;
        if (ta > M) ta -= M;
        if (ta < 0) ta += M;
        if (tb > M) tb -= M;
        if (tb < 0) tb += M;
        if (tc > M) tc -= M;
        if (tc < 0) tc += M;
        if (dp[j - 1]) {
          int wcnt = hash_table.search(ta, tb, tc, str[j], str[i]);
          if (wcnt) {
            dp[i]++;
            if (dp[j - 1] > 1 || wcnt > 1) dp[i]++;
            pre[i] = j - 1;
          }
        }
        if (dp[i] > 1) break;
        j--;
      }
    }
    if (dp[i - 1] == 0)
      puts("impossible");
    else if (dp[i - 1] > 1)
      puts("ambiguous");
    else {
      stack<int> ans;
      int x = i - 1, y;
      while (x) {
        y = pre[x];
        int ta = 0, tb = 0, tc = 0;
        for (int i = y + 1; i <= x; i++) {
          int no = (int)(str[i] - 'a' + 1);
          ta += no * hk1[no] % M, tb += no * hk2[no] % M,
              tc += no * hk3[no] % M;
          if (ta > M) ta -= M;
          if (ta < 0) ta += M;
          if (tb > M) tb -= M;
          if (tb < 0) tb += M;
          if (tc > M) tc -= M;
          if (tc < 0) tc += M;
        }
        ans.push(hash_table.get(ta, tb, tc, str[y + 1], str[x]));
        x = y;
      }
      int tp = 0;
      while (!ans.empty()) {
        int id = ans.top();
        ans.pop();
        if (tp++) putchar(' ');
        printf("%s", word[id]);
      }
      putchar('\n');
    }
  }
  return 0;
}
