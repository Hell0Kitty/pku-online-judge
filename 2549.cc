#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, data[1005];

int main() {
  while (scanf("%d", &n), n) {
    int ans, i;
    bool flag = true;
    for (i = 0; i < n; i++) scanf("%d", &data[i]);
    sort(data, data + n);
    int sz = unique(data, data + n) - data;
    n = sz;
    for (int d = n - 1; d >= 0 && flag; d--)
      for (i = 0; i < n - 3 && flag; i++) {
        int head = i + 1, tail = n - 1;
        while (head < tail) {
          int tmp = data[i] + data[head] + data[tail];
          if (tmp == data[d]) {
            if (i == d || head == d || tail == d) break;
            flag = false;
            ans = tmp;
            break;
          } else if (tmp > data[d])
            tail--;
          else
            head++;
        }
      }
    if (flag)
      printf("no solution\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
