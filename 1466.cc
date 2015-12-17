#include <memory.h>
#include <stdio.h>

#define LEFT_MAX 501
#define RIGHT_MAX 501

bool useif[RIGHT_MAX];
int link[RIGHT_MAX];

int left_num, right_num;
bool array[LEFT_MAX][RIGHT_MAX];

bool can(int t) {
  int i;
  for (i = 0; i < right_num; i++) {
    if (!useif[i] && array[t][i]) {
      useif[i] = true;
      if (link[i] == -1 || can(link[i])) {
        link[i] = t;
        return true;
      }
    }
  }
  return false;
}

int main() {
  int i, k, num, temp, num_of_this;
  char c;
  // scanf("%d\n",&count);
  // for(j=0;j<count;j++)
  while (scanf("%d", &left_num) != -1) {
    right_num = left_num;
    // link??-1
    memset(link, 0xFF, sizeof(link));
    memset(array, 0, sizeof(array));
    memset(useif, 0, sizeof(useif));

    num = 0;

    for (i = 0; i < left_num; i++) {
      scanf("%d%c%c%c%d%c", &temp, &c, &c, &c, &num_of_this, &c);
      for (k = 0; k < num_of_this; k++) {
        scanf("%d", &temp);
        array[i][temp] = true;
      }
    }
    //匹配，num为结果
    for (i = 0; i < left_num; i++) {
      memset(useif, 0, sizeof(useif));
      if (can(i)) num++;
    }
    printf("%d\n", left_num - num / 2);
  }
  return 1;
}