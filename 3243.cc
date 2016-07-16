#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long INT;
#define MAX (1000000)
INT nData[MAX];
INT nKey[MAX];

INT HashPos(INT key) { return ((unsigned)(key ^ 0xA5A5A5A5)) % MAX; }

void HashAdd(INT key, INT data) {
  INT nPos = HashPos(key);
  while (nData[nPos] != -1) {
    nPos = (nPos + 1) % MAX;
  }
  nData[nPos] = data;
  nKey[nPos] = key;
}

INT HashQuery(INT key) {
  INT nPos = HashPos(key);
  while (nData[nPos] != -1) {
    if (nKey[nPos] == key) {
      return nData[nPos];
    }
    nPos = (nPos + 1) % MAX;
  }

  return -1;
}

INT MultMod(INT nA, INT nB, INT nC) {
  INT nAns = 0;
  while (nB) {
    if (nB & 1) {
      nAns = (nAns + nA) % nC;
    }
    nA = (2 * nA) % nC;
    nB >>= 1;
  }
  return nAns;
}

INT PowerMod(INT nA, INT nX, INT nC) {
  INT nAns = 1;
  nA %= nC;
  while (nX) {
    if (nX & 1) {
      nAns = MultMod(nAns, nA, nC);
    }
    nA = MultMod(nA, nA, nC);
    nX >>= 1;
  }
  return nAns;
}

INT gcd(INT nA, INT nB) {
  if (nA < nB) swap(nA, nB);
  while (nB) {
    INT nT = nA;
    nA = nB;
    nB = nT % nB;
  }
  return nA;
}

INT egcd(INT nA, INT nB, INT& nX, INT& nY) {
  if (nA < nB) swap(nA, nB);
  if (nB == 0) {
    nX = 1;
    nY = 0;
    return nA;
  }
  INT nRet = egcd(nB, nA % nB, nX, nY);
  INT nT = nX;
  nX = nY;
  nY = nT - (nA / nB) * nY;
  return nRet;
}

INT GetAns(INT nA, INT nB, INT nC) {
  if (nC == 0) return -1;

  INT nTemp = 1;
  nB %= nC;
  for (INT i = 0; i <= 50; ++i) {
    if (nTemp == nB) {
      return i;
    }
    nTemp = MultMod(nTemp, nA, nC);
  }

  INT d;
  INT nD = 1;  // nD最后是A^k次,k是nC中因子d的次数
  INT k = 0;
  while ((d = gcd(nC, nA)) != 1) {
    k++;
    nC /= d;
    if (nB % d) return -1;
    nB /= d;
    nD = MultMod(nD, nA / d, nC);
  }

  memset(nKey, -1, sizeof(nKey));
  memset(nData, -1, sizeof(nData));
  INT nM = ceil(sqrt(1.0 * nC));
  nTemp = 1;
  for (INT j = 0; j <= nM; ++j) {
    HashAdd(nTemp, j);
    nTemp = MultMod(nTemp, nA, nC);
  }
  INT nK = PowerMod(nA, nM, nC);
  for (int i = 0; i <= nM; ++i) {
    INT x, y;
    egcd(nC, nD, x, y);
    y = (y + nC) % nC;
    INT nR = MultMod(y, nB, nC);
    int j = HashQuery(nR);
    if (j != -1) {
      return nM * i + j + k;
    }

    nD = MultMod(nD, nK, nC);
  }
  return -1;
}

int main() {
  INT nA, nB, nC;

  while (scanf("%I64d%I64d%I64d", &nA, &nC, &nB), nA + nB + nC) {
    INT nAns = GetAns(nA, nB, nC);
    if (nAns == -1) {
      printf("No Solution\n");
    } else {
      printf("%I64d\n", nAns);
    }
  }

  return 0;
}
