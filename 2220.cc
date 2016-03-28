nclude<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
    using namespace std;

const int Max = 0x7fffffff;
struct Node {
  int val[10];
} a[10];
struct Node2 {
  int num[10];
  int cnt, sum;
} ans[10], dfs_ans[10];
int vis[10];
int diff;
bool flag[10];

void init() {
  diff = Max;
  memset(flag, false, sizeof(flag));
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      ans[i].num[j] = dfs_ans[i].num[j] = 0;
    }
    ans[i].cnt = ans[i].sum = dfs_ans[i].cnt = dfs_ans[i].sum = 0;
  }
}

void init_vis(int n) {
  int N = (1 << n);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < n; j++) {
      if (i & (1 << j))
        vis[j] = 0;
      else
        vis[j] = 1;
    }
  }
}

void dfs(int cur_hunter, int cur_treasure, int num_treasure, int hunter) {
  if (cur_hunter == hunter && cur_treasure == num_treasure) {
    int t_max = dfs_ans[0].sum;
    int t_min = dfs_ans[0].sum;
    for (int i = 1; i < hunter; i++) {
      t_max = max(t_max, dfs_ans[i].sum);
      t_min = min(t_min, dfs_ans[i].sum);
    }
    if (t_max - t_min < diff) {
      diff = t_max - t_min;
      for (int i = 0; i < hunter; i++) ans[i] = dfs_ans[i];
    }
    return;
  }
  if (cur_hunter >= hunter) return;
  int N = (1 << num_treasure);
  for (int i = 0; i < N; i++) {
    int t_cnt = 0;
    bool p_flag = true;
    for (int j = 0; j < num_treasure; j++) {
      if (i & (1 << j))
        vis[j] = 0;
      else {
        vis[j] = 1;
        t_cnt++;
        if (flag[j] == true) {
          p_flag = false;
          break;
        }
      }
    }
    if (/*t_cnt!=0&&*/ p_flag == true &&
        (t_cnt + cur_treasure + hunter - cur_hunter - 1) <= num_treasure) {
      int tt = 0;
      dfs_ans[cur_hunter].sum = 0;
      dfs_ans[cur_hunter].cnt = t_cnt;
      for (int j = 0; j < num_treasure; j++) {
        if (vis[j] == 1) {
          dfs_ans[cur_hunter].num[tt++] = j;
          flag[j] = true;
          dfs_ans[cur_hunter].sum += a[cur_hunter].val[j];
        }
      }
      dfs(cur_hunter + 1, cur_treasure + t_cnt, num_treasure, hunter);
      for (int j = 0; j < tt; j++) {
        flag[dfs_ans[cur_hunter].num[j]] = false;
      }
    }
  }
  return;
}

int main() {
  int num_treasure, hunter;
  char s[12];
  int ca = 1;
  // freopen("out.txt","w",stdout);
  while (scanf("%s", s) != EOF) {
    init();
    scanf("%d%d", &num_treasure, &hunter);  //宝藏，寻宝人
    for (int i = 0; i < hunter; i++) {
      for (int j = 0; j < num_treasure; j++) {
        scanf("%d", &a[i].val[j]);
      }
    }
    scanf("%s", s);
    if (num_treasure == 1) {
      int m_min = a[0].val[0];
      int m_num = 0;
      for (int i = 1; i < hunter; i++) {
        if (m_min > a[i].val[0]) {
          m_min = a[i].val[0];
          m_num = i;
        }
      }
      if (ca != 1) printf("\n");
      ca++;
      for (int i = 0; i < hunter; i++) {
        if (i == m_num) {
          printf("1 %d\n", m_min);
        } else
          printf("0\n");
      }
      continue;
    }
    dfs(0, 0, num_treasure, hunter);
    if (ca != 1) printf("\n");
    ca++;
    for (int i = 0; i < hunter; i++) {
      for (int j = 0; j < ans[i].cnt; j++) {
        if (j == 0)
          printf("%d", ans[i].num[j] + 1);
        else
          printf(" %d", ans[i].num[j] + 1);
      }
      if (ans[i].cnt > 0)
        printf(" %d\n", ans[i].sum);
      else
        printf("%d\n", ans[i].sum);
    }
  }
  return 0;
}
