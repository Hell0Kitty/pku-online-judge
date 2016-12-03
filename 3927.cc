#include <algorithm>
#include <iostream>
#include <cstdio>

#define MAXCPN 100000

using namespace std;

struct Wed {  // wedding，婚礼

  int s, t;
  int as, at;

  void init(void) {
    scanf("%d%d", &s, &t);

    if ((t - s) % 2) {
      as = s + ((t - s - 1) >> 1);
      at = as + 1;
    } else {
      as = s + ((t - s) >> 1) - 1;
      at = as + 2;
    }
  }

  int mintv(void) { return (t - s + 2) >> 1; }

  bool operator<(const Wed &oth) const {
    return as < oth.as || (as == oth.as && at < oth.at);
  }
};

Wed w[MAXCPN];

bool can_hold_all(int n) {
  int cur_s, cur_t;
  int prv_t;

  int i;

  prv_t = (*w).mintv();
  for (i = 1; i < n; i++) {
    cur_s = w[i].s;
    if (cur_s < prv_t) cur_s = prv_t;

    cur_t = cur_s + w[i].mintv();
    if (cur_t > w[i].t) return false;

    prv_t = cur_t;
  }

  return true;
}

int main() {
  int n;
  int i;

  while (scanf("%d", &n), n) {
    for (i = 0; i < n; i++) w[i].init();
    sort(w, w + n);

    if (can_hold_all(n))
      puts("YES");
    else
      puts("NO");
  }

  return 0;
}
