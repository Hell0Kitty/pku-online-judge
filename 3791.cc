#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PROBS 1000
#define EPS .001
#define ERR .001

char inbuf[512];

int nButtons;
double charFreq[26];
double freqDenom;
int keyLetterCounts[26];

int ReadDataSet(int index) {
  int i;
  if (fgets(&(inbuf[0]), 255, stdin) == NULL) {
    fprintf(stderr, "read failed on problem %d num buttons\n", index);
    return -1;
  }
  inbuf[511] = 0;
  if (sscanf(inbuf, "%d", &nButtons) != 1) {
    fprintf(stderr, "scan failed on problem %d num buttons\n", index);
    return -2;
  }
  if (fgets(&(inbuf[0]), 255, stdin) == NULL) {
    fprintf(stderr, "read failed on problem %d char freq a-m\n", index);
    return -3;
  }
  inbuf[511] = 0;
  if (sscanf(inbuf, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf ",
             &charFreq[0], &charFreq[1], &charFreq[2], &charFreq[3],
             &charFreq[4], &charFreq[5], &charFreq[6], &charFreq[7],
             &charFreq[8], &charFreq[9], &charFreq[10], &charFreq[11],
             &charFreq[12]) != 13) {
    fprintf(stderr, "scan failed on problem %d  char freq a-m\n", index);
    return -4;
  }
  if (fgets(&(inbuf[0]), 255, stdin) == NULL) {
    fprintf(stderr, "read failed on problem %d char freq n-z\n", index);
    return -5;
  }
  inbuf[511] = 0;
  if (sscanf(inbuf, "%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf ",
             &charFreq[13], &charFreq[14], &charFreq[15], &charFreq[16],
             &charFreq[17], &charFreq[18], &charFreq[19], &charFreq[20],
             &charFreq[21], &charFreq[22], &charFreq[23], &charFreq[24],
             &charFreq[25]) != 13) {
    fprintf(stderr, "scan failed on problem %d  char freq n-z\n", index);
    return -6;
  }
  for (i = 0, freqDenom = 0.0; i < 26; i++) {
    freqDenom += charFreq[i];
  }
  return 0;
}

double bestAvg[26][26];
int bestLetterCount[26][26];

int TeleSolve() {
  int i, j, k, lim;
  double curCount;
  for (i = 0; i < 26; i++) {
    for (j = 0; j < 26; j++) {
      bestAvg[i][j] = 5000.0;
      bestLetterCount[i][j] = 0;
    }
  }
  for (i = 0, curCount = 0.0; i < 8; i++) {
    curCount += (i + 1) * charFreq[i];
    bestAvg[0][i] = curCount;
    bestLetterCount[0][i] = i + 1;
  }
  for (j = 1; j < nButtons; j++) {
    for (k = j; k < 26; k++) {
      if (bestAvg[j - 1][k - 1] > 4000.0) {
        break;
      }
      lim = 26 - nButtons + j + 1;
      if (lim > 8) lim = 8;
      for (i = 0, curCount = bestAvg[j - 1][k - 1]; i < lim; i++) {
        curCount += (i + 1) * charFreq[i + k];
        if (bestAvg[j][k + i] > curCount) {
          bestAvg[j][k + i] = curCount;
          bestLetterCount[j][k + i] = i + 1;
        }
      }
    }
  }
  return 0;
}

void PrintSolution(int probNum) {
  int i, j, k;
  for (i = nButtons - 1, j = 25; i >= 0; i--) {
    keyLetterCounts[i] = bestLetterCount[i][j];
    j -= keyLetterCounts[i];
  }
  printf("%d %.3f ", probNum, bestAvg[nButtons - 1][25] / 100.0);
  for (i = 0, j = 0; i < nButtons; i++) {
    for (k = 0; k < keyLetterCounts[i]; k++) {
      putchar('A' + j);
      j++;
    }
    putchar(' ');
  }
  printf("\n");
}

int main() {
  int probCnt, curProb, ret;

  if (fgets(&(inbuf[0]), 255, stdin) == NULL) {
    fprintf(stderr, "read failed on problem count\n");
    return -1;
  }
  inbuf[255] = 0;
  probCnt = atoi(&(inbuf[0]));
  if ((probCnt < 1) || (probCnt > MAX_PROBS)) {
    fprintf(stderr, "Problem count %d not in range 1...%d\n", probCnt,
            MAX_PROBS);
    return -2;
  }
  for (curProb = 1; curProb <= probCnt; curProb++) {
    if ((ret = ReadDataSet(curProb)) != 0) {
      fprintf(stderr, "ReadDataSet returned %d on problem %d\n", ret, curProb);
      return -3;
    }
    TeleSolve();
    PrintSolution(curProb);
  }
  return 0;
}
