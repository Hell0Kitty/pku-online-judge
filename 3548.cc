#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 20
#define MAX 3628810

char s[3][N], op;
int n[3][N], len[3];
int num;
struct cha {
  char c;
  int n;
} a[N];
bool OK;

void init(char *tmp) {
  bool used[2 * N];
  memset(n, 0, sizeof(n));
  memset(s, 0, sizeof(s));
  memset(a, 0, sizeof(a));
  memset(used, 0, sizeof(used));
  num = 0;
  int i, j, k;
  for (i = 0, j = 0; i < 3; i++) {
    len[i] = j;
    for (k = 0;; j++, k++) {
      if (tmp[j] == '+' || tmp[j] == '-' || tmp[j] == '=' || tmp[j] == '\0')
        break;
      s[i][k] = tmp[j];
      if (tmp[j] >= '0' && tmp[j] <= '9')
        n[i][k] = tmp[j] - '0';
      else {
        n[i][k] = tmp[j] - 'A' + 26;
        if (!used[tmp[j] - 'A']) {
          used[tmp[j] - 'A'] = true;
          a[num++].c = tmp[j];
        }
      }
    }
    s[i][k] = '\0';
    if (i == 0) op = tmp[j];
    len[i] = j - len[i];
    j++;
  }
}

int tran(int i) {
  int ans = 0;
  for (int k = 0; k < len[i]; k++) ans = ans * 10 + n[i][k];
  return ans;
}

void solve(int *per) {
  sort(per, per + num);  //全排列前记得排序
  do                     //对per枚举全排列
  {
    for (int i = 0; i < num; i++) a[i].n = per[i];

    for (int i = 0; i < 3; i++)
      for (int j = 0; j < len[i]; j++)
        if (s[i][j] >= 'A' && s[i][j] <= 'Z')
          for (int k = 0; k < num; k++)
            if (s[i][j] == a[k].c) n[i][j] = a[k].n;

    int ss[3];
    for (int i = 0; i < 3; i++) ss[i] = tran(i);
    if (op == '+' && ss[0] + ss[1] == ss[2]) {
      OK = true;
      break;
    }
    if (op == '-' && ss[0] - ss[1] == ss[2]) {
      OK = true;
      break;
    }

  } while (next_permutation(per, per + num));
}

int cmp(struct cha p, struct cha q) { return p.c < q.c; }

void BF() {
  int per[20];
  OK = false;
  sort(a, a + num, cmp);
  for (int state = 0; state < 1024; state++) {
    int cc = 0;
    for (int k = 0; k < 10; k++)
      if (state & (1 << k)) per[cc++] = k;
    if (cc == num) solve(per);
    if (OK) break;
  }
  for (int i = 0; i < num; i++) printf("%c %d\n", a[i].c, a[i].n);
}

int main() {
  char tmp[3 * N];
  while (scanf("%s", tmp) != EOF) {
    init(tmp);
    BF();
  }
  return 0;
}
