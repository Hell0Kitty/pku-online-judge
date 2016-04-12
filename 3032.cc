#include <iostream>
#include <vector>
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
#include <bitset>
#include <map>
#include <set>
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

int per[14];

int main() {
#ifdef HOMEPC
  freopen("NCPC06.in", "r", stdin);
#endif

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    Set(per, 0);

    if (n == 1) {
      cout << 1 << endl;
      continue;
    }
    if (n == 2) {
      cout << "2 1" << endl;
      continue;
    }

    per[2] = 1;
    int prev_pos = 2;
    For(i, 2, n + 1) {
      int cnt = 0;
      For(j, prev_pos + 1, n + 1) {
        if (!per[j]) cnt++;
        if (!per[j] && cnt == i + 1) {
          prev_pos = j;
          per[j] = i;
          break;
        }
        if (j == n) j = 0;
      }
      if (prev_pos == n) prev_pos = 0;
    }
    PF("%d", per[1]);
    For(i, 2, n + 1) PF(" %d", per[i]);
    PF("\n");
  }
  return 0;
}
