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
using namespace std;
int n , m , p;
LL a[40];
pair<LL , int> s[1 << 17] , t[1 << 18];
LL aabs(LL x) {return x > 0 ? x : -x;}
map<int , LL> h;
void work()
{
  h.clear();LL ans = 9223372036854775807LL , x; int sum , i , j , y , k;
  for (i = 0 ; i < n ; ++ i)
    cin >> a[i];
  m = n >> 1 , memset(s , 0 , sizeof(s)) , memset(t , 0 , sizeof(t));
  for (i = 0 ; i < m ; ++ i)
    h[1 << i] = a[i];
  for (i = 1 ; i < 1 << m ; ++ i)
    s[i].first = s[i & (i - 1)].first + h[i & -i] , s[i].second = s[i & (i - 1)].second + 1;
  sort(s , s + (1 << m));
  p = 0 , h.clear() , s[p ++] = s[0];
  for (i = 1 ; i < 1 << m ; ++ i)
    if (s[i].first > s[p - 1].first || !s[p - 1].first && !s[p - 1].second && !s[i].first)
      s[p ++] = s[i];
  for (i = 0 ; i < n - m ; ++ i)
    h[1 << i] = a[m + i];
  for (i = 0 ; i < 1 << (n - m) ; ++ i)
  {
    if (i) t[i].first = t[i & (i - 1)].first + h[i & -i] , t[i].second = t[i & (i - 1)].second + 1;
    k = lower_bound(s , s + p , make_pair(-t[i].first , -1 << 30)) - s;
    for (j = max(0 , k - 3) ; j < min(p , k + 4) ; ++ j)
      if (y = s[j].second + t[i].second)
      {
        x = aabs(s[j].first + t[i].first);
        if (x < ans) ans = x , sum = y;
        else if (x == ans && y < sum)
          sum = y;
      }
  }
  cout << ans << ' ' << sum << endl;
}

int main()
{
  while (scanf("%d",&n) , n)
    work();
  return 0;
}


