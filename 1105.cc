

#include <stdio.h>
#define MAXN 130
int main() {
  int i, j;
  int n, m;
  char nX[MAXN], nTerNode[MAXN], nV[MAXN][10];
  int nIndex, nCaseNum, p;
  nCaseNum = 0;
  while (1 == scanf("%d", &n), n) /*1、后面加空格处理gets()*/
  {
    getchar(); /*2、这个也是处理gets(),个人感觉这个更好些。*/
    gets(nX);
    scanf("%s %d", nTerNode, &m);
    for (i = 0; i != m; ++i) {
      scanf("%s", nV[i]);
    }

    printf("S-Tree #%d:\n", ++nCaseNum);
    p = n - 1;
    for (i = 0; i != m; ++i) {
      nIndex = 0;
      for (j = 0; j != n; ++j) {
        if (nV[i][j] == '0') continue;
        nIndex += (1 << (p - j));
      }
      printf("%c", nTerNode[nIndex]);
    }
    printf("\n\n");
    }
    return 0;
}