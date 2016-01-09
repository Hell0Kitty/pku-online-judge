#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
#define MAXV 30000
#define INF 999999
#define MAXN 11
#define MAXS 11
#define ADD 1
#define DIV 2
#define DUP 3
#define MUL 4
#define SUB 5
int S[MAXN][MAXS], atop[MAXN], y[MAXN];
int N, A[MAXN], CA[MAXN], minlen, mCount = 1;

void Print(int c) {
  switch (c) {
    case ADD:
      printf("ADD");
      break;
    case SUB:
      printf("SUB");
      break;
    case MUL:
      printf("MUL");
      break;
    case DUP:
      printf("DUP");
      break;
    case DIV:
      printf("DIV");
      break;
  }
}

void dfs(int len) {
  int i, j, a[MAXN], b[MAXN];
  if (len - 1 < minlen) {
    for (j = 0; j < N; j++)
      if (S[j][0] != y[j] || atop[j] != 0) break;
    if (j == N) {
      minlen = len - 1;
      memcpy(A, CA, sizeof(A));
    }
  }
  if (len > minlen || len > 10) return;
  for (i = 1; i <= 5; i++) {
    int con = -1;
    bool LastOneChanged = false;
    for (j = 0; j < N && con == -1; j++) {
      if (i != DUP) {
        if (atop[j] == 0) {
          con = j;
          break;
        }
        if (i == DIV && S[j][atop[j]] == 0) {
          con = j;
          break;
        }
        b[j] = S[j][atop[j]--];
        a[j] = S[j][atop[j]--];
        switch (i) {
          case ADD:
            S[j][++atop[j]] = a[j] + b[j];
            break;
          case DIV:
            S[j][++atop[j]] = a[j] / b[j];
            break;
          case MUL:
            S[j][++atop[j]] = a[j] * b[j];
            break;
          case SUB:
            S[j][++atop[j]] = a[j] - b[j];
            break;
        }
        CA[len] = i;
        if (abs(S[j][atop[j]]) > MAXV) {
          LastOneChanged = true;
          con = j;
          break;
        }
      } else {
        atop[j]++;
        S[j][atop[j]] = S[j][atop[j] - 1];
        CA[len] = DUP;
      }
    }
    if (con == -1) dfs(len + 1);
    if (i != DUP)
      for (j = 0;
           j < N && (con == -1 || ((LastOneChanged == false && j < con) ||
                                   (LastOneChanged == true && j <= con)));
           j++) {
        S[j][atop[j]] = a[j];
        S[j][++atop[j]] = b[j];
      }
    else
      for (j = 0;
           j < N && (con == -1 || ((LastOneChanged == false && j < con) ||
                                   (LastOneChanged == true && j <= con)));
           j++)
        atop[j]--;
  }
}

int main() {
  int i;
  while (scanf("%d", &N) && N) {
    for (i = 0; i < N; i++) scanf("%d", &S[i][0]);
    for (i = 0; i < N; i++) scanf("%d", &y[i]);
    memset(atop, 0, sizeof(atop));
    minlen = INF;
    dfs(1);
    printf("Program %d\n", mCount++);
    if (minlen == INF)
      printf("Impossible\n\n");
    else if (minlen == 0)
      printf("Empty sequence\n\n");
    else {
      Print(A[1]);
      for (i = 2; i <= minlen; i++) {
        printf(" ");
        Print(A[i]);
      }
      printf("\n\n");
    }
  }
  return 0;
}
