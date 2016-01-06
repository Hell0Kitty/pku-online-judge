#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct mapp {
  int count;
  int distance;
  int i;
  int d;
} map[(40 + 1) * 40];

int cmp(const void *a, const void *b) {
  if (((struct mapp *)a)->count != ((struct mapp *)b)->count)
    return ((struct mapp *)b)->count - ((struct mapp *)a)->count;
  else if (((struct mapp *)b)->distance != ((struct mapp *)a)->distance)
    return ((struct mapp *)b)->distance - ((struct mapp *)a)->distance;
  else if (((struct mapp *)b)->i != ((struct mapp *)a)->i)
    return ((struct mapp *)b)->i - ((struct mapp *)a)->i;
  else if (((struct mapp *)b)->d != ((struct mapp *)a)->d)
    return ((struct mapp *)a)->d - ((struct mapp *)b)->d;
}

int main() {
  char a[45];
  int i, d, k, j;
  int count = 0;
  int len;
  while (gets(a), strcmp(a, "END") != 0) {
    len = strlen(a);
    for (i = 0, k = 0; i < len; i++) {
      for (d = 1; i + d <= len; d++) {
        count = 0;
        map[k].i = i;
        map[k].d = d;
        for (j = i; j < len && a[j] == '.'; j += d) count++;
        if (j < len)
          map[k].distance = j;
        else
          map[k].distance = j - d;
        map[k].count = count;
        k++;
      }
    }
    qsort(map, k, sizeof(map[0]), cmp);
    printf("%d %d\n", map[0].i, map[0].d);
  }

  return 0;
}
