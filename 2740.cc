#include <iostream>
using namespace std;

struct Book {
  int id, time;
};

struct node {
  int num;
  Book a[35];
};

struct Pos {
  int deskID, pos;
};

const int INF = 1000000000;
node a[15];
int n, m, c, all[5005], sum;

void input() {
  int num[105], a[105][50], i, j;
  memset(a, -1, sizeof(a));
  for (i = 1; i <= n; i++) {
    scanf("%d", &num[i]);
    for (j = 1; j <= num[i]; j++) scanf("%d", &a[i][j]);
  }
  sum = 0;
  for (i = 1; i <= 50; i++)
    for (j = 1; j <= n; j++)
      if (a[j][i] != -1) all[++sum] = a[j][i];
}

Pos findPos(int bookID) {
  int i, j;
  Pos ans;
  for (i = 1; i <= m; i++)
    for (j = 1; j <= a[i].num; j++)
      if (a[i].a[j].id == bookID) {
        ans.deskID = i;
        ans.pos = j;
        return ans;
      }
  ans.deskID = m + 1;
  return ans;
}

void take(Pos pos) {
  if (pos.deskID == m + 1) return;
  int i;
  for (i = pos.pos; i < a[pos.deskID].num; i++)
    a[pos.deskID].a[i] = a[pos.deskID].a[i + 1];
  a[pos.deskID].num--;
}

int findempty() {
  int i;
  for (i = 2; i <= m; i++)
    if (a[i].num < c) return i;
  return m + 1;
}

Pos findMin() {
  int min = INF, i;
  Pos ans;
  ans.deskID = 1;
  for (i = 1; i <= a[1].num; i++)
    if (a[1].a[i].time < min) {
      min = a[1].a[i].time;
      ans.pos = i;
    }
  return ans;
}

int cal(int id, int time) {
  int ans = 0;
  Book temp;
  temp.id = id;
  temp.time = time;
  Pos pos = findPos(id);
  take(pos);
  ans += pos.deskID;
  if (a[1].num < c) {
    a[1].a[++a[1].num] = temp;
    ans += 1;
    return ans;
  }
  int empty = findempty();
  ans += empty;
  if (empty != m + 1) a[empty].a[++a[empty].num] = temp;
  Pos pos1 = findMin();
  Book temp1 = a[1].a[pos1.pos];
  take(pos1);
  ans += 1;
  int empty1 = findempty();
  ans += empty1;
  if (empty1 != m + 1) a[empty1].a[++a[empty1].num] = temp1;
  if (empty != empty1)
    a[empty].num--;
  else if (empty != m + 1) {
    a[empty].a[a[empty].num - 1] = a[empty].a[a[empty].num];
    a[empty].num--;
  }
  a[1].a[++a[1].num] = temp;
  ans += 1 + empty;
  return ans;
}

int main() {
  while (scanf("%d%d%d", &m, &c, &n), m || c || n) {
    input();
    int i;
    for (i = 1; i <= m; i++) a[i].num = 0;
    int cost = 0;
    for (i = 1; i <= sum; i++) cost += cal(all[i], i);
    printf("%d\n", cost);
  }
  return 0;
}
