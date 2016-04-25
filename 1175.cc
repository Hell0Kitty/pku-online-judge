#include <iostream>

#include <stdio.h>

#include <string.h>

#include <algorithm>

#include <vector>

using namespace std;

const int N = 105;

class S {
 public:
  int x[170], y[170], num[170], size;

  void cl(void) { size = 0; }

  void add(int i, int j) {
    size++;
    x[size] = j, y[size] = i;
  }

  void stan(void) {
    int mx = 1000, my = 1000, i;

    for (i = 1; i <= size; i++) mx = min(mx, x[i]), my = min(my, y[i]);

    for (i = 1; i <= size; i++) x[i] -= mx, y[i] -= my;

    for (i = 1; i <= size; i++) num[i] = y[i] * N + x[i];

    sort(num + 1, num + size + 1);
  }

  void lr(S &a) {
    a.size = this->size;

    for (int i = 1; i <= size; i++) a.x[i] = -this->x[i], a.y[i] = this->y[i];
  }

  void ud(S &a) {
    a.size = this->size;

    for (int i = 1; i <= size; i++) a.x[i] = this->x[i], a.y[i] = -this->y[i];
  }

  void rot(S &a) {
    a.size = this->size;

    for (int i = 1; i <= size; i++) a.x[i] = this->y[i], a.y[i] = this->x[i];
  }

  bool eq(S &a) {
    if (a.size == this->size) {
      for (int i = 1; i <= this->size; i++)

        if (a.num[i] != this->num[i]) return 0;

      return 1;

    }

    else

      return 0;
  }
};

bool map[N][N];

int tag[N][N], al[700], x[] = {-1, 0, 1, 1, 1, 0, -1, -1},
                        y[] = {1, 1, 1, 0, -1, -1, -1, 0};

S sky[600][8];

void dfs(int r, int c, int num)

{
  tag[r][c] = num;

  for (int k = 0; k < 8; k++) {
    if (tag[r + y[k]][c + x[k]] == -1 && map[r + y[k]][c + x[k]])

      dfs(r + y[k], c + x[k], num);
  }
}

int init(int w, int h)

{
  int i, j, n = 0;

  char s[N];

  memset(map, 0, sizeof(map));

  memset(tag, -1, sizeof(tag));

  for (i = 1; i <= h; i++) {
    scanf("%s", s + 1);

    for (j = 1; j <= w; j++) map[i][j] = s[j] == '0' ? 0 : 1;
  }

  for (i = 1; i <= h; i++)

    for (j = 1; j <= w; j++)

      if (map[i][j] && tag[i][j] == -1) dfs(i, j, ++n);

  for (i = 1; i <= n; i++) sky[i][0].cl();

  for (i = 1; i <= h; i++)

    for (j = 1; j <= w; j++)

      if (tag[i][j] != -1) sky[tag[i][j]][0].add(i, j);

  for (i = 1; i <= n; i++) {
    sky[i][0].rot(sky[i][4]);

    sky[i][0].lr(sky[i][1]);

    sky[i][0].ud(sky[i][2]);

    sky[i][2].lr(sky[i][3]);

    sky[i][4].lr(sky[i][5]);

    sky[i][4].ud(sky[i][6]);

    sky[i][6].lr(sky[i][7]);

    for (j = 0; j < 8; j++) sky[i][j].stan();
  }

  return n;
}

inline bool eq(int a, int b)

{
  for (int i = 0; i < 8; i++)

    if (sky[a][i].eq(sky[b][0])) return 1;

  return 0;
}

void deal(int n)

{
  int i, j, cnt = 0;

  memset(al, -1, sizeof(al));

  for (i = 1; i <= n; i++) {
    if (al[i] == -1) {
      al[i] = ++cnt;

      for (j = i + 1; j <= n; j++)

        if (al[j] == -1 && eq(i, j)) al[j] = cnt;
    }
  }
}

void out(int w, int h)

{
  for (int i = 1, j; i <= h; i++) {
    for (j = 1; j <= w; j++) {
      if (map[i][j])
        printf("%c", al[tag[i][j]] + 'a' - 1);

      else
        printf("0");
    }

    printf("\n");
  }
}

int main()

{
  int w, h, n;

  while (scanf("%d %d", &w, &h) == 2) {
    n = init(w, h);

    deal(n);

    out(w, h);
  }

  return 0;
}
