#include <cstdio>
#include <utility>
#include <cstring>
#include <functional>
#include <algorithm>
using namespace std;
#define lowbit(bit) ((bit) & -(bit))
#define N 1001
struct node {
  int arr[N];
  int x;
  void add(int pos) {
    while (pos < N) arr[pos]++, pos += lowbit(pos);
  }

} refer[N];
int n, aera, c;
pair<int, int> data[N];
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  return a.first < b.first;
}
int sum(int pos, int s, int e) {
  int res = 0;
  while (pos > 0)
    res += refer[e].arr[pos] - refer[s - 1].arr[pos], pos -= lowbit(pos);
  return res;
}
int get(int rank, int s, int e) {
  int begin = 1, end = N - 1;
  while (begin <= end) {
    int mid = (begin + end) / 2;
    if (sum(mid, s, e) >= rank)
      end = mid - 1;
    else
      begin = mid + 1;
  }
  return end + 1;
}
int main() {
  // freopen("ans.txt","w",stdout);
  // freopen("f.in","r",stdin);
  int test;
  scanf("%d", &test);
  while (test--) {
    scanf("%d%d", &n, &aera);
    for (int i = 0; i < n; i++) scanf("%d%d", &data[i].first, &data[i].second);
    sort(data, data + n, cmp);
    c = 2;
    memset(refer[1].arr, 0, sizeof(refer[1].arr));
    memset(refer[0].arr, 0, sizeof(refer[0].arr));
    refer[1].x = data[0].first;
    refer[1].add(data[0].second);
    for (int i = 1; i < n; i++)
      if (data[i].first == data[i - 1].first)
        refer[c - 1].add(data[i].second);
      else {
        memcpy(refer[c].arr, refer[c - 1].arr, sizeof(refer[c].arr));
        refer[c].x = data[i].first;
        refer[c++].add(data[i].second);
      }
    int ans = -1;
    for (int i = 1; i < c; i++)
      for (int j = i; j < c; j++) {
        int rank = sum(N - 1, i, j);
        int len =
            refer[j].x - refer[i].x ? aera / (refer[j].x - refer[i].x) : aera;
        while (rank) {
          int p = get(rank, i, j);
          ans = max(ans, sum(p, i, j) - sum(p - len - 1, i, j));
          rank--;
        }
      }
    printf("%d\n", ans);
  }
  return 0;
}
