#include <stdio.h>
struct {
  __int64 x, y;
} a[100];
__int64 map[100][100];
int main() {
  int w, s, p, i, j, k;
  while (scanf("%d", &w) != EOF, w) {
    for (i = 0; i <= 88; i++) {
      a[i].x = 2000000001;
      for (j = 0; j <= 88; j++) map[i][j] = 2000000001;
    }
    scanf("%d%d", &s, &p);
    j = p;
    for (i = 1; i <= p; i++) {
      j++;
      scanf("%I64d%I64d", &a[i].x, &a[i].y);
      map[i][j] = 0;
    }
    a[0].x = a[0].y = 0;
    a[2 * p + 1].x = a[2 * p + 1].y = w;
    __int64 sum, count;
    for (i = 0; i <= 0; i++) {
      sum = 0;
      count = 0;
      for (j = i + 1; j <= p + 1; j++) {
        if (j == p + 1) {
          if (w > sum) {
            if ((w - sum) % s != 0) count++;
            count = count + (w - sum) / s;
          }
          map[i][2 * p + 1] = count;
          break;
        }
        if (a[j].x > sum) {
          int tt = count;
          if ((a[j].x - sum) % s != 0) count++;
          count = count + (a[j].x - sum) / s;
          sum += (count - tt) * s;
        }
        if (a[j].x == sum) {
          map[i][j] = count;
          sum--;
        } else if (a[j].x < sum) {
          map[i][j] = count;
          while (a[j + 1].x < sum) {
            j++;
            map[i][j] = count;
          }
          if (a[j + 1].x == sum) {
            j++;
            map[i][j] = count;
            int jj = j, kk = s;
            sum--;
            while (a[jj - 1].x == sum) {
              kk--;
              map[i][jj] = count;
              sum--;
              jj--;
              if (kk == 1) break;
            }
            if (kk == 1) break;
          }
        }
      }
    }
    for (i = 1; i <= p; i++) {
      j = 1;
      sum = a[i].y;
      count = 0;
      while (a[i].y > a[j].x || i == j) j++;
      for (j; j <= p + 1; j++) {
        if (j == p + 1) {
          if (w > sum) {
            if ((w - sum) % s != 0) count++;
            count = count + (w - sum) / s;
          }
          map[i + p][2 * p + 1] = count;
          break;
        }

        if (sum < a[j].x) {
          int tt = count;
          if ((a[j].x - sum) % s != 0) count++;
          count = count + (a[j].x - sum) / s;
          sum += (count - tt) * s;
        }
        if (sum == a[j].x) {
          map[i + p][j] = count;
          sum--;
        } else if (sum > a[j].x) {
          map[i + p][j] = count;
          while (a[j + 1].x < sum) {
            j++;
            map[i + p][j] = count;
          }
          if (a[j + 1].x == sum) {
            j++;
            map[i + p][j] = count;
            int jj = j, kk = s;
            sum--;
            while (a[jj - 1].x == sum) {
              kk--;
              map[i + p][jj] = count;
              sum--;
              jj--;
              if (kk == 1) break;
            }
            if (kk == 1) break;
          }
        }
      }
    }
    for (i = 0; i <= 2 * p + 1; i++) {
      for (j = 0; j <= 2 * p + 1; j++) {
        for (k = 0; k <= 2 * p + 1; k++) {
          if (map[j][k] > map[j][i] + map[i][k])
            map[j][k] = map[j][i] + map[i][k];
        }
      }
    }
    printf("%I64d\n", map[0][2 * p + 1]);
  }
  return 0;
}
