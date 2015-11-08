#include <stdio.h>
#include <string.h>
#define SIZE 5842
#define MAX 2000000001
int num[SIZE + 1];
char rank[10];

void excel() {
  int i, j, prime[4], loc[4];
  num[0] = 1, loc[0] = loc[1] = loc[2] = loc[3] = 0;
  prime[0] = 2, prime[1] = 3, prime[2] = 5, prime[3] = 7;
  for (i = 1; i <= 5842; i++) {
    int min = MAX;
    for (j = 0; j < 4; j++)
      if (num[loc[j]] * prime[j] < min) min = num[loc[j]] * prime[j];
    for (j = 0; j < 4; j++)
      if (num[loc[j]] * prime[j] == min) loc[j]++;
    num[i] = min;
  }
}

void make_ranked(int n) /*加数字后面的英语序数词，四级没过。。。网上查的*/
{
  int last = n % 10;
  int seclast = (n % 100) / 10;
  if (last > 3 || last == 0)
    strcpy(rank, "th");
  else if (last == 3)
    strcpy(rank, "rd");
  else if (last == 2)
    strcpy(rank, "nd");
  else
    strcpy(rank, "st");

  if (last == 1 && seclast == 1) strcpy(rank, "th");
  if (last == 2 && seclast == 1) strcpy(rank, "th");
  if (last == 3 && seclast == 1) strcpy(rank, "th");
}

int main() {
  int n;
  excel();
  while (scanf("%d", &n) && n) {
    make_ranked(n);
    printf("The %d%s humble number is %d.\n", n, rank, num[n - 1]);
  }
  return 0;
}