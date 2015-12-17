

#include <iostream>
#include <algorithm>
using namespace std;
int sum, n, flag;
int numb[1005], ways[1005];
void dfs(int now, int now_sum, int ll) {
  int i;
  if (now_sum == sum) {
    flag = 1;
    for (i = 1; i < ll - 1; i++)
      cout << ways[i] << '+';
    cout << ways[i] << endl;
    return;
  }
  int last = -1;
  for (i = now + 1; i <= n; i++) {
    if (last == numb[i])
      continue;
    if (now_sum + numb[i] > sum)
      continue;
    ways[ll] = numb[i];
    last = numb[i];
    dfs(i, now_sum + numb[i], ll + 1);
  }
}
int main() {
  int i;
  while (cin >> sum >> n, sum, n) {
    flag = 0;
    for (i = 1; i <= n; i++)
      cin >> numb[i];
    cout << "Sums of " << sum << ':' << endl;
    dfs(0, 0, 1);
    if (!flag)
      cout << "NONE\n";
  }
  return 0;
}