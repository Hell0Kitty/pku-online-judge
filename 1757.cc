#include <stdio.h>
#include <limits.h>
#include <string.h>
#define N 10001

int sequence[N], line, time, result, answer[N / 2 + 2][2];

int find() {
  memset(sequence, 0, sizeof(sequence));

  int k, time1, p, q, i, aim, kmax = 0;

  for (k = 1; k <= 10000; k++) {
    aim = line;
    time1 = time;
    p = 0;
    q = k - 1;
    while (time1 > 0) {
      time1--;
      i = (p + q) / 2;
      if (i == aim && time1 > 0) break;
      if (i == aim && time1 == 0) {
        sequence[k] = 1;
        kmax = k;
        break;
      }
      if (line < i)
        q = i - 1;
      else
        p = i + 1;
    }
  }

  result = 0;
  memset(answer, 0, sizeof(answer));

  i = 1;

  while (i <= kmax) {
    if (sequence[i] == 1) {
      result++;
      answer[result][0] = i;
      while (sequence[i] == 1) i++;
      answer[result][1] = i - 1;
    } else
      i++;
  }

  printf("%d\n", result);

  for (i = 1; i <= result; i++) printf("%d %d\n", answer[i][0], answer[i][1]);

  return 0;
}

int main() {
  scanf("%d%d", &line, &time);
  find();
  return 0;
}