#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <algorithm>
#include <list>
#include <cstdio>
#include <stack>
#include <cstring>
#include <climits>
#include <cmath>
#include <string>
#include <functional>
#include <sstream>
#include <map>
using namespace std;
#define For(i, a, b) for (int i = a; i < b; i++)
#define Rep(i, a) for (int i = 0; i < a; i++)
#define ALL(v) (v).begin(), (v).end()
#define Set(a, x) memset((a), (x), sizeof(a))
#define EXIST(a, b) find(ALL(a), (b)) != (a).end()
#define Sort(x) sort(ALL(x))
#define GSORT(x) sort(ALL(x), greater<typeof(*((x).begin()))>())
#define UNIQUE(v) \
  Sort(v);        \
  (v).resize(unique(ALL(v)) - (v).begin())
#define MP make_pair
#define SF scanf
#define PF printf
#define MAXN 1001
#define MAXM 1001
#define MOD 1000000007
#define Dbug cout << "";
#define EPS 1e-15
typedef long long ll;
typedef pair<int, int> pii;
int n, in[MAXN];
string name[MAXN];
map<string, int> mp;
vector<pii> vec;
bool del[MAXN], play[MAXN];
string a, b;
int main() {
  // ios_base::sync_with_stdio(false);
  // freopen("a.in","r",stdin);
  while (cin >> n) {
    Set(del, 0);
    vec.clear();
    Set(in, 0);
    mp.clear();
    Rep(i, n) {
      cin >> name[i];
      mp[name[i]] = i;
    }
    Rep(i, n - 1) {
      cin >> a >> b;
      int u = mp[a], v = mp[b];
      in[u]++, in[v]++;
      vec.push_back(MP(u, v));
    }
    int tn = 1;
    int cnt = n;
    while (cnt > 1) {
      Set(play, 0);
      PF("Round #%d\n", tn++);
      int num = cnt;
      if (cnt & 1) num--;
      Rep(i,
          vec.size()) if (del[vec[i].first] == 0 && del[vec[i].second] == 0 &&
                          play[vec[i].first] == 0 && play[vec[i].second] == 0) {
        if (in[vec[i].first] >= 1 && in[vec[i].second] == 1) {
          in[vec[i].first]--;
          in[vec[i].second]--;
          play[vec[i].first] = play[vec[i].second] = 1;
          num--;
          del[vec[i].second] = 1;
          cout << name[vec[i].first] << " defeats " << name[vec[i].second]
               << endl;
        } else if (in[vec[i].first] == 1 && in[vec[i].second] >= 1) {
          in[vec[i].first]--;
          in[vec[i].second]--;
          play[vec[i].first] = play[vec[i].second] = 1;
          num--;
          del[vec[i].first] = 1;
          cout << name[vec[i].second] << " defeats " << name[vec[i].first]
               << endl;
        }
      }
      vector<int> z;
      Rep(i, n) if (del[i] == 0 && in[i] == 0 && play[i] == 0) z.push_back(i);
      if (z.size()) Rep(i, n) if (del[i] == 0 && in[i] > 0 && play[i] == 0) {
          int h = z[z.size() - 1];
          z.pop_back();
          play[h] = play[i] = 1;
          num--;
          del[h] = 1;
          cout << name[i] << " defeats " << name[h] << endl;
        }
      if (z.size()) {
        Rep(i, z.size()) {
          if (i + 1 >= z.size()) break;
          play[z[i + 1]] = play[z[i]] = 1;
          del[z[i + 1]] = 1;
          cout << name[z[i]] << " defeats " << name[z[i + 1]] << endl;
        }
      }
      Rep(i, n) if (del[i] == 0 && play[i] == 0) cout
          << name[i] << " advances with wildcard\n";
      cnt = (cnt + 1) / 2;
    }
    Rep(i, n) if (del[i] == 0) cout << "Winner: " << name[i] << endl
                                    << endl;
  }
  return 0;
}
