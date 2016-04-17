#include <stdio.h>
int ring[1005][1005];
int flag1, flag2;
int minjudge1(int i, int j, int n) {
  int x, count = 0;
  if (flag1 == i - 1 || flag2 == i - 1) {
    for (x = flag1; x > i - 1; x--) {
      if (ring[x - 1][flag2] - ring[x][flag2] != 1) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag1 = x - 1;
        return 1;
      }
    }
    flag1 = x;
    for (x = flag2; x < n - i; x++) {
      if (ring[flag1][x + 1] - ring[flag1][x] != 1) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag2 = x + 1;
        return 1;
      }
    }
    flag2 = x;
    for (x = flag1; x < n - i; x++) {
      if (ring[x + 1][flag2] - ring[x][flag2] != 1) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag1 = x + 1;
        return 1;
      }
    }
  } else {
    for (x = flag1; x < n - i; x++) {
      if (ring[x + 1][flag2] - ring[x][flag2] != 1) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag1 = x + 1;
        return 1;
      }
    }
    flag1 = x;
    for (x = flag2; x > i - 1; x--) {
      if (ring[flag1][x - 1] - ring[flag1][x] != 1) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag2 = x - 1;
        return 1;
      }
    }
    flag2 = x;
    for (x = flag1; x > i - 1; x--) {
      if (ring[x - 1][flag2] - ring[x][flag2] != 1) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag1 = x - 1;
        return 1;
      }
    }
  }
}

int minjudge2(int i, int j, int n) {
  int x, count = 0;
  if (flag1 == i - 1 || flag2 == i - 1) {
    for (x = flag1; x > i - 1; x--) {
      if (ring[x - 1][flag2] - ring[x][flag2] != -1) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag1 = x - 1;
        return 1;
      }
    }
    flag1 = x;
    for (x = flag2; x < n - i; x++) {
      if (ring[flag1][x + 1] - ring[flag1][x] != -1) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag2 = x + 1;
        return 1;
      }
    }
    flag2 = x;
    for (x = flag1; x < n - i; x++) {
      if (ring[x + 1][flag2] - ring[x][flag2] != -1) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag1 = x + 1;
        return 1;
      }
    }
  } else {
    for (x = flag1; x < n - i; x++) {
      if (ring[x + 1][flag2] - ring[x][flag2] != -1) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag1 = x + 1;
        return 1;
      }
    }
    flag1 = x;
    for (x = flag2; x > i - 1; x--) {
      if (ring[flag1][x - 1] - ring[flag1][x] != -1) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag2 = x - 1;
        return 1;
      }
    }
    flag2 = x;
    for (x = flag1; x > i - 1; x--) {
      if (ring[x - 1][flag2] - ring[x][flag2] != -1) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag1 = x - 1;
        return 1;
      }
    }
  }
}

int maxjudge1(int i, int n) {
  int x, count = 0;
  if (flag1 == i - 1 || flag2 == i - 1) {
    for (x = flag1; x > i - 1; x--) {
      if (ring[x - 1][flag2] - ring[x][flag2] != n) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag1 = x - 1;
        return 1;
      }
    }
    flag1 = x;
    for (x = flag2; x < n - i; x++) {
      if (ring[flag1][x + 1] - ring[flag1][x] != n) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag2 = x + 1;
        return 1;
      }
    }
    flag2 = x;
    for (x = flag1; x < n - i; x++) {
      if (ring[x + 1][flag2] - ring[x][flag2] != n) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag1 = x + 1;
        return 1;
      }
    }
  } else {
    for (x = flag1; x < n - i; x++) {
      if (ring[x + 1][flag2] - ring[x][flag2] != n) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag1 = x + 1;
        return 1;
      }
    }
    flag1 = x;
    for (x = flag2; x > i - 1; x--) {
      if (ring[flag1][x - 1] - ring[flag1][x] != n) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag2 = x - 1;
        return 1;
      }
    }
    flag2 = x;
    for (x = flag1; x > i - 1; x--) {
      if (ring[x - 1][flag2] - ring[x][flag2] != n) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag1 = x - 1;
        return 1;
      }
    }
  }
}

int maxjudge2(int i, int n) {
  int x, count = 0;
  if (flag1 == i - 1 || flag2 == i - 1) {
    for (x = flag1; x > i - 1; x--) {
      if (ring[x - 1][flag2] - ring[x][flag2] != -1 * n) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag1 = x - 1;
        return 1;
      }
    }
    flag1 = x;
    for (x = flag2; x < n - i; x++) {
      if (ring[flag1][x + 1] - ring[flag1][x] != -1 * n) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag2 = x + 1;
        return 1;
      }
    }
    flag2 = x;
    for (x = flag1; x < n - i; x++) {
      if (ring[x + 1][flag2] - ring[x][flag2] != -1 * n) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag1 = x + 1;
        return 1;
      }
    }
  } else {
    for (x = flag1; x < n - i; x++) {
      if (ring[x + 1][flag2] - ring[x][flag2] != -1 * n) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag1 = x + 1;
        return 1;
      }
    }
    flag1 = x;
    for (x = flag2; x > i - 1; x--) {
      if (ring[flag1][x - 1] - ring[flag1][x] != -1 * n) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag2 = x - 1;
        return 1;
      }
    }
    flag2 = x;
    for (x = flag1; x > i - 1; x--) {
      if (ring[x - 1][flag2] - ring[x][flag2] != -1 * n) return 0;
      count++;
      if (count == n - i * 2 + 1) {
        flag1 = x - 1;
        return 1;
      }
    }
  }
}

int judge(int n, int i) {
  int j;
  for (j = i - 1; j <= n - i; j++) {
    if (ring[i - 1][j] == n * (i - 1) + i) {
      flag2 = j;
      flag1 = i - 1;
      break;
    }
    if (ring[n - i][j] == n * (i - 1) + i) {
      flag2 = j;
      flag1 = n - i;
      break;
    }
    if (ring[j][i - 1] == n * (i - 1) + i) {
      flag1 = j;
      flag2 = i - 1;
      break;
    }
    if (ring[j][n - i] == n * (i - 1) + i) {
      flag1 = j;
      flag2 = n - i;
      break;
    }
  }
  if (!minjudge1(i, j, n)) return 1;
  if (!maxjudge1(i, n)) return 1;
  j = flag2;
  if (!minjudge2(i, j, n)) return 1;
  if (!maxjudge2(i, n)) return 1;
  return 0;
}

int main() {
  int cas, n, rn, i, j;
  for (cas = 1;; cas++) {
    scanf("%d", &n);
    for (i = 0; i < n; i++)
      for (j = 0; j < n; j++) scanf("%d", &ring[i][j]);
    if (n == 0) break;
    printf("%d. ", cas);
    if (n == 1) {
      if (ring[0][0] == 1)
        printf("YES\n");
      else
        printf("NO\n");
      continue;
    }

    if (n % 2)
      rn = n / 2 + 1;
    else
      rn = n / 2;
    for (i = 1; i <= rn; i++)
      if (judge(n, i)) break;
    if (i == rn + 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
