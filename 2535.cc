#include <stdio.h>
#include <string.h>

int problemRank[102];
int isHardest[102];

int main() {
  int N, P;
  int minNum, maxNum;
  scanf("%d%d", &N, &P);

  int i, j;
  int nowProblemScore[102];

  memset(problemRank, 0, sizeof(problemRank));
  memset(isHardest, 0, sizeof(isHardest));
  for (i = 0; i < N; i++) {
    minNum = 0x7fffffff;
    maxNum = -1;
    for (j = 0; j < P; j++) {
      scanf("%d", &nowProblemScore[j]);

      if (nowProblemScore[j] < minNum)
        minNum = nowProblemScore[j];

      if (nowProblemScore[j] > maxNum)
        maxNum = nowProblemScore[j];
    }

    // printf("minNum == %d\n",minNum);  //ok

    for (j = 0; j < P; j++) {
      if (minNum == nowProblemScore[j])
        problemRank[j]++;

      if (maxNum == nowProblemScore[j])
        isHardest[j] = 1;
    }
  }

  /*for(j=0;j<P;j++)
    printf("%d ",problemRank[j]);
  printf("end\n");*/

  for (i = 0; i < P; i++)
    if (isHardest[i] == 0 && problemRank[i] > N / 2) {
      printf("%d", i + 1);
      break;
    }

  if (i == P) {
    printf("0\n");
    return 0;
  }

  //最后的输出
  for (j = i + 1; j < P; j++)
    if (isHardest[j] == 0 && problemRank[j] > N / 2)
      printf(" %d", j + 1);

  printf("\n");

  return 0;
}