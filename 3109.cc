
#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#define N 100005
typedef long long LL;
#define fi first
#define se second
using namespace std;
int n , m;
pair<int , int> a[N];
int top[N] , bot[N] , d[N] , c[N];
struct opt
{
  int p , x;
  bool f;
  bool operator < (const opt& r) const {
    if (x == r.x)
      return f > r.f;
    return x < r.x;
  }
}t[N << 1];

void add(int x , int w)
{
  for (int i = x ; i <= m ; i += i & -i)
    c[i] += w;
}
int sum(int x)
{
  int _s = 0;
  for (int i = x ; i ; i &= i - 1)
    _s += c[i];
  return _s;
}

void work()
{
  int i , j , x , y;
  scanf("%d",&n);
  for (i = 1 ; i <= n ; ++ i)
    scanf("%d%d",&a[i].fi , &a[i].se) , d[i] = a[i].se;
  sort(a + 1 , a + 1 + n) , sort(d + 1 , d + 1 + n);
  m = unique(d + 1 , d + 1 + n) - d - 1;
  for (i = 1 ; i <= n ; ++ i)
    a[i].se = lower_bound(d + 1 , d + 1 + m , a[i].se) - d;
  for (i = 1 ; i <= m ; ++ i) top[i] = 1 << 30;
  for (i = 1 ; i <= n ; ++ i)
  {
    if (top[a[i].se] == 1 << 30)
      top[a[i].se] = a[i].fi;
    bot[a[i].se] = a[i].fi;
  }
  for (i = 1 ; i <= m ; ++ i)
    t[2 * i - 1] = (opt) {i , top[i] , 1} , t[2 * i] = (opt) {i , bot[i] , 0};
  sort(t + 1 , t + m + m + 1);
  LL ans = 0; j = 1;
  for (i = 1 ; i <= n ; )
  {
    x = a[i].fi;
    int l = 1 << 30 , r = -1 << 30;
    while (i <= n && a[i].fi == x)
      l = min(a[i].se , l) , r = max(a[i].se , r) , ++ i;
    while (j <= m + m && t[j].x < x) ++ j;
    while (j <= m + m && t[j].x == x && t[j].f)
      add(t[j].p , 1) , ++ j;
    ans += sum(r) - sum(l -1);
    while (j <= m + m && t[j].x == x && !t[j].f)
      add(t[j].p , -1) , ++ j;
  }
  cout << ans << endl;
}

int main()
{
  work();
  return 0;
}



