#include <iostream>
#include <queue>
using namespace std;

struct node {
  int flag, id, next;
};

struct Point {
  char x1[255], y1[255], x2[255], y2[255];
  int key1, key2;
};

struct Node {
  char x[255], y[255];
  int num;
};

const int mod = 10007;
node edges[1000000];
Point p[3005];
int head[mod], e, n, visit[3005];
Node a[3005];
int num;

void init(char s[]) {
  int i, j;
  for (i = 0; s[i] && s[i] == '0'; i++)
    ;
  if (!s[i]) {
    s[0] = '0';
    s[1] = '\0';
    return;
  }
  for (j = i; s[j]; j++) s[j - i] = s[j];
  s[j - i] = '\0';
}

int cal(char s[]) {
  int ans = 0, i;
  for (i = 0; s[i]; i++) ans = (ans + (i + 1) * s[i] * s[i]) % mod;
  return ans;
}

void insert(int key, int id, int flag) {
  edges[e].id = id;
  edges[e].flag = flag;
  edges[e].next = head[key];
  head[key] = e++;
}

int ok(char s1[], char s2[]) { return strcmp(s1, s2) == 0; }

int find(int key, int id) {
  int i, id1;
  for (i = head[key]; i != -1; i = edges[i].next)
    if (edges[i].id != id && !visit[edges[i].id]) {
      id1 = edges[i].id;
      if (ok(p[id1].x1, p[id].x1) && ok(p[id1].y1, p[id].y1)) return id1;
      if (ok(p[id1].x2, p[id].x2) && ok(p[id1].y2, p[id].y2)) return id1;
      if (ok(p[id1].x1, p[id].x2) && ok(p[id1].y1, p[id].y2)) return id1;
      if (ok(p[id1].x2, p[id].x1) && ok(p[id1].y2, p[id].y1)) return id1;
    }
  return -1;
}

int isconnect() {
  int i, k;
  queue<int> Q;

  memset(visit, 0, sizeof(visit));
  Q.push(1);
  visit[1] = 1;
  while (!Q.empty()) {
    k = Q.front();
    Q.pop();

    i = find(p[k].key1, k);
    if (i != -1 && !visit[i]) {
      visit[i] = 1;
      Q.push(i);
    }
    i = find(p[k].key2, k);
    if (i != -1 && !visit[i]) {
      visit[i] = 1;
      Q.push(i);
    }
  }
  for (i = 1; i <= n; i++)
    if (!visit[i]) return 0;
  return 1;
}

void Add(char x[], char y[]) {
  int i;
  for (i = 1; i <= num; i++)
    if (ok(a[i].x, x) && ok(a[i].y, y)) {
      a[i].num++;
      return;
    }
  num++;
  a[num].num = 1;
  strcpy(a[num].x, x);
  strcpy(a[num].y, y);
}

int isclosed() {
  int i, j, id;
  for (i = 0; i < mod; i++) {
    num = 0;
    for (j = head[i]; j != -1; j = edges[j].next) {
      id = edges[j].id;
      if (edges[j].flag == 0)
        Add(p[id].x1, p[id].y1);
      else
        Add(p[id].x2, p[id].y2);
    }
    for (j = 1; j <= num; j++)
      if (a[j].num & 1) return 0;
  }
  return 1;
}

int main() {
  scanf("%d", &n);
  int i;
  memset(head, -1, sizeof(head));
  e = 0;
  for (i = 1; i <= n; i++) {
    scanf("%s%s%s%s", p[i].x1, p[i].y1, p[i].x2, p[i].y2);
    init(p[i].x1);
    init(p[i].y1);
    init(p[i].x2);
    init(p[i].y2);
    p[i].key1 = cal(p[i].x1 + 3) * cal(p[i].y1 + 5) % mod;
    p[i].key2 = cal(p[i].x2 + 3) * cal(p[i].y2 + 5) % mod;
    insert(p[i].key1, i, 0);
    insert(p[i].key2, i, 1);
  }
  if (isconnect() && isclosed())
    puts("1");
  else
    puts("0");
  return 0;
}
