#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <queue>
#include <ctime>
using namespace std;
template <class T>
void checkmin(T &t, T x) {
  if (x < t) t = x;
}
template <class T>
void checkmax(T &t, T x) {
  if (x > t) t = x;
}
template <class T>
void _checkmin(T &t, T x) {
  if (t == -1) t = x;
  if (x < t) t = x;
}
template <class T>
void _checkmax(T &t, T x) {
  if (t == -1) t = x;
  if (x > t) t = x;
}
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
typedef long long lld;
#define foreach \
  (it, v) for (__typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define DEBUG(a) cout << #a " = " << (a) << endl;
#define DEBUGARR(a, n)                               \
  for (int i = 0; i < (n); i++) {                    \
    cout << #a "[" << i << "] = " << (a)[i] << endl; \
  }
const int N = 10;
int n;
char buf[10000], ss[10000];
string Name[N];
map<string, int> ref;
vector<PII> vec[N];
map<int, int> Max[N];
map<int, int> Min[N];

int f[105][105];
int g[105][105];

void dp(int st) {
  reverse(vec[st].begin(), vec[st].end());
  memset(f, 0xFF, sizeof(f));
  f[0][0] = 1;
  for (int i = 0; i < vec[st].size(); i++) {
    for (int j = 0; j <= 100; j++) {
      if (f[i][j] != -1) {
        if (vec[st][i].second != -1) {
          if (f[i][j] > vec[st][i].second) continue;
          if (j + vec[st][i].second <= 100) {
            _checkmin(f[i + 1][j + vec[st][i].second], vec[st][i].second);
          }
        } else {
          for (int k = f[i][j]; j + k <= 100; k++) {
            _checkmin(f[i + 1][j + k], k);
          }
        }
      }
    }
  }
  memset(g, 0xFF, sizeof(g));
  g[vec[st].size()][0] = 100;
  for (int i = vec[st].size(); i >= 1; i--) {
    for (int j = 0; j <= 100; j++) {
      if (g[i][j] != -1) {
        if (vec[st][i - 1].second != -1) {
          if (g[i][j] < vec[st][i - 1].second) continue;
          if (j + vec[st][i - 1].second <= 100) {
            _checkmax(g[i - 1][j + vec[st][i - 1].second],
                      vec[st][i - 1].second);
          }
        } else {
          for (int k = 1; k <= g[i][j] && j + k <= 100; k++) {
            _checkmax(g[i - 1][j + k], k);
          }
        }
      }
    }
  }
  Max[st].clear();
  Min[st].clear();
  for (int i = 0; i < vec[st].size(); i++) {
    int &Ma = Max[st][vec[st][i].first];
    int &Mi = Min[st][vec[st][i].first];
    Ma = -1;
    Mi = -1;
    if (vec[st][i].second != -1) {
      Ma = Mi = vec[st][i].second;
      continue;
    }
    for (int j = 0; j <= 100; j++) {
      for (int k = 0; j + k <= 100; k++) {
        if (f[i][k] != -1 && g[i + 1][100 - j - k] != -1 && f[i][k] <= j &&
            g[i + 1][100 - j - k] >= j) {
          _checkmin(Mi, j);
          _checkmax(Ma, j);
        }
      }
    }
  }
  /*
  DEBUG(st);
  foreach (it, Max[st]) {
          printf("Max %d %d\n", it->first, it->second);
  }
  foreach (it, Min[st]) {
          printf("Min %d %d\n", it->first, it->second);
  }
  */
}

int main() {
#ifdef cwj
  freopen("in", "r", stdin);
#endif
  while (scanf("%d", &n) != EOF && n) {
    ref.clear();
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      vec[i].clear();
      Name[i] = string(buf);
      int m;
      scanf("%d", &m);
      gets(buf);
      for (int j = 0; j < m; j++) {
        gets(buf);
        int x, id;
        if (strchr(buf, ' ') != NULL) {
          sscanf(buf, "%s %d", ss, &x);
          if (ref.count(ss)) {
            id = ref[ss];
          } else {
            id = ref[ss] = ref.size() - 1;
          }
        } else {
          if (ref.count(buf)) {
            id = ref[buf];
          } else {
            id = ref[buf] = ref.size() - 1;
          }
          x = -1;
        }
        //				DEBUG(id);
        //				DEBUG(x);
        if (x) {
          vec[i].push_back(make_pair(id, x));
        }
      }
      dp(i);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
      scanf("%s", buf);
      if (strcmp(buf, "most") == 0) {
        scanf("%s", buf);
        vector<int> ans;
        int id = ref[buf];
        for (int j = 0; j < n; j++) {
          int w = Max[j].count(id) ? Max[j][id] : 0;
          bool ok = 1;
          for (int k = 0; k < n; k++) {
            int _w = Min[k].count(id) ? Min[k][id] : 0;
            if (_w > w) {
              ok = 0;
              break;
            }
          }
          if (ok) ans.push_back(j);
        }
        foreach (it, ans) {
          if (it != ans.begin()) printf(" ");
          printf("%s", Name[*it].c_str());
        }
        puts("");
      } else {
        scanf("%s", buf);
        vector<int> ans;
        if (!ref.count(buf)) {
          for (int i = 0; i < n; i++) {
            printf("%s%c", Name[i].c_str(), i + 1 == n ? '\n' : ' ');
          }
          continue;
        }
        int id = ref[buf];
        for (int j = 0; j < n; j++) {
          int w = Min[j].count(id) ? Min[j][id] : 0;
          bool ok = 1;
          for (int k = 0; k < n; k++) {
            int _w = Max[k].count(id) ? Max[k][id] : 0;
            if (_w < w) {
              ok = 0;
              break;
            }
          }
          if (ok) ans.push_back(j);
        }
        foreach (it, ans) {
          if (it != ans.begin()) printf(" ");
          printf("%s", Name[*it].c_str());
        }
        puts("");
      }
    }
  }
}
