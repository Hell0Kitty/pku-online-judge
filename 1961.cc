#define MAX_LENGTH 1000001
#include <stdio.h>
#include <string.h>
char s[MAX_LENGTH];
int next[MAX_LENGTH];
int main() {
  int i, j, k, length, count, num = 0;
  while (1) {
    scanf("%d", &length);
    if (length == 0)
      break;
    // length++;
    scanf("%s", s + 1);

    i = 1;
    j = 0;
    next[1] = 0;
    //求next
    while (i <= length) {
      if (s[i] == s[j] || j == 0) {
        i++;
        j++;
        next[i] = j;
      } else
        j = next[j];
    }



    printf("Test case #%d\n", ++num);
    for (k = 2; k <= length; k++) {
      if (k % ((k + 1) - next[k + 1]) == 0) {
        count = k / ((k + 1) - next[k + 1]);
        if (count != 1)
          printf("%d %d\n", k, count);
      }
    }
    printf("\n");
  }
  return 1;
}